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
	void grabMineral(MineralTypes mineral);
	COLORREF getColor();


private:
	int direction;
	COLORREF COLOR = RGB(255, 255, 255);
	double ANGLE_STEP = 2.5;
	int DEFAULT_ANGLE = 300;
	int MIN_ANGLE = 190;
	int MAX_ANGLE = 350;
	double SPEED = 0.03;
	double RADIUS = 0.007;
	double LENGTH = 0.05;
	double x0;
	double y0;
	double x;
	double y;
	double angle;
	HookStates hookState;
	void calculate(double c);
	MineralTypes mineral;
};

#pragma once
