#pragma once
#include <vector>
#include <string>

class Square
{
public:
	Square();
	Square(int length, int height);
	const std::vector<std::string>& getSquare() const;
	void square(const std::vector<std::string>& square);
	~Square();
private:
	std::vector<std::string> square_;
	int length_;
	int height_;
};