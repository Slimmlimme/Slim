#pragma once
#include "GameObject.h"

class Gold : public GameObject, Place
{
public:
	Gold();
	Gold(int& x, int& y, char& symbol);
	bool getHurt();
	~Gold();
	std::vector<std::string> place(std::vector<std::string>& square);
};