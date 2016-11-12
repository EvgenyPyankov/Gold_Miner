#include "stdafx.h"
#include "LevelGenerator.h"


list<Mineral> LevelGenerator::getMinerals(Levels level) {
	list<Mineral> minerals;
	switch (level)
	{
	case Constants::One:
		minerals.push_back(Mineral(0.1, 0.4, 0.05, Gold));
		minerals.push_back(Mineral(0.5, 0.6, 0.03, Boulder));
		minerals.push_back(Mineral(0.4, 0.3, 0.05, Boulder));
		break;
	case Constants::Two:
		break;
	default:
		break;
	}

	return minerals;
}