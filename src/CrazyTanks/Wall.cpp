#include "stdafx.h"
#include "Wall.h"

Wall::Wall()
{
}

Wall::Wall(const int& health, const int& x, const int& y, const char& symbol) : Object(x, y, symbol)
{
	health_ = health;
}

const int&
Wall::getHealth() const
{
	return health_;
}

void 
Wall::getHurt()
{
	health_--;
}

bool 
Wall::isDestroyed()
{
	if (health_ <= 0)
		return true;
	return false;
}

Wall::~Wall()
{
}

std::vector<std::string> 
Wall::place(const std::vector<std::string>& field)
{
	std::vector<std::string> _field = field;
	_field[getPoint().getY()][getPoint().getX()] = getSymbol();
	if(isDestroyed())
		_field[getPoint().getY()][getPoint().getX()] = getBackgroundSymbol();
	return _field;
}

