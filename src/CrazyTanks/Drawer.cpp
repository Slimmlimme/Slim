#include "stdafx.h"
#include "Drawer.h"

Drawer::Drawer()
{
}

Drawer::Drawer(const Field& field, const Info& info)
{
	field_ = field;
	info_ = info;
}

void 
Drawer::field(const Field& field)
{
	field_ = field;
}

void 
Drawer::info(const Info& info)
{
	info_ = info;
}

void 
Drawer::draw()
{
	system("cls");
	for (int i = 0; i < getFieldHeight(); i++){
		for (int j = 0; j < getFieldLength(); j++){
			std::cout << field_.getField()[i][j];
		}
		std::cout << std::endl;
	}
	info_.currentTime (clock());
	std::cout << "Score: " << info_.getScore() << " Lives: " << info_.getPlayerHealth() << " Game time: " << info_.getTime()/1000;
}
