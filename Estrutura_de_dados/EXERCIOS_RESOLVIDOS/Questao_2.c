#include<stdio.h>
#include"TAD_COMPLETO/TAD_Pilha_estatica.h"

/* 2.	Dada uma pilha contendo n�meros inteiros quaisquer,
 construir uma fun��o que coloca os pares na base da pilha e
 os �mpares no topo da pilha. Usar duas pilhas como auxiliares.*/

typedef struct Item {
    TipoChave chave;
} Item;

void Imprime (TipoPilha_EsT Pilha);
void par_e_impar(TipoPilha_EsT *Pilha);

int main() {
    TipoPilha_EsT p1;
    inicia_Pilha_EsT(&p1);
    Item it[10] = {1,2,3,4,5,6,7,8,9,10};
    int i;
    for(i=0; i<10; i++) {
        empilha_EsT(&it[i],&p1);
    }
    Imprime(p1);
    divide_par_e_impar(&p1);
    Imprime(p1);
    return 0;
}


void divide_par_e_impar(TipoPilha_EsT *Pilha) {
    if(pilha_EsT_Vazia(*Pilha))
        return;
   int aux;
    TipoPilha_EsT par;// pilha auxiliar
    TipoPilha_EsT impar;// pilha auxiliar
    inicia_Pilha_EsT(&par);
    inicia_Pilha_EsT(&impar);
    Item  *temp;
    aux = Pilha->topo;
    while(aux != -1) {
        temp = (int) Pilha->itens[aux]; // devido ao nosso TAD abstrato o CAST e necess�rio para ter acesso ao dados da struct
        if((temp->chave % 2) ==0) {
            empilha_EsT(temp,&par);
        } else {
            empilha_EsT(temp,&impar);
        }
        aux--;
    }
    inicia_Pilha_EsT(Pilha); // zerando a pilha
    *Pilha = par; // n�o precisamos de loop para pegar a primeira pilha.
    aux= impar.topo;
    while(aux != -1) {
        empilha_EsT(impar.itens[aux],Pilha); // pegando a segunda pilha
        aux--;
    }
}

void imprime_pliha_EsT (TipoPilha_EsT Pilha) {
   int Aux;
    Item *temp;
    for (Aux = Pilha.topo; Aux >= 0; Aux--) {
        temp =  Pilha.itens[Aux];
        printf("Chave : %d\n", temp->chave);
    }
    printf("\n");
}
