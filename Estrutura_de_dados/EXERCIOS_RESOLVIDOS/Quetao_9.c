#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "TAD_ESD.h"
#include"TAD_Lista_Encadeada.h"
#include"TAD_Pilha_Encadeada.h"
/*9.Dada uma lista encadeada de caracteres formada por
uma sequência alternada de letras e dígitos, construa um
 funcao que retorne uma lista na qual as letras são mantidas na
 sequência original e os dígitos são colocados na ordem inversa.
 Exemplos:
A 1 E 5 T 7 W 8 G →  A E T W G 8 7 5 1

3 C 9 H 4 Q 6 → C H Q 6 4 9 3
*/


typedef struct Item {
    TipoChave chave;
    char carac;
} Item;



void Imprime (TipoPilha_EnC Pilha);
void Imprime_Lista(TipoListaEncad Lista);
void organiza_lista(TipoListaEncad *Lista);

int main() {
	TipoListaEncad L1;
	    inicia_Lista_Enc(&L1);
	    Item it[9] = {
	        {1,'A'},
	        {2,'1'},
	        {3,'E'},
	        {4,'5'},
	        {5,'T'},
	        {6,'7'},
	        {7,'W'},
	        {8,'8'},
	        {9,'G'}
	    };

	    int i;
	    for(i=0; i<9; i++) {
	        insere_Lista_Enc(&it[i],&L1);
	    }
	    printf("\nLISTA ORIGINAL\n");
	    Imprime_Lista(L1);

	    organiza_lista(&L1);

	    printf("\nLISTA ORGANIZADA\n");
	    Imprime_Lista(L1);
    return 0;
}
void organiza_lista(TipoListaEncad *Lista) {

    if(lista_Enc_Vazia(Lista))
        return;
    Apontador aux;
    Item *temp,*temp1;
    TipoListaEncad l_letra; // as letras ir� para lista
    TipoPilha_EnC p_digito;// os digitos ser�o colacados provisoriamente em uma pilha
    Inicia_Pilha_Enc(&p_digito);
    inicia_Lista_Enc(&l_letra);
    aux= Lista->Primeiro;
    while(aux->Prox != NULL) {
        temp = aux->Prox->item;
        if(isdigit(temp->carac)) { // verifica se � um digito
            Empilha_EnC(temp,&p_digito);
        } else {
            insere_Lista_Enc(temp,&l_letra);
        }
        aux=aux->Prox;
    }

    aux = p_digito.Topo->Prox;
   while(aux!=NULL){
	   insere_Lista_Enc(aux->item,&l_letra);// passando a pilha para a lista
	   aux=aux->Prox;
   }
    inicia_Lista_Enc(Lista);//  dando um fim na lista originam

  *Lista = l_letra; // a lista modificada (resultado)
}


void Imprime_Lista(TipoListaEncad Lista) {
    printf("\n");
    Apontador aux;
    Item *temp; // para ter acesso aos dados  vindo da lista devemos utilizar a struct local
    aux = Lista.Primeiro->Prox;
    while (aux != NULL ) {
        temp = aux->item;  // aux fornece um apontador para uma struct TipoItem
        printf("%c ", temp->carac);
        aux = aux->Prox;
    }
    printf("\n");

}

void Imprime (TipoPilha_EnC Pilha) {
    Item *temp;
    Apontador aux;
    aux = Pilha.Topo->Prox;
    while (aux != NULL) {
        temp = aux->item;
        printf("%c", temp->carac);
        aux = aux->Prox;
    }
    printf("\n");
}


