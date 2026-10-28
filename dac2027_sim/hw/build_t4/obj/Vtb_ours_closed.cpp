// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_ours_closed__pch.h"

//============================================================
// Constructors

Vtb_ours_closed::Vtb_ours_closed(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_ours_closed__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_ours_closed::Vtb_ours_closed(const char* _vcname__)
    : Vtb_ours_closed(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_ours_closed::~Vtb_ours_closed() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_ours_closed___024root___eval_debug_assertions(Vtb_ours_closed___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_ours_closed___024root___eval_static(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___eval_initial(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___eval_settle(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___eval(Vtb_ours_closed___024root* vlSelf);

void Vtb_ours_closed::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_ours_closed::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_ours_closed___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_ours_closed___024root___eval_static(&(vlSymsp->TOP));
        Vtb_ours_closed___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_ours_closed___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_ours_closed___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_ours_closed::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_ours_closed::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_ours_closed::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_ours_closed___024root___eval_final(Vtb_ours_closed___024root* vlSelf);

VL_ATTR_COLD void Vtb_ours_closed::final() {
    contextp()->executingFinal(true);
    Vtb_ours_closed___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_ours_closed::hierName() const { return vlSymsp->name(); }
const char* Vtb_ours_closed::modelName() const { return "Vtb_ours_closed"; }
unsigned Vtb_ours_closed::threads() const { return 1; }
void Vtb_ours_closed::prepareClone() const { contextp()->prepareClone(); }
void Vtb_ours_closed::atClone() const {
    contextp()->threadPoolpOnClone();
}
