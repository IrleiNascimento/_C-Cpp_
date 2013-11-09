#include<stdio.h>
#include"TAD_ESD.h"
#include"TAD_Pilha_estatica.h"

/* 1.	Dada uma pilha P, construir uma função que inverte a ordem dos
 elementos dessa pilha, utilizando apenas uma estrutura auxiliar.
 Definir adequadamente a estrutura auxiliar e prever a possibilidade da pilha estar vazia.*/
typedef struct Item {
    TipoChave chave;
} Item;

void Imprime (TipoPilha_EsT Pilha);
void inverte_pilha(TipoPilha_EsT *Pilha);

void Imprime (TipoPilha_EsT Pilha) {
   int Aux;
    Item *temp;
    for (Aux = Pilha.topo; Aux >= 0; Aux--) {
        temp =  Pilha.itens[Aux];
        printf("Chave : %d\n", temp->chave);
    }
    printf("\n");
}
