#include "stdafx.h"
#include "Gold.h"

Gold::Gold()
{
}

Gold::Gold(int x, int y, char symbol):Object(x,y,symbol)
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

Gold::~Gold()
{
}

std::vector<std::string> Gold::place(std::vector<std::string>& field)
{
	std::vector<std::string> _field = field;
	_field[getPoint().getY()][getPoint().getX()] = getBackgroundSymbol();
	_field[getPoint().getY()][getPoint().getX()] = getSymbol();
	return _field;
}
