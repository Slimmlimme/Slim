#include "Object.h"
#ifndef WALL_H
#define WALL_H

class Wall: public Object, Place
{
public:
	Wall();
	Wall(const int health, const int x, const int y, const char symbol);
	const int getHealth() const;
	void getHurt();
	bool isDestroyed();
	~Wall();
	std::vector<std::string> place(const std::vector<std::string>& field);
private:
	int health_;
};
#endif
