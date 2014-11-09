#include <stdio.h>


typedef int TipoChave;
typedef struct TipoCelula * Apontador;

typedef struct {
	TipoChave reg;

} TipoItem;

typedef struct TipoCelula {
	TipoItem item;
	Apontador Prox;
} TipoCelula;

typedef struct {
	Apontador frente, tras;
	int tamanho;
} TipoFila;

void Inicia(TipoFila *Fila);
int Vazia(TipoFila *Fila);
void Enfileira(TipoItem x, TipoFila *Fila);
int Desenfileira(TipoFila *Fila, TipoItem *item);
void imprime(TipoFila Fila);
void fechar(int s);

void Inicia(TipoFila *Fila) {
	Fila->frente = (Apontador) malloc(sizeof(TipoCelula));
	Fila->tras = Fila->frente;
	Fila->frente->Prox = NULL;
	Fila->tamanho = 0;
}

int Vazia(TipoFila *Fila) {
	return (Fila->frente == Fila->tras);
}

void Enfileira(TipoItem x, TipoFila *Fila) {
	Fila->tras->Prox = (Apontador) malloc(sizeof(TipoCelula));
	Fila->tras = Fila->tras->Prox;
	Fila->tras->item = x;
	Fila->tras->Prox = NULL;
	Fila->tamanho = Fila->tamanho + 1;
}

int Desenfileira(TipoFila *Fila, TipoItem *item) {
	Apontador aux;
	if (Vazia(Fila)) {
		printf("fila Vazia\n");
		return 0;
	} else {
		aux = Fila->frente;
		Fila->frente = Fila->frente->Prox;
		*item = Fila->frente->item;
		free(aux);
		Fila->tamanho = Fila->tamanho - 1;
	}
	return 1;
}
void imprime(TipoFila Fila){
	if(Vazia(&Fila)){
		printf("Nenhum processo...");
		return;
	}
	Apontador aux = Fila.frente->Prox;
	while(aux !=NULL){
		printf("Numero do processo : %d\n",aux->item.reg);
		aux= aux->Prox;
	}
}
void fechar(int s) {
	char op;
	printf("\n'ENTER' - menu \n");
	op = getch();
s = 1;
}
int main(int argc, char **argv) {
	int s=1;
	int process_count=0;
	char op;
	TipoItem item;
	TipoFila fila;
	Inicia(&fila);

	do {
system("cls");
	    printf("        Gerenciador de Processos       ");
		printf("\n\n1 - Incluir processo na Fila\n");
		printf("2 - Retirar processo da Fila\n");
		printf("3 - Listar processos\n");
		printf("4 - sair\n\n");

		op = getch();

		switch (op) {
		case '1':

			process_count++;
			item.reg = process_count;
			Enfileira(item, &fila);
            printf("Processo de numero %d inserido na fila...",process_count);
			fechar(s);
			break;
		case '2':
		if(!Vazia(&fila)){
			Desenfileira(&fila, &item);
			printf( "Processo numero %d  foi retirado\n",item.reg );
			}else
			printf("Nenhum processo...");
			fechar(s);
			break;
		case '3':
            imprime(fila);
            fechar(s);
			break;
			case '4':
			exit(0);
			break;
		default:
			break;
		}
	} while (s);

	return 0;
}

