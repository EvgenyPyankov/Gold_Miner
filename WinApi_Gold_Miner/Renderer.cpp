#include "stdafx.h"
#include "Renderer.h"
#include "Converter.h"


void Renderer::render(HWND hWnd, Hook hook)
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

	drawHook(cdc, hook);

	// копирование из буфера в видимый контекст
	BitBlt(hdc, 0, 0, rect.right, rect.bottom, cdc, 0, 0, SRCCOPY);

	SelectObject(cdc, oldBmp);
	DeleteObject(hScreen);
	DeleteObject(brush);
	DeleteDC(cdc);
	EndPaint(hWnd, &ps);
}

void Renderer::drawHook(HDC hdc, Hook hook)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, NULL);
	SelectObject(hdc, hPen);
	int x = Converter::getX(hook.getX());
	int y = Converter::getY(hook.getY());
	Ellipse(hdc, x, y, x + 15, y + 15);
	DeleteObject(hPen);
}



