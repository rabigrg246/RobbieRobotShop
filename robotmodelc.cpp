#include <iostream>
#include <string>

#include "torso.h"
#include "locomotor.h"
#include "arm.h"
#include "battery.h"
#include "head.h"

using namespace std;

int main() {

	string name, type, description;
	int partnumber=0,speed=0,power=0,power1=0, battery_compartment=0,energy=0;
	double weight=0.0, cost=0.0;
	char ch;
	
	cout << "Enter the name of the Robot : ";
	cin >> name;
	cout << "Enter the partnumber: ";
	cin >> partnumber;
	cout << "(T)orso" << endl << "(H)ead" << endl << "(L)ocomotor" << endl << "(A)rm" << endl << "(B)attery" << endl;
	cout << "Choose the type of the robot component(i.e. 'T' for torso): ";
	cin >> ch;
	
	if (ch == 'T')
	{
		type = "torso";
		cout << "Enter the number of battery compartment(1 to 3): ";
		cin >> battery_compartment;
		cout << "Enter the weight of the robot component: ";
		cin >> weight;
		cout << "Enter the cost oof the robot component: ";
		cin >> cost;
		cout << "Enter the description of the robot: ";
		cin >> description;
		cout << endl;



		torso newtorso(name, partnumber, type, battery_compartment, weight, cost, description);
		cout << "Name: " << newtorso.getname() << endl;
		cout << "PartNumber: " << newtorso.getpartnumber() << endl;
		cout << "Type: " << newtorso.gettype() << endl;
		cout << "Number of battery compartment: " << newtorso.getcompartment() << endl;
		cout << "Weight: " << newtorso.getweight() << endl;
		cout << "Cost: " << newtorso.getcost() << endl;
		cout << "Description: " << newtorso.getdescription() << endl;

	}
	else if (ch == 'H')
	{
		type = "head";

		cout << "Enter the weight of the robot component: ";
		cin >> weight;
		cout << "Enter the cost oof the robot component: ";
		cin >> cost;
		cout << "Enter the description of the robot: ";
		cin >> description;
		cout << endl;

		head newhead(name, partnumber, type, weight, cost, description);
		cout << "Name: " << newhead.getname() << endl;
		cout << "PartNumber: " << newhead.getpartnumber() << endl;
		cout << "Type: " << newhead.gettype() << endl;
		cout << "Weight: " << newhead.getweight() << endl;
		cout << "Cost: " << newhead.getcost() << endl;
		cout << "Description: " << newhead.getdescription() << endl;
		
	}
	else if (ch == 'L')
	{
		type = "locomotor";
		cout << "Enter the speed of the locomotor(in mph): ";
		cin >> speed;
		cout << "Enter the power consumed by the locomotor(in watt): ";
		cin >> power;

		cout << "Enter the weight of the robot component: ";
		cin >> weight;
		cout << "Enter the cost oof the robot component: ";
		cin >> cost;
		cout << "Enter the description of the robot: ";
		cin >> description;
		cout << endl;

		locomotor newlocomotor(name, partnumber, type, speed, power, weight, cost, description);
		cout << "Name: " << newlocomotor.getname() << endl;
		cout << "PartNumber: " << newlocomotor.getpartnumber() << endl;
		cout << "Type: " << newlocomotor.gettype() << endl;
		cout << "The speed of the locomotor(in mph)" << newlocomotor.getspeed() << endl;
		cout << "The power consumed by the locomotor(in watt)" << newlocomotor.getpower() << endl;
		cout << "Weight: " << newlocomotor.getweight() << endl;
		cout << "Cost: " << newlocomotor.getcost() << endl;
		cout << "Description: " << newlocomotor.getdescription() << endl;
	}

	else if (ch == 'A')
	{
		type = "arm";
		cout << "Enter the power consumed by the arm(in watt): ";
		cin >> power1;

		cout << "Enter the weight of the robot component: ";
		cin >> weight;
		cout << "Enter the cost oof the robot component: ";
		cin >> cost;
		cout << "Enter the description of the robot: ";
		cin >> description;
		cout << endl;

		arm newarm(name, partnumber, type, power1, weight, cost, description);
		cout << "Name: " << newarm.getname() << endl;
		cout << "PartNumber: " << newarm.getpartnumber() << endl;
		cout << "Type: " << newarm.gettype() << endl;
		cout << "The power consumed by the arm(in watt)" << newarm.getpower() << endl;
		cout << "Weight: " << newarm.getweight() << endl;
		cout << "Cost: " << newarm.getcost() << endl;
		cout << "Description: " << newarm.getdescription() << endl;
	}
	else if (ch == 'B')
	{
		type = "battery";
			cout << "Enter the energy provided by the battery(in kilowatt hours): ";
			cin >>energy; 

			cout << "Enter the weight of the robot component: ";
			cin >> weight;
			cout << "Enter the cost oof the robot component: ";
			cin >> cost;
			cout << "Enter the description of the robot: ";
			cin >> description;
			cout << endl;
			

			battery newbattery(name, partnumber, type, energy, weight, cost, description);
			cout << "Name: " << newbattery.getname() << endl;
			cout << "PartNumber: " << newbattery.getpartnumber() << endl;
			cout << "Type: " << newbattery.gettype() << endl;
			cout << "The energy contained by the battery(in kilowatt per hours)" << newbattery.getenergy() << endl;
			cout << "Weight: " << newbattery.getweight() << endl;
			cout << "Cost: " << newbattery.getcost() << endl;
			cout << "Description: " << newbattery.getdescription() << endl;

		}

	return 0;
}