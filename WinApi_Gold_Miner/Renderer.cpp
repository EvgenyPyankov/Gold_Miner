#include "stdafx.h"
#include "Renderer.h"
#include "Converter.h"
#include <iostream>


void Renderer::render(HWND hWnd, Hook hook, vector<Mineral> minerals, int timeLeft, int score)
{
	//AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
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

	drawInfo(cdc, timeLeft, score);
	for (Mineral mineral : minerals) {
		//int buf = mineral.getX();
		//char buffer[10];
		//snprintf(buffer, sizeof(buffer), "%g", buf);
		//TextOut(cdc, 10, 10, &buffer, sizeof(buffer));
		//std::cout << buf;
		//printf(buffer);
		drawMineral(cdc, mineral);		
	}

	HPEN hLinePen = CreatePen(PS_SOLID, 7, RGB(0, 0, 0));
	HPEN hPenOld = (HPEN)SelectObject(hdc, hLinePen);
	MoveToEx(cdc, Converter::getX(0.5), 0, NULL);
	LineTo(cdc, Converter::getX(hook.getX()), Converter::getY(hook.getY()));
	SelectObject(hdc, hPenOld);
	DeleteObject(hLinePen);

	drawHook(cdc, hook);

	// копирование из буфера в видимый контекст
	BitBlt(hdc, 0, 0, rect.right, rect.bottom, cdc, 0, 0, SRCCOPY);

	SelectObject(cdc, oldBmp);
	DeleteObject(hScreen);
	DeleteObject(brush);
	DeleteDC(cdc);
	EndPaint(hWnd, &ps);
}

//[]WCHAR Renderer::convertToText(int number)
//{
//	WCHAR  buffer[100];
//	wsprintf(buffer, TEXT("vaue = %d"), number);
//	return buffer;
//}


void Renderer::drawNumber(HDC hdc, double x, double y, int number)
{
	int x0 = Converter::getX(x);
	int y0 = Converter::getY(y);
	WCHAR  buffer[100];
	wsprintf(buffer, TEXT("vaue = %d"), number);
	TextOut(hdc, x0, y0, buffer, lstrlen(buffer));

}


void Renderer::drawInfo(HDC hdc, int timeLeft, int score)
{
	/*WCHAR  hah[100];
	wsprintf(hah, TEXT("vaue = %d"), score);
	TextOut(hdc, 0.01, 0.01, hah, lstrlen(hah));*/
	drawNumber(hdc, 0.01, 0.01, timeLeft);
	drawNumber(hdc, 0.01, 0.05, score);
}


void Renderer::drawHook(HDC hdc, Hook hook)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, NULL);
	SelectObject(hdc, hPen);
	int radius = Converter::getLength(hook.getRadius());
	int x = Converter::getX(hook.getX())-radius;
	int y = Converter::getY(hook.getY())- radius;
	Ellipse(hdc, x, y, x + radius*2, y +radius*2);
	DeleteObject(hPen);
}

void Renderer::drawMineral(HDC hdc, Mineral mineral)
{
	int radius = Converter::getLength(mineral.getR());
	int x = Converter::getX(mineral.getX())-radius;
	int y = Converter::getY(mineral.getY()) - radius;
	Ellipse(hdc, x, y, x + radius*2, y + radius*2);
}




