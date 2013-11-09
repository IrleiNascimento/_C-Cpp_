#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "TAD_COMPLETO/TAD_Pilha_Encadeada.h"

/* 8.Utilizando uma pilha, escreva um m�todo que receba um
n�mero inteiro positivo no formato decimal e
converte este n�mero para o formato bin�rio. Exemplos:*/


typedef struct Item {
    TipoChave chave;
    int num;
} Item;


void imprime_binario(TipoPilha_EnC Pilha);
void Imprime_p_EnC (TipoPilha_EnC Pilha);

char *converte_int_binario(int num);


int main() {
    TipoPilha_EnC p1;
    Inicia_Pilha_Enc(&p1);

    Item it[10] = {
        {1,25},
        {2,24},
        {3,23},
        {4,22},
        {5,21},
        {6,20},
        {7,19},
        {8,18},
        {9,16},
        {10,30}
    };

    int i;
    for(i=0; i<10; i++) {
        Empilha_EnC(&it[i],&p1);
    }
    printf("\n VALORES DA PILHA EM DECIMAL\n");
    printf("\nTOPO =");
    Imprime_p_EnC(p1);
    printf("\n\nCONVERSAO\n\n");
    imprime_binario(p1);
    int n= 500067;
//converte_int_binario(n);
    return 0;
}



char *converte_int_binario(int num) {
    char  str_bin[256];
    itoa(num,str_bin,2);
    return str_bin;
}

void Imprime_p_EnC (TipoPilha_EnC Pilha) {
    if(pilha_Enc_Vazia(Pilha)) {
        printf("Pilha Vazia\n");
        return;
    }
    Item *temp;
    Apontador aux;
    aux = Pilha.Topo->Prox;
    while (aux != NULL) {
        temp = aux->item;
        printf("%d ", temp->num);
        aux = aux->Prox;
    }
    printf("\n");
}
void imprime_binario(TipoPilha_EnC Pilha) {

    if(pilha_Enc_Vazia(Pilha)) {
        printf("Pilha Vazia\n");
        return;
    }
    Item *temp;
    Apontador aux;
    aux = Pilha.Topo->Prox;
    while (aux != NULL) {
        temp = aux->item;
        printf("%d  ->  %s\n",temp->num,converte_int_binario(temp->num));
        aux = aux->Prox;
    }
    printf("\n");
}
