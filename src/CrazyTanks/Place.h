#include <vector>
#include <string>
#ifndef H_PLACE
#define H_PLACE

class Place
{
public:
	virtual std::vector<std::string> place(std::vector<std::string>& square) = 0;
};
#endif // !H_PLACE