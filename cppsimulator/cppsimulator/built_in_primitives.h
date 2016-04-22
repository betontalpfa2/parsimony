#ifndef BUILT_IN_PRIMITIVES_H
#define BUILT_IN_PRIMITIVES_H

#include "NetFlow.h"
#include "sim_types.h"

class NetFlow;

value_t get_value(const NetFlow* const net, simtime_t time, value_t atNull = LOW);

void calculate_LUT(simtime_t time,
	uint64_t lut,
	NetFlow* out,
	const NetFlow* const in0,
	const NetFlow* const in1,
	const NetFlow* const in2 = NULL,
	const NetFlow* const in3 = NULL,
	const NetFlow* const in4 = NULL,
	const NetFlow* const in5 = NULL
	);

void calculate_BUF(simtime_t time,
	NetFlow* out,
	const NetFlow* const in
	);



#endif // BUILT_IN_PRIMITIVES_H