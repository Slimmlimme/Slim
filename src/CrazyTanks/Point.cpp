#include "stdafx.h"
#include "Point.h"


Point::Point()
{
}

Point::Point(const std::initializer_list<int>& coords)
{
	auto it = coords.begin();
	x_ = *it;
	it++;
	y_ = *it;
}

const int& 
Point::getX() const
{
	return x_;
}

const int& 
Point::getY() const
{
	return y_;
}

void 
Point::setX(const int& x)
{
	x_ = x;
}

void 
Point::y(const int& y)
{
	y_ = y;
}


