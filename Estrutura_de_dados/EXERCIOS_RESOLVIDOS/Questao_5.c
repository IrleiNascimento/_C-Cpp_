
#include<stdio.h>
#include"TAD_Pilha_Encadeada.h"
#include"TAD_Fila_Dinamica.h"

/* 5.Dada uma pilha P1 vazia e uma fila F1.
Escreva uma fun��o que inverta a ordem dos elementos de F1.*/

typedef struct Item {
	TipoChave chave;
} Item;
void Imprime_f(TipoFilaDin Fila);
void Imprime_p (TipoPilha_EnC Pilha);
void inverte_fila_na_pilha(TipoPilha_EnC *p1,TipoFilaDin *f1);
int main() {
    TipoFilaDin f1;
    TipoPilha_EnC p2;
    Inicia_f(&f1);
    Inicia_Pilha_Enc(&p2);
    Item it[10] = { 10, 9, 8, 7, 6, 5,  4,3, 2,1};
    //Item it2[10] = {25,24,23, 22,20,19,18,17,16,3};
    int i;
    for(i=0; i<10; i++) {
        Enfileira(&it[i],&f1);
        //Empilha(&it2[i],&p2);
    }
    printf("\nFILA F1 ORIGEM\n");
    printf("\nFRENTE =");
    Imprime_f(f1);

    inverte_fila_na_pilha(&p2,&f1);
       printf("\nPILHA P2\n");
    printf("\nTOPO =");
    Imprime_p(p2);

    printf("\nFILA F1 RESULTADO\n");
    printf("\nFRENTE =");
    Imprime_f(f1);
    return 0;
}



void inverte_fila_na_pilha(TipoPilha_EnC *p1,TipoFilaDin *f1){
TipoItem it_temp;
int aux=f1->tamanho;


while(aux>0 ){
Desenfileira(f1,&it_temp);
Empilha_EnC(it_temp,p1);
aux--;
}

Apontador p = p1->Topo->Prox;
while(p!=NULL){
DesEmpilha_EnC(p1,&it_temp);
Enfileira(it_temp,f1);
p=p->Prox;
}

}
void Imprime_f(TipoFilaDin Fila) {
    if(Vazia_f(&Fila)){
        printf("Fila Vazia\n");
        return;
    }
    Item *temp;
    Apontador aux;
    aux = Fila.frente->Prox;
    while (aux != NULL) {
        temp = aux->item;
        printf("%d  ", temp->chave);
        aux = aux->Prox;
    }
      printf("\n");
}

void Imprime_p (TipoPilha_EnC Pilha) {
      if(pilha_Enc_Vazia(Pilha)){
        printf("Pilha Vazia\n");
        return;
    }
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


