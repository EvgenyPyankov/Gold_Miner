#pragma once
#include "Constants.h"
#include "Mineral.h"
#include <list>

using namespace Constants;
using namespace std;

class LevelGenerator
{
public:
	static list<Mineral> getMinerals(Levels level);

};
