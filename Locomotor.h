#ifndef LOCOMOTOR_H
#define LOCOMOTOR_H

#include <iostream>


using namespace std;

class locomotor {
public:
	locomotor();

	locomotor(string,int,string,int,int,double,double,string);

	~locomotor();
	string getname() const;
	int getpartnumber() const;
	string gettype() const;
	int getspeed() const;
	int getpower() const;
	double getweight() const;
	double getcost() const;
	string getdescription() const;

private:
	string newname;
	int newpartnumber;
	string newtype;
	int newspeed;
	int newpower;
	double newweight;
	double newcost;
	string newdescription;
};

#endif