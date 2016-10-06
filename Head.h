#pragma once
#include <iostream>
#include<string>
using namespace std;

class Head
{
public:
	Head();
	~Head();

	//Getter Function
	string getType();

private:
	string Type;
};

