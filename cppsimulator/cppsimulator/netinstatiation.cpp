/******************************************************************************
 * Net instancer.
 * This file instantiate all nets in the simulation.
 * This file was generated by a verilog parser.
 ******************************************************************************/

 
#include <stdio.h>
#include "NetFlow.h"
#include "netinstatiation.h"
#include "SimulatorEngine.h"

void instance_nets(SimulatorEngine *engine){

	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__GRAY__INST_SCOUNT__0_SCLK_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_CLK__BUFGP_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_L2_G__RT__13_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SMCOUNT__COUNT__LUT_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_L1_G__RT__17_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__RESET__6_DB5LUT__O__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__GRAY__INST_SCOUNT__1_SCLK_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__OUT__1__OBUF_SI_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__OUT__2__OBUF_SI_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BPROTOCOMP1_DCYINITGND_D0_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_ENABLE_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_ENABLE__IBUF__59_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__RESET__2_DB5LUT__O__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__OUT__5__OBUF_SI_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT__0__OBUF__99_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_ENABLE__IBUF__0_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__OUT__3__OBUF_SI_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__OUT__7__OBUF_SI_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__OUT__0__OBUF_SI_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__OUT__4__OBUF_SI_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__OUT__6__OBUF_SI_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__GRAY__INST_SMCOUNT__COUNT__XOR_L7_G__CO_A1_B__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_CLK_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__GRAY__INST_SCOUNT__7_SCLK_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__GRAY__INST_SMCOUNT__COUNT__XOR_L7_G__CO_A0_B__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT__5__OBUF__0_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_CONST__ONE_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__GRAY__INST_SCOUNT__6_SCLK_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT__1__OBUF__121_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__GRAY__INST_SMCOUNT__COUNT__XOR_L7_G__DI_A3_B__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__GRAY__INST_SMCOUNT__COUNT__CY_L3_G__CO_A1_B__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_VCC_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__GRAY__INST_SMCOUNT__COUNT__CY_L3_G__CO_A0_B__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_GND_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__GRAY__INST_SMCOUNT__COUNT__XOR_L7_G__CO_A2_B__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__GRAY__INST_SMCOUNT__COUNT__XOR_L7_G__CO_A3_B__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__RESET__3_DA5LUT__O__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT__6__OBUF__115_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__GRAY__INST_SCOUNT__5_SCLK_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_A1_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_A2_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_A3_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_A4_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_A5_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_A6_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_A7_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SRESULT_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SRESULT_A1_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SRESULT_A2_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SRESULT_A3_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SRESULT_A4_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SRESULT_A5_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SRESULT_A6_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SRESULT_A7_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__GRAY__INST_SMCOUNT__COUNT__CY_L3_G__CO_A2_B__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT_A1_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT_A2_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT_A3_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT_A4_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT_A5_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT_A6_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT_A7_B"));
	engine->register_net(new NetFlow("NET_INDEX__BCLK__BUFGP_SIBUFG__56_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT__5__OBUF__90_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT__4__OBUF__135_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_RST_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_L5_G__RT__43_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_L6_G__RT__39_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__GRAY__INST_SCOUNT__4_SCLK_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__RESET_DC5LUT__O__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__RESET__5_DC5LUT__O__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BCNTR__INST_SCNTR__133_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__GRAY__INST_SCOUNT__2_SCLK_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BCLK__BUFGP_SIBUFG__0_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__Q__OBUF_SI_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT__0__OBUF__0_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_L4_G__RT__47_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT__3__OBUF__126_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__RESET__4_DD5LUT__O__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT__2__OBUF__0_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_Q_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_L7_G__RT__29_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_OUT__2__OBUF__84_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__CNTR__INST_SCNTR_SCLK_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SCOUNT_L3_G__RT__1_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLW__N0__2_DA5LUT__O__UNCONNECTED_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX_CONST__ZERO_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__GRAY__INST_SCOUNT__3_SCLK_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BNLWBUFFERSIGNAL__CLK__BUFGP_SBUFG_SIN_A0_B"));
	engine->register_net(new NetFlow("NET_INDEX__BGRAY__INST_SMCOUNT__COUNT__CY_A3_B"));

}

