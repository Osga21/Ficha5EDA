#pragma once
class Ponto {
private:
	int x, y; // coordenadas do ponto
public:
	Ponto(); // construtor por omiss�o
	Ponto(int x0, int y0); //construtor para atribui��o
	void AtribuirXY(int novo_x, int novo_y); // novas coordenadas
	float ObterDistancia(Ponto p2); // calcula a distancia a um ponto p2
	int obterX(); // devolve a coordenada x
	int obterY(); // devolve a coordenada y
};