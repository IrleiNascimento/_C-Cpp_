#include<stdio.h>
#include<string.h>
#include "TAD_ESD.h"
#include "TAD_Pilha_Encadeada.h"
/* 7.Escreva um programa para ler uma frase e imprimi-la com as
 palavras invertidas (como um espelho). Exemplo:
 a frase "A pilha do gato" deve sair "A ahlip od otagï"*/

typedef struct {
	char ch;
} Item;

void Imprime(TipoPilha_EnC Pilha);
char *str_reverse(TipoPilha_EnC *Pilha);

int main() {
	TipoPilha_EnC P1;
	TipoPilha_EnC P2;
	Inicia_Pilha_Enc(&P1);
	Inicia_Pilha_Enc(&P2);
	char frase[256];
	printf("\nDIGITE UMA FRASE\n");
    gets(frase);
	int count = 0, i = 0, j = 0, tam = strlen(frase);
	Item letra[tam];
	Item *temp;
	for (j = 0; j < tam; j++) {
		if (frase[j] == ' ') {
			Empilha_EnC(&letra[j], &P2);
			for (i = 0; i < count; i++) {
				DesEmpilha_EnC(&P1, &temp);
				Empilha_EnC(temp, &P2);
			}
			count = 0;
		}
		letra[j].ch = frase[j];
		Empilha_EnC(&letra[j], &P1);
		count++;
	}
	for (i = 0; i < count; i++) {
		DesEmpilha_EnC(&P1, &temp);
		Empilha_EnC(temp, &P2);
	}
	Apontador aux = P2.Topo->Prox;
	while (aux->Prox != NULL ) {
		DesEmpilha_EnC(&P2, &temp);
		Empilha_EnC(temp, &P1);
		aux = aux->Prox;
	}
	Imprime(P1);
	return 0;
}

void Imprime(TipoPilha_EnC Pilha) {
	Item *temp;
	Apontador aux;
	aux = Pilha.Topo->Prox;
	while (aux != NULL ) {
		temp = aux->item;
		printf("%c", temp->ch);
		aux = aux->Prox;
	}
	printf("\n");
}
