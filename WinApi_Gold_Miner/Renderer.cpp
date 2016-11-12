#include "stdafx.h"
#include "Renderer.h"

Renderer::Renderer(void)
{
}

void Renderer::render(HWND hWnd)
{
	HBITMAP hScreen, oldBmp;
	PAINTSTRUCT ps;
	RECT rect;
	HDC hdc, cdc;

	GetClientRect(hWnd, &rect);

	hdc = BeginPaint(hWnd, &ps);
	cdc = CreateCompatibleDC(hdc);
	hScreen = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
	oldBmp = (HBITMAP)SelectObject(cdc, hScreen);

	HBRUSH brush = CreateSolidBrush(RGB(40, 200, 80));
	FillRect(cdc, &ps.rcPaint, brush);



	// копирование из буфера в видимый контекст
	BitBlt(hdc, 0, 0, rect.right, rect.bottom, cdc, 0, 0, SRCCOPY);

	SelectObject(cdc, oldBmp);
	DeleteObject(hScreen);
	DeleteObject(brush);
	DeleteDC(cdc);
	EndPaint(hWnd, &ps);
}



Renderer::~Renderer(void)
{
}
