#include "stdafx.h"
#include "Square.h"

Square::Square()
{
}

Square::Square(int length, int height)
{
	length_ = length;
	height_ = height;
	for (int i = 0; i < height_; i++)
	{
		std::string row = "";
		for (int j = 0; j < length_; j++)
		{
			if (i == 0 || j == 0 || i == height_ - 1 || j == length_ - 1)
				row.push_back(178);
			else row.push_back(176);
		}
		square_.push_back(row);
	}
}

const std::vector<std::string>& Square::getSquare() const
{
	return square_;
}

void Square::square(const std::vector<std::string>& square)
{
	square_ = square;
}

Square::~Square()
{
}
