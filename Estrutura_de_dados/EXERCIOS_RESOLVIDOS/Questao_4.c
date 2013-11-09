#include<stdio.h>
#include"TAD_COMPLETO/TAD_Pilha_Encadeada.h"
#include"TAD_COMPLETO/TAD_Pilha_Estatica.h"
/* 4.Dadas duas pilhas P1 e P2. Fa�a uma fun��o que transfira os
elementos de P1 para P2, mantendo a mesma ordem dos elementos.*/

typedef struct Item {
    TipoChave chave;
} Item;

void transfere_pilha_encadeada(  TipoPilha_EnC *p1,  TipoPilha_EnC *p2);
void transfere_pilha_estatica(  TipoPilha_EsT *p1,  TipoPilha_EsT *p2);
int main() {
    TipoPilha_EnC p1;
      TipoPilha_EnC p2;
    Inicia_Pilha_Enc(&p1);
    Inicia_Pilha_Enc(&p2);
    Item it[10] = { 10, 9, 8, 7, 6, 5,  4,3, 2,1};
    Item it2[10] = {25,24,23, 22,20,19,18,17,16,3};
    int i;
    for(i=0; i<10; i++) {
        Empilha_EnC(&it[i],&p1);
        Empilha_EnC(&it2[i],&p2);
    }
    printf("\nPILHA 1");
    printf("\nTOPO =");
    Imprime(p1);
    printf("\nPILHA 2");
    printf("\nTOPO =");
    Imprime(p2);
    transfere_pilha_encadeada(&p1,&p2);
    printf("\nPILHA 1");
    printf("\nTOPO =");
    Imprime(p1);
    printf("\nPILHA 2\n");
    printf("\nTOPO =");

    Imprime(p2);
    return 0;
}


void transfere_pilha_encadeada(  TipoPilha_EnC *p1,  TipoPilha_EnC *p2) {
    if(pilha_Enc_Vazia(*p1) && pilha_Enc_Vazia(*p2))
        return;
    p2->Fundo->Prox = p1->Topo->Prox;
    p2->Tamanho+= p1->Tamanho;
    Inicia_Pilha_Enc(p1);
}


void transfere_pilha_estatica(TipoPilha_EsT *p1,  TipoPilha_EsT *p2) {
      TipoPilha_EsT p_temp;
    inicia_Pilha_EsT(&p_temp);
   int aux = p1->topo;
    while(aux> -1){
        empilha_EsT(p1->itens[aux],&p_temp);
        aux--;
    }
    aux = p_temp.topo;
    while(aux> -1) {
        empilha_EsT(p_temp.itens[aux],p2);
        aux--;
    }
}


void Imprime (  TipoPilha_EnC Pilha) {
    Item *temp;
    Apontador aux;
    aux = Pilha.Topo->Prox;
    while (aux != NULL) {
        temp = aux->item;
        printf("%d ", temp->chave);
        aux = aux->Prox;
    }
    printf("\n");
}
