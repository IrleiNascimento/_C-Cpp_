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

int busca_binaria(int chave, TipoLista *Lista);

int main() {
	TipoLista listaAlunos;
	TipoItem item;
	int i;
	Inicia_Lista(&listaAlunos);

	TipoItem alunos[MaxTam] = {

	{ 1, " Fernado", 8.0 }, { 2, " João", 9.0 }, { 3, " Jozé", 5.0 }, { 4,
			" Ricardo", 6.5 }, { 5, " Carlos", 7.5 }, { 6, " Souza", 4.0 }, { 7,
			" Henrique", 3.0 }, { 8, " Irlei", 8.5 }, { 9, " Jaime", 4.5 }, {
			10, "Gabriel", 9.0 },

	};

	for (i = 0; i < 10; i++) {
		Insere_Lista(alunos[i], &listaAlunos);
	}

	ImprimeLista(listaAlunos);

	printf("\n");

	printf("Buscando a chave 5:\n");

	printf("Resultado da busca:   %d\n\n", busca_binaria(8, &listaAlunos));

	printf("Buscando a chave 11:\n");
	printf("Resultado da busca:   %d", busca_binaria(11, &listaAlunos));

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

int busca_binaria(int valor, TipoLista *Lista) {
	int result = 0;
	Apontador maior = 0;
	Apontador menor = 0;
	Apontador meio = 0;
	if (Lista_Vazia(*Lista))
		return 0;
	maior = Lista->Ultimo;
	meio = (maior +menor) / 2;
	while ((!result) && (maior >= menor)) {
		if (Lista->itens[meio].chave == valor) {
			result = 1;
		} else if (valor < Lista->itens[meio].chave){
			maior = meio - 1;
		}else
			menor = meio + 1;
			meio = (maior + menor) / 2;
	}
	return (result ?  meio : -1);
}

