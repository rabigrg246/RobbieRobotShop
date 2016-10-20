#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef TORSO_H
#define TORSO_H


class Torso
{
public:
	//Default Constructor
	Torso();

	//Overload constructor
	Torso(int);

	//Deconstructors
	~Torso();

	// Setter Function
	void setCompartments(int num_compart);
	
	//Getter Function
	int getCompartments();
	string getType();


private:
	int new_Compartments;
	string Type;
};

#endif // !TORSO_H
