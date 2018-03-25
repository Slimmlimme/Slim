#include "Point.h"
#include "Place.h"
#include <vector>
#include <string>
#include <memory>
#include "Constants.h"
#ifndef H_OBJECT
#define H_OBJECT

class Object
{
public:
	Object();
	Object(const int& x, const int& y, const char& symbol);
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
#endif // !H_OBJECT