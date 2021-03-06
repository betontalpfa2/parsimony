/******************************************************************************
 * Generated Cpp template for simulation primitives.
 * Author: Benedek Racz
 ******************************************************************************/

#ifndef X_CLKDLL_MAXIMUM_PERIOD_CHECK_H
#define X_CLKDLL_MAXIMUM_PERIOD_CHECK_H

#include "NetFlow.h"
#include "sim_types.h"
#include "Primitive.h"

namespace CPrimitives {
	
	class x_clkdll_maximum_period_check: public Primitive{

		//Verilog Parameters:
		parameter_string_t clock_name;
		parameter_int_t maximum_period;
		//Verilog Ports in definition order:
		NetFlow* CLOCK_A0_B; // net ID: clock lsb: 0  msb: 0 INPUT
		NetFlow* RST_A0_B; // net ID: rst lsb: 0  msb: 0 INPUT
		
		public: x_clkdll_maximum_period_check(
			const char * name,
			//Verilog Parameters:
			parameter_string_t clock_name, // Default: ""
			parameter_int_t maximum_period, // Default: 0
			//Verilog Ports in definition order:
			NetFlow* CLOCK_A0_B, // net ID: clock lsb: 0  msb: 0 INPUT
			NetFlow* RST_A0_B // net ID: rst lsb: 0  msb: 0 INPUT
			):Primitive(name){
			
			// Assign parameters and ports: 
			//Verilog Parameters:
			this->clock_name = clock_name; // Default: ""
			this->maximum_period = maximum_period; // Default: 0
			//Verilog Ports in definition order:
			this->CLOCK_A0_B = CLOCK_A0_B; // net ID: clock lsb: 0  msb: 0 INPUT
			this->RST_A0_B = RST_A0_B; // net ID: rst lsb: 0  msb: 0 INPUT
			
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
#endif // X_CLKDLL_MAXIMUM_PERIOD_CHECK_H
