/* 
 * File:   TAD_Fila_Dinamica.h
 * Author: Irlei
 *
 * Created on 16 de Junho de 2013, 22:29
 */
#include <stdio.h>
#include <stdlib.h>
#include"TAD_ESD.h"
#ifndef TAD_FILA_DINAMICA_H
#define	TAD_FILA_DINAMICA_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif



typedef struct {
    Apontador frente, tras;
    int tamanho;
} TipoFilaDin;

void Inicia_f(TipoFilaDin *Fila);
int Vazia_f(TipoFilaDin *Fila);
void Enfileira(TipoItem x, TipoFilaDin *Fila);
int Desenfileira(TipoFilaDin *Fila, TipoItem *item);


void Inicia_f(TipoFilaDin *Fila) {
    Fila->frente = (Apontador)malloc (sizeof(TipoCelula));
    Fila->tras = Fila->frente;
    Fila->frente->Prox = NULL;
    Fila->tamanho = 0;
}

int Vazia_f(TipoFilaDin *Fila) {
    return (Fila->frente == Fila->tras);
}




void Enfileira(TipoItem x, TipoFilaDin *Fila) {
    Fila->tras->Prox = (Apontador)malloc (sizeof(TipoCelula));
    Fila->tras = Fila->tras->Prox;
    Fila->tras->item = x;
    Fila->tras->Prox = NULL;
    Fila->tamanho = Fila->tamanho + 1;
}

int Desenfileira(TipoFilaDin *Fila, TipoItem *item) {
    Apontador aux;
    if (Vazia_f(Fila)) {
        printf("fila Vazia\n");
        return 0;
    } else {
        aux = Fila->frente;
        Fila->frente = Fila->frente->Prox;
        *item = Fila->frente->item;
        free(aux);
        Fila->tamanho = Fila->tamanho - 1;
    }
    return 1;
}


#endif	/* TAD_FILA_DINAMICA_H */
