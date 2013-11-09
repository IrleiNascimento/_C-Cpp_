#include <stdio.h>
#include <stdlib.h>


#include"TAD_ESD.h"


typedef struct {
	Apontador Primeiro, Ultimo;
	int tamanho;
} TipoListaEncad;

void inicia_Lista_Enc(TipoListaEncad *Lista);
void insere_Lista_Enc(TipoItem x, TipoListaEncad *Lista);
void remove_Lista_Enc(Apontador p, TipoListaEncad *Lista, TipoItem *itens_lista);
int lista_Enc_Vazia(TipoListaEncad *Lista);



void inicia_Lista_Enc(TipoListaEncad *Lista) {
	Lista->Primeiro = (Apontador) malloc(sizeof(TipoCelula));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
	Lista->tamanho = 0;
}
void insere_Lista_Enc(TipoItem x, TipoListaEncad *Lista)
{

	Lista->Ultimo->Prox = (Apontador) malloc(sizeof(TipoCelula));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->item = x;
	Lista->Ultimo->Prox = NULL;
	Lista->tamanho += 1;
}
void remove_Lista_Enc(Apontador p, TipoListaEncad *Lista, TipoItem *item) {
	/* Obs.: o itens_lista a ser retirado � o seguinte ao apontado por  p */
	Apontador pAux;
	if (lista_Enc_Vazia(Lista) || p == NULL || p->Prox == NULL ) {
		printf(" Erro Lista lista_Enc_Vazia ou posicao nao existe\n");
		return;
	}
	pAux = p->Prox;
	*item = pAux->item;
	p->Prox = pAux->Prox;
	if (p->Prox == NULL )
		Lista->Ultimo = p;
	free(pAux);
	Lista->tamanho = Lista->tamanho - 1;
}
int lista_Enc_Vazia(TipoListaEncad *Lista) {
	return (Lista->Primeiro == Lista->Ultimo);
}


