#include "stdafx.h"
#include "Mineral.h"


Mineral::Mineral(double x, double y, double d, MineralTypes type)
{
	this->x = x;
	this->y = y;
	this->d = d;
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

double Mineral::getD()
{
	return d;
}

MineralTypes Mineral::getType() {
	return type;
}