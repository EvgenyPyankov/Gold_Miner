#include "stdafx.h"
#include "Renderer.h"
#include "Converter.h"


void Renderer::render(HWND hWnd, Hook hook, list<Mineral> minerals)
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

	// ����������� �� ������ � ������� ��������
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
	int radius = Converter::getLength(hook.getRadius());
	int x = Converter::getX(hook.getX())-radius;
	int y = Converter::getY(hook.getY())- radius;
	Ellipse(hdc, x, y, x + radius*2, y +radius*2);
	DeleteObject(hPen);
}

void Renderer::drawMineral(HDC hdc, Mineral mineral)
{
	int diameter = Converter::getLength(mineral.getD());
	int x = Converter::getX(mineral.getX());
	int y = Converter::getY(mineral.getY());
	Ellipse(hdc, x, y, x + diameter, y + diameter);
}




