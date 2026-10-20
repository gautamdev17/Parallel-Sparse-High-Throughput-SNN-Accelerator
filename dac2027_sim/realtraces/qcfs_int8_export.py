"""
qcfs_int8_export.py -- SNN-QCFS-Pruning's test_quantize.py __main__, step for step and with the repo's own functions and
data loader, minus its CollectiveSparsityProfiler (its per-layer F.unfold makes the INT8 evaluation take ~84 s per
batch on a CPU, ~3.5 h for the test set; it only prints zero-count statistics and does not change the saved file).

  <venv python> qcfs_int8_export.py [restore] [save_path]
    default: ~/SNN-QCFS-Pruning/pruned/final_cifar10_vgg16_group_sl.pth
          -> ~/SNN-QCFS-Pruning/pruned/quantized_cifar10_vgg16_group_sl_int8.pth
  Saved dict = test_quantize.py's: {int_weights: {layer: {w_int (int8), scale, bias}}, masks, n_bits, L}
"""
import os, sys
import torch

REPO = os.path.expanduser("~/SNN-QCFS-Pruning")
sys.path.insert(0, REPO)

if __name__ == "__main__":
    import test_quantize as TQ
    restore = sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "pruned", "final_cifar10_vgg16_group_sl.pth")
    save_path = sys.argv[2] if len(sys.argv) > 2 else os.path.join(REPO, "pruned", "quantized_cifar10_vgg16_group_sl_int8.pth")
    n_bits, L, device = 8, 8, torch.device("cpu")
    torch.set_num_threads(os.cpu_count())

    trainloader, testloader = TQ.GetCifar10(64)     # test_quantize.py default batch size

    ckpt = torch.load(restore, map_location="cpu", weights_only=False)
    if isinstance(ckpt, dict) and "masks" in ckpt:
        model, masks = ckpt["model"], ckpt["masks"]
    else:
        model, masks = ckpt, {}

    model.set_L(L)
    model.set_T(0)
    TQ.apply_masks(model, masks)
    model.to(device).eval()

    TQ.fold_all_batchnorms(model)
    TQ.swap_to_quant(model, n_bits=n_bits)
    TQ.calibrate_all(model)
    model.to(device)

    acc_wq = TQ.evaluate(model, testloader, device, T=0)
    print(f"After weight quant (W{n_bits}): {acc_wq:.2f}%", flush=True)

    payload = TQ.export_integer_weights(model)
    TQ.apply_masks(model, masks)
    torch.save({"int_weights": payload, "masks": masks, "n_bits": n_bits, "L": L}, save_path)
    print(f"Saved to {save_path}")

    nz = sum(int((p["w_int"] != 0).sum()) for p in payload.values())
    tot = sum(p["w_int"].numel() for p in payload.values())
    mask_sp = sum((~m).sum().item() for m in masks.values()) / max(sum(m.numel() for m in masks.values()), 1) * 100
    print(f"Final quantized model: W{n_bits}, mask sparsity={mask_sp:.1f}%, INT8 zero weights={100 * (1 - nz / tot):.2f}%")
