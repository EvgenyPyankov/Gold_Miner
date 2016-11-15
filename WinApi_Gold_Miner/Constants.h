#pragma once
#include <map>
#include <windows.h>

using namespace std;

namespace Constants {

	const enum  MineralTypes {
		Boulder,
		SmallBoulder,
		Gold,
		SmallGold,
		Diamond,
		Void
	};

	const enum Levels {
		One,
		Two
	};

	const enum States {
		Menu,
		Store,
		Level,
		Results
	};

	const enum HookStates {
		Aiming,
		Forward,
		Backward
	};

	const int WIDTH = 1000;
	const int HEIGHT = 600;

	const int LEVEL_TIME = 30;

	const double PI = 3.14159265;

	const map<MineralTypes, int> mineralValues = {
		{Boulder, 20},
		{Gold, 300},
		{SmallBoulder, 10},
		{SmallGold, 150},
		{Diamond, 500}
	};

	const map<MineralTypes, double> mineralSizes = {
		{Boulder, 0.07},
		{Gold, 0.05},
		{ SmallBoulder, 0.035 },
		{ SmallGold, 0.035 },
		{ Diamond, 0.02 }
	};

	const map<MineralTypes, double> speeds = {
		{ Boulder, 0.005 },
		{ Gold, 0.005},
		{ SmallBoulder, 0.008 },
		{ SmallGold, 0.008 },
		{ Diamond, 0.03 },
		{Void, 0.03}
	};

	const map<MineralTypes, COLORREF>colors = {
		{ Boulder, RGB(128,128,128) },
		{ Gold, RGB(255, 204, 38) },
		{ SmallBoulder, RGB(128,128,128) },
		{ SmallGold, RGB(255, 204, 38) },
		{ Diamond, RGB(0, 255, 128) },
		{ Void, RGB(0, 0, 255) }
	};

	const COLORREF BCKGRND_COLOR = RGB(76, 153, 0);

	static TCHAR winMessage[] = _T("You won!");
	static TCHAR loseMessage[] = _T("You lost!");
	

}