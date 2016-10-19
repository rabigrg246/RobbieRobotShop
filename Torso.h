#ifndef TORSO_H
#define TORSO_H

#include <iostream>


using namespace std;

class torso {
public:
	torso();

	torso(string, int, string, int, double, double, string);

	~torso();
	string getname() const;
	int getpartnumber() const;
	string gettype() const;
	int getcompartment() const;
	double getweight() const;
	double getcost() const;
	string getdescription() const;

private:
	string newname;
	int newpartnumber;
	string newtype;
	int newbattery_compartment;
	double newweight;
	double newcost;
	string newdescription;
};

#endif