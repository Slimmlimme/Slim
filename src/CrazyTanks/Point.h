#include <initializer_list>
#ifndef H_POINT
#define H_POINT

class Point
{
public:
	Point();
	Point(const std::initializer_list<int>& coords);
	const int getX() const;
	const int getY() const;
	void setX(const int x);
	void setY(const int y);
private:
	int x_;
	int y_;
};
#endif // !H_POINT