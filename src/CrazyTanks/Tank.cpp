#include "stdafx.h"
#include "Tank.h"

Tank::Tank()
{
}

Tank::Tank(int health, int x, int y, char symbol, bool isPlayer) : Object(x, y, symbol)
{
	isPlayer_ = isPlayer;
	health_ = health;
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
		}
	}
}

bool 
Tank::behavior(std::vector<std::string> square, int xPlayer, int yPlayer, int xGold, int yGold)
{
	if (isPlayer_) {
		if (_kbhit()) {
			switch (_getch()) {
			case 72:
				move();
				direction_ = getDirectionUp();
				break;
			case 80:
				move();
				direction_ = getDirectionDown();
				break;
			case 75:
				move();
				direction_ = getDirectionLeft();
				break;
			case 77:
				move();
				direction_ = getDirectionRight();
				break;
			case 32:
				return true;
			};
		}
	} 
	return false;
	//else{
	//	int xDistanceGold, xDistancePlayer;
	//	int yDistanceGold, yDistancePlayer;
	//	xDistanceGold = getPoint().getX() - xGold;
	//	yDistanceGold = getPoint().getY() - yGold;
	//	xDistancePlayer = getPoint().getX() - xPlayer;
	//	yDistancePlayer = getPoint().getY() - yPlayer;
	//	int diagonalDistanceGold, diagonalDistancePlayer;
	//	diagonalDistanceGold = sqrt(xGold*xGold + yGold * yGold);
	//	diagonalDistancePlayer = sqrt(xPlayer*xPlayer + yPlayer * yPlayer);
	//	if (getPoint().getY() != yGold){
	//		direction_ = getDirectionDown();
	//		move();
	//	}
	//	else {
	//		if (xGold > getPoint().getX()) {
	//			direction_ = getDirectionRight();
	//			return true;
	//		}
	//		if (xGold < getPoint().getX()) {
	//			direction_ = getDirectionLeft();
	//			return true;
	//		}
	//	}
	//	/*if (getPoint().getX() == xGold || getPoint().getY() == yGold || getPoint().getX() == xPlayer || getPoint().getY() == yPlayer) {
	//		if ((getPoint().getX() - xGold > 0 && getPoint().getY() == yGold) || (getPoint().getX() - xPlayer > 0 && getPoint().getY() == yPlayer) )
	//			direction_ = getDirectionLeft();
	//		if ((getPoint().getX() - xGold < 0 && getPoint().getY() == yGold) || (getPoint().getX() - xPlayer < 0 && getPoint().getY() == yPlayer))
	//			direction_ = getDirectionRight();
	//		if ((getPoint().getY() - yGold > 0 && getPoint().getX() == xGold) || (getPoint().getY() - yPlayer > 0 && getPoint().getX() == xPlayer))
	//			direction_ = getDirectionUp();
	//		if ((getPoint().getY() - yGold < 0 && getPoint().getX() == xGold) || getPoint().getY() - yPlayer > 0 && getPoint().getX() == yPlayer)
	//			direction_ = getDirectionDown();*/

	//	//}
	//	return false();
	//}
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

std::vector<std::string> Tank::place(std::vector<std::string>& field)
{
	std::vector<std::string> _field = field;
	_field[getPointOld().getY()][getPointOld().getX()] = getBackgroundSymbol();
	_field[getPoint().getY()][getPoint().getX()] = getSymbol();
	if (health_ == 0)
		_field[getPoint().getY()][getPoint().getX()] = getBackgroundSymbol();
	return _field;
}
