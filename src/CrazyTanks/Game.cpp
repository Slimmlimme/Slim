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
	drawer_ = Drawer(objectStorage_.getField(), objectStorage_.getInfo());
	gameOver_ = false;
	while (!gameOver_){
		placeObjects();
		Field field = objectStorage_.getField();
		drawer_.field(field);
		Info info = objectStorage_.getInfo();
		drawer_.info(info);
		drawer_.draw();
		std::vector<std::string> _field = field.getField();
		for (int i = 0; i < objectStorage_.sizeOfTanks(); i++){
			Tank tank = objectStorage_.getTank(i);
			int x = tank.getPoint().getX();
			int y = tank.getPoint().getY();
			if (tank.behavior(field.getField(), PLAYER.getPoint().getX(), PLAYER.getPoint().getX(),STORAGE.getGold().getPoint().getX(),STORAGE.getGold().getPoint().getY())) {
				int _x = x;
				int _y = y;
				switch (tank.getDirection()) {
				case 1:
					_y--;
					break;
				case 2:
					_x++;
					break;
				case 3:
					_y++;
					break;
				case 4:
					_x--;
					break;
				}
				Bullet bullet(tank.getDirection(), _x, _y, getEnemySymbol(), tank.isPlayer());
				STORAGE.bullet(getMaxNumberOfBullets(), bullet);
			}
			switch (tank.getDirection()) {
			case 1:
				y--;
				break;
			case 2:
				x++;
				break;
			case 3:
				y++;
				break;
			case 4:
				x--;
				break;
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
		for (int i = 0; i < STORAGE.sizeOfBullets(); i++) {
			Bullet bullet = STORAGE.getBullet(i);
			int x = bullet.getPoint().getX();
			int y = bullet.getPoint().getY();
			switch (bullet.getDirection()) {
			case 1:
				y--;
				break;
			case 2:
				x++;
				break;
			case 3:
				y++;
				break;
			case 4:
				x--;
				break;
			}
			if (bullet.collision()&& i > 0) {
				Point point(x, y);
				STORAGE.collide(STORAGE.getObjectSymbol(point),point,bullet.isPlayerBullet());
				STORAGE.deleteBullet(i);
				if(i > 0)
					i--;
			}
			if (_field[y][x] == getEnemySymbol() ||
				_field[y][x] == getPlayerSymbol()||
				_field[y][x] == getWallSymbol() ||
				_field[y][x] == getBorderSymbol() ||
				_field[y][x] == getGoldSymbol() ||
				_field[y][x] == getFortressSymbol()) {
				bullet.canMove(false);
			}
			else bullet.canMove(true);
			bullet.move();
			STORAGE.bullet(i, bullet);
		}
		STORAGE.field(field);
		if (PLAYER.getHealth() == 0)
			gameOver_ = true;
		info.playerHealth(PLAYER.getHealth());
		info.score(6 - objectStorage_.sizeOfTanks());
		objectStorage_.info(info);
	}
	std::cout << std::endl << text_ << std::endl;
}

void 
Game::placeObjects()
{
	Field field = objectStorage_.getField();
	std::vector<std::string> _field = field.getField();

	//place walls
	for (int i = 0; i < objectStorage_.sizeOfWalls(); i++){
		
		Wall wall = objectStorage_.getWall(i);
		_field = wall.place(_field);
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
	for (int i = 0; i < objectStorage_.sizeOfFortress(); i++){
		Wall wall = objectStorage_.getFortressWall(i);
		_field = wall.place(_field);
		if (wall.getHealth() == 0) {
			objectStorage_.deleteFortressWall(i);
			if (i > 0)
				i--;
		}
	}

	//place player
	Tank player = objectStorage_.getTank(getPlayerTankIndex());
	_field = player.place(_field);
	if (player.getHealth() == 0) {
		gameOver_ = true;
		text_ = "You lost(";
	}

	//place enemies
	for (int i = 1; i < objectStorage_.sizeOfTanks(); i++){
		Tank enemy = objectStorage_.getTank(i);
		_field = enemy.place(_field);
		if (enemy.getHealth() == 0) {
			objectStorage_.deleteTank(i);
			if (i > 1)
				i--;
		}
	}
	if (objectStorage_.sizeOfTanks() == 1 && objectStorage_.getTank(getPlayerTankIndex()).isPlayer()) {
		gameOver_ = true;
		text_ = "You won!";
	}


	//place bullet
	if (objectStorage_.sizeOfBullets() != 0){
		for (int i = 1; i < objectStorage_.sizeOfBullets(); i++){
			Bullet bullet = objectStorage_.getBullet(i);
			_field = bullet.place(_field);
		}
	}

	field.field(_field);
	objectStorage_.field(field);
}
