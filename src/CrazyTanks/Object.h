#pragma once
#include "Point.h"
#include "Place.h"
#include <vector>
#include <string>
#include <memory>
#include "Constants.h"

class Object
{
public:
	Object();
	Object(int& x, int& y, char& symbol);
	const Point& getPoint() const;
	void point(const int& x, const int& y);
	const Point& getPointOld() const;
	void pointOld(const int& x, const int& y);
	const char& getSymbol() const;
	virtual ~Object();
private:
	Point point_;
	Point pointOld_;
	char symbol_;
};