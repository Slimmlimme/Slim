#include "stdafx.h"
#include "Field.h"

Field::Field()
{
}

char Field::getGameObjectSymbol(Point & point)
{
	return 0;
}

void Field::collide(char & gameObjectHit, Point & gameObjectPoint)
{
}

const Square & Field::getSquare() const
{
	return square_;
}

void Field::square(Square & square)
{
	square_ = square;
}

const Tank & Field::getPlayer() const
{
	return player_;
}

void Field::player(const Tank & player)
{
	player_ = player;
}

const Tank & Field::getEnemy(const int & index) const
{
	return enemies_[index];
}

void Field::enemy(const int & index, const Tank & enemy)
{
	enemies_[index] = enemy;
}

const Projectile & Field::projectile(const int & index) const
{
	return projectiles_[index];
}

void Field::projectile(const int & index, const Projectile & projectile)
{
	projectiles_[index] = projectile;
}

void Field::wall(const int & index, const Wall & wall)
{
	walls_[index] = wall;
}

const Wall & Field::getFortressWall(const int & index) const
{
	return fortress_[index];
}

void Field::fortressWall(const int & index, Wall & wall)
{
	fortress_[index] = wall;
}

const Gold & Field::getGold() const
{
	return gold_;
}

void Field::gold(const Gold & gold)
{
	gold_ = gold;
}

int Field::getTime(int & currentTime)
{
	currentTime_ = currentTime;
	return beginTime_ - currentTime_;
}

const int & Field::getScore() const
{
	return score_;
}

void Field::increaseScore()
{
	score_++;
}

bool Field::isGameOver()
{
	return gameOver_;
}

Field::~Field()
{
}

const Wall & Field::getWall(const int & index) const
{
	return walls_[index];
}
