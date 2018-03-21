#pragma once
#include "GameObject.h"

class Tank : public GameObject, Place
{
public:
	Tank();
	Tank(int health, int x, int y, char symbol);
	const int& getHealth() const;
	void getHurt();
	void move();
	bool behavior(std::vector<std::string> square, int xPlayer, int yPlayer, int xGold, int yGold);
	bool shoot();
	int getDirection();
	~Tank();
	std::vector<std::string> place(std::vector<std::string>& square);
private:
	int health_;
	int direction_;
};