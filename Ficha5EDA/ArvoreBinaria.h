#pragma once
#include <stdio.h>

class No {
public:
    double valor;
    No* menor;
    No* maior;
	int ycoord;
	int xcoord;
	int pos;

	 No( double v ) { 
		valor = v; 
		menor = NULL; 
		maior = NULL; 
	}
	 No(int x, int y, double v) {
		 xcoord = x;
		 ycoord = y;
		 valor = v;
	 }
	 No() { valor = 0; xcoord = 0; ycoord = 0; }
};

class ArvoreBinaria
{
private:
	No* raiz;

public:
	ArvoreBinaria( );
	~ArvoreBinaria( );

	void Inserir (No* &no, double valor, int pos, int pai);
	void Remover (double valor);
	No* Pesquisar (double valor);
	void Listar ();

private:
	//bool Pesquisar(No* no, double valor);
	No* Pesquisar(No* no, double valor);
	void Inserir(No* &no, double valor);
	void Remover(No* &no, double valor);
	void listarPreOrdem(No* no);
	void listarPosOrdem(No* no);
	void listarEmOrdem(No* no);
	No* valorMin(No* no);
};
