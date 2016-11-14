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

public:
	Renderer(void);

	void static render(HWND hWnd, Hook hook, vector<Mineral> minerals);
};