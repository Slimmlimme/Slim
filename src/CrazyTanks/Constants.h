#ifndef H_CONSTANTS
#define H_CONSTANTS
#pragma warning( disable : 4309 )

//Field and objects coords
extern int getFieldHeight();
extern int getFieldLength();
extern int getFieldBeginX();
extern int getFieldBeginY();
extern int getFieldEndX();
extern int getFieldEndY();
extern int getPlayerStartPositionX();
extern int getPlayerStartPositionY();
extern int getGoldPositionX();
extern int getGoldPositionY();

//Objects health
extern int getEnemyHealth();
extern int getPlayerHealth();
extern int getMaxWallHealth();
extern int getGoldHealth();

//Directions
extern int getDirectionUp();
extern int getDirectionRight();
extern int getDirectionDown();
extern int getDirectionLeft();

//Objects amounts
extern int getWallsAmount();
extern int getFortressWallsAmount();
extern int getMaxNumberOfBullets();
extern int getEnemiesAmount();

//Array indexes
extern int getArrayBeginIndex();
extern int getPlayerTankIndex();
extern int getEnemyTankBeginIndex();

//Objects symbols
extern char getPlayerSymbol();
extern char getEnemySymbol();
extern char getWallSymbol();
extern char getFortressSymbol();
extern char getGoldSymbol();
extern char getBorderSymbol();
extern char getBackgroundSymbol();
extern char getBulletSymbol();

//Other constants
extern int getActionCooldown();
extern int getStartScore();
#pragma warning( default : 4309 )
#endif // !H_CONSTANTS