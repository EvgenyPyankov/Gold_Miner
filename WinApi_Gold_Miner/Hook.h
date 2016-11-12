#pragma once

#include "Constants.h"

using namespace Constants;

class Hook
{
public:
	Hook();
	Hook(double x, double y);
	double getX();
	double getY();
	double getRadius();
	void calculatePosition();
	HookStates getHookState();
	void pullHook();

	//void setX(double x);
	//void setY(double y);


private:
	int direction;
	double ANGLE_STEP = 2.5;
	int DEFAULT_ANGLE = 300;
	int MIN_ANGLE = 190;
	int MAX_ANGLE = 350;
	double SPEED = 0.05;
	double RADIUS = 0.02;
	double LENGTH = 0.05;
	double x0;
	double y0;
	double x;
	double y;
	double angle;
	HookStates hookState;
	void calculate(double c);
};

#pragma once
