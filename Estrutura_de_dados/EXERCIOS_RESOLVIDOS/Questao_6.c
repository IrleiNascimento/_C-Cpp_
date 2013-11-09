
#include<stdio.h>
#include"TAD_COMPLETO/TAD_Pilha_Encadeada.h"
#include"TAD_COMPLETO/TAD_Pilha_estatica.h"
#include"TAD_COMPLETO/TAD_Fila_Dinamica.h"

/* 6.Construir uma fun��o que troca de lugar o
elemento que est� no topo da pilha com o que
est� na base da pilha. Usar apenas uma pilha como auxiliar.*/

typedef struct Item {
	TipoChave chave;
} Item;
void Imprime_f(TipoFilaDin Fila);
void Imprime_p_EnC (TipoPilha_EnC Pilha);
void Imprime_p_EsT (TipoPilha_EsT Pilha);
void troca_topo_fundo_p_encadeada(TipoPilha_EnC *Pilha);
void troca_topo_fundo_p_estatica(TipoPilha_EsT *Pilha);
int main() {

    TipoPilha_EnC p1;
    Inicia_Pilha_Enc(&p1);
     TipoPilha_EsT p2;
    inicia_Pilha_EsT(&p2);
    Item it[10] = {25,24,23, 22,20,19,18,17,16,3};
     Item it2[10] = {30,24,23, 22,20,19,18,17,16,66};
    int i;
    for(i=0; i<10; i++) {
        Empilha_EnC(&it[i],&p1);
         empilha_EsT(&it2[i],&p2);
    }
     printf("\n\nTESTE COM PILHA ENCADEADA\n\n");
    printf("\nPILHA ORIGEM\n");
    printf("\nTOPO =");
     Imprime_p_EnC(p1);
   troca_topo_fundo_p_encadeada(&p1);
    printf("\nPILHA P2 RESULTADO\n");
    printf("\nTOPO =");
     Imprime_p_EnC(p1);
     printf("\n");
      system("pause");
        printf("\n\nTESTE COM PILHA ESTATICA\n\n");
       printf("\nPILHA ORIGEM\n");
    printf("\nTOPO =");
     Imprime_p_EsT(p2);
   troca_topo_fundo_p_estatica(&p2);
    printf("\n\nPILHA P2 RESULTADO\n");
    printf("\nTOPO =");
     Imprime_p_EsT(p2);
    return 0;
}
void troca_topo_fundo_p_estatica(TipoPilha_EsT *Pilha){
if(pilha_EsT_Vazia(*Pilha))
return;
TipoItem item_aux;
item_aux =Pilha->itens[Pilha->topo];
Pilha->itens[Pilha->topo]=Pilha->itens[0];
Pilha->itens[0]=item_aux ;

}

void troca_topo_fundo_p_encadeada(TipoPilha_EnC *Pilha){
if(pilha_Enc_Vazia(*Pilha))
return;
TipoItem item_aux;
item_aux = Pilha->Topo->Prox->item;
Pilha->Topo->Prox->item = Pilha->Fundo->item;
Pilha->Fundo->item = item_aux;
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
        aux = aux->item;
    }
      printf("\n");
}
void Imprime_p_EsT (TipoPilha_EsT Pilha){

    int aux;
 Item *temp;
    for (aux = Pilha.topo; aux >= 0; aux--){
        temp = Pilha.itens[aux];
        printf("%d ", temp->chave);
    }
}
void Imprime_p_EnC (TipoPilha_EnC Pilha) {
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



