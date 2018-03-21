#pragma once
#include "Tank.h"
#include "Projectile.h"
#include "Wall.h"
#include "Gold.h"
#include "Square.h"

class Field
{
public:
	Field();
	char getGameObjectSymbol(Point& point);
	void collide(char& gameObjectHit, Point& gameObjectPoint);
	const Square& getSquare() const;
	void square(Square& square);
	const Tank& getPlayer() const;
	void player(const Tank& player);
	const Tank& getEnemy(const int& index) const;
	void enemy(const int& index, const Tank& enemy);
	const Projectile& projectile(const int& index) const;
	void projectile(const int& index, const Projectile& projectile);
	const Wall& getWall(const int& index) const;
	void wall(const int& index, const Wall& wall);
	const Wall& getFortressWall(const int& index) const;
	void fortressWall(const int& index, Wall& wall);
	const Gold& getGold() const;
	void gold(const Gold& gold);
	int getTime(int& currentTime);
	const int& getScore() const;
	void increaseScore();
	bool isGameOver();
	~Field();

private:
	Square square_;
	Tank player_;
	std::vector<Tank> enemies_;
	std::vector<Projectile> projectiles_;
	std::vector<Wall> walls_;
	std::vector<Wall> fortress_;
	Gold gold_;
	int beginTime_;
	int currentTime_;
	int score_;
	bool gameOver_;
};
