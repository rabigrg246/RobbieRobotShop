#include "stdafx.h"
#include "Arm.h"


//Set default
Arm::Arm()
{
	type = "Arm";
	new_power = new double[2]; //Left and right arm energy consumption
}

Arm::~Arm()
{
	delete[] new_power;
}

void Arm::setPower(double* power)
{
	new_power[0] = power[0];
	new_power[1] = power[1];
}

double* Arm::getPower()
{
	return new_power;
}

string Arm::getType()
{
	return type;
}
