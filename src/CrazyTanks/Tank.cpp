#include "stdafx.h"
#include "Tank.h"

Tank::Tank()
{
}

Tank::Tank(int health, int x, int y, char symbol) : GameObject(x, y, symbol)
{
	health_ = health;
}


const int& Tank::getHealth() const
{
	return health_;
}

void Tank::getHurt()
{
	health_--;
}

void Tank::move()
{
	switch (direction_)
	{
	case 1:
		point(getPoint().getX(),getPoint().getY() - 1);
		break;
	case 2:
		point(getPoint().getX() + 1, getPoint().getY());
		break;
	case 3:
		point(getPoint().getX(), getPoint().getY() + 1);
		break;
	case 4:
		point(getPoint().getX() - 1, getPoint().getY());
		break;
	}
}

bool Tank::behavior(std::vector<std::string> square, int xPlayer, int yPlayer, int xGold, int yGold)
{
	return false;
}

bool Tank::shoot()
{
	return true;
}

int Tank::getDirection()
{
	return direction_;
}

Tank::~Tank()
{
}

std::vector<std::string> Tank::place(std::vector<std::string>& square)
{
	return square;
}
