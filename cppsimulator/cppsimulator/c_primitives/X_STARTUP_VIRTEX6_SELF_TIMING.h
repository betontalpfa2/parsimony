/******************************************************************************
 * Generated Cpp template for simulation primitives.
 * Author: Benedek Racz
 ******************************************************************************/

#ifndef X_STARTUP_VIRTEX6_SELF_TIMING_H
#define X_STARTUP_VIRTEX6_SELF_TIMING_H

#include "NetFlow.h"
#include "sim_types.h"
#include "Primitive.h"

namespace CPrimitives {
	
	class X_STARTUP_VIRTEX6_SELF_TIMING: public Primitive{

		//Verilog Parameters:
		parameter_string_t LOC;
		parameter_enum_t PROG_USR;
		//Verilog Ports in definition order:
		NetFlow* CFGCLK_A0_B; // net ID: CFGCLK lsb: 0  msb: 0 OUTPUT
		NetFlow* CFGMCLK_A0_B; // net ID: CFGMCLK lsb: 0  msb: 0 OUTPUT
		NetFlow* DINSPI_A0_B; // net ID: DINSPI lsb: 0  msb: 0 OUTPUT
		NetFlow* EOS_A0_B; // net ID: EOS lsb: 0  msb: 0 OUTPUT
		NetFlow* PREQ_A0_B; // net ID: PREQ lsb: 0  msb: 0 OUTPUT
		NetFlow* TCKSPI_A0_B; // net ID: TCKSPI lsb: 0  msb: 0 OUTPUT
		NetFlow* CLK_A0_B; // net ID: CLK lsb: 0  msb: 0 INPUT
		NetFlow* GSR_A0_B; // net ID: GSR lsb: 0  msb: 0 INPUT
		NetFlow* GTS_A0_B; // net ID: GTS lsb: 0  msb: 0 INPUT
		NetFlow* KEYCLEARB_A0_B; // net ID: KEYCLEARB lsb: 0  msb: 0 INPUT
		NetFlow* PACK_A0_B; // net ID: PACK lsb: 0  msb: 0 INPUT
		NetFlow* USRCCLKO_A0_B; // net ID: USRCCLKO lsb: 0  msb: 0 INPUT
		NetFlow* USRCCLKTS_A0_B; // net ID: USRCCLKTS lsb: 0  msb: 0 INPUT
		NetFlow* USRDONEO_A0_B; // net ID: USRDONEO lsb: 0  msb: 0 INPUT
		NetFlow* USRDONETS_A0_B; // net ID: USRDONETS lsb: 0  msb: 0 INPUT
		
		public: X_STARTUP_VIRTEX6_SELF_TIMING(
			const char * name,
			//Verilog Parameters:
			parameter_string_t LOC, // Default: "UNPLACED"
			parameter_enum_t PROG_USR, // Default: "FALSE"
			//Verilog Ports in definition order:
			NetFlow* CFGCLK_A0_B, // net ID: CFGCLK lsb: 0  msb: 0 OUTPUT
			NetFlow* CFGMCLK_A0_B, // net ID: CFGMCLK lsb: 0  msb: 0 OUTPUT
			NetFlow* DINSPI_A0_B, // net ID: DINSPI lsb: 0  msb: 0 OUTPUT
			NetFlow* EOS_A0_B, // net ID: EOS lsb: 0  msb: 0 OUTPUT
			NetFlow* PREQ_A0_B, // net ID: PREQ lsb: 0  msb: 0 OUTPUT
			NetFlow* TCKSPI_A0_B, // net ID: TCKSPI lsb: 0  msb: 0 OUTPUT
			NetFlow* CLK_A0_B, // net ID: CLK lsb: 0  msb: 0 INPUT
			NetFlow* GSR_A0_B, // net ID: GSR lsb: 0  msb: 0 INPUT
			NetFlow* GTS_A0_B, // net ID: GTS lsb: 0  msb: 0 INPUT
			NetFlow* KEYCLEARB_A0_B, // net ID: KEYCLEARB lsb: 0  msb: 0 INPUT
			NetFlow* PACK_A0_B, // net ID: PACK lsb: 0  msb: 0 INPUT
			NetFlow* USRCCLKO_A0_B, // net ID: USRCCLKO lsb: 0  msb: 0 INPUT
			NetFlow* USRCCLKTS_A0_B, // net ID: USRCCLKTS lsb: 0  msb: 0 INPUT
			NetFlow* USRDONEO_A0_B, // net ID: USRDONEO lsb: 0  msb: 0 INPUT
			NetFlow* USRDONETS_A0_B // net ID: USRDONETS lsb: 0  msb: 0 INPUT
			):Primitive(name){
			
			// Assign parameters and ports: 
			//Verilog Parameters:
			this->LOC = LOC; // Default: "UNPLACED"
			this->PROG_USR = PROG_USR; // Default: "FALSE"
			//Verilog Ports in definition order:
			this->CFGCLK_A0_B = CFGCLK_A0_B; // net ID: CFGCLK lsb: 0  msb: 0 OUTPUT
			this->CFGMCLK_A0_B = CFGMCLK_A0_B; // net ID: CFGMCLK lsb: 0  msb: 0 OUTPUT
			this->DINSPI_A0_B = DINSPI_A0_B; // net ID: DINSPI lsb: 0  msb: 0 OUTPUT
			this->EOS_A0_B = EOS_A0_B; // net ID: EOS lsb: 0  msb: 0 OUTPUT
			this->PREQ_A0_B = PREQ_A0_B; // net ID: PREQ lsb: 0  msb: 0 OUTPUT
			this->TCKSPI_A0_B = TCKSPI_A0_B; // net ID: TCKSPI lsb: 0  msb: 0 OUTPUT
			this->CLK_A0_B = CLK_A0_B; // net ID: CLK lsb: 0  msb: 0 INPUT
			this->GSR_A0_B = GSR_A0_B; // net ID: GSR lsb: 0  msb: 0 INPUT
			this->GTS_A0_B = GTS_A0_B; // net ID: GTS lsb: 0  msb: 0 INPUT
			this->KEYCLEARB_A0_B = KEYCLEARB_A0_B; // net ID: KEYCLEARB lsb: 0  msb: 0 INPUT
			this->PACK_A0_B = PACK_A0_B; // net ID: PACK lsb: 0  msb: 0 INPUT
			this->USRCCLKO_A0_B = USRCCLKO_A0_B; // net ID: USRCCLKO lsb: 0  msb: 0 INPUT
			this->USRCCLKTS_A0_B = USRCCLKTS_A0_B; // net ID: USRCCLKTS lsb: 0  msb: 0 INPUT
			this->USRDONEO_A0_B = USRDONEO_A0_B; // net ID: USRDONEO lsb: 0  msb: 0 INPUT
			this->USRDONETS_A0_B = USRDONETS_A0_B; // net ID: USRDONETS lsb: 0  msb: 0 INPUT
			
			register_wait_on_event_nets();
			
		}
		
		void register_wait_on_event_nets(){
		// TODO
		}
		
		bool calculate(simtime_t time){
		// TODO
		}
		};
		
}
#endif // X_STARTUP_VIRTEX6_SELF_TIMING_H
