/* 
 * Lista_Duplamente_Encadeada.c
 * Author: Irlei
 *
 * Created on 20 de Março de 2013, 20:20
 */

#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;

typedef struct {
	TipoChave chave;
} TipoItem;

typedef struct TipoCelula *Apontador;

typedef struct TipoCelula {
	TipoItem Item;
	Apontador Prox, Ant;
} celula;

typedef struct {
	Apontador Primeiro, Ultimo;
	int tamanho;
} TipoLista;

void Inicia(TipoLista *Lista);
void Insere(TipoItem x, TipoLista *Lista);
void Retira(Apontador p, TipoLista *Lista, TipoItem *item);
int Vazia(TipoLista *Lista);
void Imprime(TipoLista Lista);

void Inicia(TipoLista *Lista) {
	Lista->Primeiro = (Apontador) malloc(sizeof(celula));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Ultimo->Ant = Lista->Primeiro;
	Lista->Primeiro->Prox = Lista->Ultimo;
	Lista->tamanho = 0;
}

void Insere(TipoItem x, TipoLista *Lista) {
	Apontador aux = Lista->Ultimo;
	Lista->Ultimo->Prox = (Apontador) malloc(sizeof(celula));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->Item = x;
	Lista->Ultimo->Ant = aux;
	Lista->Ultimo->Prox = Lista->Primeiro;
	Lista->Primeiro->Ant = Lista->Ultimo;
	Lista->tamanho = Lista->tamanho + 1;

}
void Retira(Apontador p, TipoLista *Lista, TipoItem *item) {
	Apontador pAux;
	if (Vazia(Lista) || p == Lista->Primeiro || p->Prox == Lista->Primeiro) {
		printf(" Erro Lista Vazia ou posicao nao existe\n");
		return;
	}
	pAux = p->Prox;
	*item = pAux->Item;
	p->Prox = pAux->Prox;
	p->Prox->Ant = p;
	if (p->Prox == Lista->Primeiro)
		Lista->Ultimo = p;
	free(pAux);
	Lista->tamanho = Lista->tamanho - 1;
}

int Vazia(TipoLista *Lista) {
	return (Lista->Primeiro == Lista->Ultimo);
}

void Imprime(TipoLista Lista) {
	Apontador Aux;
	Aux = Lista.Primeiro->Prox;
	printf("  ANT                 CHAVE                PROX  \n\n");
	while (Aux != Lista.Primeiro) {
		printf("  %d            %d             %d\n", Aux->Ant->Item.chave, Aux->Item.chave,
				Aux->Prox->Item.chave);
		Aux = Aux->Prox;
	}
}

int main(int argc, char **argv) {
	printf(" \nTESTE  COM 10 ITENS, CHAVE DE 1 A 10 \n\n");
	TipoItem it[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	TipoLista l1;
	Inicia(&l1);

	int i;
	for (i = 0; i < 10; i++) {
		Insere(it[i], &l1);
	}
	Imprime(l1);
	printf("\nAPONTAR PARA REMOCAO ITENS DE CHAVE : 3 ,4, 8,9\n");
	printf("\n");
	Apontador p = l1.Primeiro->Prox ;
	TipoItem it0;
	while(p != l1.Primeiro){
		if(p->Prox->Item.chave == 3){
			Retira(p, &l1, &it0);
	printf(" Chave %d  removida\n", it0.chave);
		}
		if(p->Prox->Item.chave == 4){
				Retira(p, &l1, &it0);
		printf(" Chave %d  removida\n", it0.chave);
		}
		if(p->Prox->Item.chave == 8){
				Retira(p, &l1, &it0);
		printf(" Chave %d  removida\n", it0.chave);
		}
		if(p->Prox->Item.chave == 9){
				Retira(p, &l1, &it0);
		printf(" Chave %d  removida\n", it0.chave);
		}
		p=p->Prox;
	}

	printf("\nLISTA POS REMOCAO\n\n");
	Imprime(l1);

	printf("\nObs: O numero grande no inicio/fim da lista e o ponteiro do no cabeca\napenas para ficar claro que se trata de uma fila circular\n\n\n");
	return 0;
}

