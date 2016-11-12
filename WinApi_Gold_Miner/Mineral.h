
#pragma once
#include "Constants.h"

using namespace Constants;


class Mineral
{
private:
	double x;
	double y;
	double d;
	MineralTypes type;
public:
	Mineral(double, double, double, MineralTypes);
	double getX();
	double getY();
	double getD();
	MineralTypes getType();
};
