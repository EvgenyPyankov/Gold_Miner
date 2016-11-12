#pragma once
#include <windows.h>

class Renderer
{

private:

public:
	Renderer(void);

	void static render(HWND hWnd);
	~Renderer(void);
};