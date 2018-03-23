#pragma once
#include "Director.h"
#include "Drawer.h"
#include "ObjectStorage.h"
#include "GameObjectStorageBuilder.h"
#include "Constants.h"
#define PLAYER objectStorage_.getTank(getPlayerTankIndex())
#define STORAGE objectStorage_

class Game
{
public:
	Game();
	void run();
	void placeObjects();
private:
	Director director_;
	Drawer drawer_;
	ObjectStorage objectStorage_;
	bool gameOver_;
	std::string text_;
};
