#include "stdafx.h"
#include "Robot_Parts.h"
#include "Locomotor.h"
#include "Battery.h"
#include "Torso.h"
#include "Head.h"
#include "Arm.h"

Robot_Parts::Robot_Parts()
{
	Robot_Parts::name = name;
	Robot_Parts::PartsNumber = PartsNumber;
	Robot_Parts::price = price;
}

//Create a Locomotor
void Robot_Parts::create_Locomotor()
{
	Locomotor L1;
	
	double maxSpeed, power;
	cout << "Enter the maximum speed of the locomotor: ";
	cin >> maxSpeed;

	cout << "Enter the power consumption when operating: ";
	cin >> power;

	L1.setMaxSpeed(maxSpeed);
	L1.setPowerConsumed(power);
}

//Create Battery
void Robot_Parts::create_Battery()
{
	Battery B1;
	Torso Tx;

	int num = Tx.getCompartments();
	double energy[3];

	//Loop for 3 different battery compartment
	for (int i = 1; i <= num; i++)
	{
		cout << "Enter the maximum energy provided by the battery in Compartment" << i << " (kWh): ";
		cin >> energy[i - 1];
	}

	B1.setEnergy(energy);
}

//Create Arms
void Robot_Parts::create_Arm()
{
	Arm A1;
	double power[2];

	cout << "Enter the energy consumed by the LEFT arm :";
	cin >> power[0];

	cout << "Enter the energy consumed by the RIGHT arm :";
	cin >> power[1];

	A1.setPower(power);
}


//Create a Torso
void Robot_Parts::create_Torso()
{
	Torso T1;
	
	int compart, c=0;
	while (!c)
	{
		cout << "Enter the number battery compartments (1-3)";
		cin >> compart;

		//Blank line
		cout << endl;

		if (compart >= 1 && compart <= 3)
			c = 1;
	}

	T1.setCompartments(compart);
}

Robot_Parts::~Robot_Parts()
{
}
