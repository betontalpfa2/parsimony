
#include "NetFlow.h"
#include "simulator_base.h"
#include "base_vector.h"
#include "sim_types.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <Primitive.h>
 
/******************************************************************************
* returns the name of net_flow's net
*****************************************************************************/
NetFlow::NetFlow(const char* name, unsigned lengthOfData, net_level_t initial_level, bool monitor_change):
	name(0),
	data(lengthOfData)
{
	init(name, initial_level, monitor_change);
}

/******************************************************************************
* initialize the net_flow. Use new_net_flow instead.
*****************************************************************************/
void NetFlow::init(const char* name, net_level_t initial_level, bool monitor_change) {
	this->monitor_change = monitor_change;
	set_name(name);
	this->readers = new base::Vector<reader_t>();
	this->drivers = new base::Vector<driver_t>();
	
	// set_at(initial_level, 0);
	net_change_struct new_element;
	new_element.level = initial_level;
	new_element.time = 0;
	this->data.push_back(new_element);
	now_index = 0;

}

/******************************************************************************
* returns the name of net_flow's net
*****************************************************************************/
const char* NetFlow::get_name() const {
	return this->name;
}

/******************************************************************************
* sets the name of net_flow's net
*****************************************************************************/
void NetFlow::set_name(const char *new_name) {
	if (this->name) {
		free(this->name);
	}
	this->name = _strdup(new_name);
}


/******************************************************************************
* returns the use_in_event flag:
* If use_in_event is true this net is used in an event (somewhere in the
* simulation) So If it changes some primitive/cell/process must be rerun.
*****************************************************************************/
bool NetFlow::get_use_in_event() const {
	return !this->event_readers.empty();
}

/******************************************************************************
* check if net_flow's value is equal at the given time. The 0 time is the start
* of the simulation.
*****************************************************************************/
bool NetFlow::is_equal_at(value_t val, simtime_t time) const {
	net_level_t net_level;
	value_t net_value;// = UNDEFINED;
	assert(time >= 0);
	//if (time >= 0) {
	net_level = get_at(time);
	net_value = net_level.value;
	//}
	return net_value == val;
}

/******************************************************************************
* check if net_flow's value is equal at the given time. The 0 time is the
* current time of the simulation.
* The followings are the same:
* is_equal_from_now(net_flow, val, 0);
* is_equal_at(net_flow, val, get_current_time());
*****************************************************************************/
bool NetFlow::is_equal_from_now(value_t val, simtime_t time) const {
	return is_equal_at(val, time + engine->get_current_time());
}

/******************************************************************************
* returns the net value at a given time. The 0 time is the start
* of the simulation.
*****************************************************************************/
net_level_t NetFlow::get_at(simtime_t serach_time) const {

	net_change_t tmp_net_value_change;

	int index = __find_nearest_earlier_index__(serach_time);

	tmp_net_value_change = data.get(index);

	return tmp_net_value_change.level;

}

/******************************************************************************
* returns the net value at a given time. The 0 time is the
* current time of the simulation.
* The followings are the same:
* get_from_now(net_flow, 0);
* get_at(net_flow, get_current_time());
*****************************************************************************/
net_level_t NetFlow::get_from_now(const simtime_t time) const  {
	return get_at(time + engine->get_current_time());
}

/******************************************************************************
* checks if the net has the given value at the current time.
* The followings are the same:
* is_equal_from_now(net_flow, val, 0);
* is_equal_now(net_flow, val);
*****************************************************************************/
bool NetFlow::is_equal_now(const value_t val) const {
	return is_equal_from_now(val, 0);
}

/******************************************************************************
* 
*****************************************************************************/
bool NetFlow::is_equal_prev(const value_t val, simtime_t time) const  {
	if (time < 0) {
		return is_equal_from_now(val, -1);
	}
	return is_equal_at(val, time - 1);
}


value_t NetFlow::get_value_prev(simtime_t time) const {
	if (time < 0) {
		return UNDEFINED;
	}
	return get_at(time - 1).value;

}


bool NetFlow::posedge_at(simtime_t time) {
	if (is_equal_at(HIGH, time) && is_equal_prev(LOW, time)) {
		return true;
	}
	return false;
}

/******************************************************************************
* Sets the net_flow value at the given time. The 0 time is the start
* of the simulation.
*****************************************************************************/
bool NetFlow::set_at(const net_level_t level, const simtime_t set_time) {
	net_change_t new_element;//= new net_change_t();
	new_element.level = level;
	new_element.time = set_time;

	/**
	* Negative settime is illegal
	*/
	assert(set_time >= 0);

	/**
	* If the data vector is empty then push the new element
	*/
	assert(!data.empty());

	/**
	* If the new value is equal the previous, there is no change in value => we dont do anythink.
	*/
	if (is_equal_at(level, set_time)) {
		return false;
	}


	/**
	* Erease mod: remove all later event on the net than set_time:
	*/
	//unsigned size = data.size();
	net_change_struct ncs;
	bool mustret = false;
	while (true) {
		ncs = data.get_last();

		/**
		 * If the last change is in the future ... 
		 * Remove it (consider the last index, and the emty list...)
		 */
		if (ncs.time >= set_time) {
			if (ncs.time == set_time) {
				now_index--;
			}
			this->data.remove_last();

			if (data.empty()) {
				this->data.push_back(new_element);
				now_index = 0;
				return true;
			}
		}
		else {
			assert(mustret == false);
			mustret = true;
			/// Here the last change (in the data) happened in the past.
			if (is_equal_at(level, set_time)) {
				if (set_time <= engine->get_current_time()) {
					now_index = data.size() - 1;
				}
				return true;
			}
			else {
				this->data.push_back(new_element);
				if (set_time<=engine->get_current_time()) {
					now_index = data.size() - 1;
					// If the value has to be changed, and we are at now, there must be some rerun...
					if (set_time == engine->get_current_time()) {
						return true;
					}
				}
				return false;
			}
			assert(0);
		}
	}
	assert(0);
}


void NetFlow::clear_change_flag() {
	changed_in_this_delta = false;
}

/******************************************************************************
* Sets the net_flow value at the given time. The 0 time is the
* current time of the simulation.
* The followings are the same:
* set_value_from_now(net_flow, val, 0);
* set_value_at(net_flow, val, get_current_time());
*****************************************************************************/
bool NetFlow::set_from_now(const net_level_t level, const simtime_t set_time) {
	return set_at(level, set_time + engine->get_current_time());
}


bool NetFlow::set_from_now(const value_t val, const simtime_t set_time, const strength_t strength) {
	return set_at(val, set_time + engine->get_current_time(), strength);
}


bool NetFlow::set_at(const value_t val, const simtime_t time, const strength_t strength) {
	return set_at(new_net_level(val, strength), time);
}

/******************************************************************************

*****************************************************************************/
bool NetFlow::set_now(const net_level_t level) {
	return set_from_now(level, 0);
}

/******************************************************************************

*****************************************************************************/
bool NetFlow::set_now(const value_t val, const strength_t strength) {
	return set_from_now(val, 0, strength);
}

int NetFlow::__find_nearest_earlier_index__(const simtime_t serach_time) const  {
	net_change_t tmp_net_value_change ;
	simtime_t tmp_time;
	int first_index;
	int last_index;
	int middle_index;

	if (engine->get_current_time() == serach_time) {
		return now_index;
	}
	if (serach_time > engine->get_current_time()) {
		first_index = now_index;
		last_index = this->data.size() - 1;
		middle_index = (first_index + last_index) / 2;
	}
	else {
		first_index = 0;
		last_index = now_index;
		middle_index = (first_index + last_index) / 2;
	}


	if (last_index < 0) {
		return -1;
	}


	while (first_index <= last_index) {
		tmp_net_value_change = data.get(middle_index);
		tmp_time = tmp_net_value_change.time;
		if (tmp_time < serach_time) {
			first_index = middle_index + 1;
		}
		else if (tmp_time == serach_time) {
			return middle_index;
		}
		else {
			last_index = middle_index - 1;
		}
		middle_index = (first_index + last_index) / 2;
	}
	return last_index;

}


void NetFlow::register_reader(const reader_t & reader_primitive) { 
	this->drivers->push_back(reader_primitive);
}


void NetFlow::register_driver(const driver_t & driver_primitive) {
	this->drivers->push_back(driver_primitive);
}

bool NetFlow::step_time(const simtime_t time_to_step)
{
	bool changed_in_this_ts = false;

	if (data.size() == 1) {
		now_index = 0;
		if (time_to_step == now_index) {
			changed_in_this_ts = true;
		}
		return changed_in_this_ts;
	}
	while (true) {
		if (now_index + 1 >= (signed)data.size())
			return changed_in_this_ts;
		if (data.get(now_index + 1).time > time_to_step)
			return changed_in_this_ts;
		now_index++;
		if (time_to_step == data.get(now_index).time ) {
			changed_in_this_ts = true;
		}
	}
	//return changed_in_this_ts;
}



/*NetFlow::NetFlow(const NetFlow & other)
{
	set_name(other.name);
	data = base::Vector<net_change_t>(other.data);

	now_index = other.now_index;

	use_in_event = other.use_in_event;

	current_driver_count = other.current_driver_count;
	
	monitor_change = other.monitor_change;

	drivers = new base::Vector<driver_t>(*drivers);

	readers = new base::Vector<reader_t>(*readers);
}*/


NetFlow::~NetFlow()
{
	free(name);


	delete drivers;

	delete readers;
}


void NetFlow::register_event_reader(Primitive*  const reader_primitive) {
	event_readers.push_back(reader_primitive);
}



net_level_t new_net_level(value_t val, strength_t strength) {
	net_level_t new_instance;
	new_instance.value = val;
	new_instance.strength = strength;
	return new_instance;
}

void NetFlow::print_flow(int numOfChange) const {
	char charBuff[4];
	if (numOfChange<0) {
		numOfChange = data.size();
	}
	printf("%s: ", name);
	for (int i = 0; i < numOfChange; i++) {
		net_change_t change = data.get(i);
		to_string(change.level, charBuff);
		printf("   %llu: %s", change.time, charBuff);
	}
	printf("\n");
}


bool NetFlow::is_equal_at(net_level_t level, simtime_t time) const {
	return is_equal_at(level.value, time);
}

void NetFlow::generate_clock(simtime_t period, simtime_t until, value_t start_value) {
	generate_clock(period, engine->get_current_time(), until, start_value);
}

// Note that this function is not thread safe
void NetFlow::generate_clock(simtime_t half_period, simtime_t from, simtime_t until, value_t start_value) {

	while (from < until) {
		try {
			set_at(new_net_level(start_value), from);
		}
		
		catch (exception_code_t ex) {
			if (NET_FLOW_VECTOR_IS_FULL == ex) {
				engine->expand_all_nets();
				set_at(new_net_level(start_value), from);
			}
		}

		if (LOW == start_value) {
			start_value = HIGH;
		}
		else {
			start_value = LOW;
		}
		from += half_period;
	}
}