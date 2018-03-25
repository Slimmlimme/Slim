#include "Object.h"
#ifndef WALL_H
#define WALL_H

class Wall: public Object, Place
{
public:
	Wall();
	Wall(int health, int x, int y, char symbol);
	const int& getHealth() const;
	void getHurt();
	bool isDestroyed();
	~Wall();
	std::vector<std::string> place(std::vector<std::string>& field);
private:
	int health_;
};
#endif
