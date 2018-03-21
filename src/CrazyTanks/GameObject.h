#pragma once
#include "Point.h"
#include "Place.h"
#include <vector>
#include <string>
#include <memory>

class GameObject
{
public:
	GameObject();
	GameObject(int& x, int& y, char& symbol);
	const Point& getPoint() const;
	void point(const int& x, const int& y);
	const Point& getPointOld() const;
	void pointOld(const int& x, const int& y);
	const char& getSymbol() const;
	virtual ~GameObject();
private:
	Point point_;
	Point pointOld_;
	char symbol_;
};