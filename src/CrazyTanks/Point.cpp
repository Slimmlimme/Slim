#include "stdafx.h"
#include "Point.h"


Point::Point()
{
}

Point::Point(int& x, int& y)
{
	x_ = x;
	y_ = y;
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
Point::x(const int& x)
{
	x_ = x;
}

void 
Point::y(const int& y)
{
	y_ = y;
}


