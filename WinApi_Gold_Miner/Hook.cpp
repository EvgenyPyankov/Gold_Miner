#include "stdafx.h"
#include "Hook.h"
#include "Constants.h"
#include <valarray>

using namespace Constants;
using namespace std;

Hook::Hook() {}

Hook::Hook(double x, double y, double angle)
{
	this->x = x;
	this->y = y;
	this->angle = angle;
	hookState = Aiming;
}

double Hook::getX()
{
	return x;
}

double Hook::getY()
{
	return y;
}

void Hook::calculatePosition()
{
	switch (hookState)
	{
	case Aiming:
	{
		x = 0.5;
		y = 0.1;
		calculate(0.1);
		angle += 2.5;
	}
	case Forward:
	{
		//calculate(0.02);
	}
	}

}

void Hook::calculate(double c)
{
	double ang = 270 - angle;
	y += c * cos(ang * PI / 180);
	double buf = c*sin(ang*PI / 180);
	if (ang < 0)
		x -= buf;
	else
		x += buf;
}


HookStates Hook::getHookState()
{
	return hookState;
}

void Hook::pullHook()
{
	if (hookState == Aiming)
	{
		hookState = Forward;
	}
}




