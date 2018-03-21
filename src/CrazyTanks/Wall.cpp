#include "stdafx.h"
#include "Wall.h"

Wall::Wall()
{
}

Wall::Wall(int& health, int& x, int& y, char& symbol) : GameObject(x,y,symbol)
{
	health_ = health;
}

const int& Wall::getHealth() const
{
	return health_;
}

void Wall::getHurt()
{
	health_--;
}

bool Wall::isDestroyed()
{
	if (health_ == 0)
		return true;
	return false;
}

Wall::~Wall()
{
}

std::vector<std::string> Wall::place(std::vector<std::string>& square)
{
	return std::vector<std::string>();
}

