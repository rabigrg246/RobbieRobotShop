#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef ARM_H
#define ARM_H


class Arm
{
public:
	//Default Constructor
	Arm();

	//Overload constructor
	Arm(double*);

	//Deconstructors
	~Arm();

	// Setter Function
	void setPower(double*);

	//Getter Function
	double* getPower();
	string getType();

private:
	double* new_power;
	string type;
};

#endif // !Arm_H
