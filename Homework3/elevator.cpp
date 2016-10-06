 #ifdef _MSC_VER
 #include "stdafx.h"
 #endif
 #include "std_lib_facilities.h"
 #include "elevator.h"

 void Elevator::goto_floor(int floor) {
	 if (floor >= 0 && floor <= top_floor)
		 desired_floor = floor;
	 else
		 throw Invalid_floor{};
 }

 void Elevator::move() {
	 if (desired_floor > current_floor)
		  current_floor+=1;
	 going_up = true;
	 idle = false;

 }

 int Elevator::get_current_floor() {
	 return current_floor;
 }

 int Elevator::get_desired_floor() {
	 return desired_floor;
 }

 bool Elevator::is_going_up() {
	 return going_up;
 }

 bool Elevator::has_arrived() {
	 return (current_floor == desired_floor) && !idle;
		 
 }

 bool Elevator::is_idle() {
	 return idle;
 }


