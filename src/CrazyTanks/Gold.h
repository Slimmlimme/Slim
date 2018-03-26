#include "Object.h"
#include "Constants.h"
#ifndef H_GOLD
#define H_GOLD

class Gold : public Object, Place
{
public:
	Gold();
	Gold(const int& x, const int& y, const char& symbol);
	void getHurt();
	const int& getHealth() const;
	const bool isAlive() const;
	~Gold();
	std::vector<std::string> place(const std::vector<std::string>& field);
private:
	int health_;
};
#endif // !H_GOLD