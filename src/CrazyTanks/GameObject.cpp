#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(int& x, int& y, char& symbol)
{
	point_ = Point(x,y);
	pointOld_ = Point(x,y);
	symbol_ = symbol;
}

const Point& GameObject::getPoint() const
{
	return point_;
}

void GameObject::point(const int& x, const int& y)
{
	point_.x(x);
	point_.y(y);
}

const Point& GameObject::getPointOld() const
{
	return pointOld_;
}

void GameObject::pointOld(const int& x, const int& y)
{
	pointOld_.x(x);
	pointOld_.y(y);
}

const char& GameObject::getSymbol() const
{
	return symbol_;
}

GameObject::~GameObject()
{
}
