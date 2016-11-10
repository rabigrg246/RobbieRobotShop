#include "Customer.h"


Customer::Customer()
{
}


Customer::~Customer()
{
}

string Customer::getname()
{
	return name;
}

bool Customer::is_active(string user)
{
	if (user == "PM" || user == "SA")
		return true;
	else
		return false;

}