// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ours_closed.h for the primary calling header

#include "Vtb_ours_closed__pch.h"

void Vtb_ours_closed___024root___nba_sequent__TOP__3(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___nba_sequent__TOP__3\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__row_in[0U] 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__inj_v) 
            << 0x0000000dU) | (((IData)(vlSelfRef.tb_ours_closed__DOT__inj_par) 
                                << 0x0000000cU) | (
                                                   (0x00000f00U 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__inj_bits) 
                                                       << 8U)) 
                                                   | (0x000000ffU 
                                                      & vlSelfRef.tb_ours_closed__DOT__inj_lab))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U] 
        = (IData)((QData)((IData)((0x0000007fU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                          >> 0x00000031U))))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U] 
        = ((0xf0000000U & (vlSelfRef.tb_ours_closed__DOT__sl_m[3U] 
                           << 0x0000000cU)) | (IData)(
                                                      ((QData)((IData)(
                                                                       (0x0000007fU 
                                                                        & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                                                >> 0x00000031U))))) 
                                                       >> 0x00000020U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = ((0x0000f000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]) 
           | (0x0000ffffU & (vlSelfRef.tb_ours_closed__DOT__sl_m[3U] 
                             >> 0x00000014U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = (0x00009000U | (0x00000fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U] 
        = (IData)((QData)((IData)((0x0000007fU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                          >> 0x0000002aU))))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U] 
        = ((vlSelfRef.tb_ours_closed__DOT__sl_m[3U] 
            << 0x0000001cU) | (IData)(((QData)((IData)(
                                                       (0x0000007fU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                                   >> 0x0000002aU))))) 
                                       >> 0x00000020U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = ((0x0000f000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]) 
           | (0x00000fffU & (vlSelfRef.tb_ours_closed__DOT__sl_m[3U] 
                             >> 4U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = (0x00009000U | (0x00000fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U] 
        = (IData)((QData)((IData)((0x0000007fU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                          >> 0x00000023U))))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U] 
        = ((0xf0000000U & (vlSelfRef.tb_ours_closed__DOT__sl_m[2U] 
                           << 0x0000000cU)) | (IData)(
                                                      ((QData)((IData)(
                                                                       (0x0000007fU 
                                                                        & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                                                >> 0x00000023U))))) 
                                                       >> 0x00000020U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = ((0x0000f000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]) 
           | (0x0000ffffU & (vlSelfRef.tb_ours_closed__DOT__sl_m[2U] 
                             >> 0x00000014U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = (0x00009000U | (0x00000fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U] 
        = (IData)((QData)((IData)((0x0000007fU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                          >> 0x0000001cU))))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U] 
        = ((vlSelfRef.tb_ours_closed__DOT__sl_m[2U] 
            << 0x0000001cU) | (IData)(((QData)((IData)(
                                                       (0x0000007fU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                                   >> 0x0000001cU))))) 
                                       >> 0x00000020U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = ((0x0000f000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]) 
           | (0x00000fffU & (vlSelfRef.tb_ours_closed__DOT__sl_m[2U] 
                             >> 4U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = (0x00009000U | (0x00000fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U] 
        = (IData)((QData)((IData)((0x0000007fU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                          >> 0x00000015U))))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U] 
        = ((0xf0000000U & (vlSelfRef.tb_ours_closed__DOT__sl_m[1U] 
                           << 0x0000000cU)) | (IData)(
                                                      ((QData)((IData)(
                                                                       (0x0000007fU 
                                                                        & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                                                >> 0x00000015U))))) 
                                                       >> 0x00000020U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = ((0x0000f000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]) 
           | (0x0000ffffU & (vlSelfRef.tb_ours_closed__DOT__sl_m[1U] 
                             >> 0x00000014U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = (0x00009000U | (0x00000fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U] 
        = (IData)((QData)((IData)((0x0000007fU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                          >> 0x0000000eU))))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U] 
        = ((vlSelfRef.tb_ours_closed__DOT__sl_m[1U] 
            << 0x0000001cU) | (IData)(((QData)((IData)(
                                                       (0x0000007fU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                                   >> 0x0000000eU))))) 
                                       >> 0x00000020U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = ((0x0000f000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]) 
           | (0x00000fffU & (vlSelfRef.tb_ours_closed__DOT__sl_m[1U] 
                             >> 4U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = (0x00009000U | (0x00000fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U] 
        = (IData)((QData)((IData)((0x0000007fU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                          >> 7U))))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U] 
        = ((0xf0000000U & (vlSelfRef.tb_ours_closed__DOT__sl_m[0U] 
                           << 0x0000000cU)) | (IData)(
                                                      ((QData)((IData)(
                                                                       (0x0000007fU 
                                                                        & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__sl_id 
                                                                                >> 7U))))) 
                                                       >> 0x00000020U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = ((0x0000f000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]) 
           | (0x0000ffffU & (vlSelfRef.tb_ours_closed__DOT__sl_m[0U] 
                             >> 0x00000014U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = (0x00009000U | (0x00000fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U] 
        = (IData)((QData)((IData)((0x0000007fU & (IData)(vlSelfRef.tb_ours_closed__DOT__sl_id)))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U] 
        = ((vlSelfRef.tb_ours_closed__DOT__sl_m[0U] 
            << 0x0000001cU) | (IData)(((QData)((IData)(
                                                       (0x0000007fU 
                                                        & (IData)(vlSelfRef.tb_ours_closed__DOT__sl_id)))) 
                                       >> 0x00000020U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = ((0x0000f000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]) 
           | (0x00000fffU & (vlSelfRef.tb_ours_closed__DOT__sl_m[0U] 
                             >> 4U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U] 
        = (0x00009000U | (0x00000fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U]));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__sl_v) 
            >> 7U) & (0U != (vlSelfRef.tb_ours_closed__DOT__sl_m[3U] 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__sl_v) 
            >> 6U) & (0U != (0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__sl_m[3U])));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__sl_v) 
            >> 5U) & (0U != (vlSelfRef.tb_ours_closed__DOT__sl_m[2U] 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__sl_v) 
            >> 4U) & (0U != (0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__sl_m[2U])));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__sl_v) 
            >> 3U) & (0U != (vlSelfRef.tb_ours_closed__DOT__sl_m[1U] 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__sl_v) 
            >> 2U) & (0U != (0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__sl_m[1U])));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__sl_v) 
            >> 1U) & (0U != (vlSelfRef.tb_ours_closed__DOT__sl_m[0U] 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act 
        = ((IData)(vlSelfRef.tb_ours_closed__DOT__sl_v) 
           & (0U != (0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__sl_m[0U])));
}

void Vtb_ours_closed___024root___nba_sequent__TOP__4(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___nba_sequent__TOP__4\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest;
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest = 0;
    CData/*6:0*/ tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest;
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest = 0;
    CData/*6:0*/ tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest;
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest = 0;
    CData/*6:0*/ tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest;
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest = 0;
    // Body
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[0U] = (IData)(
                                                           (((QData)((IData)(
                                                                             (0x00001fffU 
                                                                              & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                             << 0x0000001aU) 
                                                            | (QData)((IData)(
                                                                              ((0x03ffe000U 
                                                                                & ((IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U)) 
                                                                                << 0x0000000dU)) 
                                                                               | (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[1U] = 
        ((0xffffff80U & vlSelfRef.tb_ours_closed__DOT__obuf_addr[1U]) 
         | (IData)(((((QData)((IData)((0x00001fffU 
                                       & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                  >> 0x00000028U))))) 
                      << 0x0000001aU) | (QData)((IData)(
                                                        ((0x03ffe000U 
                                                          & ((IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                      >> 0x00000028U)) 
                                                             << 0x0000000dU)) 
                                                         | (0x00001fffU 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                       >> 0x00000028U))))))) 
                    >> 0x00000020U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[1U] = 
        ((0x0000007fU & vlSelfRef.tb_ours_closed__DOT__obuf_addr[1U]) 
         | ((IData)((((QData)((IData)((0x00001fffU 
                                       & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                  >> 0x00000028U))))) 
                      << 0x0000001aU) | (QData)((IData)(
                                                        ((0x03ffe000U 
                                                          & ((IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                      >> 0x00000028U)) 
                                                             << 0x0000000dU)) 
                                                         | (0x00001fffU 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                       >> 0x00000028U)))))))) 
            << 7U));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[2U] = 
        ((0xffffc000U & vlSelfRef.tb_ours_closed__DOT__obuf_addr[2U]) 
         | (((IData)((((QData)((IData)((0x00001fffU 
                                        & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                   >> 0x00000028U))))) 
                       << 0x0000001aU) | (QData)((IData)(
                                                         ((0x03ffe000U 
                                                           & ((IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                       >> 0x00000028U)) 
                                                              << 0x0000000dU)) 
                                                          | (0x00001fffU 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                        >> 0x00000028U)))))))) 
             >> 0x00000019U) | ((IData)(((((QData)((IData)(
                                                           (0x00001fffU 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                       >> 0x00000028U))))) 
                                           << 0x0000001aU) 
                                          | (QData)((IData)(
                                                            ((0x03ffe000U 
                                                              & ((IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                          >> 0x00000028U)) 
                                                                 << 0x0000000dU)) 
                                                             | (0x00001fffU 
                                                                & (IData)(
                                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                           >> 0x00000028U))))))) 
                                         >> 0x00000020U)) 
                                << 7U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[2U] = 
        ((0x00003fffU & vlSelfRef.tb_ours_closed__DOT__obuf_addr[2U]) 
         | ((IData)((((QData)((IData)((0x00001fffU 
                                       & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                  >> 0x00000028U))))) 
                      << 0x0000001aU) | (QData)((IData)(
                                                        ((0x03ffe000U 
                                                          & ((IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                      >> 0x00000028U)) 
                                                             << 0x0000000dU)) 
                                                         | (0x00001fffU 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                       >> 0x00000028U)))))))) 
            << 0x0000000eU));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[3U] = 
        ((0xffe00000U & vlSelfRef.tb_ours_closed__DOT__obuf_addr[3U]) 
         | (((IData)((((QData)((IData)((0x00001fffU 
                                        & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                   >> 0x00000028U))))) 
                       << 0x0000001aU) | (QData)((IData)(
                                                         ((0x03ffe000U 
                                                           & ((IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                       >> 0x00000028U)) 
                                                              << 0x0000000dU)) 
                                                          | (0x00001fffU 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                        >> 0x00000028U)))))))) 
             >> 0x00000012U) | ((IData)(((((QData)((IData)(
                                                           (0x00001fffU 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                       >> 0x00000028U))))) 
                                           << 0x0000001aU) 
                                          | (QData)((IData)(
                                                            ((0x03ffe000U 
                                                              & ((IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                          >> 0x00000028U)) 
                                                                 << 0x0000000dU)) 
                                                             | (0x00001fffU 
                                                                & (IData)(
                                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                           >> 0x00000028U))))))) 
                                         >> 0x00000020U)) 
                                << 0x0000000eU)));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[3U] = 
        ((0x001fffffU & vlSelfRef.tb_ours_closed__DOT__obuf_addr[3U]) 
         | ((IData)((((QData)((IData)((0x00001fffU 
                                       & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                  >> 0x00000028U))))) 
                      << 0x0000001aU) | (QData)((IData)(
                                                        ((0x03ffe000U 
                                                          & ((IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                      >> 0x00000028U)) 
                                                             << 0x0000000dU)) 
                                                         | (0x00001fffU 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                       >> 0x00000028U)))))))) 
            << 0x00000015U));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[4U] = 
        ((0xf0000000U & vlSelfRef.tb_ours_closed__DOT__obuf_addr[4U]) 
         | (((IData)((((QData)((IData)((0x00001fffU 
                                        & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                   >> 0x00000028U))))) 
                       << 0x0000001aU) | (QData)((IData)(
                                                         ((0x03ffe000U 
                                                           & ((IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                       >> 0x00000028U)) 
                                                              << 0x0000000dU)) 
                                                          | (0x00001fffU 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                        >> 0x00000028U)))))))) 
             >> 0x0000000bU) | ((IData)(((((QData)((IData)(
                                                           (0x00001fffU 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                       >> 0x00000028U))))) 
                                           << 0x0000001aU) 
                                          | (QData)((IData)(
                                                            ((0x03ffe000U 
                                                              & ((IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                          >> 0x00000028U)) 
                                                                 << 0x0000000dU)) 
                                                             | (0x00001fffU 
                                                                & (IData)(
                                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                           >> 0x00000028U))))))) 
                                         >> 0x00000020U)) 
                                << 0x00000015U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[4U] = 
        ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_addr[4U]) 
         | ((IData)((((QData)((IData)((0x00001fffU 
                                       & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                  >> 0x00000028U))))) 
                      << 0x0000001aU) | (QData)((IData)(
                                                        ((0x03ffe000U 
                                                          & ((IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                      >> 0x00000028U)) 
                                                             << 0x0000000dU)) 
                                                         | (0x00001fffU 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                       >> 0x00000028U)))))))) 
            << 0x0000001cU));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[5U] = 
        (((IData)((((QData)((IData)((0x00001fffU & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                            >> 0x00000028U))))) 
                    << 0x0000001aU) | (QData)((IData)(
                                                      ((0x03ffe000U 
                                                        & ((IData)(
                                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                    >> 0x00000028U)) 
                                                           << 0x0000000dU)) 
                                                       | (0x00001fffU 
                                                          & (IData)(
                                                                    (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                     >> 0x00000028U)))))))) 
          >> 4U) | ((IData)(((((QData)((IData)((0x00001fffU 
                                                & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                           >> 0x00000028U))))) 
                               << 0x0000001aU) | (QData)((IData)(
                                                                 ((0x03ffe000U 
                                                                   & ((IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                               >> 0x00000028U)) 
                                                                      << 0x0000000dU)) 
                                                                  | (0x00001fffU 
                                                                     & (IData)(
                                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))))) 
                             >> 0x00000020U)) << 0x0000001cU));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[6U] = 
        ((0x0000fff8U & vlSelfRef.tb_ours_closed__DOT__obuf_addr[6U]) 
         | (0x0000ffffU & ((IData)(((((QData)((IData)(
                                                      (0x00001fffU 
                                                       & (IData)(
                                                                 (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                  >> 0x00000028U))))) 
                                      << 0x0000001aU) 
                                     | (QData)((IData)(
                                                       ((0x03ffe000U 
                                                         & ((IData)(
                                                                    (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                     >> 0x00000028U)) 
                                                            << 0x0000000dU)) 
                                                        | (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                      >> 0x00000028U))))))) 
                                    >> 0x00000020U)) 
                           >> 4U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_addr[6U] = 
        ((7U & vlSelfRef.tb_ours_closed__DOT__obuf_addr[6U]) 
         | (0x0000fff8U & ((IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                    >> 0x00000028U)) 
                           << 3U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_waddr[0U] = (IData)(
                                                            (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a)) 
                                                              << 0x00000027U) 
                                                             | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a)) 
                                                                 << 0x0000001aU) 
                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                                                << 0x0000000dU) 
                                                                                | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a)))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_waddr[1U] = 
        ((0xfff00000U & vlSelfRef.tb_ours_closed__DOT__obuf_waddr[1U]) 
         | (IData)(((((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a)) 
                      << 0x00000027U) | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a)) 
                                          << 0x0000001aU) 
                                         | (QData)((IData)(
                                                           (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             << 0x0000000dU) 
                                                            | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a)))))) 
                    >> 0x00000020U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_waddr[1U] = 
        ((0x000fffffU & vlSelfRef.tb_ours_closed__DOT__obuf_waddr[1U]) 
         | ((IData)((((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a)) 
                      << 0x00000027U) | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a)) 
                                          << 0x0000001aU) 
                                         | (QData)((IData)(
                                                           (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             << 0x0000000dU) 
                                                            | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a))))))) 
            << 0x00000014U));
    vlSelfRef.tb_ours_closed__DOT__obuf_waddr[2U] = 
        (((IData)((((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a)) 
                    << 0x00000027U) | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a)) 
                                        << 0x0000001aU) 
                                       | (QData)((IData)(
                                                         (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                           << 0x0000000dU) 
                                                          | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a))))))) 
          >> 0x0000000cU) | ((IData)(((((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a)) 
                                        << 0x00000027U) 
                                       | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a)) 
                                           << 0x0000001aU) 
                                          | (QData)((IData)(
                                                            (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                              << 0x0000000dU) 
                                                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a)))))) 
                                      >> 0x00000020U)) 
                             << 0x00000014U));
    vlSelfRef.tb_ours_closed__DOT__obuf_waddr[3U] = 
        ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_waddr[3U]) 
         | ((IData)(((((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a)) 
                       << 0x00000027U) | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a)) 
                                           << 0x0000001aU) 
                                          | (QData)((IData)(
                                                            (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                              << 0x0000000dU) 
                                                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a)))))) 
                     >> 0x00000020U)) >> 0x0000000cU));
    vlSelfRef.tb_ours_closed__DOT__obuf_waddr[3U] = 
        ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_waddr[3U]) 
         | ((IData)((((QData)((IData)((((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                        << 0x0000000dU) 
                                       | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a)))) 
                      << 0x0000001aU) | (QData)((IData)(
                                                        (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                          << 0x0000000dU) 
                                                         | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a)))))) 
            << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_waddr[4U] = 
        (((IData)((((QData)((IData)((((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                      << 0x0000000dU) 
                                     | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a)))) 
                    << 0x0000001aU) | (QData)((IData)(
                                                      (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                        << 0x0000000dU) 
                                                       | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a)))))) 
          >> 0x00000018U) | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                              << 0x0000001cU) | ((IData)(
                                                         ((((QData)((IData)(
                                                                            (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                              << 0x0000000dU) 
                                                                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a)))) 
                                                            << 0x0000001aU) 
                                                           | (QData)((IData)(
                                                                             (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                                               << 0x0000000dU) 
                                                                              | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a))))) 
                                                          >> 0x00000020U)) 
                                                 << 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_waddr[5U] = 
        ((0xfffffe00U & vlSelfRef.tb_ours_closed__DOT__obuf_waddr[5U]) 
         | (((0x000000ffU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                             >> 4U)) | ((IData)(((((QData)((IData)(
                                                                   (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                     << 0x0000000dU) 
                                                                    | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a)))) 
                                                   << 0x0000001aU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                                      << 0x0000000dU) 
                                                                     | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a))))) 
                                                 >> 0x00000020U)) 
                                        >> 0x00000018U)) 
            | (0x0fffff00U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                              >> 4U))));
    vlSelfRef.tb_ours_closed__DOT__obuf_waddr[5U] = 
        ((0x000001ffU & vlSelfRef.tb_ours_closed__DOT__obuf_waddr[5U]) 
         | ((IData)((((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a)) 
                      << 0x0000001aU) | (QData)((IData)(
                                                        (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                          << 0x0000000dU) 
                                                         | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a)))))) 
            << 9U));
    vlSelfRef.tb_ours_closed__DOT__obuf_waddr[6U] = 
        (0x0000ffffU & (((IData)((((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a)) 
                                   << 0x0000001aU) 
                                  | (QData)((IData)(
                                                    (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                      << 0x0000000dU) 
                                                     | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a)))))) 
                         >> 0x00000017U) | ((IData)(
                                                    ((((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a)) 
                                                       << 0x0000001aU) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                          << 0x0000000dU) 
                                                                         | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a))))) 
                                                     >> 0x00000020U)) 
                                            << 9U)));
    vlSelfRef.tb_ours_closed__DOT__gv = (((QData)((IData)(
                                                          ((((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gv) 
                                                             << 0x0000000fU) 
                                                            | ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gv) 
                                                               << 0x0000000aU)) 
                                                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gv) 
                                                               << 5U) 
                                                              | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gv))))) 
                                          << 0x00000014U) 
                                         | (QData)((IData)(
                                                           ((((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gv) 
                                                              << 0x0000000fU) 
                                                             | ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gv) 
                                                                << 0x0000000aU)) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gv) 
                                                                << 5U) 
                                                               | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gv))))));
    vlSelfRef.tb_ours_closed__DOT__gm[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gm[0U];
    vlSelfRef.tb_ours_closed__DOT__gm[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gm[1U];
    vlSelfRef.tb_ours_closed__DOT__gm[2U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gm[0U] 
                                              << 0x00000010U) 
                                             | vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gm[2U]);
    vlSelfRef.tb_ours_closed__DOT__gm[3U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gm[0U] 
                                              >> 0x00000010U) 
                                             | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gm[1U] 
                                                << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gm[4U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gm[1U] 
                                              >> 0x00000010U) 
                                             | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gm[2U] 
                                                << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gm[5U] = (((0x0000ffffU 
                                               & vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gm[0U]) 
                                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gm[2U] 
                                                 >> 0x00000010U)) 
                                             | (0xffff0000U 
                                                & vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gm[0U]));
    vlSelfRef.tb_ours_closed__DOT__gm[6U] = ((0x0000ffffU 
                                              & vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gm[1U]) 
                                             | (0xffff0000U 
                                                & vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gm[1U]));
    vlSelfRef.tb_ours_closed__DOT__gm[7U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gm[0U] 
                                              << 0x00000010U) 
                                             | (0x0000ffffU 
                                                & vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gm[2U]));
    vlSelfRef.tb_ours_closed__DOT__gm[8U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gm[0U] 
                                              >> 0x00000010U) 
                                             | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gm[1U] 
                                                << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gm[9U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gm[1U] 
                                              >> 0x00000010U) 
                                             | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gm[2U] 
                                                << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gm[10U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gm[0U];
    vlSelfRef.tb_ours_closed__DOT__gm[11U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gm[1U];
    vlSelfRef.tb_ours_closed__DOT__gm[12U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gm[0U] 
                                               << 0x00000010U) 
                                              | vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gm[2U]);
    vlSelfRef.tb_ours_closed__DOT__gm[13U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gm[0U] 
                                               >> 0x00000010U) 
                                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gm[1U] 
                                                 << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gm[14U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gm[1U] 
                                               >> 0x00000010U) 
                                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gm[2U] 
                                                 << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gm[15U] = (((0x0000ffffU 
                                                & vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gm[0U]) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gm[2U] 
                                                  >> 0x00000010U)) 
                                              | (0xffff0000U 
                                                 & vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gm[0U]));
    vlSelfRef.tb_ours_closed__DOT__gm[16U] = ((0x0000ffffU 
                                               & vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gm[1U]) 
                                              | (0xffff0000U 
                                                 & vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gm[1U]));
    vlSelfRef.tb_ours_closed__DOT__gm[17U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gm[0U] 
                                               << 0x00000010U) 
                                              | (0x0000ffffU 
                                                 & vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gm[2U]));
    vlSelfRef.tb_ours_closed__DOT__gm[18U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gm[0U] 
                                               >> 0x00000010U) 
                                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gm[1U] 
                                                 << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gm[19U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gm[1U] 
                                               >> 0x00000010U) 
                                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gm[2U] 
                                                 << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__glab[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gl[0U];
    vlSelfRef.tb_ours_closed__DOT__glab[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gl[1U];
    vlSelfRef.tb_ours_closed__DOT__glab[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gl[2U];
    vlSelfRef.tb_ours_closed__DOT__glab[3U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gl[3U];
    vlSelfRef.tb_ours_closed__DOT__glab[4U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gl[4U];
    vlSelfRef.tb_ours_closed__DOT__glab[5U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gl[0U];
    vlSelfRef.tb_ours_closed__DOT__glab[6U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gl[1U];
    vlSelfRef.tb_ours_closed__DOT__glab[7U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gl[2U];
    vlSelfRef.tb_ours_closed__DOT__glab[8U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gl[3U];
    vlSelfRef.tb_ours_closed__DOT__glab[9U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gl[4U];
    vlSelfRef.tb_ours_closed__DOT__glab[10U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gl[0U];
    vlSelfRef.tb_ours_closed__DOT__glab[11U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gl[1U];
    vlSelfRef.tb_ours_closed__DOT__glab[12U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gl[2U];
    vlSelfRef.tb_ours_closed__DOT__glab[13U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gl[3U];
    vlSelfRef.tb_ours_closed__DOT__glab[14U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gl[4U];
    vlSelfRef.tb_ours_closed__DOT__glab[15U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gl[0U];
    vlSelfRef.tb_ours_closed__DOT__glab[16U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gl[1U];
    vlSelfRef.tb_ours_closed__DOT__glab[17U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gl[2U];
    vlSelfRef.tb_ours_closed__DOT__glab[18U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gl[3U];
    vlSelfRef.tb_ours_closed__DOT__glab[19U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gl[4U];
    vlSelfRef.tb_ours_closed__DOT__glab[20U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gl[0U];
    vlSelfRef.tb_ours_closed__DOT__glab[21U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gl[1U];
    vlSelfRef.tb_ours_closed__DOT__glab[22U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gl[2U];
    vlSelfRef.tb_ours_closed__DOT__glab[23U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gl[3U];
    vlSelfRef.tb_ours_closed__DOT__glab[24U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gl[4U];
    vlSelfRef.tb_ours_closed__DOT__glab[25U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gl[0U];
    vlSelfRef.tb_ours_closed__DOT__glab[26U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gl[1U];
    vlSelfRef.tb_ours_closed__DOT__glab[27U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gl[2U];
    vlSelfRef.tb_ours_closed__DOT__glab[28U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gl[3U];
    vlSelfRef.tb_ours_closed__DOT__glab[29U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gl[4U];
    vlSelfRef.tb_ours_closed__DOT__glab[30U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gl[0U];
    vlSelfRef.tb_ours_closed__DOT__glab[31U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gl[1U];
    vlSelfRef.tb_ours_closed__DOT__glab[32U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gl[2U];
    vlSelfRef.tb_ours_closed__DOT__glab[33U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gl[3U];
    vlSelfRef.tb_ours_closed__DOT__glab[34U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gl[4U];
    vlSelfRef.tb_ours_closed__DOT__glab[35U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gl[0U];
    vlSelfRef.tb_ours_closed__DOT__glab[36U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gl[1U];
    vlSelfRef.tb_ours_closed__DOT__glab[37U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gl[2U];
    vlSelfRef.tb_ours_closed__DOT__glab[38U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gl[3U];
    vlSelfRef.tb_ours_closed__DOT__glab[39U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gl[4U];
    vlSelfRef.tb_ours_closed__DOT__gid[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gid[0U];
    vlSelfRef.tb_ours_closed__DOT__gid[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gid[1U];
    vlSelfRef.tb_ours_closed__DOT__gid[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gid[2U];
    vlSelfRef.tb_ours_closed__DOT__gid[3U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gid[3U];
    vlSelfRef.tb_ours_closed__DOT__gid[4U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gid[0U] 
                                               << 0x0000000cU) 
                                              | vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gid[4U]);
    vlSelfRef.tb_ours_closed__DOT__gid[5U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gid[0U] 
                                               >> 0x00000014U) 
                                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gid[1U] 
                                                 << 0x0000000cU));
    vlSelfRef.tb_ours_closed__DOT__gid[6U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gid[1U] 
                                               >> 0x00000014U) 
                                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gid[2U] 
                                                 << 0x0000000cU));
    vlSelfRef.tb_ours_closed__DOT__gid[7U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gid[2U] 
                                               >> 0x00000014U) 
                                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gid[3U] 
                                                 << 0x0000000cU));
    vlSelfRef.tb_ours_closed__DOT__gid[8U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid[0U] 
                                               << 0x00000018U) 
                                              | ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gid[3U] 
                                                  >> 0x00000014U) 
                                                 | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gid[4U] 
                                                    << 0x0000000cU)));
    vlSelfRef.tb_ours_closed__DOT__gid[9U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid[0U] 
                                               >> 8U) 
                                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid[1U] 
                                                 << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__gid[10U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid[1U] 
                                                >> 8U) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid[2U] 
                                                  << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__gid[11U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid[2U] 
                                                >> 8U) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid[3U] 
                                                  << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__gid[12U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid[3U] 
                                                >> 8U) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid[4U] 
                                                  << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__gid[13U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gid[0U] 
                                                << 4U) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid[4U] 
                                                  >> 8U));
    vlSelfRef.tb_ours_closed__DOT__gid[14U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gid[0U] 
                                                >> 0x0000001cU) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gid[1U] 
                                                  << 4U));
    vlSelfRef.tb_ours_closed__DOT__gid[15U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gid[1U] 
                                                >> 0x0000001cU) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gid[2U] 
                                                  << 4U));
    vlSelfRef.tb_ours_closed__DOT__gid[16U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gid[2U] 
                                                >> 0x0000001cU) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gid[3U] 
                                                  << 4U));
    vlSelfRef.tb_ours_closed__DOT__gid[17U] = ((0xffff0000U 
                                                & vlSelfRef.tb_ours_closed__DOT__gid[17U]) 
                                               | ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gid[3U] 
                                                   >> 0x0000001cU) 
                                                  | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gid[4U] 
                                                     << 4U)));
    vlSelfRef.tb_ours_closed__DOT__gid[17U] = ((0x0000ffffU 
                                                & vlSelfRef.tb_ours_closed__DOT__gid[17U]) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid[0U] 
                                                  << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gid[18U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid[0U] 
                                                >> 0x00000010U) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid[1U] 
                                                  << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gid[19U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid[1U] 
                                                >> 0x00000010U) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid[2U] 
                                                  << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gid[20U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid[2U] 
                                                >> 0x00000010U) 
                                               | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid[3U] 
                                                  << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__gid[21U] = ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid[3U] 
                                                >> 0x00000010U) 
                                               | ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[0U] 
                                                   << 0x0000001cU) 
                                                  | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid[4U] 
                                                     << 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__gid[22U] = (((0x0000ffffU 
                                                 & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[0U] 
                                                    >> 4U)) 
                                                | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid[4U] 
                                                   >> 0x00000010U)) 
                                               | ((0x0fff0000U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[0U] 
                                                      >> 4U)) 
                                                  | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[1U] 
                                                     << 0x0000001cU)));
    vlSelfRef.tb_ours_closed__DOT__gid[23U] = ((0x0000ffffU 
                                                & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[1U] 
                                                   >> 4U)) 
                                               | ((0x0fff0000U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[1U] 
                                                      >> 4U)) 
                                                  | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[2U] 
                                                     << 0x0000001cU)));
    vlSelfRef.tb_ours_closed__DOT__gid[24U] = ((0x0000ffffU 
                                                & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[2U] 
                                                   >> 4U)) 
                                               | ((0x0fff0000U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[2U] 
                                                      >> 4U)) 
                                                  | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[3U] 
                                                     << 0x0000001cU)));
    vlSelfRef.tb_ours_closed__DOT__gid[25U] = ((0x0000ffffU 
                                                & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[3U] 
                                                   >> 4U)) 
                                               | ((0x0fff0000U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[3U] 
                                                      >> 4U)) 
                                                  | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[4U] 
                                                     << 0x0000001cU)));
    vlSelfRef.tb_ours_closed__DOT__gid[26U] = (((0x0000ff00U 
                                                 & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[0U] 
                                                    << 8U)) 
                                                | (0x0000ffffU 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid[4U] 
                                                      >> 4U))) 
                                               | (0xffff0000U 
                                                  & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[0U] 
                                                     << 8U)));
    vlSelfRef.tb_ours_closed__DOT__gid[27U] = (((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[0U] 
                                                 >> 0x00000018U) 
                                                | (0x0000ff00U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[1U] 
                                                      << 8U))) 
                                               | (0xffff0000U 
                                                  & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[1U] 
                                                     << 8U)));
    vlSelfRef.tb_ours_closed__DOT__gid[28U] = (((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[1U] 
                                                 >> 0x00000018U) 
                                                | (0x0000ff00U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[2U] 
                                                      << 8U))) 
                                               | (0xffff0000U 
                                                  & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[2U] 
                                                     << 8U)));
    vlSelfRef.tb_ours_closed__DOT__gid[29U] = (((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[2U] 
                                                 >> 0x00000018U) 
                                                | (0x0000ff00U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[3U] 
                                                      << 8U))) 
                                               | (0xffff0000U 
                                                  & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[3U] 
                                                     << 8U)));
    vlSelfRef.tb_ours_closed__DOT__gid[30U] = (((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[3U] 
                                                 >> 0x00000018U) 
                                                | (0x0000ff00U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[4U] 
                                                      << 8U))) 
                                               | ((vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[0U] 
                                                   << 0x00000014U) 
                                                  | (0xffff0000U 
                                                     & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[4U] 
                                                        << 8U))));
    vlSelfRef.tb_ours_closed__DOT__gid[31U] = (((0x0000ffffU 
                                                 & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[0U] 
                                                    >> 0x0000000cU)) 
                                                | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid[4U] 
                                                   >> 0x00000018U)) 
                                               | ((0x000f0000U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[0U] 
                                                      >> 0x0000000cU)) 
                                                  | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[1U] 
                                                     << 0x00000014U)));
    vlSelfRef.tb_ours_closed__DOT__gid[32U] = ((0x0000ffffU 
                                                & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[1U] 
                                                   >> 0x0000000cU)) 
                                               | ((0x000f0000U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[1U] 
                                                      >> 0x0000000cU)) 
                                                  | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[2U] 
                                                     << 0x00000014U)));
    vlSelfRef.tb_ours_closed__DOT__gid[33U] = ((0x0000ffffU 
                                                & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[2U] 
                                                   >> 0x0000000cU)) 
                                               | ((0x000f0000U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[2U] 
                                                      >> 0x0000000cU)) 
                                                  | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[3U] 
                                                     << 0x00000014U)));
    vlSelfRef.tb_ours_closed__DOT__gid[34U] = ((0x0000ffffU 
                                                & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[3U] 
                                                   >> 0x0000000cU)) 
                                               | ((0x000f0000U 
                                                   & (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[3U] 
                                                      >> 0x0000000cU)) 
                                                  | (vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid[4U] 
                                                     << 0x00000014U)));
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sS__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sV__v0) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sS[0U] = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sS[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sV__v2) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sS[1U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sS__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sV__v3) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sS[0U] 
            = vlSelfRef.__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sS__v3;
    }
    vlSelfRef.tb_ours_closed__DOT__obuf_we = (((((((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                   << 3U) 
                                                  | ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                     << 2U)) 
                                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                     << 1U) 
                                                    | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v))) 
                                                << 0x0000000cU) 
                                               | (((((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                     << 3U) 
                                                    | ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                       << 2U)) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                       << 1U) 
                                                      | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v))) 
                                                  << 8U)) 
                                              | ((((((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                     << 3U) 
                                                    | ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                       << 2U)) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                       << 1U) 
                                                      | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v))) 
                                                  << 4U) 
                                                 | ((((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                      << 3U) 
                                                     | ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                        << 2U)) 
                                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                        << 1U) 
                                                       | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v)))));
    if (vlSelfRef.tb_ours_closed__DOT__rst) {
        vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__cnt = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__3__KET____DOT__fifo__overflow = 0U;
        vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__cnt = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__2__KET____DOT__fifo__overflow = 0U;
        vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__cnt = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__1__KET____DOT__fifo__overflow = 0U;
        vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__cnt = 0U;
        vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__0__KET____DOT__fifo__overflow = 0U;
    } else {
        vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__cnt 
            = (0x000000ffU & (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__cnt) 
                               + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr)) 
                              - (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nrd)));
        if ((0x00000050U < (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__cnt) 
                             + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr)) 
                            - (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nrd)))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__3__KET____DOT__fifo__overflow = 1U;
        }
        vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__cnt 
            = (0x000000ffU & (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__cnt) 
                               + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr)) 
                              - (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nrd)));
        if ((0x00000050U < (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__cnt) 
                             + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr)) 
                            - (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nrd)))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__2__KET____DOT__fifo__overflow = 1U;
        }
        vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__cnt 
            = (0x000000ffU & (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__cnt) 
                               + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr)) 
                              - (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nrd)));
        if ((0x00000050U < (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__cnt) 
                             + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr)) 
                            - (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nrd)))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__1__KET____DOT__fifo__overflow = 1U;
        }
        vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__cnt 
            = (0x000000ffU & (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__cnt) 
                               + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr)) 
                              - (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nrd)));
        if ((0x00000050U < (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__cnt) 
                             + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr)) 
                            - (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nrd)))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__0__KET____DOT__fifo__overflow = 1U;
        }
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[0U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (1U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 1U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 2U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 3U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 4U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 5U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 6U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 7U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 8U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 9U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 0x0aU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 0x0bU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 0x0cU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 0x0dU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 0x0eU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U] 
                                   >> 0x0fU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__cnt 
        = vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__cnt;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[0U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (1U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 1U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 2U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 3U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 4U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 5U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 6U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 7U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 8U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 9U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 0x0aU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 0x0bU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 0x0cU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 0x0dU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 0x0eU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U] 
                                   >> 0x0fU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__cnt 
        = vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__cnt;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[0U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (1U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 1U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 2U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 3U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 4U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 5U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 6U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 7U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 8U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 9U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 0x0aU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 0x0bU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 0x0cU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 0x0dU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 0x0eU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U] 
                                   >> 0x0fU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__cnt 
        = vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__cnt;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[0U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (1U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 1U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 2U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 3U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 4U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 5U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 6U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 7U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 8U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 9U))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 0x0aU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 0x0bU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 0x0cU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 0x0dU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 0x0eU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr 
        = (0x0000001fU & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr) 
                          + (1U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U] 
                                   >> 0x0fU))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__cnt 
        = vlSelfRef.__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__cnt;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xfffeU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[0U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[0U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xfffdU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[1U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[1U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xfffbU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[2U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[2U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xfff7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[3U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[3U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xffefU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[4U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[4U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xffdfU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[5U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[5U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xffbfU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[6U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[6U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xff7fU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[7U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[7U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xfeffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[8U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[8U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xfdffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[9U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[9U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xfbffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[10U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[10U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xf7ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[11U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[11U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xefffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[12U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[12U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xdfffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[13U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[13U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0xbfffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[14U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[14U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
        = (0x7fffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[15U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[15U] = 0U;
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[0U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[0U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[0U])));
    if ((1U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[1U])) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[0U]))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[1U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[1U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[1U])));
    if ((2U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[3U])) 
                                         << 0x0000002bU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[2U])) 
                                            << 0x0000000bU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[1U])) 
                                              >> 0x00000015U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[2U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[2U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[2U])));
    if ((4U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[4U])) 
                                         << 0x00000016U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[3U])) 
                                           >> 0x0000000aU)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[3U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[3U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[3U])));
    if ((8U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[6U])) 
                                         << 0x00000021U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[5U])) 
                                            << 1U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[4U])) 
                                              >> 0x0000001fU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[4U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[4U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[4U])));
    if ((0x00000010U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[8U])) 
                                         << 0x0000002cU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[7U])) 
                                            << 0x0000000cU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[6U])) 
                                              >> 0x00000014U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[5U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[5U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[5U])));
    if ((0x00000020U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[9U])) 
                                         << 0x00000017U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[8U])) 
                                           >> 9U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[6U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[6U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[6U])));
    if ((0x00000040U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[11U])) 
                                         << 0x00000022U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[10U])) 
                                            << 2U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[9U])) 
                                              >> 0x0000001eU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[7U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[7U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[7U])));
    if ((0x00000080U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[13U])) 
                                         << 0x0000002dU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[12U])) 
                                            << 0x0000000dU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[11U])) 
                                              >> 0x00000013U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[8U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[8U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[8U])));
    if ((0x00000100U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[14U])) 
                                         << 0x00000018U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[13U])) 
                                           >> 8U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[9U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[9U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[9U])));
    if ((0x00000200U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[16U])) 
                                         << 0x00000023U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[15U])) 
                                            << 3U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[14U])) 
                                              >> 0x0000001dU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[10U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[10U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[10U])));
    if ((0x00000400U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[18U])) 
                                         << 0x0000002eU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[17U])) 
                                            << 0x0000000eU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[16U])) 
                                              >> 0x00000012U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[11U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[11U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[11U])));
    if ((0x00000800U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[19U])) 
                                         << 0x00000019U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[18U])) 
                                           >> 7U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[12U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[12U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[12U])));
    if ((0x00001000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[21U])) 
                                         << 0x00000024U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[20U])) 
                                            << 4U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[19U])) 
                                              >> 0x0000001cU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[13U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[13U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[13U])));
    if ((0x00002000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[23U])) 
                                         << 0x0000002fU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[22U])) 
                                            << 0x0000000fU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[21U])) 
                                              >> 0x00000011U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[14U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[14U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[14U])));
    if ((0x00004000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[24U])) 
                                         << 0x0000001aU) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[23U])) 
                                           >> 6U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[15U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[15U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[15U])));
    if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][3U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[26U])) 
                                         << 0x00000025U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[25U])) 
                                            << 5U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd[24U])) 
                                              >> 0x0000001bU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail 
        = ((4U <= (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__cnt))
            ? 4U : (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__cnt)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xfffeU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[0U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[0U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xfffdU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[1U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[1U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xfffbU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[2U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[2U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xfff7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[3U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[3U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xffefU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[4U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[4U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xffdfU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[5U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[5U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xffbfU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[6U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[6U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xff7fU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[7U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[7U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xfeffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[8U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[8U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xfdffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[9U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[9U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xfbffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[10U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[10U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xf7ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[11U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[11U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xefffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[12U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[12U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xdfffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[13U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[13U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0xbfffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[14U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[14U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
        = (0x7fffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[15U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[15U] = 0U;
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[0U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[0U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[0U])));
    if ((1U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[1U])) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[0U]))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[1U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[1U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[1U])));
    if ((2U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[3U])) 
                                         << 0x0000002bU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[2U])) 
                                            << 0x0000000bU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[1U])) 
                                              >> 0x00000015U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[2U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[2U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[2U])));
    if ((4U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[4U])) 
                                         << 0x00000016U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[3U])) 
                                           >> 0x0000000aU)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[3U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[3U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[3U])));
    if ((8U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[6U])) 
                                         << 0x00000021U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[5U])) 
                                            << 1U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[4U])) 
                                              >> 0x0000001fU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[4U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[4U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[4U])));
    if ((0x00000010U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[8U])) 
                                         << 0x0000002cU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[7U])) 
                                            << 0x0000000cU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[6U])) 
                                              >> 0x00000014U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[5U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[5U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[5U])));
    if ((0x00000020U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[9U])) 
                                         << 0x00000017U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[8U])) 
                                           >> 9U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[6U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[6U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[6U])));
    if ((0x00000040U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[11U])) 
                                         << 0x00000022U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[10U])) 
                                            << 2U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[9U])) 
                                              >> 0x0000001eU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[7U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[7U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[7U])));
    if ((0x00000080U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[13U])) 
                                         << 0x0000002dU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[12U])) 
                                            << 0x0000000dU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[11U])) 
                                              >> 0x00000013U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[8U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[8U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[8U])));
    if ((0x00000100U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[14U])) 
                                         << 0x00000018U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[13U])) 
                                           >> 8U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[9U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[9U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[9U])));
    if ((0x00000200U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[16U])) 
                                         << 0x00000023U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[15U])) 
                                            << 3U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[14U])) 
                                              >> 0x0000001dU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[10U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[10U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[10U])));
    if ((0x00000400U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[18U])) 
                                         << 0x0000002eU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[17U])) 
                                            << 0x0000000eU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[16U])) 
                                              >> 0x00000012U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[11U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[11U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[11U])));
    if ((0x00000800U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[19U])) 
                                         << 0x00000019U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[18U])) 
                                           >> 7U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[12U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[12U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[12U])));
    if ((0x00001000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[21U])) 
                                         << 0x00000024U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[20U])) 
                                            << 4U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[19U])) 
                                              >> 0x0000001cU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[13U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[13U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[13U])));
    if ((0x00002000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[23U])) 
                                         << 0x0000002fU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[22U])) 
                                            << 0x0000000fU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[21U])) 
                                              >> 0x00000011U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[14U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[14U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[14U])));
    if ((0x00004000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[24U])) 
                                         << 0x0000001aU) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[23U])) 
                                           >> 6U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[15U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[15U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[15U])));
    if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][2U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[26U])) 
                                         << 0x00000025U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[25U])) 
                                            << 5U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd[24U])) 
                                              >> 0x0000001bU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail 
        = ((4U <= (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__cnt))
            ? 4U : (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__cnt)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xfffeU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[0U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[0U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xfffdU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[1U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[1U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xfffbU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[2U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[2U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xfff7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[3U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[3U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xffefU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[4U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[4U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xffdfU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[5U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[5U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xffbfU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[6U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[6U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xff7fU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[7U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[7U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xfeffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[8U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[8U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xfdffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[9U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[9U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xfbffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[10U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[10U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xf7ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[11U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[11U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xefffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[12U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[12U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xdfffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[13U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[13U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0xbfffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[14U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[14U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
        = (0x7fffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[15U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[15U] = 0U;
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[0U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[0U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[0U])));
    if ((1U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[1U])) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[0U]))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[1U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[1U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[1U])));
    if ((2U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[3U])) 
                                         << 0x0000002bU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[2U])) 
                                            << 0x0000000bU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[1U])) 
                                              >> 0x00000015U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[2U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[2U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[2U])));
    if ((4U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[4U])) 
                                         << 0x00000016U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[3U])) 
                                           >> 0x0000000aU)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[3U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[3U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[3U])));
    if ((8U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[6U])) 
                                         << 0x00000021U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[5U])) 
                                            << 1U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[4U])) 
                                              >> 0x0000001fU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[4U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[4U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[4U])));
    if ((0x00000010U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[8U])) 
                                         << 0x0000002cU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[7U])) 
                                            << 0x0000000cU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[6U])) 
                                              >> 0x00000014U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[5U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[5U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[5U])));
    if ((0x00000020U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[9U])) 
                                         << 0x00000017U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[8U])) 
                                           >> 9U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[6U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[6U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[6U])));
    if ((0x00000040U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[11U])) 
                                         << 0x00000022U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[10U])) 
                                            << 2U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[9U])) 
                                              >> 0x0000001eU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[7U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[7U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[7U])));
    if ((0x00000080U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[13U])) 
                                         << 0x0000002dU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[12U])) 
                                            << 0x0000000dU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[11U])) 
                                              >> 0x00000013U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[8U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[8U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[8U])));
    if ((0x00000100U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[14U])) 
                                         << 0x00000018U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[13U])) 
                                           >> 8U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[9U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[9U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[9U])));
    if ((0x00000200U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[16U])) 
                                         << 0x00000023U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[15U])) 
                                            << 3U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[14U])) 
                                              >> 0x0000001dU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[10U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[10U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[10U])));
    if ((0x00000400U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[18U])) 
                                         << 0x0000002eU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[17U])) 
                                            << 0x0000000eU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[16U])) 
                                              >> 0x00000012U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[11U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[11U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[11U])));
    if ((0x00000800U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[19U])) 
                                         << 0x00000019U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[18U])) 
                                           >> 7U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[12U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[12U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[12U])));
    if ((0x00001000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[21U])) 
                                         << 0x00000024U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[20U])) 
                                            << 4U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[19U])) 
                                              >> 0x0000001cU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[13U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[13U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[13U])));
    if ((0x00002000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[23U])) 
                                         << 0x0000002fU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[22U])) 
                                            << 0x0000000fU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[21U])) 
                                              >> 0x00000011U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[14U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[14U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[14U])));
    if ((0x00004000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[24U])) 
                                         << 0x0000001aU) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[23U])) 
                                           >> 6U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[15U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[15U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[15U])));
    if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][1U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[26U])) 
                                         << 0x00000025U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[25U])) 
                                            << 5U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd[24U])) 
                                              >> 0x0000001bU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail 
        = ((4U <= (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__cnt))
            ? 4U : (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__cnt)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xfffeU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[0U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[0U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xfffdU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[1U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[1U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xfffbU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[2U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[2U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xfff7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[3U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[3U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xffefU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[4U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[4U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xffdfU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[5U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[5U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xffbfU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[6U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[6U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xff7fU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[7U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[7U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xfeffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[8U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[8U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xfdffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[9U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[9U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xfbffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[10U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[10U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xf7ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[11U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[11U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xefffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[12U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[12U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xdfffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[13U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[13U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0xbfffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[14U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[14U] = 0U;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
        = (0x7fffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[15U] = 0ULL;
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[15U] = 0U;
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[0U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[0U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[0U])));
    if ((1U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[1U])) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[0U]))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[1U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[1U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[1U])));
    if ((2U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[3U])) 
                                         << 0x0000002bU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[2U])) 
                                            << 0x0000000bU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[1U])) 
                                              >> 0x00000015U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[2U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[2U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[2U])));
    if ((4U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[4U])) 
                                         << 0x00000016U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[3U])) 
                                           >> 0x0000000aU)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[3U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[3U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[3U])));
    if ((8U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[6U])) 
                                         << 0x00000021U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[5U])) 
                                            << 1U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[4U])) 
                                              >> 0x0000001fU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[4U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[4U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[4U])));
    if ((0x00000010U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[8U])) 
                                         << 0x0000002cU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[7U])) 
                                            << 0x0000000cU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[6U])) 
                                              >> 0x00000014U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[5U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[5U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[5U])));
    if ((0x00000020U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[9U])) 
                                         << 0x00000017U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[8U])) 
                                           >> 9U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[6U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[6U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[6U])));
    if ((0x00000040U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[11U])) 
                                         << 0x00000022U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[10U])) 
                                            << 2U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[9U])) 
                                              >> 0x0000001eU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[7U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[7U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[7U])));
    if ((0x00000080U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[13U])) 
                                         << 0x0000002dU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[12U])) 
                                            << 0x0000000dU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[11U])) 
                                              >> 0x00000013U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[8U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[8U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[8U])));
    if ((0x00000100U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[14U])) 
                                         << 0x00000018U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[13U])) 
                                           >> 8U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[9U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[9U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[9U])));
    if ((0x00000200U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[16U])) 
                                         << 0x00000023U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[15U])) 
                                            << 3U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[14U])) 
                                              >> 0x0000001dU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[10U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[10U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[10U])));
    if ((0x00000400U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[18U])) 
                                         << 0x0000002eU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[17U])) 
                                            << 0x0000000eU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[16U])) 
                                              >> 0x00000012U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[11U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[11U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[11U])));
    if ((0x00000800U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[19U])) 
                                         << 0x00000019U) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[18U])) 
                                           >> 7U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[12U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[12U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[12U])));
    if ((0x00001000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[21U])) 
                                         << 0x00000024U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[20U])) 
                                            << 4U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[19U])) 
                                              >> 0x0000001cU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[13U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[13U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[13U])));
    if ((0x00002000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[23U])) 
                                         << 0x0000002fU) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[22U])) 
                                            << 0x0000000fU) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[21U])) 
                                              >> 0x00000011U))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[14U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[14U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[14U])));
    if ((0x00004000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[24U])) 
                                         << 0x0000001aU) 
                                        | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[23U])) 
                                           >> 6U)));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest 
        = (0x0000007fU & ((0x00000050U <= ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                                           + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[15U]))
                           ? (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                               + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[15U]) 
                              - (IData)(0x00000050U))
                           : ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr) 
                              + vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[15U])));
    if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[4U][0U])) {
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe 
            = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest)))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (0x001fffffffffffffULL & (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[26U])) 
                                         << 0x00000025U) 
                                        | (((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[25U])) 
                                            << 5U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd[24U])) 
                                              >> 0x0000001bU))));
        vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[(0x0000000fU 
                                                                                & (IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest))] 
            = (7U & ((IData)(tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__dest) 
                     >> 4U));
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail 
        = ((4U <= (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__cnt))
            ? 4U : (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__cnt)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__0__KET__ 
        = ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                   == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                              >> 0x00000028U))))) 
               | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                               == 
                                                               (0x00001fffU 
                                                                & (IData)(
                                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                           >> 0x00000028U))))))))))))))))))))) 
           & (0U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__4__KET__ 
        = ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                   == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                              >> 0x00000028U))))) 
               | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((0U 
                                                                 < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                & ((0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                               >> 0x00000028U))) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((1U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((3U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | ((2U 
                                                                         < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                        & ((0x00001fffU 
                                                                            & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                           == 
                                                                           (0x00001fffU 
                                                                            & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))))))))))))))))))))))) 
           & (0U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__8__KET__ 
        = ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                   == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                              >> 0x00000028U))))) 
               | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((0U 
                                                                 < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                & ((0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                               >> 0x00000028U))) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((1U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((2U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((3U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((0U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                               & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                              | (((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | ((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))))))))))))))))))))))))))) 
           & (0U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__12__KET__ 
        = ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                   == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                              >> 0x00000028U))))) 
               | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((0U 
                                                                 < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                & ((0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                               >> 0x00000028U))) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((1U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((2U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((3U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((0U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                               & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                              | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | ((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))))))))))))))))))))))))))))))) 
           & (0U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__1__KET__ 
        = ((1U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | ((0U 
                                                                   < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                  & ((0x00001fffU 
                                                                      & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                     == 
                                                                     (0x00001fffU 
                                                                      & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U)))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__0__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__5__KET__ 
        = ((1U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((0U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((1U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((2U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((0U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | ((3U 
                                                                               < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                              & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U)))))))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__4__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__9__KET__ 
        = ((1U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((0U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((1U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((2U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((3U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                               & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                              | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | ((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U)))))))))))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__8__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__13__KET__ 
        = ((1U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((0U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((1U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((2U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((3U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                               & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                              | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | ((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U)))))))))))))))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__12__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__2__KET__ 
        = ((2U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((1U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | ((0U 
                                                                      < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                     & ((0x00001fffU 
                                                                         & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                        == 
                                                                        (0x00001fffU 
                                                                         & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__1__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__6__KET__ 
        = ((2U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((0U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((1U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((2U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((3U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                               & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                              | ((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))))))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__5__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__10__KET__ 
        = ((2U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((0U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((1U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((2U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((3U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                               & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                              | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | ((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))))))))))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__9__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__14__KET__ 
        = ((2U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((0U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((1U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((2U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((3U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                               & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                              | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | ((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))))))))))))))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__13__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__3__KET__ 
        = ((3U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((0U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((2U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | ((1U 
                                                                         < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                        & ((0x00001fffU 
                                                                            & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                           == 
                                                                           (0x00001fffU 
                                                                            & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U)))))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__2__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__7__KET__ 
        = ((3U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((0U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((1U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((2U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((3U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                               & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                              | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | ((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U)))))))))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__6__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__11__KET__ 
        = ((3U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
           & ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((0U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((1U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((2U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((3U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                               & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                              | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | ((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U)))))))))))))))))))))))))))))))) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__10__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__15__KET__ 
        = ((~ (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                   == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                              >> 0x00000028U))))) 
               | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                   & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                      == (0x00001fffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                 >> 0x00000028U))))) 
                  | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                      & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                         == (0x00001fffU & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                     | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                            == (0x00001fffU & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                        | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                            & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                               == (0x00001fffU & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                           | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                               & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                  == (0x00001fffU & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                              | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                  & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                     == (0x00001fffU 
                                         & (IData)(
                                                   (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                    >> 0x00000028U))))) 
                                 | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                     & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                        == (0x00001fffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                       >> 0x00000028U))))) 
                                    | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                        & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                           == (0x00001fffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                          >> 0x00000028U))))) 
                                       | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                           & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                              == (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                              & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                 == 
                                                 (0x00001fffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                             >> 0x00000028U))))) 
                                             | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                 & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                    == 
                                                    (0x00001fffU 
                                                     & (IData)(
                                                               (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                >> 0x00000028U))))) 
                                                | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v) 
                                                    & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a) 
                                                       == 
                                                       (0x00001fffU 
                                                        & (IData)(
                                                                  (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                   >> 0x00000028U))))) 
                                                   | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v) 
                                                       & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a) 
                                                          == 
                                                          (0x00001fffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                      >> 0x00000028U))))) 
                                                      | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v) 
                                                          & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a) 
                                                             == 
                                                             (0x00001fffU 
                                                              & (IData)(
                                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                         >> 0x00000028U))))) 
                                                         | (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v) 
                                                             & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a) 
                                                                == 
                                                                (0x00001fffU 
                                                                 & (IData)(
                                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                            >> 0x00000028U))))) 
                                                            | (((0U 
                                                                 < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                & ((0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                               >> 0x00000028U))) 
                                                                   == 
                                                                   (0x00001fffU 
                                                                    & (IData)(
                                                                              (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                               >> 0x00000028U))))) 
                                                               | (((1U 
                                                                    < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                   & ((0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                      == 
                                                                      (0x00001fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                  | (((2U 
                                                                       < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                      & ((0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                         == 
                                                                         (0x00001fffU 
                                                                          & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                     | (((3U 
                                                                          < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail)) 
                                                                         & ((0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                            == 
                                                                            (0x00001fffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                        | (((0U 
                                                                             < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                            & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                               == 
                                                                               (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                           | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                               & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                              | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((3U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((0U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | (((2U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent 
                                                                                >> 0x00000028U))))) 
                                                                                | ((1U 
                                                                                < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail)) 
                                                                                & ((0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent 
                                                                                >> 0x00000028U))) 
                                                                                == 
                                                                                (0x00001fffU 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent 
                                                                                >> 0x00000028U)))))))))))))))))))))))))))))))))))) 
           & ((3U < (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail)) 
              & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__14__KET__)));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nrd 
        = (7U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__0__KET__) 
                 + ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__1__KET__) 
                    + ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__3__KET__) 
                       + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__2__KET__)))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nrd 
        = (7U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__4__KET__) 
                 + ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__5__KET__) 
                    + ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__7__KET__) 
                       + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__6__KET__)))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nrd 
        = (7U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__8__KET__) 
                 + ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__9__KET__) 
                    + ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__11__KET__) 
                       + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__10__KET__)))));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nrd 
        = (7U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ok__BRA__12__KET__) 
                 + ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__13__KET__) 
                    + ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__15__KET__) 
                       + (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__iss__BRA__14__KET__)))));
}

void Vtb_ours_closed___024root___nba_comb__TOP__0(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___nba_comb__TOP__0\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[0U] = 
        ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[0U]) 
         | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[0U] 
                           + ((0x00fffc00U & ((- (IData)(
                                                         (1U 
                                                          & (IData)(
                                                                    (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                     >> 9U))))) 
                                              << 0x0000000aU)) 
                              | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[0U] = 
        ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[0U]) 
         | ((((vlSelfRef.tb_ours_closed__DOT__rdq[1U] 
               << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[0U] 
                         >> 0x00000018U)) + ((0x00fffc00U 
                                              & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                             | (0x000003ffU 
                                                & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
            << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[1U] = 
        ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[1U]) 
         | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[1U] 
                              << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[0U] 
                                        >> 0x00000018U)) 
                            + ((0x00fffc00U & ((- (IData)(
                                                          (1U 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                      >> 0x00000013U))))) 
                                               << 0x0000000aU)) 
                               | (0x000003ffU & (IData)(
                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                         >> 0x0000000aU))))) 
                           >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[1U] = 
        ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[1U]) 
         | ((((vlSelfRef.tb_ours_closed__DOT__rdq[2U] 
               << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[1U] 
                                  >> 0x00000010U)) 
             + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                          >> 0x0000001dU))))) 
                                << 0x0000000aU)) | 
                (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                        >> 0x00000014U))))) 
            << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[2U] = 
        ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[2U]) 
         | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[2U] 
                              << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[1U] 
                                                 >> 0x00000010U)) 
                            + ((0x00fffc00U & ((- (IData)(
                                                          (1U 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                      >> 0x0000001dU))))) 
                                               << 0x0000000aU)) 
                               | (0x000003ffU & (IData)(
                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                         >> 0x00000014U))))) 
                           >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[2U] = 
        ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[2U]) 
         | ((((vlSelfRef.tb_ours_closed__DOT__rdq[2U] 
               << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[2U] 
                                  >> 8U)) + ((0x00fffc00U 
                                              & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                        >> 0x00000027U))))) 
                                                 << 0x0000000aU)) 
                                             | (0x000003ffU 
                                                & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                           >> 0x0000001eU))))) 
            << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[3U] = 
        ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[3U]) 
         | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[3U] 
                           + ((0x00fffc00U & ((- (IData)(
                                                         (1U 
                                                          & (IData)(
                                                                    (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                     >> 9U))))) 
                                              << 0x0000000aU)) 
                              | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[3U] = 
        ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[3U]) 
         | ((((vlSelfRef.tb_ours_closed__DOT__rdq[4U] 
               << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[3U] 
                         >> 0x00000018U)) + ((0x00fffc00U 
                                              & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                             | (0x000003ffU 
                                                & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
            << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[4U] = 
        ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[4U]) 
         | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[4U] 
                              << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[3U] 
                                        >> 0x00000018U)) 
                            + ((0x00fffc00U & ((- (IData)(
                                                          (1U 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                      >> 0x00000013U))))) 
                                               << 0x0000000aU)) 
                               | (0x000003ffU & (IData)(
                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                         >> 0x0000000aU))))) 
                           >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[4U] = 
        ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[4U]) 
         | ((((vlSelfRef.tb_ours_closed__DOT__rdq[5U] 
               << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[4U] 
                                  >> 0x00000010U)) 
             + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                          >> 0x0000001dU))))) 
                                << 0x0000000aU)) | 
                (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                        >> 0x00000014U))))) 
            << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[5U] = 
        ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[5U]) 
         | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[5U] 
                              << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[4U] 
                                                 >> 0x00000010U)) 
                            + ((0x00fffc00U & ((- (IData)(
                                                          (1U 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                      >> 0x0000001dU))))) 
                                               << 0x0000000aU)) 
                               | (0x000003ffU & (IData)(
                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                         >> 0x00000014U))))) 
                           >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[5U] = 
        ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[5U]) 
         | ((((vlSelfRef.tb_ours_closed__DOT__rdq[5U] 
               << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[5U] 
                                  >> 8U)) + ((0x00fffc00U 
                                              & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                        >> 0x00000027U))))) 
                                                 << 0x0000000aU)) 
                                             | (0x000003ffU 
                                                & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                           >> 0x0000001eU))))) 
            << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[6U] = 
        ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[6U]) 
         | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[6U] 
                           + ((0x00fffc00U & ((- (IData)(
                                                         (1U 
                                                          & (IData)(
                                                                    (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                     >> 9U))))) 
                                              << 0x0000000aU)) 
                              | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[6U] = 
        ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[6U]) 
         | ((((vlSelfRef.tb_ours_closed__DOT__rdq[7U] 
               << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[6U] 
                         >> 0x00000018U)) + ((0x00fffc00U 
                                              & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                             | (0x000003ffU 
                                                & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
            << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[7U] = 
        ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[7U]) 
         | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[7U] 
                              << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[6U] 
                                        >> 0x00000018U)) 
                            + ((0x00fffc00U & ((- (IData)(
                                                          (1U 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                      >> 0x00000013U))))) 
                                               << 0x0000000aU)) 
                               | (0x000003ffU & (IData)(
                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                         >> 0x0000000aU))))) 
                           >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[7U] = 
        ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[7U]) 
         | ((((vlSelfRef.tb_ours_closed__DOT__rdq[8U] 
               << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[7U] 
                                  >> 0x00000010U)) 
             + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                          >> 0x0000001dU))))) 
                                << 0x0000000aU)) | 
                (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                        >> 0x00000014U))))) 
            << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[8U] = 
        ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[8U]) 
         | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[8U] 
                              << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[7U] 
                                                 >> 0x00000010U)) 
                            + ((0x00fffc00U & ((- (IData)(
                                                          (1U 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                      >> 0x0000001dU))))) 
                                               << 0x0000000aU)) 
                               | (0x000003ffU & (IData)(
                                                        (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                         >> 0x00000014U))))) 
                           >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[8U] = 
        ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[8U]) 
         | ((((vlSelfRef.tb_ours_closed__DOT__rdq[8U] 
               << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[8U] 
                                  >> 8U)) + ((0x00fffc00U 
                                              & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                        >> 0x00000027U))))) 
                                                 << 0x0000000aU)) 
                                             | (0x000003ffU 
                                                & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                           >> 0x0000001eU))))) 
            << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[9U] = 
        ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[9U]) 
         | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[9U] 
                           + ((0x00fffc00U & ((- (IData)(
                                                         (1U 
                                                          & (IData)(
                                                                    (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                     >> 9U))))) 
                                              << 0x0000000aU)) 
                              | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[9U] = 
        ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[9U]) 
         | ((((vlSelfRef.tb_ours_closed__DOT__rdq[10U] 
               << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[9U] 
                         >> 0x00000018U)) + ((0x00fffc00U 
                                              & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                             | (0x000003ffU 
                                                & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
            << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[10U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[10U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[10U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[9U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[10U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[10U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[11U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[10U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[11U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[11U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[11U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[10U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[11U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[11U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[11U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[11U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[12U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[12U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[12U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[12U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[12U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[13U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[12U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[13U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[13U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[13U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[12U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[13U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[13U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[14U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[13U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[14U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[14U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[14U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[13U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[14U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[14U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[14U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[14U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[15U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[15U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[15U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[15U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[15U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[16U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[15U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[16U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[16U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[16U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[15U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[16U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[16U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[17U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[16U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[17U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[17U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[17U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[16U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[17U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[17U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[17U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[17U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[18U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[18U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[18U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[18U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[18U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[19U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[18U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[19U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[19U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[19U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[18U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[19U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[19U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[20U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[19U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[20U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[20U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[20U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[19U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[20U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[20U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[20U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[20U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[21U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[21U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[21U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[21U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[21U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[22U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[21U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[22U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[22U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[22U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[21U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[22U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[22U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[23U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[22U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[23U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[23U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[23U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[22U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[23U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[23U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[23U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[23U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[24U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[24U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[24U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[24U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[24U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[25U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[24U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[25U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[25U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[25U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[24U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[25U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[25U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[26U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[25U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[26U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[26U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[26U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[25U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[26U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[26U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[26U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[26U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[27U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[27U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[27U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[27U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[27U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[28U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[27U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[28U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[28U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[28U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[27U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[28U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[28U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[29U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[28U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[29U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[29U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[29U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[28U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[29U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[29U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[29U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[29U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[30U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[30U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[30U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[30U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[30U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[31U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[30U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[31U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[31U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[31U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[30U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[31U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[31U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[32U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[31U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[32U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[32U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[32U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[31U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[32U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[32U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[32U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[32U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[33U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[33U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[33U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[33U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[33U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[34U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[33U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[34U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[34U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[34U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[33U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[34U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[34U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[35U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[34U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[35U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[35U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[35U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[34U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[35U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[35U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[35U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[35U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[36U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[36U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[36U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[36U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[36U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[37U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[36U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[37U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[37U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[37U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[36U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[37U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[37U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[38U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[37U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[38U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[38U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[38U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[37U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[38U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[38U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[38U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[38U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[39U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[39U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[39U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[39U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[39U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[40U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[39U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[40U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[40U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[40U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[39U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[40U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[40U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[41U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[40U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[41U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[41U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[41U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[40U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[41U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[41U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[41U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[41U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[42U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[42U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[42U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[42U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[42U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[43U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[42U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[43U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[43U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[43U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[42U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[43U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[43U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[44U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[43U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[44U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[44U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[44U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[43U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[44U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[44U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[44U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[44U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[45U] 
        = ((0xff000000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[45U]) 
           | (0x00ffffffU & (vlSelfRef.tb_ours_closed__DOT__rdq[45U] 
                             + ((0x00fffc00U & ((- (IData)(
                                                           (1U 
                                                            & (IData)(
                                                                      (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                       >> 9U))))) 
                                                << 0x0000000aU)) 
                                | (0x000003ffU & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d))))));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[45U] 
        = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[45U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[46U] 
                 << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[45U] 
                           >> 0x00000018U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                          >> 0x00000013U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                             >> 0x0000000aU))))) 
              << 0x00000018U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[46U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[46U]) 
           | (0x0000ffffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[46U] 
                                << 8U) | (vlSelfRef.tb_ours_closed__DOT__rdq[45U] 
                                          >> 0x00000018U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                        >> 0x00000013U))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                           >> 0x0000000aU))))) 
                             >> 8U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[46U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[46U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[47U] 
                 << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[46U] 
                                    >> 0x00000010U)) 
               + ((0x00fffc00U & ((- (IData)((1U & (IData)(
                                                           (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                            >> 0x0000001dU))))) 
                                  << 0x0000000aU)) 
                  | (0x000003ffU & (IData)((vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                            >> 0x00000014U))))) 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[47U] 
        = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[47U]) 
           | (0x000000ffU & ((((vlSelfRef.tb_ours_closed__DOT__rdq[47U] 
                                << 0x00000010U) | (vlSelfRef.tb_ours_closed__DOT__rdq[46U] 
                                                   >> 0x00000010U)) 
                              + ((0x00fffc00U & ((- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                        >> 0x0000001dU))))) 
                                                 << 0x0000000aU)) 
                                 | (0x000003ffU & (IData)(
                                                          (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                           >> 0x00000014U))))) 
                             >> 0x00000010U)));
    vlSelfRef.tb_ours_closed__DOT__obuf_wdata[47U] 
        = ((0x000000ffU & vlSelfRef.tb_ours_closed__DOT__obuf_wdata[47U]) 
           | ((((vlSelfRef.tb_ours_closed__DOT__rdq[47U] 
                 << 0x00000018U) | (vlSelfRef.tb_ours_closed__DOT__rdq[47U] 
                                    >> 8U)) + ((0x00fffc00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                                          >> 0x00000027U))))) 
                                                   << 0x0000000aU)) 
                                               | (0x000003ffU 
                                                  & (IData)(
                                                            (vlSelfRef.tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d 
                                                             >> 0x0000001eU))))) 
              << 8U));
}
