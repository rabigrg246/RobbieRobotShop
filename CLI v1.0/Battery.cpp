#include "stdafx.h"
#include "Battery.h"


//Set default
Battery::Battery()
{
	type = "Battery";
	new_energy = new double[3];
}

Battery::~Battery()
{
	delete[] new_energy;
}

void Battery::setEnergy(double* energy)
{
	new_energy[0] = energy[0];
	new_energy[1] = energy[1];
	new_energy[2] = energy[2];
}

string Battery::getType()
{
	return type;
}
