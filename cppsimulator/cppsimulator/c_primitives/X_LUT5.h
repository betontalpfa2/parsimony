/******************************************************************************
 * Generated Cpp template for simulation primitives.
 * Author: Benedek Racz
 ******************************************************************************/

#ifndef X_LUT5_H
#define X_LUT5_H

#include "NetFlow.h"
#include "sim_types.h"
#include "Primitive.h"
namespace CPrimitives {
	
	class X_LUT5: public Primitive{

		//Verilog Parameters:
		parameter_int_t INIT;
		parameter_string_t LOC;
		//Verilog Ports in definition order:
		NetFlow* O_A0_B; // net ID: O lsb: 0  msb: 0 OUTPUT
		NetFlow* ADR0_A0_B; // net ID: ADR0 lsb: 0  msb: 0 INPUT
		NetFlow* ADR1_A0_B; // net ID: ADR1 lsb: 0  msb: 0 INPUT
		NetFlow* ADR2_A0_B; // net ID: ADR2 lsb: 0  msb: 0 INPUT
		NetFlow* ADR3_A0_B; // net ID: ADR3 lsb: 0  msb: 0 INPUT
		NetFlow* ADR4_A0_B; // net ID: ADR4 lsb: 0  msb: 0 INPUT
		


		public: X_LUT5(
			const char * name,
			//Verilog Parameters:
			parameter_int_t INIT, // Default: 32'h00000000
			parameter_string_t LOC, // Default: "UNPLACED"
			//Verilog Ports in definition order:
			NetFlow* O_A0_B, // net ID: O lsb: 0  msb: 0 OUTPUT
			NetFlow* ADR0_A0_B, // net ID: ADR0 lsb: 0  msb: 0 INPUT
			NetFlow* ADR1_A0_B, // net ID: ADR1 lsb: 0  msb: 0 INPUT
			NetFlow* ADR2_A0_B, // net ID: ADR2 lsb: 0  msb: 0 INPUT
			NetFlow* ADR3_A0_B, // net ID: ADR3 lsb: 0  msb: 0 INPUT
			NetFlow* ADR4_A0_B // net ID: ADR4 lsb: 0  msb: 0 INPUT
			):Primitive(name, true){
			
			// Assign parameters and ports: 
			//Verilog Parameters:
			this->INIT = INIT; // Default: 32'h00000000
			this->LOC = LOC; // Default: "UNPLACED"
			//Verilog Ports in definition order:
			this->O_A0_B = O_A0_B; // net ID: O lsb: 0  msb: 0 OUTPUT
			this->ADR0_A0_B = ADR0_A0_B; // net ID: ADR0 lsb: 0  msb: 0 INPUT
			this->ADR1_A0_B = ADR1_A0_B; // net ID: ADR1 lsb: 0  msb: 0 INPUT
			this->ADR2_A0_B = ADR2_A0_B; // net ID: ADR2 lsb: 0  msb: 0 INPUT
			this->ADR3_A0_B = ADR3_A0_B; // net ID: ADR3 lsb: 0  msb: 0 INPUT
			this->ADR4_A0_B = ADR4_A0_B; // net ID: ADR4 lsb: 0  msb: 0 INPUT
			
			register_wait_on_event_nets();
			

		}
		
		void register_wait_on_event_nets(){
			ADR0_A0_B->register_event_reader(this);
			ADR1_A0_B->register_event_reader(this);
			ADR2_A0_B->register_event_reader(this);
			ADR3_A0_B->register_event_reader(this);
			ADR4_A0_B->register_event_reader(this);
		}

		bool calculate(simtime_t time){
			return calculate_LUT(time,
				INIT,
				O_A0_B,
				ADR0_A0_B,
				ADR1_A0_B,
				ADR2_A0_B,
				ADR3_A0_B,
				ADR4_A0_B
				);
		}

		};
		
}
#endif // X_LUT5_H
