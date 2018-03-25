#include "Object.h"
#include <conio.h>
#include <cmath>
#ifndef H_TANK
#define H_TANK

class Tank : public Object, Place
{
public:
	Tank();
	Tank(int health, int x, int y, char symbol,bool isPlayer);
	const int& getHealth() const;
	void getHurt();
	void move();
	bool behavior(const std::vector<std::string>& field, const int& xPlayer, const int& yPlayer, const int& xGold, const int& yGold);
	bool shoot();
	void canMove(const bool& canMove);
	const bool& isPlayer() const;
	const int& getDirection() const; 
	~Tank();
	std::vector<std::string> place(std::vector<std::string>& field);
private:
	bool canMove_;
	bool isPlayer_;
	int health_;
	int direction_;
};
#endif // !H_TANK