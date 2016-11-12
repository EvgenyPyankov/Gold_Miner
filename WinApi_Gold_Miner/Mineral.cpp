#include "stdafx.h"
#include "Mineral.h"


Mineral::Mineral(double x, double y, double r, MineralTypes type)
{
	this->x = x;
	this->y = y;
	this->r = r;
	this->type = type;
}

double Mineral::getX()
{
	return x;
}
double Mineral::getY()
{
	return y;
}

double Mineral::getR()
{
	return r;
}

MineralTypes Mineral::getType() {
	return type;
}