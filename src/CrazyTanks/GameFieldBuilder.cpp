#include "stdafx.h"
#include "GameFieldBuilder.h"
#include <ctime>

void GameFieldBuilder::createField()
{
	buildSquare();
	buildWalls();
	buildGold();
	buildFortress();
	buildPlayer();
	buildEnemies();
}

void GameFieldBuilder::buildSquare()
{
	std::shared_ptr<Square> square(new Square(30, 20));

	field.square(*square);
}

void GameFieldBuilder::buildPlayer()
{
	std::shared_ptr<Tank> player(new Tank(3, 18, 15, '%'));

	field.player(*player);
}

void GameFieldBuilder::buildEnemies()
{
	int x, y;
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		x = rand() % 28 + 1;
		y = rand() % 13 + 1;
		std::shared_ptr<Tank> enemy(new Tank(1, x, y, '¹'));
		field.enemy(i, *enemy);
	}
}

void GameFieldBuilder::buildWalls()
{
	int x, y, health;
	srand(time(0));
	char symbol = '#';
	for (int i = 0, j = 0; i < 15; i++, j++)
	{
		x = rand() % 28 + 1;
		y = rand() % 13 + 1;
		health = rand() % 3 + 1;
		std::shared_ptr<Wall> wall(new Wall(health, x, y, symbol));
		field.wall(i, *wall);
		if (x > 1 && x < 28)
		{
			
			field.wall(j++, *std::make_shared<Wall> (new Wall(health,x+1,y,symbol));
		}
	}
}

void GameFieldBuilder::buildFortress()
{
}

void GameFieldBuilder::buildGold()
{
}
