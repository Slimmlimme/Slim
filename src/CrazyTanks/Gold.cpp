#include "stdafx.h"
#include "Gold.h"

Gold::Gold()
{
}

Gold::Gold(int & x, int & y, char & symbol):GameObject(x,y,symbol)
{
}

bool Gold::getHurt()
{
	return true;
}

Gold::~Gold()
{
}

std::vector<std::string> Gold::place(std::vector<std::string>& square)
{
	return std::vector<std::string>();
}
