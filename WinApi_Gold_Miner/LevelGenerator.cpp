#include "stdafx.h"
#include "LevelGenerator.h"


list<Mineral> LevelGenerator::getMinerals(Levels level) {
	list<Mineral> minerals;
	switch (level)
	{
	case Constants::One:
		minerals.push_back(Mineral(0.0, 0.4, 0.2, Gold));
		minerals.push_back(Mineral(0.5, 0.6, 0.2, Boulder));
		minerals.push_back(Mineral(0.4, 0.3, 0.1, Boulder));
		break;
	case Constants::Two:
		break;
	default:
		break;
	}

	return minerals;
}