#pragma once
#include "Object.h"
#include <conio.h>
#include <cmath>

class Tank : public Object, Place
{
public:
	Tank();
	Tank(int health, int x, int y, char symbol,bool isPlayer);
	const int& getHealth() const;
	void getHurt();
	void move();
	bool behavior(std::vector<std::string> field, int xPlayer, int yPlayer, int xGold, int yGold);
	bool shoot();
	void canMove(const bool& canMove);
	const bool& isPlayer() const;
	const int& getDirection() const;
	~Tank();
	std::vector<std::string> place(std::vector<std::string>& field);
private:
	bool canMove_;
	bool isPlayer_;
	int health_;
	int direction_;
};