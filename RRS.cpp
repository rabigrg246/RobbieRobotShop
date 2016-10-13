/*
Robbie Robot Shop
Anil Poudel & Rabi Gurung
CSE 1325 Fall 2016
*/

#include "stdafx.h"
#include <iostream>
#include "Robot_Parts.h"
#include "Menu_Items.h"
using namespace std;

//Main Function
int main()
{
	Menu_Items Menu;
	char ch='A';

	while (ch)
	{
	
		cout << "\n\n\t*************** ROBBIE ROBOT SHOP ***************" << endl;
		cout << "\t***************     Main Menu     ***************" << endl;

		cout << "\t1. (N)ew Shop" << endl;
		cout << "\t2. (L)og In As" << endl;
		cout << "\t3. (R)eports" << endl;
		cout << "\t4. (Q)uit" << endl;

		cout << "\nEnter your choice: ";
		cin >> ch;


		ch = toupper(ch);

		switch (ch)
		{
		case 'N':
			Menu.CreateMenu();
			break;

		case 'L':
			Menu.LoginMenu();
			break;

		case 'R':
			break;
		
		case 'Q':
			exit(0);
		}
	}

	return 0;
}