#pragma once
#include <iostream>
using namespace std;

#ifndef LOCOMOTOR_H
#define LOCOMOTOR_H


class Locomotor
{
public:
	//Default Constructor
	Locomotor();
	
	//Overload constructor
	Locomotor(double);

	//Deconstructors
	~Locomotor();

	// Setter Function
	void setMaxSpeed(double);
	void setPowerConsumed(double);

private:
	int new_maxSpeed;
	int new_PowerConsumed;
};

#endif // !LOCOMOTOR_H
