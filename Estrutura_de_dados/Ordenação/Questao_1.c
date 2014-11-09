/*
 * main.c
 *
 *  Created on: 08/04/2013
 *      Author: Irlei
 */

#include <stdio.h>
#include <string.h>
#define MaxTam 20
#define InicioVetor 0

typedef int TipoChave;
typedef int Apontador;

typedef struct {
	TipoChave chave;
	char aluno[80];
	float nota;
} TipoItem;

typedef struct {
	TipoItem itens[MaxTam];
	Apontador Primeiro, Ultimo;
} TipoLista;

void Inicia_Lista(TipoLista *Lista);
int Lista_Vazia(TipoLista Lista);
int Insere_Lista(TipoItem x, TipoLista *Lista);
void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item);
void ImprimeLista(TipoLista Lista);

int buscar_item(int chave, TipoLista *Lista);

void remove_varios(int qtd,int pos,TipoLista *L1);
TipoLista retorna_encadeado(TipoLista *L1);
int main() {
	TipoLista listaAlunos;
	TipoItem item;
	int i;
	Inicia_Lista(&listaAlunos);

	TipoItem alunos[MaxTam] = {

	{ 1, " Fernado", 8.0 }, { 2, " João", 9.0 }, { 3, " Jozé", 5.0 }, { 4,
			" Ricardo", 6.5 }, { 5, " Carlos", 7.5 }, { 6, " Souza", 4.0 }, { 7,
			" Henrique", 3.0 }, { 8, " Irlei", 8.5 }, { 9, " Jaime", 4.5 }, { 10,
			"Gabriel", 9.0 },

	};

	for (i = 0; i < 10; i++) {
		Insere_Lista(alunos[i], &listaAlunos);
	}

	remove_varios(3,4,&listaAlunos);

	return 0;
}

void Inicia_Lista(TipoLista *Lista) {
	Lista->Primeiro = InicioVetor;
	Lista->Ultimo = Lista->Primeiro;
}

int Lista_Vazia(TipoLista Lista) {
	return Lista.Primeiro == Lista.Ultimo;
}

int Insere_Lista(TipoItem x, TipoLista *Lista) {
	if (Lista->Ultimo > MaxTam - 1) {
		printf("Lista esta cheia\n");
		return (0);
	} else {
		Lista->itens[Lista->Ultimo] = x;
		Lista->Ultimo++;
		return (1);
	}
}

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item) {

	int Aux;
	if (Lista_Vazia(*Lista) || p >= Lista->Ultimo) {
		printf("Erro posicao nao existe! %d        U%d\n", p, Lista->Ultimo);
		return;
	}

	*Item = Lista->itens[p - 1];

	for (Aux = p; Aux < Lista->Ultimo; Aux++) {
		Lista->itens[Aux - 1] = Lista->itens[Aux];
	}
	Lista->Ultimo--;
}

void ImprimeLista(TipoLista Lista) {

	printf("CHAVE             ALUNO             NOTA\n\n");
	int Aux;
	for (Aux = Lista.Primeiro; Aux <= (Lista.Ultimo - 1); Aux++)
		printf("%d                  %s            %.2f\n",
				Lista.itens[Aux].chave, Lista.itens[Aux].aluno,
				Lista.itens[Aux].nota);
}

int buscar_item(int valor, TipoLista *Lista) {
	Apontador aux;
	if (Lista_Vazia(*Lista))
		return 0;
	int result = 0;
	aux = Lista->Primeiro;
	while ((!result) && (aux <= Lista->Ultimo)) {
		if (Lista->itens[aux].chave == valor) {
			result = 1;
		}
		aux++;
	}
	return (result ? aux - 1 : -1);
}

void remove_varios(int qtd,int pos,TipoLista *L1){
	Apontador aux;
	TipoItem item;
	aux = L1->Primeiro;
	while(aux < L1->Ultimo){
		if(aux == pos){
			int i, r=aux+1;
			for(i=0;i<qtd;i++){
				Retira_Lista(r+i,L1,&item);
				r=r-1; // esqueci isso na prova
			}
			break;
		}
		aux++;
	}
}

TipoLista_ENC retorna_encadeada(TipoLista *L1){
	Apontador aux;
	Insere_Lista_ENC L2;
	Insere_Lista_ENC(&L2);
	while(aux < L1->Ultimo){
		if(L1->itens[aux].chave %2 ==0){
			Insere_Lista_ENC(&L2);
		}
		aux++;
	}
	return L2;
}

TipoLista valores_iguais(TipoLista *L1, TipoLista *L2) {
	Apontador aux, aux2;
	TipoLista L3;
	Inicia_Lista(&L3);
	aux = L1->Primeiro;
	aux2 = L2->Primeiro;
	while (aux < L1->Ultimo) {
		while (aux2 < L2->Ultimo) {
			if (L1->itens[aux].chave == L2->itens[aux2].chave) {
				Insere_Lista(L1->itens[aux2], &L3);
				break; // esqueci isso na prova
			}
			aux2++;
		}
		aux++;
	}
	return L3;
}
