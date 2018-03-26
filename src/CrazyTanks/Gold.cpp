#include "stdafx.h"
#include "Gold.h"

Gold::Gold()
{
}

Gold::Gold(const int& x, const int& y, const char& symbol) : Object(x, y, symbol)
{
	health_ = getGoldHealth();
}

void 
Gold::getHurt()
{
	health_--;
}

const int& 
Gold::getHealth() const
{
	return health_;
}

const bool Gold::isAlive() const
{
	if (health_ > 0)
		return true;
	else return false;
}

Gold::~Gold()
{
}

std::vector<std::string> 
Gold::place(const std::vector<std::string>& field)
{
	std::vector<std::string> _field = field;
	_field[getPoint().getY()][getPoint().getX()] = getSymbol();
	return _field;
}
