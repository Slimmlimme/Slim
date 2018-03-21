#pragma once

class Point
{
public:
	Point();
	Point(int& x, int& y);
	const int& getX() const;
	const int& getY() const;
	void x(const int& x);
	void y(const int& y);
private:
	int x_;
	int y_;
};