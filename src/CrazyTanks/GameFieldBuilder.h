#pragma once
#include "FieldBuilder.h"

class GameFieldBuilder: public FieldBuilder
{
public:
	void createField();
	void buildSquare();
	void buildPlayer();
	void buildEnemies();
	void buildWalls();
	void buildFortress();
	void buildGold();
	const Field& getField() const;
};