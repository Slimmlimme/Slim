#include "stdafx.h"
#include "Object.h"

Object::Object()
{
}

Object::Object(const int& x, const int& y, const char& symbol)
{
	point_ = Point {x, y};
	pointOld_ = Point {x, y};
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
	point_.setX (x);
	point_.setY (y);
}

const Point& 
Object::getPointOld() const
{
	return pointOld_;
}

void 
Object::pointOld(const int& x, const int& y)
{
	pointOld_.setX (x);
	pointOld_.setY (y);
}

const char& 
Object::getSymbol() const
{
	return symbol_;
}

Object::~Object()
{
}
