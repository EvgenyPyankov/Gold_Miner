#pragma once
#include "Constants.h"
#include "Mineral.h"
#include <list>
#include <vector>

using namespace Constants;
using namespace std;

class LevelGenerator
{
public:
	static vector<Mineral> getMinerals(Levels level);

};
