#include "Field.h"
#include "Info.h"
#include "Constants.h"
#include <iostream>
#include <ctime>
#include <windows.h>
#ifndef H_DRAWER
#define H_DRAWER

class Drawer
{
public:
	Drawer();
	Drawer(const Field& field, const Info& info);
	void field(const Field& field);
	void info(const Info& info);
	void draw();
private:
	Field field_;
	Info info_;
};
#endif // !H_DRAWER