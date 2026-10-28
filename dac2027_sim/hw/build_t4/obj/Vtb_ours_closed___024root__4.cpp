// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ours_closed.h for the primary calling header

#include "Vtb_ours_closed__pch.h"

void Vtb_ours_closed___024root___nba_comb__TOP__3(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___nba_comb__TOP__3\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot;
    tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old;
    tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add;
    tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add = 0;
    CData/*3:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add = 0;
    CData/*3:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add = 0;
    CData/*3:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add = 0;
    CData/*3:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add;
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add = 0;
    CData/*3:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add = 0;
    CData/*3:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add = 0;
    CData/*3:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add = 0;
    CData/*3:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old = 0;
    SData/*9:0*/ tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add;
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_36;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_40;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_44;
    VlWide<3>/*95:0*/ __Vtemp_46;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_76;
    VlWide<3>/*95:0*/ __Vtemp_89;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_128;
    VlWide<3>/*95:0*/ __Vtemp_141;
    // Body
    tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[2U][0U] 
                            >> 4U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(2U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(2U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[2U][0U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[2U][0U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(2U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(2U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[2U][0U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[2U][0U] 
             >> 2U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[2U][0U] 
                            >> 6U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(3U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(3U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[2U][0U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[2U][0U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(3U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(3U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[2U][0U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[2U][0U] 
             >> 3U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__2__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][3U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][4U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][5U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][6U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][7U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][8U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][9U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][10U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][11U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][12U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][13U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][14U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][15U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][16U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][17U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][18U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U][19U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[1U][3U];
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][3U]));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                          << 2U))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                             << 2U))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                    << 2U)) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                         << 2U))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][3U] 
          & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][3U]) 
         & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][3U] 
                            >> 2U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(1U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(1U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(1U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(1U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][3U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][3U] 
             >> 1U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][3U] 
                            >> 4U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(2U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(2U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(2U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(2U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][3U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][3U] 
             >> 2U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][3U] 
                            >> 6U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(3U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(3U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][3U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(3U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(3U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][3U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][3U] 
             >> 3U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][3U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][4U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][5U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][6U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][7U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][8U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][9U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][10U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][11U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][12U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][13U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][14U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][15U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][16U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][17U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][18U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U][19U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[1U][2U];
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][2U]));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                          << 2U))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                             << 2U))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                    << 2U)) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                         << 2U))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][2U] 
          & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][2U]) 
         & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][2U] 
                            >> 2U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(1U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(1U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(1U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(1U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][2U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][2U] 
             >> 1U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][2U] 
                            >> 4U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(2U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(2U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(2U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(2U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][2U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][2U] 
             >> 2U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][2U] 
                            >> 6U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(3U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(3U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][2U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(3U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(3U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][2U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][2U] 
             >> 3U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][3U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][4U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][5U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][6U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][7U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][8U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][9U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][10U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][11U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][12U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][13U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][14U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][15U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][16U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][17U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][18U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U][19U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[1U][1U];
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][1U]));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                          << 2U))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                             << 2U))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                    << 2U)) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                         << 2U))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][1U] 
          & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][1U]) 
         & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][1U] 
                            >> 2U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(1U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(1U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(1U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(1U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][1U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][1U] 
             >> 1U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][1U] 
                            >> 4U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(2U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(2U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(2U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(2U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][1U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][1U] 
             >> 2U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][1U] 
                            >> 6U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(3U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(3U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][1U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(3U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(3U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][1U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][1U] 
             >> 3U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][3U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][4U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][5U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][6U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][7U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][8U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][9U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][10U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][11U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][12U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][13U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][14U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][15U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][16U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][17U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][18U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U][19U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[1U][0U];
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][0U]));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                          << 2U))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                             << 2U))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                    << 2U)) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                         << 2U))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][0U] 
          & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][0U]) 
         & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][0U] 
                            >> 2U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(1U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(1U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(1U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(1U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][0U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][0U] 
             >> 1U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][0U] 
                            >> 4U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(2U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(2U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(2U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(2U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][0U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][0U] 
             >> 2U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[1U][0U] 
                            >> 6U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(3U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(3U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[1U][0U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(3U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(3U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[1U][0U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[1U][0U] 
             >> 3U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__1__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][3U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][4U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][5U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][6U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][7U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][8U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][9U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][10U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][11U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][12U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][13U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][14U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][15U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][16U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][17U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][18U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U][19U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[0U][3U];
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][3U]));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                          << 2U))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                             << 2U))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                    << 2U)) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                         << 2U))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][3U] 
          & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][3U]) 
         & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][3U] 
                            >> 2U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(1U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(1U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(1U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(1U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][3U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][3U] 
             >> 1U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][3U] 
                            >> 4U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(2U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(2U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(2U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(2U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][3U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][3U] 
             >> 2U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][3U] 
                            >> 6U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(3U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(3U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][3U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(3U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(3U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][3U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][3U] 
             >> 3U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__3__KET____DOT__pe__DOT__ntch));
        }
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][3U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][4U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][5U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][6U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][7U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][8U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][9U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][10U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][11U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][12U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][13U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][14U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][15U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][16U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][17U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][18U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U][19U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[0U][2U];
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][2U]));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                          << 2U))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                             << 2U))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                    << 2U)) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                         << 2U))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][2U] 
          & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][2U]) 
         & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][2U] 
                            >> 2U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(1U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(1U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(1U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(1U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][2U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][2U] 
             >> 1U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][2U] 
                            >> 4U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(2U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(2U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(2U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(2U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][2U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][2U] 
             >> 2U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][2U] 
                            >> 6U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(3U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(3U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][2U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(3U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(3U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][2U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][2U] 
             >> 3U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__2__KET____DOT__pe__DOT__ntch));
        }
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][3U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][4U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][5U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][6U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][7U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][8U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][9U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][10U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][11U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][12U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][13U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][14U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][15U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][16U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][17U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][18U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U][19U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[0U][1U];
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][1U]));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                          << 2U))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                             << 2U))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                    << 2U)) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                         << 2U))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][1U] 
          & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][1U]) 
         & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][1U] 
                            >> 2U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(1U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(1U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(1U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(1U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][1U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][1U] 
             >> 1U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][1U] 
                            >> 4U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(2U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(2U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(2U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(2U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][1U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][1U] 
             >> 2U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][1U] 
                            >> 6U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(3U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(3U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][1U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(3U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(3U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][1U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][1U] 
             >> 3U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__1__KET____DOT__pe__DOT__ntch));
        }
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][3U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][4U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][5U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][6U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][7U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][8U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][9U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][10U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][11U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][12U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][13U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][14U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][15U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][16U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][17U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][18U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U][19U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
        = vlSelfRef.tb_ours_closed__DOT__dut__DOT__bt[0U][0U];
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][0U]));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                          << 2U))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                             << 2U))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                  << 2U)))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                    << 2U)) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                         << 2U))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][0U] 
          & vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][0U]) 
         & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfffffc00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U]) 
                   | (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xfffc00ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xfc00ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000010U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
                = ((0x00ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000018U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffffffcU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 8U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][0U] 
                            >> 2U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(1U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(1U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(1U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(1U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(1U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][0U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][0U] 
             >> 1U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xfff003ffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xf003ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000012U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
                = ((0x03ffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001aU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xfffffff0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xfffff003U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][0U] 
                            >> 4U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(2U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(2U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(2U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(2U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(2U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][0U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][0U] 
             >> 2U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
                = ((0xc00fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000014U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
                = ((0x0fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffffffc0U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xffffc00fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 4U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
                = ((0xffc00fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000cU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
    }
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot 
        = (((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__f) 
            << 2U) | (3U & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sl[0U][0U] 
                            >> 6U)));
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old 
        = ((0x027fU >= (0x000003ffU & ((IData)(0x0000000aU) 
                                       * ((IData)(3U) 
                                          + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                             << 2U)))))
            ? (0x000003ffU & (((0U == (0x0000001fU 
                                       & ((IData)(0x0000000aU) 
                                          * ((IData)(3U) 
                                             + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                << 2U)))))
                                ? 0U : (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U]
                                        [(((IData)(9U) 
                                           + (0x000003ffU 
                                              & ((IData)(0x0000000aU) 
                                                 * 
                                                 ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))) 
                                          >> 5U)] << 
                                        ((IData)(0x00000020U) 
                                         - (0x0000001fU 
                                            & ((IData)(0x0000000aU) 
                                               * ((IData)(3U) 
                                                  + 
                                                  ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                   << 2U))))))) 
                              | (vlSelfRef.tb_ours_closed__DOT__dut__DOT__bs[0U][0U]
                                 [(0x0000001fU & (((IData)(0x0000000aU) 
                                                   * 
                                                   ((IData)(3U) 
                                                    + 
                                                    ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                                     << 2U))) 
                                                  >> 5U))] 
                                 >> (0x0000001fU & 
                                     ((IData)(0x0000000aU) 
                                      * ((IData)(3U) 
                                         + ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot) 
                                            << 2U)))))))
            : 0U);
    tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add 
        = (0x000003ffU & ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__old) 
                          + ((0x00000300U & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w) 
                                                            >> 7U)))) 
                                             << 8U)) 
                             | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))));
    if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__sv[0U][0U] 
          & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__sb[0U][0U] 
             >> 3U)) & (0U != VL_EXTENDS_II(32,8, (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__w))))) {
        if ((0U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[0U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[1U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (1U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((1U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[2U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (2U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((2U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[3U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (4U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((3U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[4U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (8U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((4U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[5U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[6U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000010U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((5U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[7U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000020U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((6U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[8U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000040U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((7U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[9U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000080U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((8U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[10U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[11U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000100U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((9U == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[12U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000200U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0aU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[13U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000400U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0bU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[14U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00000800U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0cU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U] 
                = ((0x3fffffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[15U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000001eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U] 
                = ((0xffffff00U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[16U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      >> 2U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00001000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0dU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U] 
                = ((0xffff003fU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[17U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 6U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00002000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0eU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U] 
                = ((0xff003fffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[18U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x0000000eU));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00004000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
        if ((0x0fU == (IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__slot))) {
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U] 
                = ((0x003fffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__nsum[19U]) 
                   | ((IData)(tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__add) 
                      << 0x00000016U));
            vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch 
                = (0x00008000U | (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__r__BRA__0__KET____DOT__col__BRA__0__KET____DOT__pe__DOT__ntch));
        }
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_293 = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) 
                                                  & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any));
    if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act) {
        if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any) {
            if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) {
                if ((0U != (1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_2[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[0U];
                    __Vtemp_2[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[1U];
                    __Vtemp_2[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[2U];
                } else {
                    __Vtemp_2[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_2[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_2[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[2U];
                }
                if ((0U != (3U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_4[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_4[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_4[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[7U];
                } else {
                    __Vtemp_4[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[0U];
                    __Vtemp_4[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[1U];
                    __Vtemp_4[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[2U];
                }
                if ((0U != (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_6[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[0U];
                    __Vtemp_6[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[1U];
                    __Vtemp_6[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[2U];
                } else {
                    __Vtemp_6[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_6[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_6[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[7U];
                }
                if ((0U != (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[2U] = 0U;
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[2U];
                }
            } else {
                if ((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_2[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_260[0U];
                    __Vtemp_2[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_260[1U];
                    __Vtemp_2[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_260[2U];
                } else {
                    __Vtemp_2[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_2[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_2[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[2U];
                }
                if ((2U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_4[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_261[0U];
                    __Vtemp_4[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_261[1U];
                    __Vtemp_4[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_261[2U];
                } else {
                    __Vtemp_4[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[0U];
                    __Vtemp_4[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[1U];
                    __Vtemp_4[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[2U];
                }
                if ((4U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_6[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_262[0U];
                    __Vtemp_6[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_262[1U];
                    __Vtemp_6[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_262[2U];
                } else {
                    __Vtemp_6[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_6[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_6[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[7U];
                }
                if ((8U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_263[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_263[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_263[2U];
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_267[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[2U];
                }
            }
        } else if ((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[9U] 
                    >> 0x0000001fU)) {
            __Vtemp_2[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[0U];
            __Vtemp_2[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[1U];
            __Vtemp_2[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[2U];
            __Vtemp_4[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[5U];
            __Vtemp_4[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[6U];
            __Vtemp_4[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[7U];
            __Vtemp_6[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[0U];
            __Vtemp_6[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[1U];
            __Vtemp_6[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[2U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_267[2U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
        } else {
            if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[2U])) {
                __Vtemp_2[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[0U];
                __Vtemp_2[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[1U];
                __Vtemp_2[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[2U];
            } else {
                __Vtemp_2[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_2[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_2[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[4U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[2U] 
                                               >> 0x0000000fU)))) {
                __Vtemp_4[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_4[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_4[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_4[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[0U];
                __Vtemp_4[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[1U];
                __Vtemp_4[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[2U];
            }
            if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[4U] 
                  >> 0x0000001fU) & (~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[7U] 
                                        >> 0x0000000fU)))) {
                __Vtemp_6[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_6[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_6[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_6[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[5U];
                __Vtemp_6[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[6U];
                __Vtemp_6[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[7U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[9U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[7U] 
                                               >> 0x0000000fU)))) {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_267[2U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_267[2U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[2U];
            }
        }
    } else {
        __Vtemp_2[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[0U];
        __Vtemp_2[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[1U];
        __Vtemp_2[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[2U];
        __Vtemp_4[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[0U];
        __Vtemp_4[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[1U];
        __Vtemp_4[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_21[2U];
        __Vtemp_6[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[5U];
        __Vtemp_6[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[6U];
        __Vtemp_6[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[7U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[0U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[1U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_267[2U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_23[2U];
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_264[0U] 
        = __Vtemp_2[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_264[1U] 
        = __Vtemp_2[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_264[2U] 
        = (0x0000ffffU & __Vtemp_2[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_265[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_265[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_265[2U] 
        = (0x0000ffffU & __Vtemp_4[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_266[0U] 
        = __Vtemp_6[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_266[1U] 
        = __Vtemp_6[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_266[2U] 
        = (0x0000ffffU & __Vtemp_6[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_295 = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) 
                                                  & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any));
    if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act) {
        if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any) {
            if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) {
                if ((0U != (1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_8[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[0U];
                    __Vtemp_8[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[1U];
                    __Vtemp_8[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[2U];
                } else {
                    __Vtemp_8[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_8[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_8[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[2U];
                }
                if ((0U != (3U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_10[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_10[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_10[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[7U];
                } else {
                    __Vtemp_10[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[0U];
                    __Vtemp_10[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[1U];
                    __Vtemp_10[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[2U];
                }
                if ((0U != (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_12[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[0U];
                    __Vtemp_12[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[1U];
                    __Vtemp_12[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[2U];
                } else {
                    __Vtemp_12[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_12[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_12[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[7U];
                }
                if ((0U != (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[2U] = 0U;
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[2U];
                }
            } else {
                if ((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_8[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_252[0U];
                    __Vtemp_8[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_252[1U];
                    __Vtemp_8[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_252[2U];
                } else {
                    __Vtemp_8[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_8[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_8[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[2U];
                }
                if ((2U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_10[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_253[0U];
                    __Vtemp_10[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_253[1U];
                    __Vtemp_10[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_253[2U];
                } else {
                    __Vtemp_10[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[0U];
                    __Vtemp_10[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[1U];
                    __Vtemp_10[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[2U];
                }
                if ((4U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_12[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_254[0U];
                    __Vtemp_12[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_254[1U];
                    __Vtemp_12[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_254[2U];
                } else {
                    __Vtemp_12[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_12[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_12[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[7U];
                }
                if ((8U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_255[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_255[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_255[2U];
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_259[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[2U];
                }
            }
        } else if ((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[9U] 
                    >> 0x0000001fU)) {
            __Vtemp_8[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[0U];
            __Vtemp_8[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[1U];
            __Vtemp_8[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[2U];
            __Vtemp_10[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[5U];
            __Vtemp_10[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[6U];
            __Vtemp_10[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[7U];
            __Vtemp_12[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[0U];
            __Vtemp_12[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[1U];
            __Vtemp_12[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[2U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_259[2U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
        } else {
            if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[2U])) {
                __Vtemp_8[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[0U];
                __Vtemp_8[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[1U];
                __Vtemp_8[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[2U];
            } else {
                __Vtemp_8[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_8[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_8[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[4U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[2U] 
                                               >> 0x0000000fU)))) {
                __Vtemp_10[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_10[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_10[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_10[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[0U];
                __Vtemp_10[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[1U];
                __Vtemp_10[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[2U];
            }
            if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[4U] 
                  >> 0x0000001fU) & (~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[7U] 
                                        >> 0x0000000fU)))) {
                __Vtemp_12[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_12[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_12[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_12[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[5U];
                __Vtemp_12[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[6U];
                __Vtemp_12[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[7U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[9U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[7U] 
                                               >> 0x0000000fU)))) {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_259[2U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_259[2U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[2U];
            }
        }
    } else {
        __Vtemp_8[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[0U];
        __Vtemp_8[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[1U];
        __Vtemp_8[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[2U];
        __Vtemp_10[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[0U];
        __Vtemp_10[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[1U];
        __Vtemp_10[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_18[2U];
        __Vtemp_12[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[5U];
        __Vtemp_12[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[6U];
        __Vtemp_12[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[7U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[0U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[1U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_259[2U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_20[2U];
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_256[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_256[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_256[2U] 
        = (0x0000ffffU & __Vtemp_8[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_257[0U] 
        = __Vtemp_10[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_257[1U] 
        = __Vtemp_10[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_257[2U] 
        = (0x0000ffffU & __Vtemp_10[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_258[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_258[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_258[2U] 
        = (0x0000ffffU & __Vtemp_12[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_297 = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) 
                                                  & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any));
    if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act) {
        if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any) {
            if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) {
                if ((0U != (1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_14[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[0U];
                    __Vtemp_14[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[1U];
                    __Vtemp_14[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[2U];
                } else {
                    __Vtemp_14[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_14[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_14[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[2U];
                }
                if ((0U != (3U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_16[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_16[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_16[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[7U];
                } else {
                    __Vtemp_16[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[0U];
                    __Vtemp_16[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[1U];
                    __Vtemp_16[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[2U];
                }
                if ((0U != (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_18[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[0U];
                    __Vtemp_18[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[1U];
                    __Vtemp_18[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[2U];
                } else {
                    __Vtemp_18[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_18[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_18[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[7U];
                }
                if ((0U != (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[2U] = 0U;
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[2U];
                }
            } else {
                if ((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_14[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_244[0U];
                    __Vtemp_14[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_244[1U];
                    __Vtemp_14[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_244[2U];
                } else {
                    __Vtemp_14[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_14[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_14[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[2U];
                }
                if ((2U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_16[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_245[0U];
                    __Vtemp_16[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_245[1U];
                    __Vtemp_16[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_245[2U];
                } else {
                    __Vtemp_16[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[0U];
                    __Vtemp_16[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[1U];
                    __Vtemp_16[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[2U];
                }
                if ((4U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_18[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_246[0U];
                    __Vtemp_18[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_246[1U];
                    __Vtemp_18[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_246[2U];
                } else {
                    __Vtemp_18[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_18[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_18[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[7U];
                }
                if ((8U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_247[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_247[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_247[2U];
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_251[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[2U];
                }
            }
        } else if ((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[9U] 
                    >> 0x0000001fU)) {
            __Vtemp_14[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[0U];
            __Vtemp_14[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[1U];
            __Vtemp_14[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[2U];
            __Vtemp_16[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[5U];
            __Vtemp_16[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[6U];
            __Vtemp_16[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[7U];
            __Vtemp_18[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[0U];
            __Vtemp_18[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[1U];
            __Vtemp_18[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[2U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_251[2U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
        } else {
            if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[2U])) {
                __Vtemp_14[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[0U];
                __Vtemp_14[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[1U];
                __Vtemp_14[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[2U];
            } else {
                __Vtemp_14[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_14[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_14[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[4U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[2U] 
                                               >> 0x0000000fU)))) {
                __Vtemp_16[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_16[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_16[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_16[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[0U];
                __Vtemp_16[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[1U];
                __Vtemp_16[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[2U];
            }
            if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[4U] 
                  >> 0x0000001fU) & (~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[7U] 
                                        >> 0x0000000fU)))) {
                __Vtemp_18[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_18[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_18[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_18[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[5U];
                __Vtemp_18[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[6U];
                __Vtemp_18[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[7U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[9U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[7U] 
                                               >> 0x0000000fU)))) {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_251[2U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_251[2U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[2U];
            }
        }
    } else {
        __Vtemp_14[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[0U];
        __Vtemp_14[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[1U];
        __Vtemp_14[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[2U];
        __Vtemp_16[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[0U];
        __Vtemp_16[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[1U];
        __Vtemp_16[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_15[2U];
        __Vtemp_18[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[5U];
        __Vtemp_18[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[6U];
        __Vtemp_18[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[7U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[0U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[1U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_251[2U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_17[2U];
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_248[0U] 
        = __Vtemp_14[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_248[1U] 
        = __Vtemp_14[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_248[2U] 
        = (0x0000ffffU & __Vtemp_14[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_249[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_249[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_249[2U] 
        = (0x0000ffffU & __Vtemp_16[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_250[0U] 
        = __Vtemp_18[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_250[1U] 
        = __Vtemp_18[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_250[2U] 
        = (0x0000ffffU & __Vtemp_18[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_299 = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) 
                                                  & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any));
    if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act) {
        if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any) {
            if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) {
                if ((0U != (1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_20[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[0U];
                    __Vtemp_20[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[1U];
                    __Vtemp_20[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[2U];
                } else {
                    __Vtemp_20[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_20[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_20[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[2U];
                }
                if ((0U != (3U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_22[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_22[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_22[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[7U];
                } else {
                    __Vtemp_22[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[0U];
                    __Vtemp_22[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[1U];
                    __Vtemp_22[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[2U];
                }
                if ((0U != (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_24[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[0U];
                    __Vtemp_24[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[1U];
                    __Vtemp_24[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[2U];
                } else {
                    __Vtemp_24[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_24[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_24[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[7U];
                }
                if ((0U != (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[2U] = 0U;
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[2U];
                }
            } else {
                if ((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_20[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_236[0U];
                    __Vtemp_20[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_236[1U];
                    __Vtemp_20[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_236[2U];
                } else {
                    __Vtemp_20[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_20[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_20[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[2U];
                }
                if ((2U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_22[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_237[0U];
                    __Vtemp_22[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_237[1U];
                    __Vtemp_22[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_237[2U];
                } else {
                    __Vtemp_22[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[0U];
                    __Vtemp_22[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[1U];
                    __Vtemp_22[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[2U];
                }
                if ((4U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_24[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_238[0U];
                    __Vtemp_24[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_238[1U];
                    __Vtemp_24[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_238[2U];
                } else {
                    __Vtemp_24[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_24[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_24[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[7U];
                }
                if ((8U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_239[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_239[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_239[2U];
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_243[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[2U];
                }
            }
        } else if ((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[9U] 
                    >> 0x0000001fU)) {
            __Vtemp_20[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[0U];
            __Vtemp_20[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[1U];
            __Vtemp_20[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[2U];
            __Vtemp_22[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[5U];
            __Vtemp_22[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[6U];
            __Vtemp_22[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[7U];
            __Vtemp_24[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[0U];
            __Vtemp_24[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[1U];
            __Vtemp_24[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[2U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_243[2U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
        } else {
            if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[2U])) {
                __Vtemp_20[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[0U];
                __Vtemp_20[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[1U];
                __Vtemp_20[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[2U];
            } else {
                __Vtemp_20[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_20[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_20[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[4U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[2U] 
                                               >> 0x0000000fU)))) {
                __Vtemp_22[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_22[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_22[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_22[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[0U];
                __Vtemp_22[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[1U];
                __Vtemp_22[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[2U];
            }
            if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[4U] 
                  >> 0x0000001fU) & (~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[7U] 
                                        >> 0x0000000fU)))) {
                __Vtemp_24[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_24[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_24[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_24[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[5U];
                __Vtemp_24[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[6U];
                __Vtemp_24[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[7U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[9U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[7U] 
                                               >> 0x0000000fU)))) {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_243[2U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_243[2U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[2U];
            }
        }
    } else {
        __Vtemp_20[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[0U];
        __Vtemp_20[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[1U];
        __Vtemp_20[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[2U];
        __Vtemp_22[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[0U];
        __Vtemp_22[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[1U];
        __Vtemp_22[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_12[2U];
        __Vtemp_24[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[5U];
        __Vtemp_24[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[6U];
        __Vtemp_24[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[7U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[0U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[1U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_243[2U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_14[2U];
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_240[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_240[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_240[2U] 
        = (0x0000ffffU & __Vtemp_20[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_241[0U] 
        = __Vtemp_22[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_241[1U] 
        = __Vtemp_22[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_241[2U] 
        = (0x0000ffffU & __Vtemp_22[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_242[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_242[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_242[2U] 
        = (0x0000ffffU & __Vtemp_24[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_301 = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) 
                                                  & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any));
    if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act) {
        if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any) {
            if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) {
                if ((0U != (1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_26[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[0U];
                    __Vtemp_26[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[1U];
                    __Vtemp_26[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[2U];
                } else {
                    __Vtemp_26[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_26[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_26[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[2U];
                }
                if ((0U != (3U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_28[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_28[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_28[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[7U];
                } else {
                    __Vtemp_28[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[0U];
                    __Vtemp_28[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[1U];
                    __Vtemp_28[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[2U];
                }
                if ((0U != (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_30[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[0U];
                    __Vtemp_30[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[1U];
                    __Vtemp_30[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[2U];
                } else {
                    __Vtemp_30[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_30[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_30[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[7U];
                }
                if ((0U != (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[2U] = 0U;
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[2U];
                }
            } else {
                if ((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_26[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_228[0U];
                    __Vtemp_26[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_228[1U];
                    __Vtemp_26[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_228[2U];
                } else {
                    __Vtemp_26[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_26[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_26[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[2U];
                }
                if ((2U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_28[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_229[0U];
                    __Vtemp_28[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_229[1U];
                    __Vtemp_28[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_229[2U];
                } else {
                    __Vtemp_28[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[0U];
                    __Vtemp_28[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[1U];
                    __Vtemp_28[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[2U];
                }
                if ((4U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_30[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_230[0U];
                    __Vtemp_30[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_230[1U];
                    __Vtemp_30[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_230[2U];
                } else {
                    __Vtemp_30[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_30[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_30[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[7U];
                }
                if ((8U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_231[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_231[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_231[2U];
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_235[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[2U];
                }
            }
        } else if ((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[9U] 
                    >> 0x0000001fU)) {
            __Vtemp_26[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[0U];
            __Vtemp_26[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[1U];
            __Vtemp_26[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[2U];
            __Vtemp_28[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[5U];
            __Vtemp_28[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[6U];
            __Vtemp_28[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[7U];
            __Vtemp_30[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[0U];
            __Vtemp_30[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[1U];
            __Vtemp_30[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[2U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_235[2U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
        } else {
            if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[2U])) {
                __Vtemp_26[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[0U];
                __Vtemp_26[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[1U];
                __Vtemp_26[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[2U];
            } else {
                __Vtemp_26[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_26[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_26[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[4U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[2U] 
                                               >> 0x0000000fU)))) {
                __Vtemp_28[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_28[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_28[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_28[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[0U];
                __Vtemp_28[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[1U];
                __Vtemp_28[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[2U];
            }
            if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[4U] 
                  >> 0x0000001fU) & (~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[7U] 
                                        >> 0x0000000fU)))) {
                __Vtemp_30[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_30[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_30[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_30[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[5U];
                __Vtemp_30[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[6U];
                __Vtemp_30[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[7U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[9U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[7U] 
                                               >> 0x0000000fU)))) {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_235[2U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_235[2U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[2U];
            }
        }
    } else {
        __Vtemp_26[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[0U];
        __Vtemp_26[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[1U];
        __Vtemp_26[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[2U];
        __Vtemp_28[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[0U];
        __Vtemp_28[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[1U];
        __Vtemp_28[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_9[2U];
        __Vtemp_30[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[5U];
        __Vtemp_30[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[6U];
        __Vtemp_30[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[7U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[0U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[1U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_235[2U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_11[2U];
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_232[0U] 
        = __Vtemp_26[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_232[1U] 
        = __Vtemp_26[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_232[2U] 
        = (0x0000ffffU & __Vtemp_26[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_233[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_233[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_233[2U] 
        = (0x0000ffffU & __Vtemp_28[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_234[0U] 
        = __Vtemp_30[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_234[1U] 
        = __Vtemp_30[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_234[2U] 
        = (0x0000ffffU & __Vtemp_30[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_303 = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) 
                                                  & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any));
    if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act) {
        if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any) {
            if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) {
                if ((0U != (1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_32[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[0U];
                    __Vtemp_32[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[1U];
                    __Vtemp_32[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[2U];
                } else {
                    __Vtemp_32[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_32[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_32[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[2U];
                }
                if ((0U != (3U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_34[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_34[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_34[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[7U];
                } else {
                    __Vtemp_34[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[0U];
                    __Vtemp_34[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[1U];
                    __Vtemp_34[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[2U];
                }
                if ((0U != (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_36[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[0U];
                    __Vtemp_36[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[1U];
                    __Vtemp_36[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[2U];
                } else {
                    __Vtemp_36[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_36[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_36[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[7U];
                }
                if ((0U != (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[2U] = 0U;
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[2U];
                }
            } else {
                if ((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_32[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_220[0U];
                    __Vtemp_32[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_220[1U];
                    __Vtemp_32[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_220[2U];
                } else {
                    __Vtemp_32[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_32[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_32[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[2U];
                }
                if ((2U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_34[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_221[0U];
                    __Vtemp_34[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_221[1U];
                    __Vtemp_34[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_221[2U];
                } else {
                    __Vtemp_34[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[0U];
                    __Vtemp_34[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[1U];
                    __Vtemp_34[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[2U];
                }
                if ((4U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_36[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_222[0U];
                    __Vtemp_36[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_222[1U];
                    __Vtemp_36[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_222[2U];
                } else {
                    __Vtemp_36[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_36[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_36[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[7U];
                }
                if ((8U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_223[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_223[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_223[2U];
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_227[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[2U];
                }
            }
        } else if ((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[9U] 
                    >> 0x0000001fU)) {
            __Vtemp_32[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[0U];
            __Vtemp_32[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[1U];
            __Vtemp_32[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[2U];
            __Vtemp_34[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[5U];
            __Vtemp_34[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[6U];
            __Vtemp_34[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[7U];
            __Vtemp_36[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[0U];
            __Vtemp_36[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[1U];
            __Vtemp_36[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[2U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_227[2U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
        } else {
            if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[2U])) {
                __Vtemp_32[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[0U];
                __Vtemp_32[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[1U];
                __Vtemp_32[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[2U];
            } else {
                __Vtemp_32[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_32[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_32[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[4U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[2U] 
                                               >> 0x0000000fU)))) {
                __Vtemp_34[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_34[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_34[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_34[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[0U];
                __Vtemp_34[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[1U];
                __Vtemp_34[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[2U];
            }
            if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[4U] 
                  >> 0x0000001fU) & (~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[7U] 
                                        >> 0x0000000fU)))) {
                __Vtemp_36[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_36[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_36[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_36[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[5U];
                __Vtemp_36[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[6U];
                __Vtemp_36[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[7U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[9U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[7U] 
                                               >> 0x0000000fU)))) {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_227[2U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_227[2U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[2U];
            }
        }
    } else {
        __Vtemp_32[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[0U];
        __Vtemp_32[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[1U];
        __Vtemp_32[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[2U];
        __Vtemp_34[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[0U];
        __Vtemp_34[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[1U];
        __Vtemp_34[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_6[2U];
        __Vtemp_36[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[5U];
        __Vtemp_36[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[6U];
        __Vtemp_36[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[7U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[0U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[1U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_227[2U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_8[2U];
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_224[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_224[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_224[2U] 
        = (0x0000ffffU & __Vtemp_32[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_225[0U] 
        = __Vtemp_34[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_225[1U] 
        = __Vtemp_34[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_225[2U] 
        = (0x0000ffffU & __Vtemp_34[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_226[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_226[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_226[2U] 
        = (0x0000ffffU & __Vtemp_36[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_305 = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) 
                                                  & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any));
    if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act) {
        if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any) {
            if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) {
                if ((0U != (1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_38[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[0U];
                    __Vtemp_38[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[1U];
                    __Vtemp_38[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[2U];
                } else {
                    __Vtemp_38[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_38[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_38[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[2U];
                }
                if ((0U != (3U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_40[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_40[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_40[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[7U];
                } else {
                    __Vtemp_40[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[0U];
                    __Vtemp_40[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[1U];
                    __Vtemp_40[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[2U];
                }
                if ((0U != (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_42[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[0U];
                    __Vtemp_42[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[1U];
                    __Vtemp_42[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[2U];
                } else {
                    __Vtemp_42[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_42[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_42[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[7U];
                }
                if ((0U != (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[2U] = 0U;
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[2U];
                }
            } else {
                if ((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_38[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_212[0U];
                    __Vtemp_38[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_212[1U];
                    __Vtemp_38[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_212[2U];
                } else {
                    __Vtemp_38[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_38[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_38[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[2U];
                }
                if ((2U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_40[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_213[0U];
                    __Vtemp_40[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_213[1U];
                    __Vtemp_40[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_213[2U];
                } else {
                    __Vtemp_40[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[0U];
                    __Vtemp_40[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[1U];
                    __Vtemp_40[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[2U];
                }
                if ((4U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_42[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_214[0U];
                    __Vtemp_42[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_214[1U];
                    __Vtemp_42[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_214[2U];
                } else {
                    __Vtemp_42[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_42[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_42[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[7U];
                }
                if ((8U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_215[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_215[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_215[2U];
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_219[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[2U];
                }
            }
        } else if ((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[9U] 
                    >> 0x0000001fU)) {
            __Vtemp_38[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[0U];
            __Vtemp_38[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[1U];
            __Vtemp_38[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[2U];
            __Vtemp_40[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[5U];
            __Vtemp_40[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[6U];
            __Vtemp_40[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[7U];
            __Vtemp_42[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[0U];
            __Vtemp_42[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[1U];
            __Vtemp_42[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[2U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_219[2U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
        } else {
            if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[2U])) {
                __Vtemp_38[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[0U];
                __Vtemp_38[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[1U];
                __Vtemp_38[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[2U];
            } else {
                __Vtemp_38[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_38[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_38[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[4U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[2U] 
                                               >> 0x0000000fU)))) {
                __Vtemp_40[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_40[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_40[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_40[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[0U];
                __Vtemp_40[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[1U];
                __Vtemp_40[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[2U];
            }
            if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[4U] 
                  >> 0x0000001fU) & (~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[7U] 
                                        >> 0x0000000fU)))) {
                __Vtemp_42[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_42[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_42[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_42[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[5U];
                __Vtemp_42[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[6U];
                __Vtemp_42[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[7U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[9U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[7U] 
                                               >> 0x0000000fU)))) {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_219[2U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_219[2U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[2U];
            }
        }
    } else {
        __Vtemp_38[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[0U];
        __Vtemp_38[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[1U];
        __Vtemp_38[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[2U];
        __Vtemp_40[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[0U];
        __Vtemp_40[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[1U];
        __Vtemp_40[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_3[2U];
        __Vtemp_42[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[5U];
        __Vtemp_42[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[6U];
        __Vtemp_42[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[7U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[0U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[1U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_219[2U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_5[2U];
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_216[0U] 
        = __Vtemp_38[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_216[1U] 
        = __Vtemp_38[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_216[2U] 
        = (0x0000ffffU & __Vtemp_38[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_217[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_217[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_217[2U] 
        = (0x0000ffffU & __Vtemp_40[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_218[0U] 
        = __Vtemp_42[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_218[1U] 
        = __Vtemp_42[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_218[2U] 
        = (0x0000ffffU & __Vtemp_42[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_307 = ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) 
                                                  & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any));
    if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__act) {
        if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__any) {
            if (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__full) {
                if ((0U != (1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_44[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[0U];
                    __Vtemp_44[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[1U];
                    __Vtemp_44[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[2U];
                } else {
                    __Vtemp_44[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_44[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_44[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[2U];
                }
                if ((0U != (3U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_46[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_46[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_46[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[7U];
                } else {
                    __Vtemp_46[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[0U];
                    __Vtemp_46[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[1U];
                    __Vtemp_46[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[2U];
                }
                if ((0U != (7U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) {
                    __Vtemp_48[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[0U];
                    __Vtemp_48[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[1U];
                    __Vtemp_48[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[2U];
                } else {
                    __Vtemp_48[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_48[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_48[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[7U];
                }
                if ((0U != (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U] = 0U;
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[2U] = 0U;
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[2U];
                }
            } else {
                if ((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_44[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_204[0U];
                    __Vtemp_44[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_204[1U];
                    __Vtemp_44[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_204[2U];
                } else {
                    __Vtemp_44[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[0U];
                    __Vtemp_44[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[1U];
                    __Vtemp_44[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[2U];
                }
                if ((2U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_46[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_205[0U];
                    __Vtemp_46[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_205[1U];
                    __Vtemp_46[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_205[2U];
                } else {
                    __Vtemp_46[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[0U];
                    __Vtemp_46[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[1U];
                    __Vtemp_46[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[2U];
                }
                if ((4U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    __Vtemp_48[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_206[0U];
                    __Vtemp_48[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_206[1U];
                    __Vtemp_48[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_206[2U];
                } else {
                    __Vtemp_48[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[5U];
                    __Vtemp_48[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[6U];
                    __Vtemp_48[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[7U];
                }
                if ((8U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel))) {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_207[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_207[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_207[2U];
                } else {
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[0U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[1U];
                    vlSelfRef.__VdfgRegularize_hebeb780c_0_211[2U] 
                        = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[2U];
                }
            }
        } else if ((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[9U] 
                    >> 0x0000001fU)) {
            __Vtemp_44[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[0U];
            __Vtemp_44[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[1U];
            __Vtemp_44[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[2U];
            __Vtemp_46[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[5U];
            __Vtemp_46[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[6U];
            __Vtemp_46[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[7U];
            __Vtemp_48[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[0U];
            __Vtemp_48[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[1U];
            __Vtemp_48[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[2U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
            vlSelfRef.__VdfgRegularize_hebeb780c_0_211[2U] 
                = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
        } else {
            if ((0x00008000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[2U])) {
                __Vtemp_44[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[0U];
                __Vtemp_44[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[1U];
                __Vtemp_44[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[2U];
            } else {
                __Vtemp_44[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_44[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_44[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[4U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[2U] 
                                               >> 0x0000000fU)))) {
                __Vtemp_46[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_46[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_46[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_46[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[0U];
                __Vtemp_46[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[1U];
                __Vtemp_46[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[2U];
            }
            if (((vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[4U] 
                  >> 0x0000001fU) & (~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[7U] 
                                        >> 0x0000000fU)))) {
                __Vtemp_48[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                __Vtemp_48[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                __Vtemp_48[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                __Vtemp_48[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[5U];
                __Vtemp_48[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[6U];
                __Vtemp_48[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[7U];
            }
            if ((1U & ((~ (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[9U] 
                           >> 0x0000001fU)) & (vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[7U] 
                                               >> 0x0000000fU)))) {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_211[2U] 
                    = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__fresh[2U];
            } else {
                vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[0U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[1U];
                vlSelfRef.__VdfgRegularize_hebeb780c_0_211[2U] 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[2U];
            }
        }
    } else {
        __Vtemp_44[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[0U];
        __Vtemp_44[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[1U];
        __Vtemp_44[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[2U];
        __Vtemp_46[0U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[0U];
        __Vtemp_46[1U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[1U];
        __Vtemp_46[2U] = vlSelfRef.__VdfgRegularize_hebeb780c_0_0[2U];
        __Vtemp_48[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[5U];
        __Vtemp_48[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[6U];
        __Vtemp_48[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[7U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[0U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[1U];
        vlSelfRef.__VdfgRegularize_hebeb780c_0_211[2U] 
            = vlSelfRef.__VdfgRegularize_hebeb780c_0_2[2U];
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_208[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_208[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_208[2U] 
        = (0x0000ffffU & __Vtemp_44[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_209[0U] 
        = __Vtemp_46[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_209[1U] 
        = __Vtemp_46[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_209[2U] 
        = (0x0000ffffU & __Vtemp_46[2U]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_210[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_210[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__VdfgRegularize_hebeb780c_0_210[2U] 
        = (0x0000ffffU & __Vtemp_48[2U]);
    if (vlSelfRef.__VdfgRegularize_hebeb780c_0_293) {
        __Vtemp_50[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_260[0U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_261[0U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_262[0U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_263[0U]))));
        __Vtemp_50[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_260[1U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_261[1U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_262[1U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_263[1U]))));
        __Vtemp_50[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_260[2U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_261[2U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_262[2U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_263[2U]))));
    } else {
        __Vtemp_50[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[0U];
        __Vtemp_50[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[1U];
        __Vtemp_50[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_50[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_50[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_50[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_264[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_264[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[1U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_264[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[2U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_265[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[2U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_265[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[2U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_265[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[3U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_266[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[3U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_266[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[3U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_266[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[4U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[4U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[4U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_267[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_264[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_264[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][2U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_264[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][2U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_265[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][3U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_265[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_265[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][4U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_265[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_265[2U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][5U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_266[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][6U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_266[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][7U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_266[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][7U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][8U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_267[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__chain[1U][9U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_267[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_267[2U] 
                               << 0x00000010U));
    if (vlSelfRef.__VdfgRegularize_hebeb780c_0_295) {
        __Vtemp_63[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_252[0U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_253[0U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_254[0U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_255[0U]))));
        __Vtemp_63[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_252[1U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_253[1U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_254[1U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_255[1U]))));
        __Vtemp_63[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_252[2U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_253[2U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_254[2U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_255[2U]))));
    } else {
        __Vtemp_63[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[0U];
        __Vtemp_63[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[1U];
        __Vtemp_63[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_63[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_63[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_63[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_256[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_256[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[1U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_256[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[2U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_257[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[2U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_257[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[2U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_257[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[3U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_258[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[3U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_258[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[3U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_258[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[4U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[4U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[4U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_259[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_256[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_256[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][2U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_256[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][2U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_257[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][3U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_257[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_257[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][4U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_257[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_257[2U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][5U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_258[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][6U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_258[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][7U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_258[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][7U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][8U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_259[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__chain[1U][9U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_259[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_259[2U] 
                               << 0x00000010U));
    if (vlSelfRef.__VdfgRegularize_hebeb780c_0_297) {
        __Vtemp_76[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_244[0U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_245[0U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_246[0U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_247[0U]))));
        __Vtemp_76[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_244[1U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_245[1U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_246[1U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_247[1U]))));
        __Vtemp_76[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_244[2U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_245[2U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_246[2U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_247[2U]))));
    } else {
        __Vtemp_76[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[0U];
        __Vtemp_76[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[1U];
        __Vtemp_76[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_76[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_248[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_248[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[1U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_248[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[2U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_249[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[2U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_249[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[2U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_249[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[3U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_250[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[3U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_250[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[3U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_250[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[4U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[4U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[4U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_251[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_248[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_248[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][2U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_248[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][2U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_249[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][3U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_249[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_249[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][4U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_249[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_249[2U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][5U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_250[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][6U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_250[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][7U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_250[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][7U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][8U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_251[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__chain[1U][9U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_251[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_251[2U] 
                               << 0x00000010U));
    if (vlSelfRef.__VdfgRegularize_hebeb780c_0_299) {
        __Vtemp_89[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_236[0U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_237[0U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_238[0U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_239[0U]))));
        __Vtemp_89[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_236[1U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_237[1U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_238[1U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_239[1U]))));
        __Vtemp_89[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_236[2U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_237[2U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_238[2U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_239[2U]))));
    } else {
        __Vtemp_89[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[0U];
        __Vtemp_89[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[1U];
        __Vtemp_89[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_89[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_89[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_89[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_240[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_240[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[1U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_240[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[2U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_241[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[2U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_241[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[2U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_241[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[3U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_242[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[3U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_242[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[3U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_242[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[4U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[4U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[4U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_243[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_240[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_240[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][2U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_240[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][2U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_241[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][3U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_241[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_241[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][4U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_241[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_241[2U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][5U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_242[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][6U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_242[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][7U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_242[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][7U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][8U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_243[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__chain[1U][9U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_243[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_243[2U] 
                               << 0x00000010U));
    if (vlSelfRef.__VdfgRegularize_hebeb780c_0_301) {
        __Vtemp_102[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_228[0U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_229[0U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_230[0U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_231[0U]))));
        __Vtemp_102[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_228[1U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_229[1U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_230[1U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_231[1U]))));
        __Vtemp_102[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_228[2U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_229[2U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_230[2U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_231[2U]))));
    } else {
        __Vtemp_102[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[0U];
        __Vtemp_102[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[1U];
        __Vtemp_102[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_102[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_102[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_102[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_232[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_232[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[1U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_232[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[2U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_233[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[2U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_233[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[2U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_233[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[3U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_234[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[3U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_234[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[3U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_234[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[4U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[4U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[4U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_235[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_232[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_232[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][2U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_232[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][2U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_233[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][3U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_233[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_233[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][4U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_233[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_233[2U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][5U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_234[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][6U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_234[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][7U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_234[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][7U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][8U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_235[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__chain[1U][9U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_235[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_235[2U] 
                               << 0x00000010U));
    if (vlSelfRef.__VdfgRegularize_hebeb780c_0_303) {
        __Vtemp_115[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_220[0U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_221[0U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_222[0U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_223[0U]))));
        __Vtemp_115[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_220[1U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_221[1U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_222[1U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_223[1U]))));
        __Vtemp_115[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_220[2U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_221[2U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_222[2U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_223[2U]))));
    } else {
        __Vtemp_115[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[0U];
        __Vtemp_115[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[1U];
        __Vtemp_115[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_115[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_115[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_115[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_224[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_224[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[1U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_224[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[2U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_225[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[2U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_225[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[2U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_225[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[3U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_226[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[3U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_226[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[3U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_226[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[4U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[4U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[4U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_227[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_224[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_224[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][2U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_224[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][2U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_225[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][3U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_225[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_225[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][4U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_225[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_225[2U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][5U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_226[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][6U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_226[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][7U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_226[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][7U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][8U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_227[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__chain[1U][9U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_227[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_227[2U] 
                               << 0x00000010U));
    if (vlSelfRef.__VdfgRegularize_hebeb780c_0_305) {
        __Vtemp_128[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_212[0U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_213[0U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_214[0U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_215[0U]))));
        __Vtemp_128[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_212[1U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_213[1U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_214[1U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_215[1U]))));
        __Vtemp_128[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_212[2U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_213[2U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_214[2U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_215[2U]))));
    } else {
        __Vtemp_128[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[0U];
        __Vtemp_128[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[1U];
        __Vtemp_128[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_128[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_128[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_128[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_216[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_216[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[1U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_216[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[2U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_217[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[2U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_217[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[2U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_217[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[3U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_218[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[3U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_218[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[3U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_218[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[4U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[4U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[4U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_219[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_216[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_216[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][2U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_216[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][2U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_217[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][3U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_217[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_217[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][4U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_217[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_217[2U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][5U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_218[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][6U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_218[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][7U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_218[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][7U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][8U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_219[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__chain[1U][9U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_219[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_219[2U] 
                               << 0x00000010U));
    if (vlSelfRef.__VdfgRegularize_hebeb780c_0_307) {
        __Vtemp_141[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_204[0U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_205[0U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_206[0U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_207[0U]))));
        __Vtemp_141[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_204[1U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_205[1U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_206[1U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_207[1U]))));
        __Vtemp_141[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                            & vlSelfRef.__VdfgRegularize_hebeb780c_0_204[2U]) 
                           | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                 >> 1U)))) 
                               & vlSelfRef.__VdfgRegularize_hebeb780c_0_205[2U]) 
                              | (((- (IData)((1U & 
                                              ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                               >> 2U)))) 
                                  & vlSelfRef.__VdfgRegularize_hebeb780c_0_206[2U]) 
                                 | ((- (IData)((1U 
                                                & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 3U)))) 
                                    & vlSelfRef.__VdfgRegularize_hebeb780c_0_207[2U]))));
    } else {
        __Vtemp_141[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[0U];
        __Vtemp_141[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[1U];
        __Vtemp_141[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_141[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_141[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_141[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_208[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_208[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[1U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_208[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[2U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_209[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[2U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_209[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[2U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_209[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[3U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_210[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[3U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_210[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[3U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_210[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[4U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[4U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[4U][2U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_211[2U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][0U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_208[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][1U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_208[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][2U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_208[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][2U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][2U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_209[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][3U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_209[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_209[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][4U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_209[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_209[2U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][5U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_210[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][6U] 
        = vlSelfRef.__VdfgRegularize_hebeb780c_0_210[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0xffff0000U & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][7U]) 
           | vlSelfRef.__VdfgRegularize_hebeb780c_0_210[2U]);
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][7U] 
        = ((0x0000ffffU & vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][7U]) 
           | (vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U] 
              << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][8U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_211[0U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U] 
                               << 0x00000010U));
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__chain[1U][9U] 
        = ((vlSelfRef.__VdfgRegularize_hebeb780c_0_211[1U] 
            >> 0x00000010U) | (vlSelfRef.__VdfgRegularize_hebeb780c_0_211[2U] 
                               << 0x00000010U));
}
