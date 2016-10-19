#include "battery.h"

battery::battery() {

	int newpartnumber = 0;
	double newweight = 0;
	double newcost = 0;
	int newenergy = 0;
}

battery::battery(string name, int partnumber, string type, int energy, double weight, double cost, string description) {
	newname = name;
	newpartnumber = partnumber;
	newtype = type;
	newenergy = energy;
	newweight = weight;
	newcost = cost;
	newdescription = description;
}

battery::~battery() {

}

string battery::getname() const {
	return newname;
}
int battery::getpartnumber() const {

	return newpartnumber;
}
string battery::gettype() const {
	return newtype;
}
int battery::getenergy() const {

	return newenergy;
}
double battery::getweight() const {

	return newweight;
}
double battery::getcost() const {

	return newcost;
}
string battery::getdescription() const {
	return newdescription;
}


