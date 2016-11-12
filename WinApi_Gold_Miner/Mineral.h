
#pragma once
#include "Constants.h"

using namespace Constants;


class Mineral
{
private:
	double x;
	double y;
	double r;
	MineralTypes type;
public:
	Mineral();
	Mineral(double, double, double, MineralTypes);
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	double getR();
	MineralTypes getType();
};
