// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ours_closed.h for the primary calling header

#include "Vtb_ours_closed__pch.h"

VL_ATTR_COLD void Vtb_ours_closed___024root___stl_sequent__TOP__2(Vtb_ours_closed___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ours_closed___024root___stl_sequent__TOP__2\n"); );
    Vtb_ours_closed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
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
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_93;
    // Body
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
    if (vlSelfRef.__VdfgRegularize_hebeb780c_0_293) {
        __Vtemp_2[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_2[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_2[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_2[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[0U];
        __Vtemp_2[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[1U];
        __Vtemp_2[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_2[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_2[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__0__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_2[2U]);
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
        __Vtemp_15[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_15[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_15[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_15[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[0U];
        __Vtemp_15[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[1U];
        __Vtemp_15[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_15[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_15[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__1__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_15[2U]);
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
        __Vtemp_28[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_28[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_28[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_28[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[0U];
        __Vtemp_28[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[1U];
        __Vtemp_28[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__2__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_28[2U]);
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
        __Vtemp_41[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_41[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_41[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
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
        __Vtemp_41[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[0U];
        __Vtemp_41[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[1U];
        __Vtemp_41[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_41[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_41[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__3__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_41[2U]);
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
        __Vtemp_54[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_228[0U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_229[0U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_230[0U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_231[0U]))));
        __Vtemp_54[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_228[1U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_229[1U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_230[1U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_231[1U]))));
        __Vtemp_54[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_228[2U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_229[2U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_230[2U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_231[2U]))));
    } else {
        __Vtemp_54[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[0U];
        __Vtemp_54[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[1U];
        __Vtemp_54[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_54[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_54[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__4__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_54[2U]);
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
        __Vtemp_67[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_220[0U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_221[0U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_222[0U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_223[0U]))));
        __Vtemp_67[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_220[1U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_221[1U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_222[1U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_223[1U]))));
        __Vtemp_67[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_220[2U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_221[2U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_222[2U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_223[2U]))));
    } else {
        __Vtemp_67[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[0U];
        __Vtemp_67[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[1U];
        __Vtemp_67[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_67[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_67[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__5__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_67[2U]);
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
        __Vtemp_80[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_212[0U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_213[0U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_214[0U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_215[0U]))));
        __Vtemp_80[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_212[1U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_213[1U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_214[1U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_215[1U]))));
        __Vtemp_80[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_212[2U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_213[2U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_214[2U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_215[2U]))));
    } else {
        __Vtemp_80[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[0U];
        __Vtemp_80[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[1U];
        __Vtemp_80[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__6__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_80[2U]);
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
        __Vtemp_93[0U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_204[0U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_205[0U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_206[0U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_207[0U]))));
        __Vtemp_93[1U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_204[1U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_205[1U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_206[1U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_207[1U]))));
        __Vtemp_93[2U] = (((- (IData)((1U & (IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel)))) 
                           & vlSelfRef.__VdfgRegularize_hebeb780c_0_204[2U]) 
                          | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 1U)))) 
                              & vlSelfRef.__VdfgRegularize_hebeb780c_0_205[2U]) 
                             | (((- (IData)((1U & ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                   >> 2U)))) 
                                 & vlSelfRef.__VdfgRegularize_hebeb780c_0_206[2U]) 
                                | ((- (IData)((1U & 
                                               ((IData)(vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__st__BRA__0__KET____DOT__s__DOT__sel) 
                                                >> 3U)))) 
                                   & vlSelfRef.__VdfgRegularize_hebeb780c_0_207[2U]))));
    } else {
        __Vtemp_93[0U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[0U];
        __Vtemp_93[1U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[1U];
        __Vtemp_93[2U] = vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__q[2U];
    }
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[0U][0U] 
        = __Vtemp_93[0U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[0U][1U] 
        = __Vtemp_93[1U];
    vlSelfRef.tb_ours_closed__DOT__dut__DOT__lane__BRA__7__KET____DOT__packer__DOT__eg[0U][2U] 
        = (0x0000ffffU & __Vtemp_93[2U]);
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
