#pragma once
#include <stdio.h>

class No {
public:
    double valor;
    No* menor;
    No* maior;
    
	 No( double v ) { 
		valor = v; 
		menor = NULL; 
		maior = NULL; 
	}
};

class ArvoreBinaria
{
private:
	No* raiz;

public:
	ArvoreBinaria( );
	~ArvoreBinaria( );

	void Inserir (double valor);
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
