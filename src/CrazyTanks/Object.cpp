#include "stdafx.h"
#include "Object.h"

Object::Object()
{
}

Object::Object(int& x, int& y, char& symbol)
{
	point_ = Point(x,y);
	pointOld_ = Point(x,y);
	symbol_ = symbol;
}

const Point& 
Object::getPoint() const
{
	return point_;
}

void 
Object::point(const int& x, const int& y)
{
	point_.x(x);
	point_.y(y);
}

const Point& 
Object::getPointOld() const
{
	return pointOld_;
}

void 
Object::pointOld(const int& x, const int& y)
{
	pointOld_.x(x);
	pointOld_.y(y);
}

const char& 
Object::getSymbol() const
{
	return symbol_;
}

Object::~Object()
{
}