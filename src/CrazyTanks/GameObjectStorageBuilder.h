#pragma once
#include "ObjectStorageBuilder.h"
#include "Constants.h"

class GameObjectStorageBuilder: public ObjectStorageBuilder
{
public:
	~GameObjectStorageBuilder();
	void createObjectStorage();
	void buildField();
	void buildPlayer();
	void buildEnemies();
	void buildWalls();
	void buildFortress();
	void buildGold();
	void buildInfo();
	const ObjectStorage& getObjectStorage() const;
};