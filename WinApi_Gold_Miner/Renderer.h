#pragma once
#include "Hook.h"
#include "Mineral.h"
#include <list>
#include <vector>

using namespace std;

class Renderer
{

private:
	void static drawHook(HDC hdc, Hook hook);
	void static drawMineral(HDC hdc, Mineral mineral);
	void static drawInfo(HDC hdc, int timeLeft, int score);
	void static drawNumber(HDC hdc, double x, double y, int number);
	static WCHAR* convertToText(int number);

public:
	Renderer(void);

	void static render(HWND hWnd, Hook hook, vector<Mineral> minerals, int timeLeft, int score);
};