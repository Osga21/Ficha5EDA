#pragma once
#include <Windows.h>
#include "Ponto.h"
#include "Rectangulo.h"
class Janela {
private:
	HWND janelaId;
	Ponto cur_coord;
	bool clickou;
	static Janela* objecto;
	static Janela* ObterObjecto();
public:
	Janela();
	~Janela() { };
	bool Criar(const char* sTitulo);
	static LRESULT CALLBACK DespacharMensagens(HWND janId,
		unsigned int msg,
		WPARAM wp, LPARAM lp);
	HWND ObterId() { return janelaId; }
	bool Click() { return clickou; }
	Ponto ObterPonto() { return cur_coord; }
	int ObterLargura();
	int ObterAltura();
	Rectangulo ObterJanelaRect();
};