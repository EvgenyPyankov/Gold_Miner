#include "stdafx.h"
#include "Converter.h"
#include "Constants.h"

using namespace Constants;

int Converter::getX(double x) {
	return WIDTH*x;
}

int Converter::getY(double y) {
	return HEIGHT*y;
}

int Converter::getLength(double l) {
	return WIDTH*l;
}