#pragma once
#include <vector>
#include <string>

class Place
{
public:
	virtual std::vector<std::string> place(std::vector<std::string>& square) = 0;
};