#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>


using namespace std;

class battery {
public:
	battery();

	battery(string, int, string, int, double, double, string);

	~battery();
	string getname() const;
	int getpartnumber() const;
	string gettype() const;
	int getenergy() const;
	double getweight() const;
	double getcost() const;
	string getdescription() const;

private:
	string newname;
	int newpartnumber;
	string newtype;
	int newenergy;
	double newweight;
	double newcost;
	string newdescription;
};

#endif