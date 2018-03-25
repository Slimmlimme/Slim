#include "ObjectStorage.h"
#ifndef H_OBJECTSTORAGEBUILDER
#define H_OBJECTSTORAGEBUILDER

class ObjectStorageBuilder
{
public:
	ObjectStorageBuilder();
	virtual ~ObjectStorageBuilder();
	virtual void createObjectStorage();
	virtual void buildField();
	virtual void buildPlayer();
	virtual void buildEnemies();
	virtual void buildWalls();
	virtual void buildFortress();
	virtual void buildGold();
	virtual void buildInfo();
	virtual const ObjectStorage& getObjectStorage() const;
protected:
	ObjectStorage objectStorage;

};
#endif // !H_OBJECTSTORAGEBUILDER
