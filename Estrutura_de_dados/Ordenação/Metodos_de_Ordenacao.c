/*
 * File:   Metodos_de_Ordenacao.c
 * Author: Irlei
 *
 * Created on 18 de Março de 2013, 19:59
 */

#include <stdio.h>
#include <stdlib.h>

void ordenacao_bolha(int vet[], int tamanho) {
	int temp, i, j;
	for (i = 0; i < tamanho; i++)
		for (j = 0; j < tamanho; j++)
			if (vet[i] < vet[j]) {
				temp = vet[i];
				vet[i] = vet[j];
				vet[j] = temp;
			}
}

void ordenacao_selecao(int vet[], int tamanho) {
	int temp, atual, j;
	for (atual = 0; atual < tamanho; atual++)
		for (j = atual + 1; j < tamanho; j++)
			if (vet[atual] > vet[j]) {
				temp = vet[atual];
				vet[atual] = vet[j];
				vet[j] = temp;
			}
}

void ordenacao_shel(int vet[], int tamanho) {
	int temp, dist, i, permuta_r;
	dist = tamanho / 2;
	do {
		do {
			permuta_r = 0;
			for (i = 0; i < tamanho - dist; i++)
				if (vet[i] > vet[i + dist]) {
					temp = vet[i];
					vet[i] = vet[i + dist];
					vet[i + dist] = temp;
					permuta_r = 1;
				}
		} while (permuta_r);
		dist = dist / 2;
	} while (dist);
}

void ordenacao_quickSort(int vet[], int primeiro, int ultimo) {
	int temp, baixo, alto, separador;
	baixo = primeiro;
	alto = ultimo;
	separador = vet[(primeiro + ultimo) / 2];
	do {
		while (vet[baixo] < separador)
			baixo++;
		while (vet[alto] > separador)
			alto--;
		if (baixo <= alto) {
			temp = vet[baixo];
			vet[baixo++] = vet[alto];
			vet[alto--] = temp;
		}
	} while (baixo <= alto);
	if (primeiro < alto)
		ordenacao_quickSort(vet, primeiro, alto);
	if (baixo < ultimo)
		ordenacao_quickSort(vet, baixo, ultimo);
}

int main(int argc, char** argv) {
	int tam = 50;
	int valor[tam], i;
	printf("Aleatorio:\n\n");
	for (i = 0; i < tam; i++) {
		valor[i] = rand() % tam;
		printf("%d,", valor[i]);
	}
	printf("\n\n\n");
	ordenacao_bolha(valor, tam);
	ordenacao_selecao(valor, tam);
	ordenacao_shel(valor, tam);
	ordenacao_quickSort(valor, 0, tam - 1);
	printf("\nOrdenado:\n\n");
	for (i = 0; i < tam; i++)
		printf("%d,", valor[i]);

	printf("\n\n\n");

	system("pause");

	return 0;
}

//Fonte "A BIBLIA _ C/C++" Kris Jamsa
