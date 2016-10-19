#include "torso.h"

torso::torso() {

	int newpartnumber = 0;
	double newweight = 0;
	double newcost = 0;
	int newbattery_compartment = 0;
}

torso::torso(string name, int partnumber, string type, int battery_compartment, double weight, double cost, string description) {
	newname = name;
	newpartnumber = partnumber;
	newtype = type;
	newbattery_compartment = battery_compartment;
	newweight = weight;
	newcost = cost;
	newdescription = description;
}

torso::~torso() {

}

string torso::getname() const {
	return newname;
}
int torso::getpartnumber() const {

	return newpartnumber;
}
string torso::gettype() const {
	return newtype;
}
int torso::getcompartment() const {

	return newbattery_compartment;
}
double torso::getweight() const {

	return newweight;
}
double torso::getcost() const {

	return newcost;
}
string torso::getdescription() const {
	return newdescription;
}


