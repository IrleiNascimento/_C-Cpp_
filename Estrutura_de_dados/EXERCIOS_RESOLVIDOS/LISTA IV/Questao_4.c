#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;

typedef struct Aluno {
	TipoChave chave;
	char nome[80];
	float media;

} TipoItem;

typedef struct TipoCelula *Apontador;

typedef struct TipoCelula {
	TipoItem Item;
	Apontador Prox;
} celula;

typedef struct {
	Apontador Primeiro, Ultimo;
	int tamanho;
} TipoLista;

void Inicia(TipoLista *Lista);
void Insere(TipoItem x, TipoLista *Lista);
void Remove(Apontador p, TipoLista *Lista, TipoItem *Item);
int Vazia(TipoLista *Lista);
void Imprime(TipoLista Lista);

Apontador busca_item(int valor, TipoLista *lista);

int main() {

	TipoItem aluno[10] = { { 100, "Aluno1 ", 7.0 }, { 102, "Aluno2 ", 8.0 }, {
			103, "Aluno3 ", 6.5 }, { 104, "Aluno4 ", 4.0 }, { 106, "Aluno6 ",
			6.0 }, { 107, "Aluno7 ", 3.0 }, { 108, "Aluno8 ", 10.0 }, { 109,
			"Aluno9 ", 7.5 }, { 110, "Aluno10", 7.0 }, { 111, "Aluno5 ", 9.0 } };

	TipoLista Lista_1;

	Inicia(&Lista_1);

	int i;
	for (i = 0; i < 10; i++)
		Insere(aluno[i], &Lista_1);
	printf("ALUNOS\n\n");
	Imprime(Lista_1);

	Apontador ap = busca_item(106, &Lista_1);

	printf("Resultado da pesquisa : %s", &ap->Item.nome);

	return 0;

}

void Inicia(TipoLista *Lista) {
	Lista->Primeiro = (Apontador) malloc(sizeof(celula));

	Lista->Ultimo = Lista->Primeiro;

	Lista->Primeiro->Prox = NULL;

	Lista->tamanho = 0;
}

void Insere(TipoItem x, TipoLista *Lista)

{

	Lista->Ultimo->Prox = (Apontador) malloc(sizeof(celula));

	Lista->Ultimo = Lista->Ultimo->Prox;

	Lista->Ultimo->Item = x;

	Lista->Ultimo->Prox = NULL;

	Lista->tamanho += 1;

}
void Remove(Apontador p, TipoLista *Lista, TipoItem *Item) {
	/* Obs.: o item a ser retirado é o seguinte ao apontado por  p */
	Apontador pAux;
	if (Vazia(Lista) || p == NULL || p->Prox == NULL ) {
		printf(" Erro Lista vazia ou posicao nao existe\n");
		return;
	}
	pAux = p->Prox;
	*Item = pAux->Item;
	p->Prox = pAux->Prox;
	if (p->Prox == NULL )
		Lista->Ultimo = p;
	free(pAux);
	Lista->tamanho = Lista->tamanho - 1;
}

int Vazia(TipoLista *Lista) {
	return (Lista->Primeiro == Lista->Ultimo);
}

void Imprime(TipoLista Lista) {
	Apontador Aux;
	Aux = Lista.Primeiro->Prox;
	int posicao = 0;
	printf("\nMATRICULA      ALUNO               MEDIA     POSICAO\n\n");
	while (Aux != NULL ) {
		posicao++;
		printf("%d           %s              %.2f          %d\n",
				Aux->Item.chave, Aux->Item.nome, Aux->Item.media, posicao);

		Aux = Aux->Prox;
	}

}

Apontador busca_item(int valor, TipoLista *Lista) {
	Apontador aux;
	Apontador result=0;
	if (Vazia(Lista)) {
		return 0;
	}
	aux = Lista->Primeiro;
	while ((aux->Prox != NULL)) {
		if ((valor == aux->Prox->Item.chave)){
			result = aux;
			break;
		}
		aux = aux->Prox;
	}
	return((result) ? result : Lista->Ultimo);
}
