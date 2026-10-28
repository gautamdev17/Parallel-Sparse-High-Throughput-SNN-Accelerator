// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ours_closed.h for the primary calling header

#include "Vtb_ours_closed__pch.h"

void Vtb_ours_closed___024root___ctor_var_reset(Vtb_ours_closed___024root* vlSelf);

Vtb_ours_closed___024root::Vtb_ours_closed___024root(Vtb_ours_closed__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_ours_closed___024root___ctor_var_reset(this);
}

void Vtb_ours_closed___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_ours_closed___024root::~Vtb_ours_closed___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
