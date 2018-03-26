#include "stdafx.h"
#include "Tank.h"

Tank::Tank()
{
}

Tank::Tank(const int& health, const int& x, const int& y, const char& symbol, const bool isPlayer) : Object(x, y, symbol)
{
	isPlayer_ = isPlayer;
	health_ = health;
	cooldown_ = clock();
}

const bool
Tank::isAlive() const
{
	if (health_ > 0)
		return true;
	else return false;
}


const int& 
Tank::getHealth() const
{
	return health_;
}

void 
Tank::getHurt()
{
	health_--;
}

void 
Tank::move()
{
	if (canMove_) {
		pointOld(getPoint().getX(), getPoint().getY());
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
		default:
			break;
		}
	}
}

bool 
Tank::isReadyForAction()
{
	if (clock() - cooldown_ > getActionCooldown())
		return true;
	else return false;
}

bool 
Tank::behavior(const std::vector<std::string>& square, const int& xPlayer,const int& yPlayer,const int& xGold,const int& yGold)
{
	if (isPlayer_) {
		if (_kbhit()) {
			switch (_getch()) {
			case 72:
				move();
				direction_ = getDirectionUp();
				return false;
			case 80:
				move();
				direction_ = getDirectionDown();
				return false;
			case 75:
				move();
				direction_ = getDirectionLeft();
				return false;
			case 77:
				move();
				direction_ = getDirectionRight();
				return false;
			case 32:
				return true;
			default:
				return false;
			};
		}
		else return false;
	} 
	else {
		if (isReadyForAction()) {
			cooldown_ = clock();
			int distanceXGold, distanceYGold, distanceXPlayer, distanceYPlayer;
			distanceXGold = abs(xGold - getPoint().getX());
			distanceYGold = abs(yGold - getPoint().getY());
			distanceXPlayer = abs(xPlayer - getPoint().getX());
			distanceYPlayer = abs(yPlayer - getPoint().getY());
			if (sqrt(pow(distanceXGold, 2) + pow(distanceYGold, 2)) > sqrt((pow(distanceXPlayer, 2) + pow(distanceYPlayer, 2)))) {
				if (abs(getPoint().getX() - xPlayer) <= abs(getPoint().getY() - yPlayer)) {
					if (xPlayer > getPoint().getX()) {
						direction_ = getDirectionRight();
						move();
					}
					if (xPlayer < getPoint().getX()) {
						direction_ = getDirectionLeft();
						move();
					}
					if (xPlayer == getPoint().getX()) {
						if (yPlayer >= getPoint().getY())
							direction_ = getDirectionDown();
						if (yPlayer < getPoint().getY())
							direction_ = getDirectionUp();
						return true;
					}
				}
				else {
					if (yPlayer > getPoint().getY()) {
						direction_ = getDirectionDown();
						move();
					}
					if (yPlayer < getPoint().getY()) {
						direction_ = getDirectionUp();
						move();
					}
					if (yPlayer == getPoint().getY()) {
						if (xPlayer >= getPoint().getX())
							direction_ = getDirectionRight();
						if (xPlayer < getPoint().getX())
							direction_ = getDirectionLeft();
						return true;
					}
				}
				return false;
			}
			else {
				if (abs(getPoint().getX() - xGold) <= abs(getPoint().getY() - yGold)) {
					if (xGold > getPoint().getX()) {
						direction_ = getDirectionRight();
						move();
					}
					if (xGold < getPoint().getX()) {
						direction_ = getDirectionLeft();
						move();
					}
					if (xGold == getPoint().getX()) {
						if (yGold >= getPoint().getY())
							direction_ = getDirectionDown();
						if (yGold < getPoint().getY())
							direction_ = getDirectionUp();
						return true;
					}
				}
				else {
					if (yGold > getPoint().getY()) {
						direction_ = getDirectionDown();
						move();
					}
					if (yGold < getPoint().getY()) {
						direction_ = getDirectionUp();
						move();
					}
					if (yGold == getPoint().getY()) {
						if (xGold >= getPoint().getX())
							direction_ = getDirectionRight();
						if (xGold < getPoint().getX())
							direction_ = getDirectionLeft();
						return true;
					}
				}
				return false;
			}
		}
		return false;
	}
}

bool 
Tank::shoot()
{
	return true;
}

void 
Tank::canMove(const bool& canMove)
{
	canMove_ = canMove;
}

const bool& 
Tank::isPlayer() const
{
	return isPlayer_;
}

const int& 
Tank::getDirection() const
{
	return direction_;
}

Tank::~Tank()
{
}

std::vector<std::string> 
Tank::place(const std::vector<std::string>& field)
{
	std::vector<std::string> _field = field;
	_field[getPointOld().getY()][getPointOld().getX()] = getBackgroundSymbol();
	_field[getPoint().getY()][getPoint().getX()] = getSymbol();
	if (!isAlive())
		_field[getPoint().getY()][getPoint().getX()] = getBackgroundSymbol();
	return _field;
}
