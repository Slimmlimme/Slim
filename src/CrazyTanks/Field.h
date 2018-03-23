#pragma once
#include <vector>
#include <string>
#include "Constants.h"

class Field
{
public:
	Field();
	Field(int length, int height);
	const std::vector<std::string>& getField() const;
	void field(const std::vector<std::string>& field);
	~Field();
private:
	std::vector<std::string> field_;
	int length_;
	int height_;
};