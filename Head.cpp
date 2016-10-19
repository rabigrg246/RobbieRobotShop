#include "head.h"

head::head() {

	int newpartnumber = 0;
	double newweight = 0;
	double newcost = 0;
	
}

head::head(string name, int partnumber, string type, double weight, double cost, string description) {
	newname = name;
	newpartnumber = partnumber;
	newtype = type;
	newweight = weight;
	newcost = cost;
	newdescription = description;
}

head::~head() {

}

string head::getname() const {
	return newname;
}
int head::getpartnumber() const {

	return newpartnumber;
}
string head::gettype() const {
	return newtype;
}
double head::getweight() const {

	return newweight;
}
double head::getcost() const {

	return newcost;
}
string head::getdescription() const {
	return newdescription;
}




