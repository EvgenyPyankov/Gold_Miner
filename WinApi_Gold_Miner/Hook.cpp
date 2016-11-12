#include "stdafx.h"
#include "Hook.h"
#include "Constants.h"
#include <valarray>

using namespace Constants;
using namespace std;

Hook::Hook() {}

Hook::Hook(double x, double y)
{
	this->x0 = x;
	this->x = x;
	this->y = y + LENGTH;
	this->y0 = y;
	this->angle = DEFAULT_ANGLE;
	direction = 1;
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

double Hook::getRadius()
{
	return RADIUS;
}

void Hook::grabMineral(Mineral* mineral)
{
	this->mineral = mineral;
	hookState = Backward;
}


void Hook::calculatePosition()
{
	switch (hookState)
	{
	case Aiming:
	{
		x = x0;
		y = y0;
		angle += ANGLE_STEP*direction;
		if (angle > MAX_ANGLE)
		{
			angle = MAX_ANGLE;
			direction *= -1;
		}
		else 
			if (angle < MIN_ANGLE)
			{
				angle = MIN_ANGLE;
				direction *= -1;
			}
		calculate(LENGTH);
	}
	break;
	case Forward:
	{
		calculate(SPEED);
		if (x > 1 || x<0 || y>1 || y < 0)
			hookState = Backward;
	}
	break;
	case Backward:
	{
		calculate(SPEED);
		if (mineral != NULL){
			mineral->setX(0);
			mineral->setY(0);
		}
		if (x < 0 || y < 0) {
			hookState = Aiming;
		}
	}
	break;
	}

}

void Hook::calculate(double c)
{

	double ang = 270 - angle;
	double absAng = abs(ang);
	double tmp = c * cos(absAng * PI / 180);
	if (hookState == Backward)
		y -= tmp;
	else y += tmp;
	double buf = c*sin(absAng*PI / 180);
	if (hookState == Backward)
		buf *= -1;
	if (ang < 0)
		x += buf;
	else
		x -= buf;
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




