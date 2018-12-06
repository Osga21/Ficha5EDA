#define _CRT_SECURE_NO_WARNINGS
#include "Janela.h"
#include "Circulo.h"
#include "Linha.h"
#include "ArvoreBinaria.h"
#define VERDE RGB(0,255,0)

int main() {

	Janela janela;
	HWND janelaId;
	

	if (janela.Criar("Minha Janela")) {
		if ((janelaId = janela.ObterId()) != NULL) {

			FILE* ficheiro;
			int nnos;
			char filename[] = { "Mapa.txt" };
			ficheiro = fopen(filename, "r");
			fscanf(ficheiro, "%d", &nnos);
			int* nos;
			nos = new int[nnos];
			ArvoreBinaria arvore;

			Circulo *pnos;
			pnos = new Circulo[nnos];
			int xcoord, ycoord;
			double val;
			for (int i = 0; i < nnos; i++) {
				fscanf(ficheiro, "%d, %d, %lf", &xcoord,&ycoord,&val);
				pnos[i]=Circulo(Ponto(xcoord,ycoord),20,val);
				pnos[i].desenhar(janelaId, VERDE);

				
			}

			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) {
				DispatchMessage(&msg);
			}
		}
	}
	return 0;
}