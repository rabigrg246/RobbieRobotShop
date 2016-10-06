#include "stdafx.h"
#include "Head.h"


Head::Head()
{
	Type = "Head";
}


Head::~Head()
{
}


string Head::getType()
{
	return Type;
}