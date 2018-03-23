#pragma once
#include "Field.h"
#include "Info.h"
#include "Constants.h"
#include <iostream>
#include <ctime>

class Drawer
{
public:
	Drawer();
	Drawer(Field field, Info info);
	void field(const Field& field);
	void info(const Info& info);
	void draw();
private:
	Field field_;
	Info info_;
};