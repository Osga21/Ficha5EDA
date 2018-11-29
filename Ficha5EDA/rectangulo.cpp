#include "Rectangulo.h"

Rectangulo::Rectangulo()
{
	Ponto tl(0, 0);
	Ponto br(0, 0);
	top_left = tl;
	bottom_right = br;
}

Rectangulo::Rectangulo(Ponto tl, Ponto br)
{
	top_left = tl;
	bottom_right = br;
}

Rectangulo::Rectangulo(int x1, int y1, int x2, int y2, HWND janela)
{
	Ponto tl(x1, y1);
	Ponto br(x2, y2);
	top_left=tl;
	bottom_right = br;
}

void Rectangulo::desenhar(HWND janelaId, long cor)
{
	Ponto top_right(bottom_right.obterX(), top_left.obterY());
	Ponto bottom_left(top_left.obterX(), bottom_right.obterY());
	HDC DrawHDC = GetDC(janelaId);
	HBRUSH hOldBrush;
	HBRUSH hNewBrush;
	hNewBrush = CreateSolidBrush(cor);
	hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
	RECT rect;
	rect.bottom = bottom_right.obterY();
	rect.left = top_left.obterX();
	rect.right = bottom_right.obterX();
	rect.top = top_left.obterY();
	FillRect(DrawHDC, &rect, hNewBrush);
	DeleteObject(SelectObject(DrawHDC, hOldBrush));
	ReleaseDC(janelaId, DrawHDC);
}

bool Rectangulo::contem(Ponto p)
{
	if (p.obterX() > top_left.obterX() && p.obterX() < bottom_right.obterX() && p.obterY() < top_left.obterY() && p.obterY() > bottom_right.obterY())
		return true;
	else
		return false;
}

bool Rectangulo::contem(Rectangulo r)
{
	int rbrx, rbry, rtlx, rtly;

	rbrx = r.bottom_right.obterX();
	rbry = r.bottom_right.obterY();
	rtlx = r.top_left.obterX();
	rtly = r.top_left.obterY();
	
	int brx, bry, tlx, tly;
	brx = bottom_right.obterX();
	bry = bottom_right.obterY();
	tlx = top_left.obterX();
	tly = top_left.obterY();

	if (rbrx < brx && rtlx > tlx && rbry > bry && rbry < tly)
		return true;
	else
		return false;
}

double Rectangulo::obterArea()
{
	Ponto top_right(bottom_right.obterX(), top_left.obterY());
	Ponto bottom_left(top_left.obterX(),bottom_right.obterY());

	double altura = top_left.ObterDistancia(bottom_left);
	double base = bottom_left.ObterDistancia(bottom_right);

	return base*altura;
}

int Rectangulo::obterPerimetro()
{
	Ponto top_right(bottom_right.obterX(), top_left.obterY());
	Ponto bottom_left(top_left.obterX(), bottom_right.obterY());

	double altura = top_left.ObterDistancia(bottom_left);
	double base = bottom_left.ObterDistancia(bottom_right);
	
	return 2*base+2*altura;
}
