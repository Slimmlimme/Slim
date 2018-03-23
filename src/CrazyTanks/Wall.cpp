#include "stdafx.h"
#include "Wall.h"

Wall::Wall()
{
}

Wall::Wall(int health, int x, int y, char symbol) : Object(x,y,symbol)
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
	if (health_ == 0)
		return true;
	return false;
}

Wall::~Wall()
{
}

std::vector<std::string> Wall::place(std::vector<std::string>& field)
{
	std::vector<std::string> _field = field;
	_field[getPoint().getY()][getPoint().getX()] = getBackgroundSymbol();
	_field[getPoint().getY()][getPoint().getX()] = getSymbol();
	if(health_ == 0)
		_field[getPoint().getY()][getPoint().getX()] = getBackgroundSymbol();
	return _field;
}

