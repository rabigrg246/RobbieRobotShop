#ifndef HEAD_H
#define HEAD_H

#include <iostream>


using namespace std;

class head {
public:
	head();

	head(string, int, string, double, double, string);

	~head();
	string getname() const;
	int getpartnumber() const;
	string gettype() const;
	double getweight() const;
	double getcost() const;
	string getdescription() const;

private:
	string newname;
	int newpartnumber;
	string newtype;
	double newweight;
	double newcost;
	string newdescription;
};

#endif