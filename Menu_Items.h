#pragma once
#include <iostream>
#include <string>
using namespace std; 

class Menu_Items
{
public:
	Menu_Items();

	void CreateMenu();
	void LoginMenu();
	void PMMenu(string, string, string);
	void SAMenu(string, string, string);
	void BCMenu(string, string);

	
	~Menu_Items();
};

