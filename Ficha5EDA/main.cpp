#define _CRT_SECURE_NO_WARNINGS
#include "Janela.h"
#include "Circulo.h"
#include "Linha.h"
#define VERDE RGB(0,255,0)

int main() {

	Janela janela;
	HWND janelaId;
	FILE* ficheiro;
	int nnos;
	char filename[] = { "Mapa.txt" };
	ficheiro = fopen(filename,"r");
	fscanf(ficheiro,"%d",&nnos);
	int nos;
	nos = new int[nnos];

	if (janela.Criar("Minha Janela")) {
		if ((janelaId = janela.ObterId()) != NULL) {

			Ponto centro(100,100), p2(200,200);
			Linha linha(centro, p2);
			linha.desenhar(janelaId, RGB(0, 0, 0));

			Circulo circ(centro, 30, 1906), circ2(p2, 55, 15);
			circ2.desenhar(janelaId, VERDE);
			circ.desenhar(janelaId, VERDE);

			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) {
				DispatchMessage(&msg);
			}
		}
	}
	return 0;
}