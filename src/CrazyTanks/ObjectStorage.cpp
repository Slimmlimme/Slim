#include "stdafx.h"
#include "ObjectStorage.h"

ObjectStorage::ObjectStorage()
{
}

char 
ObjectStorage::getObjectSymbol(Point & point)
{
	std::vector<std::string> field = field_.getField();
	std::string row = field[point.getY()];
	return row[point.getX()];
}

void 
ObjectStorage::collide(const char & objectHit,const Point & objectPoint,const bool& playerBullet)
{
	switch (objectHit){
	case '#':
		for (int i = 0; i < sizeOfWalls(); i++) {
			Wall _wall = getWall(i);
			if (_wall.getPoint().getX() == objectPoint.getX() && _wall.getPoint().getY() == objectPoint.getY()) {
				_wall.getHurt();
				wall(i, _wall);
			}
			
		}
		break;
	case '¹':
		if (playerBullet) {
			for (int i = 1; i < sizeOfTanks(); i++) {
				Tank enemy = getTank(i);
				if (enemy.getPoint().getX() == objectPoint.getX() && enemy.getPoint().getY() == objectPoint.getY()) {
					enemy.getHurt();
					tank(i, enemy);
					int score = info_.getScore();
					info_.score(score++);
				}
			}
		}
		break;
	case '@':
		if (!playerBullet) {
			for (int i = 1; i < sizeOfFortress(); i++) {
				Wall wall = getFortressWall(i);
				if (wall.getPoint().getX() == objectPoint.getX() && wall.getPoint().getY() == objectPoint.getY()) {
					wall.getHurt();
					fortressWall(i, wall);
				}
			}
		}
		break;
	case '%':
		if (!playerBullet) {
			Tank player = getTank(getPlayerTankIndex());
			player.getHurt();
			tank(getPlayerTankIndex(), player);
			info_.playerHealth(getTank(getPlayerTankIndex()).getHealth());
		}
		break;
	case '$':
		if (!playerBullet) {
			Gold _gold = getGold();
			_gold.getHurt();
			gold(_gold);
		}
	}
}

const Field& 
ObjectStorage::getField() const
{
	return field_;
}

void 
ObjectStorage::field(Field & square)
{
	field_ = square;
}

const Tank& 
ObjectStorage::getTank(const int & index) const
{
	return tanks_[index];
}

void 
ObjectStorage::tank(const int & index, const Tank & tank)
{
	if(index < tanks_.size())
		tanks_[index] = tank;
	else tanks_.push_back(tank);
}

const int& 
ObjectStorage::sizeOfWalls() const
{
	return walls_.size();
}

const int& 
ObjectStorage::sizeOfTanks() const
{
	return tanks_.size();
}

const int& 
ObjectStorage::sizeOfBullets() const
{
	return bullets_.size();
}

const int & ObjectStorage::sizeOfFortress() const
{
	return fortress_.size();
}

void 
ObjectStorage::deleteBullet(const int & index)
{
	if (index < sizeOfBullets())
		bullets_.erase(bullets_.begin() + index);
}

void 
ObjectStorage::deleteTank(const int & index)
{
	if (index < sizeOfTanks())
		tanks_.erase(tanks_.begin() + index);
}

void 
ObjectStorage::deleteWall(const int & index)
{
	if (index < sizeOfWalls())
		walls_.erase(walls_.begin() + index);
}

void 
ObjectStorage::deleteFortressWall(const int & index)
{
	if (index < getFortressWallsAmount())
		fortress_.erase(fortress_.begin() + index);
}

const Bullet& 
ObjectStorage::getBullet(const int & index) const
{
		return bullets_[index];
}

void 
ObjectStorage::bullet(const int & index, const Bullet & bullet)
{
	if (index < bullets_.size())
		bullets_[index] = bullet;
	else bullets_.push_back(bullet);
}

void 
ObjectStorage::wall(const int & index, const Wall & wall)
{
	if(index < walls_.size())
		walls_[index] = wall;
	else walls_.push_back(wall);
}

const Wall& 
ObjectStorage::getFortressWall(const int & index) const
{
	return fortress_[index];
}

void 
ObjectStorage::fortressWall(const int & index, Wall & wall)
{
	if(index < fortress_.size())
		fortress_[index] = wall;
	else fortress_.push_back(wall);
}

const Gold& 
ObjectStorage::getGold() const
{
	return gold_;
}

void 
ObjectStorage::gold(const Gold & gold)
{
	gold_ = gold;
}

const Info& 
ObjectStorage::getInfo() const
{
	return info_;
}

void 
ObjectStorage::info(const Info & info)
{
	info_ = info;
}

ObjectStorage::~ObjectStorage()
{
}

const Wall& 
ObjectStorage::getWall(const int & index) const
{
	return walls_[index];
}
