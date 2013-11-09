#include<stdio.h>
#include"TAD_COMPLETO/TAD_Pilha_Encadeada.h"

/* 3.Dadas duas pilhas estaticas numericas ordenadas crescentemente a partir
do topo. Faca uma funcao que transfira os elementos dessas
pilhas para uma terceira pilha, inicialmente vazia,
de modo que ela fique ordenada decrescentemente com o maior valor no topo.*/

typedef struct Item {
    TipoChave chave;
} Item;

void Imprime (TipoPilha_EnC Pilha);
void par_e_impar(TipoPilha_EnC *Pilha);
TipoPilha_EnC inverte_ordenacao_pilha(TipoPilha_EnC *p1,TipoPilha_EnC *p2);
void ordenacao_selecao(Item vet[], int tamanho);

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

     printf("\nPILHA RESULTADO\n");
     printf("\nTOPO =");
    Imprime(inverte_ordenacao_pilha(&p1,&p2));
    return 0;
}
TipoPilha_EnC inverte_ordenacao_pilha(TipoPilha_EnC *p1,TipoPilha_EnC *p2) {
    Apontador aux,aux2,aux3;
    TipoPilha_EnC result;
    Item *temp1, *temp2;
    temp1= p1->Topo->Prox->item;
    temp2= p2->Topo->Prox->item;
    int compara_menor =(temp1->chave<=temp2->chave? 1:0);
    if(compara_menor) {
        p1->Fundo->Prox =p2->Topo->Prox;
        compara_menor=temp1->chave;
        aux = p1->Topo;
    } else {
        p2->Fundo->Prox = p1->Topo->Prox;
        compara_menor=temp2->chave;
        aux = p2->Topo;
    }
    Inicia_Pilha_Enc(&result);

    while(aux->Prox!=NULL) {
        temp1= aux->Prox->item;
        aux2 = aux->Prox;
        while(aux2->Prox!=NULL) {
            temp2=aux2->Prox->item;
            if(temp1->chave>temp2->chave) {
                aux3 = aux2->Prox;
                aux2->Prox=aux3->Prox;//ZORRA TOTAL
                aux3->Prox=aux->Prox;
                aux->Prox=aux3;
            }
            aux2=aux2->Prox;
        }
        Empilha_EnC(aux->Prox->item,&result);
          aux=aux->Prox;
    }

    return result;
}


void Imprime (TipoPilha_EnC Pilha) {
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
// considerando TipoChave como um valor inteiro
void ordenacao_selecao(Item vet[], int tamanho) {
    Item temp;
    int i,j;
    for (i = 0; i < tamanho; i++)
        for (j = i + 1; j < tamanho; j++)
            if (vet[i].chave > vet[j].chave) {
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
}


