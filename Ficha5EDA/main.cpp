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

			int xcoord, ycoord;
			double val;
			Ponto centro(0,0);
			for (int i = 0; i < nnos; i++) {
				fscanf(ficheiro, "%d%d%f", xcoord, ycoord, val);
				arvore.Inserir(i, val);
				Circulo circ(centro.AtribuirXY(xcoord,ycoord),20,val);
			}
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) {
				DispatchMessage(&msg);
			}
		}
	}
	return 0;
}