#include "stdafx.h"
#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::Projectile(int& direction, int& x, int& y, bool& playerProjectile, char& symbol) : GameObject(x,y,symbol)
{
	direction_ = direction;
	playerProjectile_ = playerProjectile;
}

void Projectile::move()
{
	switch (direction_)
	{
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

bool Projectile::collision()
{
	return false;
}

bool Projectile::isPlayerProjectile()
{
	return playerProjectile_;
}

Projectile::~Projectile()
{
}

std::vector<std::string> Projectile::place(std::vector<std::string>& square)
{
	return std::vector<std::string>();
}
