#include "stdafx.h"
#include "Locomotor.h"

//Set default
Locomotor::Locomotor()
{
	new_maxSpeed = 0.0;		
	new_PowerConsumed = 0.0;
}

Locomotor::Locomotor(double maxSpeed)
{
	new_maxSpeed = maxSpeed;
}

Locomotor::~Locomotor()
{
	
}

void Locomotor::setMaxSpeed(double maxSpeed)
{
	new_maxSpeed = maxSpeed;
	
}

void Locomotor::setPowerConsumed(double power)
{
	new_PowerConsumed = power;

}