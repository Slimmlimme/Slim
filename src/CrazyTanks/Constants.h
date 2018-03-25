#ifndef H_CONSTANTS
#define H_CONSTANTS


#pragma warning( disable : 4309 )
inline int
getFieldHeight()
{
	return 20;
}

inline int 
getFieldLength()
{
	return 30;
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
	return 3;
}

inline int 
getPlayerStartPositionX()
{
	return getFieldLength()/2+3;
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
#pragma warning( default : 4309 )
#endif // !H_CONSTANTS