#include "stdafx.h"
#include "Game.h"

Game::Game()
{
}

void 
Game::run()
{
	GameObjectStorageBuilder builder;
	objectStorage_ = director_.createObjectStorage(builder);
	placeObjects();
	drawer_ = Drawer (objectStorage_.getField(), objectStorage_.getInfo());
	gameOver_ = false;
	while (!gameOver_){
		placeObjects();
		Field field = objectStorage_.getField();
		drawer_.field (field);
		Info info = objectStorage_.getInfo();
		drawer_.info (info);
		drawer_.draw();
		std::vector<std::string> _field = field.getField();
		for (int i = getArrayBeginIndex(); i < objectStorage_.sizeOfTanks(); i++){
			Tank tank = objectStorage_.getTank(i);
			int x = tank.getPoint().getX();
			int y = tank.getPoint().getY();
			switch (tank.getDirection()) {
			case 1 :
				y--;
				break;
			case 2 :
				x++;
				break;
			case 3 :
				y++;
				break;
			case 4 :
				x--;
				break;
			default :
				break;
			}
			if (tank.behavior (field.getField(), PLAYER.getPoint().getX(), PLAYER.getPoint().getY(), STORAGE.getGold().getPoint().getX(), STORAGE.getGold().getPoint().getY())) {
				int _x = tank.getPoint().getX();
				int _y = tank.getPoint().getY();
				Bullet bullet(tank.getDirection(), _x, _y, tank.isPlayer(), getEnemySymbol());
				STORAGE.bullet(getMaxNumberOfBullets(), bullet);
			}
			if (_field[y][x] == getEnemySymbol() ||
				_field[y][x] == getPlayerSymbol() ||
				_field[y][x] == getWallSymbol() ||
				_field[y][x] == getBorderSymbol() ||
				_field[y][x] == getGoldSymbol() ||
				_field[y][x] == getFortressSymbol()) {
				tank.canMove(false);
			}
			else tank.canMove(true);
			STORAGE.tank(i, tank);
		}
		for (int i = getArrayBeginIndex(); i < STORAGE.sizeOfBullets();) {
			Bullet bullet = STORAGE.getBullet(i);
			int x = bullet.getPoint().getX();
			int y = bullet.getPoint().getY();
			switch (bullet.getDirection()) {
			case 1 :
				y--;
				break;
			case 2 :
				x++;
				break;
			case 3 :
				y++;
				break;
			case 4 :
				x--;
				break;
			default :
				break;
			}
			if (bullet.collision()) {
				Point point{x, y};
				STORAGE.collide (STORAGE.getObjectSymbol (point), point,bullet.isPlayerBullet());
				_field = bullet.place (_field);
				STORAGE.deleteBullet(i);
			}
			else {
				if ((_field[y][x] == getEnemySymbol() && bullet.isPlayerBullet()) ||
					(_field[y][x] == getPlayerSymbol() && !bullet.isPlayerBullet()) ||
					_field[y][x] == getWallSymbol() ||
					_field[y][x] == getBorderSymbol() ||
					_field[y][x] == getGoldSymbol() ||
					_field[y][x] == getFortressSymbol()) {
					bullet.canMove(false);
				}
				else bullet.canMove(true);
				bullet.move();
				STORAGE.bullet (i, bullet);
				i++;
			}
		}
		STORAGE.field (field);
		info.playerHealth(PLAYER.getHealth());
		info.score(6 - STORAGE.sizeOfTanks());
		objectStorage_.info (info);
	}
	std::cout << std::endl << text_ << std::endl;
}

void 
Game::placeObjects()
{
	Field field = objectStorage_.getField();
	std::vector<std::string> _field = field.getField();

	//place walls
	for (int i = getArrayBeginIndex(); i < objectStorage_.sizeOfWalls(); i++){
		
		Wall wall = objectStorage_.getWall(i);
		_field = wall.place (_field);
		if (wall.getHealth() == 0) {
			objectStorage_.deleteWall(i);
			if (i > 0)
				i--;
		}
	}

	//place gold
	Gold gold = objectStorage_.getGold();
	_field = gold.place(_field);
	if (gold.getHealth() == 0){
		gameOver_ = true;
		text_ = "You lost(";
	}

	//place fortress
	for (int i = getArrayBeginIndex(); i < objectStorage_.sizeOfFortress(); i++){
		Wall wall = objectStorage_.getFortressWall(i);
		_field = wall.place (_field);
		if (wall.isDestroyed()) {
			objectStorage_.deleteFortressWall(i);
			if (i > 0)
				i--;
		}
	}

	//place bullet
	if (objectStorage_.sizeOfBullets() != 0) {
		for (int i = getArrayBeginIndex(); i < objectStorage_.sizeOfBullets(); i++) {
			Bullet bullet = objectStorage_.getBullet(i);
			_field = bullet.place (_field);
		}
	}

	//place player
	Tank player = objectStorage_.getTank(getPlayerTankIndex());
	_field = player.place (_field);
	if (!objectStorage_.getTank(getPlayerTankIndex()).isAlive()) {
		gameOver_ = true;
		text_ = "You lost(";
	}

	//place enemies
	for (int i = getEnemyTankBeginIndex(); i < objectStorage_.sizeOfTanks(); i++){
		Tank enemy = objectStorage_.getTank(i);
		_field = enemy.place (_field);
		if (!enemy.isAlive()) {
			objectStorage_.deleteTank(i);
			if (i > 1)
				i--;
		}
	}
	if (objectStorage_.sizeOfTanks() == 1 && objectStorage_.getTank(getPlayerTankIndex()).isPlayer()) {
		gameOver_ = true;
		text_ = "You won!";
	}


	field.field (_field);
	objectStorage_.field (field);
}
