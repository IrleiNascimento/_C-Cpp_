#include<stdio.h>
#include"TAD_ESD.h"
#define MAXTAM 10


typedef struct{
   TipoItem itens[MAXTAM];
    int topo;
} TipoPilha_EsT;

void inicia_Pilha_EsT(TipoPilha_EsT *Pilha);
int pilha_EsT_Vazia(TipoPilha_EsT Pilha) ;
void empilha_EsT(TipoItem x, TipoPilha_EsT *Pilha);
void desempilha_EsT(TipoPilha_EsT *Pilha,TipoItem *itens);



void inicia_Pilha_EsT(TipoPilha_EsT *Pilha) {
    Pilha ->topo = -1;
}

int pilha_EsT_Vazia(TipoPilha_EsT Pilha) {
    return (Pilha.topo == -1);
}


void empilha_EsT(TipoItem x, TipoPilha_EsT *Pilha) {
    if (Pilha ->topo == MAXTAM-1){
        printf(" Erro   pilha esta  cheia\n");}
    else {
        Pilha->topo++;
        Pilha->itens[Pilha->topo] = x;
    }
}
void desempilha_EsT(TipoPilha_EsT *Pilha,TipoItem *itens) {
    if (pilha_EsT_Vazia(*Pilha))
        printf(" Erro   pilha esta  pilha_EsT_Vazia\n");
    else {
        *itens = Pilha->itens[Pilha->topo];
        Pilha->topo--;
    }
}




