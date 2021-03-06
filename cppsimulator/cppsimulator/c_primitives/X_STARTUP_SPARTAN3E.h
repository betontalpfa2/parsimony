/******************************************************************************
 * Generated Cpp template for simulation primitives.
 * Author: Benedek Racz
 ******************************************************************************/

#ifndef X_STARTUP_SPARTAN3E_H
#define X_STARTUP_SPARTAN3E_H

#include "NetFlow.h"
#include "sim_types.h"
#include "Primitive.h"

namespace CPrimitives {
	
	class X_STARTUP_SPARTAN3E: public Primitive{

		//Verilog Parameters:
		//Verilog Ports in definition order:
		NetFlow* CLK_A0_B; // net ID: CLK lsb: 0  msb: 0 INPUT
		NetFlow* GSR_A0_B; // net ID: GSR lsb: 0  msb: 0 INPUT
		NetFlow* GTS_A0_B; // net ID: GTS lsb: 0  msb: 0 INPUT
		NetFlow* MBT_A0_B; // net ID: MBT lsb: 0  msb: 0 INPUT
		
		public: X_STARTUP_SPARTAN3E(
			const char * name,
			//Verilog Parameters:
			//Verilog Ports in definition order:
			NetFlow* CLK_A0_B, // net ID: CLK lsb: 0  msb: 0 INPUT
			NetFlow* GSR_A0_B, // net ID: GSR lsb: 0  msb: 0 INPUT
			NetFlow* GTS_A0_B, // net ID: GTS lsb: 0  msb: 0 INPUT
			NetFlow* MBT_A0_B // net ID: MBT lsb: 0  msb: 0 INPUT
			):Primitive(name){
			
			// Assign parameters and ports: 
			//Verilog Parameters:
			//Verilog Ports in definition order:
			this->CLK_A0_B = CLK_A0_B; // net ID: CLK lsb: 0  msb: 0 INPUT
			this->GSR_A0_B = GSR_A0_B; // net ID: GSR lsb: 0  msb: 0 INPUT
			this->GTS_A0_B = GTS_A0_B; // net ID: GTS lsb: 0  msb: 0 INPUT
			this->MBT_A0_B = MBT_A0_B; // net ID: MBT lsb: 0  msb: 0 INPUT
			
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
#endif // X_STARTUP_SPARTAN3E_H
