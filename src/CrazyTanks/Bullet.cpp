#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(const int& direction,const int& x,const int& y, bool playerBullet,const char& symbol) : Object(x,y,symbol)
{
	direction_ = direction;
	playerBullet_ = playerBullet;
}

void 
Bullet::move()
{
	pointOld(getPoint().getX(), getPoint().getY());
	if (canMove_) {
		switch (direction_) {
		case 1:
			point(getPoint().getX(), getPoint().getY() - 1);
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
}

const bool& 
Bullet::collision() const
{
	return !canMove_;
}

bool 
Bullet::isPlayerBullet()
{
	return playerBullet_;
}

void 
Bullet::canMove(const bool & canMove)
{
	canMove_ = canMove;
}

const int& 
Bullet::getDirection() const
{
	return direction_;
}

Bullet::~Bullet()
{
}

std::vector<std::string> Bullet::place(std::vector<std::string>& field)
{
	std::vector<std::string> _field = field;
	_field[getPoint().getY()][getPoint().getX()] = getBulletSymbol();
	_field[getPointOld().getY()][getPointOld().getX()] = getBackgroundSymbol();
	return _field;
}
