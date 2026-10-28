// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ours_closed.h for the primary calling header

#include "Vtb_ours_closed__pch.h"

void Vtb_ours_closed___024root___timing_ready(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___timing_ready\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h9a259c68__0.ready("@(negedge tb_ours_closed.clk)");
    }
}

void Vtb_ours_closed___024root___timing_resume(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___timing_resume\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h9a259c68__0.moveToResumeQueue(
                                                          "@(negedge tb_ours_closed.clk)");
    vlSelfRef.__VtrigSched_h9a259c68__0.resume("@(negedge tb_ours_closed.clk)");
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_ours_closed___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ours_closed___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtb_ours_closed___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

bool Vtb_ours_closed___024root___eval_phase__act(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___eval_phase__act\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        (((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                           << 3U) 
                                                          | (((IData)(vlSelfRef.tb_ours_closed__DOT__rst) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ours_closed__DOT__rst__0))) 
                                                             << 2U)) 
                                                         | ((((~ (IData)(vlSelfRef.tb_ours_closed__DOT__clk)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ours_closed__DOT__clk__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.tb_ours_closed__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ours_closed__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__tb_ours_closed__DOT__clk__0 
            = vlSelfRef.tb_ours_closed__DOT__clk;
        vlSelfRef.__Vtrigprevexpr___TOP__tb_ours_closed__DOT__rst__0 
            = vlSelfRef.tb_ours_closed__DOT__rst;
    }
    Vtb_ours_closed___024root___timing_ready(vlSelf);
    Vtb_ours_closed___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_ours_closed___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_ours_closed___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_ours_closed___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_ours_closed___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_ours_closed___024root___eval_phase__inact(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___eval_phase__inact\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/tsweep_synth/tb/tb_ours_closed.v", 22, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_ours_closed___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vtb_ours_closed___024root___nba_sequent__TOP__0(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___nba_sequent__TOP__1(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___nba_sequent__TOP__2(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___nba_sequent__TOP__3(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___nba_sequent__TOP__4(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___nba_sequent__TOP__5(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___nba_comb__TOP__0(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___nba_comb__TOP__2(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___nba_comb__TOP__3(Vtb_ours_closed___024root* vlSelf);
void Vtb_ours_closed___024root___nba_comb__TOP__4(Vtb_ours_closed___024root* vlSelf);

bool Vtb_ours_closed___024root___eval_phase__nba(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___eval_phase__nba\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_ours_closed___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb_ours_closed___024root___nba_sequent__TOP__0(vlSelf);
                Vtb_ours_closed___024root___nba_sequent__TOP__1(vlSelf);
            }
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb_ours_closed___024root___nba_sequent__TOP__2(vlSelf);
            }
            if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb_ours_closed___024root___nba_sequent__TOP__3(vlSelf);
                Vtb_ours_closed___024root___nba_sequent__TOP__4(vlSelf);
            }
            if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb_ours_closed___024root___nba_sequent__TOP__5(vlSelf);
            }
            if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb_ours_closed___024root___nba_comb__TOP__0(vlSelf);
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_comb__TOP__1
                    vlSelfRef.tb_ours_closed__DOT__nd 
                        = (vlSelfRef.tb_ours_closed__DOT__nd_w 
                           & (- (IData)(((IData)(vlSelfRef.tb_ours_closed__DOT__nd_tag) 
                                         == (IData)(vlSelfRef.tb_ours_closed__DOT__cur_tag)))));
                }
            }
            if ((7ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb_ours_closed___024root___nba_comb__TOP__2(vlSelf);
                Vtb_ours_closed___024root___nba_comb__TOP__3(vlSelf);
                Vtb_ours_closed___024root___nba_comb__TOP__4(vlSelf);
            }
        }
        Vtb_ours_closed___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_ours_closed___024root___eval(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___eval\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_ours_closed___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/tsweep_synth/tb/tb_ours_closed.v", 22, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/tsweep_synth/tb/tb_ours_closed.v", 22, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_ours_closed___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/tsweep_synth/tb/tb_ours_closed.v", 22, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_ours_closed___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_ours_closed___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_ours_closed___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vtb_ours_closed___024root____VbeforeTrig_h9a259c68__0(Vtb_ours_closed___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root____VbeforeTrig_h9a259c68__0\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((~ (IData)(vlSelfRef.tb_ours_closed__DOT__clk)) 
                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ours_closed__DOT__clk__0)) 
                                  << 1U)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ours_closed__DOT__clk__0 
        = vlSelfRef.tb_ours_closed__DOT__clk;
    if ((2ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h9a259c68__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_ours_closed___024root___eval_debug_assertions(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___eval_debug_assertions\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
