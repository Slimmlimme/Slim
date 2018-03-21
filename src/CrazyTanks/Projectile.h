#pragma once
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile();
	Projectile(int& direction, int& x, int& y, bool& playerProjectile, char& symbol);
	void move();
	bool collision();
	bool isPlayerProjectile();
	~Projectile();
	std::vector<std::string> place(std::vector<std::string>& square);
private:
	int direction_;
	bool playerProjectile_;
};