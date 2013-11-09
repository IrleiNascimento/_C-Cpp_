/*
 * File:   TAD_Lista_Estatica.h
 * Author: Irlei
 *
 * Created on 16 de Junho de 2013, 22:50
 */

#ifndef TAD_LISTA_ESTATICA_H
#define	TAD_LISTA_ESTATICA_H

#ifdef	__cplusplus
extern "C" {
#endif
#ifdef	__cplusplus
}
#endif

#include"TAD_ESD.h"
#include <stdio.h>
#include <stdlib.h>
#define MaxTam 20
#define InicioVetor 0


typedef struct {
	TipoItem itens[MaxTam];
	int Primeiro, Ultimo;
} TipoListaEstatc;

void inicia_Lista_Est(TipoListaEstatc *Lista);
int insere_Lista_Est(TipoItem x, TipoListaEstatc *Lista);
void retira_Lista_Est(int posicao, TipoListaEstatc *Lista, TipoItem *Item) ;
int lista_Est_Vazia(TipoListaEstatc *Lista);
void imprime_Lista_Est(TipoListaEstatc Lista);

void inicia_Lista_Est(TipoListaEstatc *Lista) {
	Lista->Primeiro = InicioVetor;
	Lista->Ultimo = Lista->Primeiro;
}

int lista_Est_Vazia(TipoListaEstatc *Lista) {
	return Lista->Primeiro == Lista->Ultimo;
}

int insere_Lista_Est(TipoItem x, TipoListaEstatc *Lista) {
	if (Lista->Ultimo > MaxTam - 1) {
		printf("Lista esta cheia\n");
		return 0;
	} else {
		Lista->itens[Lista->Ultimo] = x;
		Lista->Ultimo++;
		return 1;
	}
}

void retira_Lista_Est(int posicao, TipoListaEstatc *Lista, TipoItem *Item) {
	int Aux;
	if (lista_Est_Vazia(Lista) || (posicao >= Lista->Ultimo) ){
		return;
	}
	*Item = Lista->itens[posicao - 1];
	for (Aux = posicao; Aux < Lista->Ultimo; Aux++) {
		Lista->itens[Aux - 1] = Lista->itens[Aux];
	}
	Lista->Ultimo--;
}






#endif	/* TAD_LISTA_ESTATICA_H */


