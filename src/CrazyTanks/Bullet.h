#include "Object.h"
#ifndef H_BULLET
#define H_BULLET

class Bullet : public Object
{
public:
	Bullet();
	Bullet(const int& direction,const int& x, const int& y, bool playerBullet, const char& symbol);
	void move();
	const bool& collision() const;
	bool isPlayerBullet();
	void canMove(const bool& canMove);
	const int& getDirection() const;
	~Bullet();
	std::vector<std::string> place(std::vector<std::string>& field);
private:
	bool canMove_;
	int direction_;
	bool playerBullet_;
};
#endif