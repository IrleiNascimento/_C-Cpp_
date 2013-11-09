/* 
 * File:   TAD_Pilha_Encadeada.h
 * Author: Irlei
 *
 * Created on 17 de Junho de 2013, 00:17
 */

#ifndef TAD_PILHA_ENCADEADA_H
#define	TAD_PILHA_ENCADEADA_H

#ifdef	__cplusplus
extern "C" {
#endif


#include<stdio.h>
#include <stdlib.h>
#include"TAD_ESD.h"


typedef struct TipoPilha_EnC {
    Apontador Fundo,Topo;
    int Tamanho;
} TipoPilha_EnC;


void Inicia_Pilha_Enc(TipoPilha_EnC *Pilha);
int pilha_Enc_Vazia(TipoPilha_EnC Pilha);
void Empilha_EnC(TipoItem x, TipoPilha_EnC *Pilha);
void DesEmpilha_EnC(TipoPilha_EnC *Pilha, TipoItem *item_p);



void Inicia_Pilha_Enc(TipoPilha_EnC *Pilha) {
    Pilha->Topo = (Apontador) malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;

}

int pilha_Enc_Vazia(TipoPilha_EnC Pilha) {
    return (Pilha.Topo == Pilha.Fundo);
}


void Empilha_EnC(TipoItem x, TipoPilha_EnC *Pilha)
{
    Apontador Aux;
    Aux = (Apontador) malloc(sizeof(TipoCelula));
    Pilha->Topo->item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void DesEmpilha_EnC(TipoPilha_EnC *Pilha, TipoItem *item)
{
    Apontador q;
    if (pilha_Enc_Vazia(*Pilha))  {
        printf("Erro: Pilha vazia\n");
        return;
    }
    q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *item = q->Prox->item;
    free(q);
    Pilha->Tamanho--;
}


#ifdef	__cplusplus
}
#endif

#endif	/* TAD_PILHA_ENCADEADA_H */







