#include "Object.h"
#include <conio.h>
#include <cmath>
#include <ctime>
#ifndef H_TANK
#define H_TANK

class Tank : public Object, Place
{
public:
	Tank();
	Tank(const int& health, const int& x, const int& y, const char& symbol, const bool isPlayer);
	const bool isAlive() const;
	const int& getHealth() const;
	void getHurt();
	void move();
	bool isReadyForAction();
	bool behavior(const std::vector<std::string>& field, const int& xPlayer, const int& yPlayer, const int& xGold, const int& yGold);
	bool shoot();
	void canMove(const bool& canMove);
	const bool& isPlayer() const;
	const int& getDirection() const; 
	~Tank();
	std::vector<std::string> place(const std::vector<std::string>& field);
private:
	bool canMove_;
	bool isPlayer_;
	int health_;
	int direction_;
	int cooldown_;
};
#endif // !H_TANK