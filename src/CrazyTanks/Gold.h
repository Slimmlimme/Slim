#pragma once
#include "Object.h"
#include "Constants.h"

class Gold : public Object, Place
{
public:
	Gold();
	Gold(int x, int y, char symbol);
	void getHurt();
	const int& getHealth() const;
	~Gold();
	std::vector<std::string> place(std::vector<std::string>& square);
private:
	int health_;
};