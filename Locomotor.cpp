#include "locomotor.h"

locomotor::locomotor() {

	int newpartnumber = 0;
	double newweight = 0;
	double newcost = 0;
	int newspeed = 0;
	int newpower = 0;
}

locomotor::locomotor(string name, int partnumber, string type, int speed,int power, double weight, double cost, string description) {
	newname = name;
	newpartnumber = partnumber;
	newtype = type;
	newspeed = speed;
	newpower = power;
	newweight = weight;
	newcost = cost;
	newdescription = description;
}

locomotor::~locomotor() {

}

string locomotor::getname() const {
	return newname;
}
int locomotor::getpartnumber() const {

	return newpartnumber;
}
string locomotor::gettype() const {
	return newtype;
}
int locomotor::getspeed() const {

	return newspeed;
}
int locomotor::getpower() const {

	return newpower;
}
double locomotor::getweight() const {

	return newweight;
}
double locomotor::getcost() const {

	return newcost;
}
string locomotor::getdescription() const {
	return newdescription;
}


