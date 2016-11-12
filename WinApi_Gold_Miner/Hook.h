#pragma once

#include "Constants.h"

using namespace Constants;

class Hook
{
public:
	Hook();
	Hook(double x, double y, double angle);
	double getX();
	double getY();
	void calculatePosition();
	HookStates getHookState();
	void pullHook();

	//void setX(double x);
	//void setY(double y);


private:
	double x;
	double y;
	double angle;
	HookStates hookState;
	void calculate(double c);
};

#pragma once
