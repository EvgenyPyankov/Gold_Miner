#pragma once
#include "Hook.h"

class Renderer
{

private:
	void static drawHook(HDC hdc, Hook hook);

public:
	Renderer(void);

	void static render(HWND hWnd, Hook hook);
};