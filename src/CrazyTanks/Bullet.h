#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	Bullet(int direction, int x, int y, bool playerBullet, char symbol);
	void move();
	const bool& collision() const;
	bool isPlayerBullet();
	void canMove(const bool& canMove);
	const int& getDirection() const;
	~Bullet();
	std::vector<std::string> place(std::vector<std::string>& field);
private:
	bool canMove_;
	int direction_;
	bool playerBullet_;
};