#include "stdafx.h"
#include "GameObjectStorageBuilder.h"
#include <ctime>

GameObjectStorageBuilder::~GameObjectStorageBuilder()
{

}

void
GameObjectStorageBuilder::createObjectStorage()
{
	buildField();
	buildWalls();
	buildGold();
	buildFortress();
	buildPlayer();
	buildEnemies();
	
}

void 
GameObjectStorageBuilder::buildField()
{
	Field field (getFieldLength(), getFieldHeight());
	objectStorage.field (field);
}

void 
GameObjectStorageBuilder::buildPlayer()
{
	objectStorage.tank (getPlayerTankIndex(), Tank (getPlayerHealth(), getPlayerStartPositionX(), getPlayerStartPositionY(), getPlayerSymbol(), true));
}

void 
GameObjectStorageBuilder::buildEnemies()
{
	int x, y;
	srand (time(0));
	for (int i = getEnemyTankBeginIndex(); i < getEnemiesAmount()+1; i++){
		x = rand() % (getFieldEndX()) + 1;
		y = rand() % (getFieldHeight()/2) + 1;
		objectStorage.tank(i, Tank (getEnemyHealth(), x, y, getEnemySymbol(), false));
	}
}

void 
GameObjectStorageBuilder::buildWalls()
{
	int x, y, health;
	srand (time(0));
	for (int i = getArrayBeginIndex(), j = getArrayBeginIndex(); i < getWallsAmount(); i++, j++){
		x = rand() % getFieldEndX() + 1;
		y = rand() % getFieldEndY() + 1;
		health = rand() % getMaxWallHealth() + 1;
		objectStorage.wall(j, Wall(health, x, y, getWallSymbol()));
		if (x > getFieldBeginX() && x < getFieldEndX() && rand() % 2 == 0){
			j++;
			objectStorage.wall(j, Wall(health, x + 1, y, getWallSymbol()));
			j++;
			objectStorage.wall(j, Wall(health, x - 1, y, getWallSymbol()));
		}
		if (y > getFieldBeginY() && y < getFieldEndY() && rand() % 2 == 1){
			j++;
			objectStorage.wall(j, Wall(health, x, y - 1, getWallSymbol()));
			j++;
			objectStorage.wall(j, Wall(health, x, y + 1, getWallSymbol()));
		}
	}
}

void 
GameObjectStorageBuilder::buildFortress()
{
	int xWall = getGoldPositionX()-1;
	int yWall = getGoldPositionY();
	int health = getMaxWallHealth();
	for (int i = getArrayBeginIndex(); i < getFortressWallsAmount(); i++){
		switch (i){
		case 1 :
			yWall--;
			break;
		case 2 :
			xWall++;
			break;
		case 3 :
			xWall++;
			break;
		case 4 :
			yWall++;
			break;
		default :
			break;
		}
		Wall fortressWall (health, xWall, yWall, getFortressSymbol());
		objectStorage.fortressWall (i, fortressWall);
	}
}

void 
GameObjectStorageBuilder::buildGold()
{
	objectStorage.gold (Gold (getGoldPositionX(), getGoldPositionY(), getGoldSymbol()));
}

void 
GameObjectStorageBuilder::buildInfo()
{
	objectStorage.info (Info (getStartScore(), clock()));
}

const ObjectStorage& 
GameObjectStorageBuilder::getObjectStorage() const
{
	return objectStorage;
}
