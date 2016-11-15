#include "stdafx.h"
#include "LevelGenerator.h"


vector<Mineral> LevelGenerator::getMinerals(Levels level) {
	vector<Mineral> minerals;
	switch (level)
	{
	case Constants::One:
		minerals.push_back(Mineral(0.1, 0.4, mineralSizes.at(Gold), Gold));
		minerals.push_back(Mineral(0.2, 0.7, mineralSizes.at(SmallBoulder), SmallBoulder));
		minerals.push_back(Mineral(0.5, 0.8, mineralSizes.at(SmallGold), SmallGold));
		minerals.push_back(Mineral(0.4, 0.3, mineralSizes.at(Boulder), Boulder));
		minerals.push_back(Mineral(0.6, 0.2, mineralSizes.at(Boulder), Boulder));
		minerals.push_back(Mineral(0.59, 0.65, mineralSizes.at(Diamond), Diamond));
		minerals.push_back(Mineral(0.7, 0.4, mineralSizes.at(Diamond), Diamond));
		minerals.push_back(Mineral(0.9, 0.8, mineralSizes.at(Gold), Gold));
		break;
	case Constants::Two:
		break;
	default:
		break;
	}

	return minerals;
}