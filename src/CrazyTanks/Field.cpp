#include "stdafx.h"
#include "Field.h"

Field::Field()
{
}

Field::Field(const int length, const int height)
{
	length_ = length;
	height_ = height;
	for (int i = 0; i < height_; i++){
		std::string row = "";
		for (int j = 0; j < length_; j++){
			if (i == 0 || j == 0 || i == height_ - 1 || j == length_ - 1)
				row.push_back (getBorderSymbol());
			else row.push_back (getBackgroundSymbol());
		}
		field_.push_back(row);
	}
}

const std::vector<std::string>& 
Field::getField() const
{
	return field_;
}

void 
Field::field(const std::vector<std::string>& field)
{
	field_ = field;
}

Field::~Field()
{

}
