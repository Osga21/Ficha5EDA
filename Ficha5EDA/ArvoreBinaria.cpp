#include "ArvoreBinaria.h"

ArvoreBinaria::ArvoreBinaria()
{
	raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria(void)
{
}
No* ArvoreBinaria::Pesquisar(double valor)
{
	return Pesquisar(raiz, valor);
}
No* ArvoreBinaria::Pesquisar(No* no, double valor)
{
	if (no == NULL)
		return NULL;
	else if (valor < no->valor)
		return Pesquisar (no->menor, valor);
	else if (no->valor < valor)
		return Pesquisar (no->maior, valor);
	else
		return no;
}

void ArvoreBinaria::Inserir(No* &no,double valor,int pos,int pai)
{
	pai = no->pos;
	if (no == NULL)
		no = new No(valor, pos, pai);
	else if (valor < no->valor)
		Inserir(no->menor, valor, pos, pai);
	else if (valor > no->valor)
		Inserir(no->maior, valor, pos, pai);
	else;

}

void ArvoreBinaria::Inserir(No* &no, double valor)
{

	if (no == NULL)
		no = new No(valor);
	else if (valor < no->valor)
		Inserir(no->menor, valor);
	else if (no->valor < valor)
		Inserir(no->maior, valor);
	else
		;	// N� j� existente, n�o faz nada
}

// Fun��o privada que encontra o valor minimo numa sub�rvore.
No* ArvoreBinaria::valorMin(No* no)
{
   if (no == NULL) return NULL;
   if (no->menor == NULL) return no;
   return valorMin(no->menor);
}

// Fun��o p�blica
void ArvoreBinaria::Remover(double valor)
{
   Remover(raiz, valor);
}

void ArvoreBinaria::Remover (No* &no, double valor)
{
   if (no == NULL) 
     return; 		// N� n�o existente, n�o faz nada
   if (no->valor > valor)
     Remover (no->menor, valor);
   else if (no->valor < valor)
     Remover (no->maior, valor);
   else if (no->menor != NULL && no->maior != NULL) // Dois filhos
   {
	   no->valor = valorMin (no->maior)->valor;	// Substitui valor do pelo o do n� mais pequeno pendurado da sub-�rvore do filho maior
       Remover (no->maior, no->valor);			// Elimina a folha do n� mais pequeno pendurado na sub-�rvore do filho maior do n�		
   }
   else	// Um ou zero filhos
   {
      No* pNo = no;
      no = (no->menor != NULL) ? no->menor : no->maior;
      delete pNo;
   }
}
void ArvoreBinaria::Listar()
{
	listarPreOrdem(raiz);
}
void ArvoreBinaria::listarPreOrdem(No *no)
{
	if (no == NULL)
		return;
	printf("%.0f\n", no->valor);
	listarPreOrdem(no->menor);
	listarPreOrdem(no->maior);
	
}

void ArvoreBinaria::listarEmOrdem(No *no)
{
	if (no == NULL)
		return;
	listarEmOrdem(no->menor);
	printf("%.0f\n", no->valor);
	listarEmOrdem(no->maior);
}

void ArvoreBinaria::listarPosOrdem(No *no)
{
	if (no == NULL)
		return;
	listarPosOrdem(no->menor);
	listarPosOrdem(no->maior);
	printf("%.0f\n", no->valor);
}

