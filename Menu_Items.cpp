#include "stdafx.h"
#include "Menu_Items.h"

Menu_Items::Menu_Items()
{
}


Menu_Items::~Menu_Items()
{
}

//CreateMenu Function
void Menu_Items::CreateMenu()
{
	char c = 1;
	string PMname;

	while (c)
	{
		cout << "\n\n\t*************** ROBBIE ROBOT SHOP ***************" << endl;
		cout << "\t***************   Create New     ***************" << endl;

		cout << "\t1.1 (P)roduct Manager" << endl;
		cout << "\t1.2 (S)ales Associate" << endl;
		cout << "\t1.3 (C)ustomer" << endl;
		cout << "\t1.4 (Q)uit to Main Menu" << endl;

		cout << "\nEnter your choice: ";
		cin >> c;

		c = toupper(c);

		switch (c)
		{
		case 'P':
			cout << "Enter Name: ";
			cin >> PMname;
			system("cls");
			return;
		case 'S':
			system("cls");
			return;
		case 'C':
			system("cls");
			return;
		case 'Q':
			system("cls");
			return;
		}
	}
}


//LoginMenu Function
void Menu_Items::LoginMenu()
{
	char c = 1;

	while (c)
	{
		cout << "\n\n\t*************** ROBBIE ROBOT SHOP ***************" << endl;
		cout << "\t*****************   Sign In As     ******************" << endl;

		cout << "\t1.1 (P)roduct Manager" << endl;
		cout << "\t1.2 (S)ales Associate" << endl;
		cout << "\t1.3 (C)ustomer" << endl;
		cout << "\t1.4 (Q)uit to Main Menu" << endl;

		cout << "\nEnter your choice: ";
		cin >> c;

		c = toupper(c);

		switch (c)
		{
		case 'P':
			//cout << "Enter userid: ";
			//if(userid matches then call functions.)
			PMMenu();
			system("cls");
			return;
		case 'S':
			SAMenu();
			system("cls");
			return;
		case 'C':
			BCMenu();
			system("cls");
			return;
		case 'Q':
			system("cls");
			return;
		}
	}
}


//PM Menu
void Menu_Items::PMMenu()
{
	char c = 1;

	while (c)
	{
		cout << "\n\n\t*************** ROBBIE ROBOT SHOP ***************" << endl;
		cout << "\t***************   Product Manager     ***************" << endl;

		cout << "\t1.1.1 Create Robot (P)art" << endl;
		cout << "\t1.1.2 Create Robot (M)odel" << endl;
		cout << "\t1.1.3 (E)xit to Main Menu" << endl;
		cout << "\t1.1.4 (Q)uit to Desktop" << endl;

		cout << "\nEnter your choice: ";
		cin >> c;

		c = toupper(c);

		switch (c)
		{
		case 'P':
			cout << "Robot Part" << c << endl;
			break;
		case 'M':
			cout << "Robot Model" << c << endl;
			break;
		case 'E':
			system("cls");
			return;
		case 'Q':
			exit(0);
		}
	}
}

//SA Menu
void Menu_Items::SAMenu()
{
	char c = 1;

	while (c)
	{
		cout << "\n\n\t*************** ROBBIE ROBOT SHOP ***************" << endl;
		cout << "\t***************   Sales Associate     ***************" << endl;

		cout << "\t1.2.1 Create (O)rder" << endl;
		cout << "\t1.2.2 (B)ill of Sale" << endl;
		cout << "\t1.2.3 (G)enerate Report" << endl;
		cout << "\t1.2.4 (M)ain Menu" << endl;
		cout << "\t1.2.5 (Q)uit to Desktop" << endl;

		cout << "\nEnter your choice: ";
		cin >> c;

		c = toupper(c);

		switch (c)
		{
		case 'O':
			cout << "Order Robot" << c << endl;
			break;
		case 'B':
			cout << "Bill of Sale" << c << endl;
			break;
		case 'G':
			cout << "Generate Report" << c << endl;
			break;
		case 'M':
			system("cls");
			return;
		case 'Q':
			exit(0);
		}
	}
}


//Customer Menu
void Menu_Items::BCMenu()
{
	char c = 1;

	while (c)
	{
		cout << "\n\n\t*************** ROBBIE ROBOT SHOP ***************" << endl;
		cout << "\t****************   Customer Menu     ****************" << endl;

		cout << "\t1.3.1 (B)rowse Catalog" << endl;
		cout << "\t1.3.2 (V)iew My Order" << endl;
		cout << "\t1.3.3 (G)enerate My Bill" << endl;
		cout << "\t1.3.4 (M)ain Menu" << endl;
		cout << "\t1.3.5 (Q)uit to Desktop" << endl;

		cout << "\nEnter your choice: ";
		cin >> c;

		c = toupper(c);

		switch (c)
		{
		case 'B':
			cout << "Browse Catalog" << c << endl;
			break;
		case 'V':
			cout << "View My Order" << c << endl;
			break;
		case 'G':
			cout << "Generate Outstanding Bills" << c << endl;
			break;
		case 'M':
			system("cls");
			return;
		case 'Q':
			exit(0);
		}
	}
}

