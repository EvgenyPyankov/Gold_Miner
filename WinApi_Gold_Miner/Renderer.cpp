#include "stdafx.h"
#include "Renderer.h"
#include "Converter.h"
#include <iostream>


void Renderer::render(HWND hWnd, Hook hook, vector<Mineral> minerals, int timeLeft, int score)
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

	HBRUSH brush = CreateSolidBrush(BCKGRND_COLOR);
	FillRect(cdc, &ps.rcPaint, brush);

	drawInfo(cdc, timeLeft, score);
	for (Mineral mineral : minerals) {
		drawMineral(cdc, mineral);		
	}

	HPEN hLinePen = CreatePen(PS_SOLID, 7, RGB(0, 0, 0));
	HPEN hPenOld = (HPEN)SelectObject(hdc, hLinePen);
	MoveToEx(cdc, Converter::getX(0.5), 0, NULL);
	LineTo(cdc, Converter::getX(hook.getX()), Converter::getY(hook.getY()));
	SelectObject(hdc, hPenOld);
	DeleteObject(hLinePen);

	drawHook(cdc, hook);

	BitBlt(hdc, 0, 0, rect.right, rect.bottom, cdc, 0, 0, SRCCOPY);

	SelectObject(cdc, oldBmp);
	DeleteObject(hScreen);
	DeleteObject(brush);
	DeleteDC(cdc);
	EndPaint(hWnd, &ps);
}

WCHAR* Renderer::convertToText(int number)
{
	WCHAR  buffer[100];
	wsprintf(buffer, TEXT("vaue = %d"), number);
	return buffer;
}


void Renderer::drawNumber(HDC hdc, double x, double y, int number)
{
	int x0 = Converter::getX(x);
	int y0 = Converter::getY(y);
	wchar_t  buffer[100];
	wsprintf(buffer, TEXT("vaue = %d"), number);
	TextOut(hdc, x0, y0, buffer, lstrlen(buffer));

}


void Renderer::drawInfo(HDC hdc, int timeLeft, int score)
{
	int x0 = Converter::getX(0.01);
	int y0 = Converter::getY(0.01);
	wchar_t  buffer[100];
	wsprintf(buffer, TEXT("Time left: %d"), timeLeft);
	TextOut(hdc, x0, y0, buffer, lstrlen(buffer));
	x0 = Converter::getX(0.01);
	y0 = Converter::getY(0.05);
	wsprintf(buffer, TEXT("Score: %d"), score);
	TextOut(hdc, x0, y0, buffer, lstrlen(buffer));
}


void Renderer::drawHook(HDC hdc, Hook hook)
{
	HBRUSH brush = CreateSolidBrush(hook.getColor());
	SelectObject(hdc, brush);
	int radius = Converter::getLength(hook.getRadius());
	int x = Converter::getX(hook.getX())-radius;
	int y = Converter::getY(hook.getY())- radius;
	Ellipse(hdc, x, y, x + radius*2, y +radius*2);
	DeleteObject(brush);
}

void Renderer::drawMineral(HDC hdc, Mineral mineral)
{
	HBRUSH brush = CreateSolidBrush(colors.at(mineral.getType()));
	int radius = Converter::getLength(mineral.getR());
	int x = Converter::getX(mineral.getX())-radius;
	int y = Converter::getY(mineral.getY()) - radius;
	SelectObject(hdc, brush);
	Ellipse(hdc, x, y, x + radius*2, y + radius*2);
	DeleteObject(brush);
}




