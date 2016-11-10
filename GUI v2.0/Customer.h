#pragma once

#include<string>
#include<iostream>

using namespace std;

class Customer
{
public:
	Customer();
	~Customer();

	//Getter
	string getname();
	
	bool is_active(string user);

private:
	string name;
};

