/*
 * Todas_as_Questoes.c
 *
 *  Created on: 17/06/2013
 *      Author: Irlei
 */


#include <stdio.h>
#include <ctype.h> // para utilizar algumas fun�oes de convers�o de dados
#include <stdlib.h>
#include <string.h>
#include "TAD_COMPLETO/TAD_ESD.h"  // permite a cria��o do TipoItem ,TipoChave e Apontador
#include "TAD_COMPLETO/TAD_Fila_Dinamica.h"
#include "TAD_COMPLETO/TAD_Lista_Encadeada.h"
#include "TAD_COMPLETO/TAD_Lista_Estatica.h"
#include "TAD_COMPLETO/TAD_Pilha_Encadeada.h"
#include "TAD_COMPLETO/TAD_Pilha_Estatica.h"

typedef struct{
    TipoChave chave;   /* Estrutura que sera utlizada na maior parte dos exemplos
                        por esse motivo ela est� sendo compartilha*/
} Item;

void inverte_pilha(TipoPilha_EsT *Pilha);// fun��o para Quest�o 1
void par_e_impar(TipoPilha_EsT *Pilha); // fun��o para Quest�o 2
void imprime_pliha_EnC(TipoPilha_EnC Pilha);// imprime plilha encadeada
void imprime_pliha_EsT (TipoPilha_EsT Pilha);// imprime plilha estatica
TipoPilha_EnC inverte_ordenacao_pilha(TipoPilha_EnC *p1,TipoPilha_EnC *p2);// fun��o para Quest�o 1
int main(){
	printf("\n  1.	Dada uma pilha P, construir uma fun��o que inverte a ordem dos \n"
			"elementos dessa pilha, utilizando apenas uma estrutura auxiliar. \n"
			"Definir adequadamente a estrutura auxiliar e \n"
			"prever a possibilidade da pilha estar vazia.\n\n");
	TipoPilha_EsT p1;
	    inicia_Pilha_EsT(&p1);
	    Item it[10] = {1,2,3,4,5,6,7,8,9,10};
	    int i;
	    for(i=0; i<10; i++) {
	        empilha_EsT(&it[i],&p1);
	    }
	    inverte_pilha(&p1);
	    imprime_pliha_EsT(p1);
	    inverte_pilha(&p1);
	    imprime_pliha_EsT(p1);

	    system("pause");

	    printf("\n 2.Dada uma pilha contendo n�meros inteiros quaisquer, \n"
	    		"construir uma fun��o que coloca os pares na base da pilha\n"
	    		" e os �mpares no topo da pilha. Usar duas pilhas como auxiliares. \n\n");

	       inicia_Pilha_EsT(&p1);

	       for(i=0; i<10; i++) {
	           empilha_EsT(&it[i],&p1);
	       }
	      imprime_pliha_EsT(p1);
	       divide_par_e_impar(&p1);
	       imprime_pliha_EsT(p1);
	       system("pause");
	       printf("\n 3.Dadas duas pilhas est�ticas num�ricas ordenadas crescentemente a\n"
	    		   " partir do topo. Fa�a uma fun��o que transfira os elementos \n"
	    		   "dessas pilhas para uma terceira pilha, inicialmente vazia, \n"
	    		   "de modo que ela fique ordenada decrescentemente com o maior valor no topo. \n\n");
	       TipoPilha_EnC p3;
	          TipoPilha_EnC p4;
	          Inicia_Pilha_Enc(&p3);
	          Inicia_Pilha_Enc(&p4);
	          Item it3[10] = { 10, 9, 8, 7, 6, 5,  4,3, 2,1};
	          Item it4[10] = {25,24,23, 22,20,19,18,17,16,3};

	          for(i=0; i<10; i++) {
	              Empilha_EnC(&it3[i],&p3);
	              Empilha_EnC(&it4[i],&p4);
	          }
	           printf("\nPILHA 1");
	            printf("\nTOPO =");
	            imprime_pliha_EnC(p3);
	           printf("\nPILHA 2");
	            printf("\nTOPO =");
	          imprime_pliha_EnC(p4);

	           printf("\nPILHA RESULTADO\n");
	           printf("\nTOPO =");
	          Imprime(inverte_ordenacao_pilha(&p3,&p4));
	          system("pause");
	return 0;
}

// fun��o para Quest�o 1
void inverte_pilha(TipoPilha_EsT *Pilha) {
   int aux;
    TipoItem itemAux[Pilha->topo];// estrutura auxiliar

    int tam=Pilha->topo;

    for(aux=Pilha->topo; aux>=0; aux--) {
        itemAux[aux] = Pilha->itens[aux];
    }
    inicia_Pilha_EsT(Pilha); // reinicia a pilha
    for(aux=tam; aux>=0; aux--) {
        empilha_EsT(itemAux[aux],Pilha); // empilha os valores do vetor de tras pra frente
    }
}

///////////////////////////////////////////////////////////// fun��o para Quest�o 2
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

void imprime_pliha_EnC(TipoPilha_EnC Pilha) {
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

void imprime_pliha_EsT (TipoPilha_EsT Pilha) {
   int Aux;
    Item *temp;
    for (Aux = Pilha.topo; Aux >= 0; Aux--) {
        temp =  Pilha.itens[Aux];
        printf("Chave : %d\n", temp->chave);
    }
    printf("\n");
}
