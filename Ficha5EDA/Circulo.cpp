#include "Circulo.h"



Circulo::Circulo()
{
	raio = 0;
	valor = 0;
	centro.AtribuirXY(0, 0);
}

Circulo::Circulo(Ponto c, int r, int v)
{
	raio = r;
	valor= v;
	centro.AtribuirXY(c.obterX(), c.obterY());
}


void Circulo::desenhar(HWND janelaId, long cor)
{
	if (janelaId != NULL)
	{
		HDC DrawHDC = GetDC(janelaId);
		// penstyle, width, color
		HPEN hNPen = CreatePen(PS_SOLID, 2, cor);
		HPEN hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
		HBRUSH hOldBrush;
		HBRUSH hNewBrush;
		hNewBrush = CreateSolidBrush(cor);
		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
		Ellipse(DrawHDC, centro.obterX() - raio, centro.obterY() + raio,
			centro.obterX() + raio, centro.obterY() - raio);
		char str[80];
		sprintf_s(str, "%d", valor);
		SetBkMode(DrawHDC, TRANSPARENT);
		SetTextColor(DrawHDC, RGB(0, 0, 0));
		SetTextAlign(DrawHDC, TA_CENTER | TA_BOTTOM | TA_BASELINE);
		TextOut(DrawHDC, centro.obterX(), centro.obterY(), str, strlen(str));
		DeleteObject(SelectObject(DrawHDC, hOPen));
		DeleteObject(SelectObject(DrawHDC, hOldBrush));
		ReleaseDC(janelaId, DrawHDC);
	}
}
