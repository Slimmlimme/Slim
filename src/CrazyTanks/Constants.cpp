#include "stdafx.h"
#include "Constants.h"

inline int
getFieldHeight()
{
	return 20;
}

inline int
getActionCooldown()
{
	return 1500;
}

inline int
getArrayBeginIndex()
{
	return 0;
}

inline int
getFieldLength()
{
	return 30;
}

inline int
getFieldBeginX()
{
	return 1;
}

inline int
getFieldBeginY()
{
	return 1;
}

inline int
getFieldEndX()
{
	return getFieldLength() - 2;
}

inline int
getFieldEndY()
{
	return getFieldHeight() - 2;
}

inline int
getEnemyHealth()
{
	return 1;
}

inline int
getPlayerHealth()
{
	return 3;
}

inline int
getGoldHealth()
{
	return 1;
}

inline int
getDirectionUp()
{
	return 1;
}

inline int
getDirectionRight()
{
	return 2;
}

inline int
getDirectionDown()
{
	return 3;
}

inline int
getDirectionLeft()
{
	return 4;
}

inline int
getWallsAmount()
{
	return 15;
}

inline int
getMaxNumberOfBullets()
{
	return 100;
}

inline int
getEnemiesAmount()
{
	return 5;
}

inline int
getMaxWallHealth()
{
	return 5;
}

inline int
getPlayerStartPositionX()
{
	return getFieldLength() / 2 + 3;
}

inline int
getPlayerStartPositionY()
{
	return getFieldHeight() - 2;
}

inline int
getPlayerTankIndex()
{
	return 0;
}

inline int
getEnemyTankBeginIndex()
{
	return getPlayerTankIndex() + 1;
}

inline char
getPlayerSymbol()
{
	return '%';
}

inline char
getEnemySymbol()
{
	return '¹';
}

inline char
getWallSymbol()
{
	return '#';
}

inline char
getFortressSymbol()
{
	return '@';
}

inline char
getGoldSymbol()
{
	return '$';
}

inline char
getBorderSymbol()
{
	return 178;
}

inline char
getBackgroundSymbol()
{
	return 176;
}

inline char
getBulletSymbol()
{
	return '*';
}

inline int
getGoldPositionX()
{
	return getFieldLength() / 2;
}

inline int
getGoldPositionY()
{
	return getFieldHeight() - 2;
}

inline int
getFortressWallsAmount()
{
	return 5;
}

inline int
getStartScore()
{
	return 0;
}
