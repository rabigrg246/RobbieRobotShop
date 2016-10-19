#include "arm.h"

arm::arm() {

	int newpartnumber = 0;
	double newweight = 0;
	double newcost = 0;
	int newpower = 0;
}

arm::arm(string name, int partnumber, string type, int power, double weight, double cost, string description) {
	newname = name;
	newpartnumber = partnumber;
	newtype = type;
	newpower = power;
	newweight = weight;
	newcost = cost;
	newdescription = description;
}

arm::~arm() {

}

string arm::getname() const {
	return newname;
}
int arm::getpartnumber() const {

	return newpartnumber;
}
string arm::gettype() const {
	return newtype;
}
int arm::getpower() const {

	return newpower;
}
double arm::getweight() const {

	return newweight;
}
double arm::getcost() const {

	return newcost;
}
string arm::getdescription() const {
	return newdescription;
}


