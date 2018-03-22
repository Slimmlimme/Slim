#pragma once
#include "GameObject.h"

class Wall: public GameObject, Place
{
public:
	Wall();
	Wall(int health, int x, int y, char symbol);
	const int& getHealth() const;
	void getHurt();
	bool isDestroyed();
	~Wall();
	std::vector<std::string> place(std::vector<std::string>& square);
private:
	int health_;
};
