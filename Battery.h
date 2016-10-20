#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef BATTERY_H
#define BATTERY_H


class Battery
{
public:
	//Default Constructor
	Battery();

	//Overload constructor
	Battery(double*);

	//Deconstructors
	~Battery();

	// Setter Function
	void setEnergy(double*);
	
	//Getter Function
	string getType();

private:
	double* new_energy;
	string type;
};

#endif // !BATTERY_H
