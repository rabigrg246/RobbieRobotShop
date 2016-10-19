#ifndef ARM_H
#define ARM_H

#include <iostream>


using namespace std;

class arm {
public:
	arm();

	arm(string, int, string, int, double, double, string);

	~arm();
	string getname() const;
	int getpartnumber() const;
	string gettype() const;
	int getpower() const;
	double getweight() const;
	double getcost() const;
	string getdescription() const;

private:
	string newname;
	int newpartnumber;
	string newtype;
	int newpower;
	double newweight;
	double newcost;
	string newdescription;
};

#endif