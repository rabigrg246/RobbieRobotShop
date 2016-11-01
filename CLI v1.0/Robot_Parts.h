#pragma once

#include <string>

class Robot_Parts
{
public:
	
	//Members
	std::string name;
	int PartsNumber;
	double price;
	 

	//get name
	void create_Locomotor();
	void create_Battery();
	void create_Head();
	void create_Torso();
	void create_Arm();

	Robot_Parts();
	~Robot_Parts();
};

