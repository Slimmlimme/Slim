#include "Tank.h"
#include "Bullet.h"
#include "Wall.h"
#include "Gold.h"
#include "Field.h"
#include "Info.h"
#ifndef H_OBJECTSTORAGE
#define H_OBJECTSTORAGE

class ObjectStorage
{
public:
	ObjectStorage();
	char getObjectSymbol(Point& point);
	void collide(const char& ObjectHit,const Point& ObjectPoint,const bool& playerBullet);
	const Field& getField() const;
	void field(Field& square);
	const Tank& getTank(const int& index) const;
	void tank(const int& index, const Tank& enemy);
	const int& sizeOfWalls() const;
	const int& sizeOfTanks() const;
	const int& sizeOfBullets() const;
	const int& sizeOfFortress() const;
	void deleteBullet(const int& index);
	void deleteTank(const int& index);
	void deleteWall(const int& index);
	void deleteFortressWall(const int& index);
	const Bullet& getBullet(const int& index) const;
	void bullet(const int& index, const Bullet& projectile);
	const Wall& getWall(const int& index) const;
	void wall(const int& index, const Wall& wall);
	const Wall& getFortressWall(const int& index) const;
	void fortressWall(const int& index, Wall& wall);
	const Gold& getGold() const;
	void gold(const Gold& gold);
	const Info& getInfo() const;
	void info(const Info& info);
	~ObjectStorage();

private:
	Field field_;
	std::vector<Tank> tanks_;
	std::vector<Bullet> bullets_;
	std::vector<Wall> walls_;
	std::vector<Wall> fortress_;
	Gold gold_;
	Info info_;
};
#endif // !H_OBJECTSTORAGE
