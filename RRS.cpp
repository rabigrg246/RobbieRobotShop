/*
Robbie Robot Shop
Anil Poudel & Rabi Gurung
CSE 1325 Fall 2016
*/

#include "stdafx.h"
#include <iostream>
#include "Robot_Parts.h";

using namespace std;
/*
//Create Function
void Create()
{
	Robot_Model Robot_1();
	char ch = 1;

	cout << "\t*************************************************" << endl;
	cout << "\t*************** ROBBIE ROBOT SHOP ***************" << endl;
	cout << "\t***************   Create Menu     ***************" << endl;
	cout << "\t*************************************************" << endl;

	cout << "\t1.1 (O)rder" << endl;
	cout << "\t1.2 (C)ustomer" << endl;
	cout << "\t1.3 (S)ales Associate" << endl;
	cout << "\t1.4 Robot (M)odel" << endl;
	cout << "\t1.4 Robot Com(P)onent" << endl;
	cout << "\t1.4 (Q)uit to Main Menu" << endl;

	while (ch)
	{
		cout << "Enter your choice: ";
		cin >> ch;

		ch = toupper(ch);

		switch (ch)
		{
		case 'O':
			cout << "Order" << ch << endl;
			break;
		case 'C':
			cout << "Customer" << ch << endl;
			break;
		case 'S':
			cout << "Sales Associate" << ch << endl;
			break;
		case 'M':
			cout << "Robot Model" << ch << endl;
			break;
		case 'P':
			cout << "Robot Component" << ch << endl;
			break;
		case 'Q':
			break;
		}
	}
}

*/

//Main Function
int main()
{
	Robot_Parts part1;
	char ch=1;
	cout << "\t*************************************************" << endl;
	cout << "\t*************** ROBBIE ROBOT SHOP ***************" << endl;
	cout << "\t***************     Main Menu     ***************" << endl;
	cout << "\t*************************************************" << endl;

	cout << "\t1. (C)reate" << endl;
	cout << "\t2. (R)eport" << endl;
	cout << "\t3. (S)ave" << endl;
	cout << "\t4. (Q)uit" << endl;

	while (ch)
	{
		cout << "Enter your choice: ";
		cin >> ch;

		ch = toupper(ch);

		switch (ch)
		{
		case 'C':
				cout << "Create RobotParts" << ch << endl;
				part1.create_Torso();

		case 'R':
				cout << "Report Menu" << ch << endl;
		case 'S':
				cout << "Save Menu" << ch << endl;
		case 'Q':
			exit(0);
		}
	}

	cin.ignore();
    return 0;
}

