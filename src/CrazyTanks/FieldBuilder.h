#pragma once
#include "Field.h"

class FieldBuilder
{
public:
	FieldBuilder();
	~FieldBuilder();
	virtual void createField();
	virtual void buildSquare();
	virtual void buildPlayer();
	virtual void buildEnemies();
	virtual void buildWalls();
	virtual void buildFortress();
	virtual void buildGold();
protected:
	Field field;

};
