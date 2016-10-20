#include "stdafx.h"
#include "Menu_Items.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>


using namespace std;


int counter = 0;

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
	string username, partfile, modelfile, orderfile, reportfile;
	fstream pm_file("PM.txt", ios::in | ios::out | ios::app);
	fstream sa_file("SA.txt", ios::in | ios::out | ios::app);
	
	while (c)
	{
		cout << "\n\n\t*************** ROBBIE ROBOT SHOP ***************" << endl;
		cout << "\t***************   Create New     ***************" << endl;

		cout << "\t1.1 (P)roduct Manager" << endl;
		cout << "\t1.2 (S)ales Associate" << endl;
		cout << "\t1.3 (Q)uit to Main Menu" << endl;

		cout << "\nEnter your choice: ";
		cin >> c;

		c = toupper(c);

		switch (c)
		{
		case 'P':
			cout << "Enter userid: ";
			cin >> username;
			partfile = username + "_part.txt";
			modelfile = username + "_model.txt";
			pm_file << username << " " << partfile << " " << modelfile << endl;
			pm_file.close();

			system("cls");
			return;
		case 'S':
			cout << "Enter userid: ";
			cin >> username;
			orderfile = username + "_order.txt";
			reportfile = username + "_report.txt";
			sa_file << username << " " << orderfile << " " << reportfile << " " << endl;
			sa_file.close();

			system("cls");
			return;
		
		case 'Q':
			pm_file.close();
			sa_file.close();
			system("cls");
			return;
		}
	}
}


//LoginMenu Function
void Menu_Items::LoginMenu()
{
	//Pre-processing
	char c = 1;
	fstream pm_file("PM.txt", ios::in | ios::out | ios::app);
	fstream sa_file("SA.txt", ios::in | ios::out | ios::app);
	string user_input, name, partfile, modelfile, orderfile, reportfile;

	//Menu
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
			cout << "Enter userid: ";
			cin >> user_input;

			//if(userid matches then call functions.
			pm_file.seekg(0);
			
			while (pm_file.good())
			{
				pm_file >> name >> partfile >> modelfile;

				if (name == user_input)
				{
					cerr << "Logged in as: " << user_input << endl;
					pm_file.close();
					PMMenu(name, partfile, modelfile);
				}
				else
				{
					counter++;
				}
			}
				
			if (counter != 0)
			{
				cerr << "User not found." << endl;
				pm_file.close();
				counter = 0;
			}
			
			cin.ignore();

			system("cls");
			return;

		case 'S':
			cout << "Enter userid: ";
			cin >> user_input;
			sa_file.seekg(0);

			while (sa_file.good())
			{
				sa_file >> name >> orderfile >> reportfile;

				if (name == user_input)
				{
					cerr << "Logged in as: " << user_input << endl;
					sa_file.close();
					SAMenu(name, orderfile, reportfile);
				}
				else
				{
					counter++;
				}
			}

			if (counter != 0)
			{
				cerr << "User not found." << endl;
				sa_file.close();
				counter = 0;
			}

			cin.ignore();

			system("cls");
			return;
		
		
		case 'C':
			cout << "Enter customer name: ";
			cin >> user_input;
			BCMenu(name, orderfile);
			system("cls");
			return;
	
		
		case 'Q':
			pm_file.close();
			sa_file.close();
			system("cls");
			return;
		}
	}
}






//PM Menu
void Menu_Items::PMMenu(string pm_name, string partfile, string modelfile)
{
	
	char c = 1;
	string partname, type, description, line, modelname;
	float weight, cost, loc_speed, loc_power, arm_power, batt_power, modelprice;
	char temp;
	int partnumber, battery_num, modelnumber;
	string pnum;
	string partarray[10] = {"-","-","-","-","-","-","-","-","-","-"};

	while (c)
	{
		fstream part_file(partfile, ios::in | ios::out | ios::app);
		fstream model_file(modelfile, ios::in | ios::out | ios::app);
		int a = 1, pc=0;
		weight = 0.0, cost = 0.0, loc_speed = 0.0, loc_power = 0.0, arm_power = 0.0, batt_power = 0.0, modelprice=0.0;
		partnumber = 0, battery_num = 0;
		pnum = "";

		cout << "\n\n\t*************** ROBBIE ROBOT SHOP ***************" << endl;
		cout << "\t***************   Product Manager     ***************" << endl;

		cout << "\t1.1.1 Create Robot (P)art" << endl;
		cout << "\t1.1.2 Create Robot (M)odel" << endl;
		cout << "\t1.1.3 (V)iew Robot Parts" << endl;
		cout << "\t1.1.4 (S)how Robot Models" << endl;
		cout << "\t1.1.5 (E)xit to Main Menu" << endl;
		cout << "\t1.1.6 (Q)uit to Desktop" << endl;

		cout << "\nEnter your choice: ";
		cin >> c;

		c = toupper(c);

		switch (c)
		{
		case 'P':
			cout << "Enter Part Name: ";
			cin >> partname;
			cout << "Enter Part Number: ";
			cin >> partnumber;
			cout << "Enter Part Type: \n\t(H)ead\n\t(T)orso\n\t(A)rm\n\t(L)ocomotor\n\t(B)attery" << endl;
			cin >> temp;
			temp = toupper(temp);

			if (temp == 'H')
				type = "Head";
			else if (temp == 'T')
			{
				type = "Torso";
				cout << "How many battery compartments (1-3): ";
				cin >> battery_num;
			}
			else if (temp == 'A')
			{
				type = "Arm";
				cout << "Enter power consumed by arm (in Watts): ";
				cin >> arm_power;
			}
			else if (temp == 'L')
			{
				type = "Locomotor";
				cout << "Enter speed of locomotor (in mph): ";
				cin >> loc_speed;

				cout << "Enter power consumed by locomotor (in Watt): ";
				cin >> loc_power;
			}
			else if (temp == 'B')
			{
				type = "Battery";
				cout << "Enter energy provided by battery (in kWh): ";
				cin >> batt_power;
			}
			else
			{
				type = "Undefined";
			}

			cout << "Enter Weight (grams): ";
			cin >> weight;

			cout << "Enter Cost ($): ";
			cin >> cost;
			cin.ignore();

			cout << "Enter Description: ";
			getline(cin, description);

			//Write to file
			part_file << partname << " " << partnumber << " " << type << " " << weight << " " << cost << " " << battery_num << " " << batt_power << " " << loc_speed << " " << loc_power << " " << arm_power << '\n';
			part_file << description << '\n';
			part_file.close();
			break;

			//Robot Model Creation
		case 'M':
			pc = 0;
			cout << "Enter Model Name: ";
			cin >> modelname;
			cout << "Enter Model Number: ";
			cin >> modelnumber;

			//save model name and number
			model_file << modelname << " " << modelnumber;

			do
			{
				cout << "Enter partname to add: ";
				cin >> pnum;

				part_file.seekg(0);

				while (getline(part_file, line))
				{
					istringstream iss(line);

					if ((a % 2) == 1)
					{
						iss >> partname >> partnumber >> type >> weight >> cost >> battery_num >> batt_power >> loc_speed >> loc_power >> arm_power;
						
						if (pnum == partname)
						{
							modelprice += cost;
							partarray[pc] = partname;
						}
					}

					a++;
				}

				if (pc > 10)
					break;
				else
				{
					cout << "Add more parts (y/n)?: ";
					cin >> temp;
					temp = toupper(temp);
				}

				
				pc++;
				//go back to beginning of file
				part_file.clear();
				part_file.seekg(0, ios::beg);

			} while (temp == 'Y');

			//save modelprice total
			model_file << " " << modelprice;
			
			//save components of model
			for (int i = 0; i < 10; i++)
			{
				model_file << " " << partarray[i];
			}
			model_file << "\n";

			part_file.close();
			model_file.close();
			break;

			//Robot Parts Display
		case 'V':
			part_file.seekg(0);

			cout << "\n\t------Viewing Parts-------\n\n";
			cout << "      PartName      PartNumber       Type         Weight       Cost    Description\n\n";

			while (getline(part_file, line))
			{
				istringstream iss(line);

				if ((a % 2) == 1)
				{
					iss >> partname >> partnumber >> type >> weight >> cost >> battery_num >> batt_power >> loc_speed >> loc_power >> arm_power;
					cout << setw(20) << left << partname << setw(15) << left << partnumber << setw(10) << left << type << setw(10) << right << weight << setw(9) << "$" << cost << "\t";
				}
				else
				{
					description = line;
					cout << setw(30) << left << description << endl;
				}
				a++;
			}
			part_file.close();
			break;

	//Show Models
		case 'S':
			model_file.seekg(0);

			cout << "\n\t------Viewing Models-------\n\n";
			cout << "     ModelName     ModelNumber   Total_Cost	 Part1    Part2    Part3    Part4     Part5    Part6   Part7   Part8   Part9  Part10\n\n";

			while (getline(model_file, line))
			{
				istringstream iss(line);
			
				iss >> modelname >> modelnumber >> modelprice;
				
				for (int i = 0; i < 10; i++)
					{
						iss >> partarray[i];
					}
				cout << setw(20) << left << modelname << setw(10) << left << modelnumber << right << setw(10) << right <<"$" << modelprice << "     ";
				for (int i = 0; i < 10; i++)
					{
						cout << setw(10) << left << partarray[i];
					}
					cout << endl;
			}
			model_file.close();
			break;


		case 'E':
			part_file.close();
			model_file.close();
			system("cls");
			return;

		case 'Q':
			part_file.close();
			model_file.close();
			exit(0);
		}
	}
}






//SA Menu
void Menu_Items::SAMenu(string name, string orderfile, string reportfile)
{
	fstream pm_file("PM.txt", ios::in | ios::out | ios::app);
	
	char c = 1;
	string temp1, temp2, temp3, temp4, partfile, modelfile, line, modelname, tempx;
	float modelprice;
	int modelnumber, ordernumber;
	string partarray[10] = { "-","-","-","-","-","-","-","-","-","-" };

	while (c)
	{
		fstream order_file(orderfile, ios::in | ios::out | ios::app);

		cout << "\n\n\t*************** ROBBIE ROBOT SHOP ***************" << endl;
		cout << "\t***************   Sales Associate     ***************" << endl;

		cout << "\t1.2.1 Create (O)rder" << endl;
		cout << "\t1.2.2 (B)ill of Sale" << endl;
		cout << "\t1.2.3 (M)ain Menu" << endl;
		cout << "\t1.2.4 (Q)uit to Desktop" << endl;

		cout << "\nEnter your choice: ";
		cin >> c;

		c = toupper(c);

		switch (c)
		{
		case 'O':
			cout << "--------Create new Order--------" << endl;

			cout << "Enter order number: ";
			cin >> ordernumber;

			cout << "Enter Robot Model Name: ";
			cin >> tempx;

			cout << "Enter Customer Name (First_Last):";
			cin >> temp2;

			cin.ignore();
			cout << "Enter Customer's Phone: ";
			cin >> temp3;

			cout << "Enter Date of Sale: ";
			cin >> temp4;
	
			pm_file.seekg(0);
			while (pm_file.good())
			{
				pm_file >> name >> partfile >> modelfile;

				fstream m_file(modelfile, ios::in | ios::out | ios::app);

				m_file.seekg(0);

				while (getline(m_file, line))
				{
					istringstream iss3(line);

					iss3 >> modelname >> modelnumber >> modelprice;

					for (int j = 0; j < 10; j++)
					{
						iss3 >> partarray[j];
					}

					if (tempx == modelname)
					{
						//save to file
						order_file << ordernumber << " " << temp2 << " " << temp3 << " " << temp4 << " "  << tempx << " " << modelprice << "\n";
					}
				}
				m_file.close();
			}
			pm_file.close();
			order_file.close();
			break;


		case 'B':
			order_file.seekg(0);
			cout << "\n\t------Bill of Sale-------\n\n";
			cout << "     Order_Number     CustomerName     PhoneNumber   Date_Of_Sale 	   Model_Name      Total_Price\n\n";

			while (getline(order_file, line))
			{
				istringstream iss(line);

				order_file >> ordernumber >> temp2 >> temp3 >> temp4 >> modelname >> modelprice;

				cout << "     " << setw(10) << left << ordernumber << setw(15) << left << temp2 << setw(10) << left << temp3 << setw(10) << left << temp4 << setw(10) << left << modelname<< setw(10) << left << modelprice << "     ";		
			}

		order_file.close();
			break;
		case 'M':
			order_file.close();
			pm_file.close();
			system("cls");
			return;
		case 'Q':
			order_file.close();
			pm_file.close();
			exit(0);
		}
	}
}


//Customer Menu
void Menu_Items::BCMenu(string name, string orderfile)
{
	char c = 1;
	string partfile, modelfile, line, modelname, temp1, temp2, temp3, temp4, user_input;
	float modelprice;
	int modelnumber, ordernumber;
	string partarray[10] = { "-","-","-","-","-","-","-","-","-","-" };

	while (c)
	{
		fstream pm_file("PM.txt", ios::in | ios::out | ios::app);
		fstream o_file(orderfile, ios::in | ios::out | ios::app);


		cout << "\n\n\t*************** ROBBIE ROBOT SHOP ***************" << endl;
		cout << "\t****************   Customer Menu     ****************" << endl;

		cout << "\t1.3.1 (B)rowse Catalog" << endl;
		cout << "\t1.3.2 (V)iew My Order" << endl;
		cout << "\t1.3.3 (M)ain Menu" << endl;
		cout << "\t1.3.4 (Q)uit to Desktop" << endl;

		cout << "\nEnter your choice: ";
		cin >> c;

		c = toupper(c);

		switch (c)
		{
		case 'B':
			pm_file.seekg(0);
			cout << "\n\t------Browse Catalog-------\n\n";
			cout << "     ModelName     ModelNumber   Total_Cost	 Part1    Part2    Part3    Part4     Part5    Part6   Part7   Part8   Part9  Part10\n\n";

			while (pm_file.good())
			{
				pm_file >> name >> partfile >> modelfile;

				fstream m_file(modelfile, ios::in | ios::out | ios::app);

				m_file.seekg(0);				
				while (getline(m_file, line))
				{
					istringstream iss(line);

					iss >> modelname >> modelnumber >> modelprice;

					for (int i = 0; i < 10; i++)
					{
						iss >> partarray[i];
					}
					cout << setw(20) << left << modelname << setw(10) << left << modelnumber << right << setw(10) << right << "$" << modelprice << "     ";

					for (int i = 0; i < 10; i++)
					{
						cout << setw(10) << left << partarray[i];
					}
					cout << endl;
				}
				m_file.close();
			}
			pm_file.close();
			break;

		case 'V':
			cout << "Enter your Name (First_Last): ";
			cin >> user_input;

			o_file.seekg(0);
			cout << "\n\t------View My Orders and Bills-------\n\n";
			cout << "     Order_Number     Customer_Name     PhoneNumber   Date_Of_Sale 	   Model_Name      Total_Cost\n\n";

			while (getline(o_file, line))
			{
				istringstream iss2(line);

				o_file >> ordernumber >> temp2 >> temp3 >> temp4 >> temp1 >> modelname >> modelprice;

				if(user_input == temp2)
					cout << setw(10) << left << ordernumber << setw(15) << left << temp2 << setw(10) << left << temp3 << setw(10) << left << temp4 << setw(10) << left << temp1 << setw(10) << left << modelname << setw(10) << left << modelprice << "     ";
			}
			o_file.close();
			break;

		case 'M':
			system("cls");
			return;
		case 'Q':
			exit(0);
		}
	}
}

