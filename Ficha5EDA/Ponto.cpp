#pragma once
#include "Ponto.h"
#include "math.h"

Ponto::Ponto()
{
	x = 0;
	y = 0;
}

Ponto::Ponto(int x0, int y0)
{
	x = x0;
	y = y0;
}

void Ponto::AtribuirXY(int novo_x, int novo_y)
{
	x = novo_x;
	y = novo_y;
}

float Ponto::ObterDistancia(Ponto p2)
{
	float distancia = sqrt(pow(p2.obterX()-x,2)+pow(p2.obterY()-y,2));
	return distancia;
}

int Ponto::obterX()
{
	return x;
}

int Ponto::obterY()
{
	return y;
}


