// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ours_closed.h for the primary calling header

#include "Vtb_ours_closed__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ours_closed___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_ours_closed___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vtb_ours_closed___024root___stl_sequent__TOP__0(Vtb_ours_closed___024root* vlSelf);
VL_ATTR_COLD void Vtb_ours_closed___024root___stl_sequent__TOP__1(Vtb_ours_closed___024root* vlSelf);
VL_ATTR_COLD void Vtb_ours_closed___024root___stl_sequent__TOP__2(Vtb_ours_closed___024root* vlSelf);

VL_ATTR_COLD bool Vtb_ours_closed___024root___eval_phase__stl(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___eval_phase__stl\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_ours_closed___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_ours_closed___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vtb_ours_closed___024root___stl_sequent__TOP__0(vlSelf);
                Vtb_ours_closed___024root___stl_sequent__TOP__1(vlSelf);
                Vtb_ours_closed___024root___stl_sequent__TOP__2(vlSelf);
            }
        }
    }
    return (__VstlExecute);
}

bool Vtb_ours_closed___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ours_closed___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_ours_closed___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_ours_closed.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb_ours_closed.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge tb_ours_closed.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_ours_closed___024root___ctor_var_reset(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___ctor_var_reset\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb_ours_closed__DOT__obuf_we = 0;
    VL_ZERO_RESET_W(208, vlSelf->tb_ours_closed__DOT__obuf_addr);
    VL_ZERO_RESET_W(208, vlSelf->tb_ours_closed__DOT__obuf_waddr);
    VL_ZERO_RESET_W(1536, vlSelf->tb_ours_closed__DOT__obuf_wdata);
    vlSelf->tb_ours_closed__DOT__gv = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__gm);
    VL_ZERO_RESET_W(1280, vlSelf->tb_ours_closed__DOT__glab);
    VL_ZERO_RESET_W(1120, vlSelf->tb_ours_closed__DOT__gid);
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__obuf[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__otag[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dlist[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__nd = 0;
    vlSelf->tb_ours_closed__DOT__i = 0;
    vlSelf->tb_ours_closed__DOT__ra = 0;
    vlSelf->tb_ours_closed__DOT__ntiles = 0;
    vlSelf->tb_ours_closed__DOT__nkt = 0;
    vlSelf->tb_ours_closed__DOT__npass = 0;
    vlSelf->tb_ours_closed__DOT__nslc = 0;
    vlSelf->tb_ours_closed__DOT__th = 0;
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__t_kf[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__t_kc[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__t_pc[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__k_nn[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__k_sb[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__k_pf[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__k_np[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__k_tile[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 16777216; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__p_w[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 16777216; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__p_f[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 16777216; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__p_fid[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8388608; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__slices[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__p_tile[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__p_kt[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__pk_ready[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__freed[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__ngr[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1280; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__gb_m[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1280; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__gb_l[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1280; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__gb_id[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__ln_kt[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__ln_fq[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__ln_fed[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__ln_fl[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dl_n[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dl_a[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__pend_a[__Vi0] = 0;
    }
    VL_ZERO_RESET_W(1536, vlSelf->tb_ours_closed__DOT__pend_x);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__st_cyc[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__st_q[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__slot = 0;
    vlSelf->tb_ours_closed__DOT__k = 0;
    vlSelf->tb_ours_closed__DOT__c = 0;
    vlSelf->tb_ours_closed__DOT__d = 0;
    vlSelf->tb_ours_closed__DOT__q = 0;
    vlSelf->tb_ours_closed__DOT__x = 0;
    vlSelf->tb_ours_closed__DOT__nwait = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__pe_act[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__pe_sh[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__pe_par[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__nq = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__hist_t[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__hist_n[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__need[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__hy = 0;
    vlSelf->tb_ours_closed__DOT__hk = 0;
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__spk_of[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__fo = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__vcd_file);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__row_in[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 5; ++__Vi1) {
            vlSelf->tb_ours_closed__DOT__dut__DOT__sv[__Vi0][__Vi1] = 0;
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 5; ++__Vi1) {
            vlSelf->tb_ours_closed__DOT__dut__DOT__sp[__Vi0][__Vi1] = 0;
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 5; ++__Vi1) {
            vlSelf->tb_ours_closed__DOT__dut__DOT__sb[__Vi0][__Vi1] = 0;
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 5; ++__Vi1) {
            vlSelf->tb_ours_closed__DOT__dut__DOT__sl[__Vi0][__Vi1] = 0;
        }
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__bs[__Vi0][__Vi1]);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->tb_ours_closed__DOT__dut__DOT__bt[__Vi0][__Vi1] = 0;
        }
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ok__BRA__12__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ok__BRA__8__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ok__BRA__4__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ok__BRA__0__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__15__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__14__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__13__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__11__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__10__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__9__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__7__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__6__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__5__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__3__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__2__KET__ = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__iss__BRA__1__KET__ = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__feed__BRA__1__KET____DOT__d__DOT__sk[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__feed__BRA__2__KET____DOT__d__DOT__sk[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__feed__BRA__3__KET____DOT__d__DOT__sk[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__o_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__ob_tch = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__ob_sum);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__o_lab = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__o_bits = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__o_par = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__o_v = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__dl[__Vi0] = 0;
    }
    VL_ZERO_RESET_W(848, vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__wd);
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__0__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__1__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__2__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__3__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__4__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__5__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__6__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__7__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__8__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__9__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__10__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__11__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__12__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__13__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__14__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__ent__BRA__15__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__cnt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__0__KET____DOT__fifo__overflow = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__0__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__1__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__2__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__rmw__BRA__3__KET____DOT__sb_d = 0;
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__dl[__Vi0] = 0;
    }
    VL_ZERO_RESET_W(848, vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__wd);
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__0__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__1__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__2__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__3__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__4__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__5__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__6__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__7__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__8__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__9__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__10__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__11__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__12__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__13__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__14__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__ent__BRA__15__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__cnt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__1__KET____DOT__fifo__overflow = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__0__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__1__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__2__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__rmw__BRA__3__KET____DOT__sb_d = 0;
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__dl[__Vi0] = 0;
    }
    VL_ZERO_RESET_W(848, vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__wd);
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__0__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__1__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__2__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__3__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__4__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__5__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__6__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__7__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__8__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__9__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__10__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__11__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__12__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__13__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__14__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__ent__BRA__15__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__cnt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__2__KET____DOT__fifo__overflow = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__0__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__1__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__2__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__rmw__BRA__3__KET____DOT__sb_d = 0;
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__dl[__Vi0] = 0;
    }
    VL_ZERO_RESET_W(848, vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__wd);
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__0__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__1__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__2__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__3__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__4__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__5__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__6__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__7__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__8__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__9__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__10__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__11__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__12__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__13__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__14__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__ent__BRA__15__KET____DOT__sums = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__cnt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__ids__BRA__3__KET____DOT__fifo__overflow = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__0__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__1__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__2__KET____DOT__sb_d = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__ent = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_v = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_a = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__rmw__BRA__3__KET____DOT__sb_d = 0;
    VL_ZERO_RESET_W(140, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gid);
    VL_ZERO_RESET_W(160, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gl);
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gm);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__0__KET____DOT__packer__gv = 0;
    VL_ZERO_RESET_W(140, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gid);
    VL_ZERO_RESET_W(160, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gl);
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gm);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__1__KET____DOT__packer__gv = 0;
    VL_ZERO_RESET_W(140, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gid);
    VL_ZERO_RESET_W(160, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gl);
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gm);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__2__KET____DOT__packer__gv = 0;
    VL_ZERO_RESET_W(140, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gid);
    VL_ZERO_RESET_W(160, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gl);
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gm);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__3__KET____DOT__packer__gv = 0;
    VL_ZERO_RESET_W(140, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gid);
    VL_ZERO_RESET_W(160, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gl);
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gm);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__4__KET____DOT__packer__gv = 0;
    VL_ZERO_RESET_W(140, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gid);
    VL_ZERO_RESET_W(160, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gl);
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gm);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__5__KET____DOT__packer__gv = 0;
    VL_ZERO_RESET_W(140, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gid);
    VL_ZERO_RESET_W(160, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gl);
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gm);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__6__KET____DOT__packer__gv = 0;
    VL_ZERO_RESET_W(140, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gid);
    VL_ZERO_RESET_W(160, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gl);
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gm);
    vlSelf->tb_ours_closed__DOT__dut__DOT____Vcellout__lane__BRA__7__KET____DOT__packer__gv = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__xt = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sV[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sS[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sX[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__Vt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__St = 0;
    VL_ZERO_RESET_W(96, vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__src);
    vlSelf->tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__xt = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__swap = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__swap = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__swap = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__swap = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__3__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__swap = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__swap = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__swap = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__swap = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__swap = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__f = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__swap = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__f = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__swap = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__f = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__swap = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__swap = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__f = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__swap = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__f = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__swap = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__f = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__wa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ws = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__fa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__fs = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__pa = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ps = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__swap = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f = 0;
    VL_ZERO_RESET_W(640, vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum);
    vlSelf->tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch = 0;
    VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full = 0;
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh);
    VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full = 0;
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh);
    VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full = 0;
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh);
    VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full = 0;
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh);
    VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full = 0;
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh);
    VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full = 0;
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh);
    VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full = 0;
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh);
    VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(320, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[__Vi0]);
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full = 0;
    VL_ZERO_RESET_W(80, vlSelf->tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh);
    for (int __Vi0 = 0; __Vi0 < 80; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__mem[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__wptr = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rptr = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__rank[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nwr = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__avail = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__nrd = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bdata[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__bwe = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__fifo__DOT__brow[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 80; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__mem[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__wptr = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rptr = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__rank[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nwr = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__avail = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__nrd = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bdata[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__bwe = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__fifo__DOT__brow[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 80; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__mem[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__wptr = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rptr = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__rank[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nwr = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__avail = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__nrd = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bdata[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__bwe = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__fifo__DOT__brow[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 80; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__mem[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__wptr = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rptr = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__rank[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nwr = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__avail = 0;
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__nrd = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bdata[__Vi0] = 0;
    }
    vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__bwe = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__fifo__DOT__brow[__Vi0] = 0;
    }
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_0);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_2);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_3);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_5);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_6);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_8);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_9);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_11);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_12);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_14);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_15);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_17);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_18);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_20);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_21);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_23);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_204);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_205);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_206);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_207);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_208);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_209);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_210);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_211);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_212);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_213);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_214);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_215);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_216);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_217);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_218);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_219);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_220);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_221);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_222);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_223);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_224);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_225);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_226);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_227);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_228);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_229);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_230);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_231);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_232);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_233);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_234);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_235);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_236);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_237);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_238);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_239);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_240);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_241);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_242);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_243);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_244);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_245);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_246);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_247);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_248);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_249);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_250);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_251);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_252);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_253);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_254);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_255);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_256);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_257);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_258);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_259);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_260);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_261);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_262);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_263);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_264);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_265);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_266);
    VL_ZERO_RESET_W(80, vlSelf->__VdfgRegularize_hebeb780c_0_267);
    vlSelf->__VdfgRegularize_hebeb780c_0_293 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_295 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_297 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_299 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_301 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_303 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_305 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_307 = 0;
    vlSelf->__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__3__KET____DOT__cnt = 0;
    vlSelf->__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__2__KET____DOT__cnt = 0;
    vlSelf->__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__1__KET____DOT__cnt = 0;
    vlSelf->__Vdly__tb_ours_closed__DOT__dut__DOT__ids__BRA__0__KET____DOT__cnt = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__15__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__14__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__13__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__12__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__11__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__10__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__9__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__8__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__7__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__6__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__5__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__4__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__3__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__2__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__1__KET____DOT__u__DOT__sS__v3 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sV__v0 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sV__v2 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sS__v2 = 0;
    vlSelf->__VdlySet__tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sV__v3 = 0;
    vlSelf->__VdlyVal__tb_ours_closed__DOT__dut__DOT__lif__BRA__0__KET____DOT__u__DOT__sS__v3 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_ours_closed__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ours_closed__DOT__rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
