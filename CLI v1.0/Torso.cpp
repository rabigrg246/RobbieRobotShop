#include "stdafx.h"
#include "Torso.h"

//Set default
Torso::Torso()
{
	new_Compartments = 1;
}

Torso::Torso(int num_compart)
{
	new_Compartments = num_compart;
}

Torso::~Torso()
{

}

void Torso::setCompartments(int num_compart)
{
	new_Compartments = num_compart;

}

int Torso::getCompartments()
{
	return new_Compartments;
}

string Torso::getType()
{
	return Type;
}