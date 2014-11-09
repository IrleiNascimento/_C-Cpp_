#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 10
#define CHEGADA 1
#define SAIDA 0

typedef char TipoChave;
typedef struct TipoCelula * Apontador;

typedef struct {
	TipoChave placa[10];
	int manobras;
} TipoItem;

typedef struct TipoCelula {
	TipoItem carro;
	Apontador Prox, Ant;
} TipoCelula;

typedef struct {
	Apontador frente, tras;
	int tamanho;
} TipoFila;

typedef struct {
	TipoItem carros[MAXTAM];
	int sul, norte;
	int carros_count;
} ESTAC;

void estacionamento(ESTAC *estac,TipoFila *espera,TipoItem *carro,int operacao);

void Inicia_ESTAC(ESTAC *estac);
int ESTAC_Vazia(ESTAC *estac);
void Enfileira_ESTAC(TipoItem x, ESTAC *estac);
void Desenfileira_ESTAC(ESTAC *estac, TipoItem *item);
void Imprime(ESTAC estac);

void Inicia(TipoFila *Fila);
int Vazia(TipoFila *Fila);
void Enfileira(TipoItem carro, TipoFila *Fila);
int Desenfileira(TipoFila *Fila, TipoItem *item);
void Imprime_E(TipoFila Fila);
void fechar(int s);

void retirar_carro(ESTAC *estac, char *placa);
int estacionar(ESTAC *estac, TipoItem *carro);
void mensagem(TipoItem carro, int msg);
int pesquisa(ESTAC *estac, char *placa);
void deslocar(ESTAC *estac, int posicao);
int fila_de_espera(TipoFila *Fila, TipoItem *carro, int op);

void Inicia_ESTAC(ESTAC *estac) {
	estac->sul = 1;
	estac->norte = estac->sul;
	estac->carros_count = 0;
}

int ESTAC_Vazia(ESTAC *estac) {
	return (estac->sul == estac->norte);
}

void Imprime(ESTAC estac) {
	if (ESTAC_Vazia(&estac)) {
		printf("\nErro fila esta vazia\n");
		return;
	}
	int aux = estac.norte;
	while (aux < estac.sul) {
		printf("Placa  : %s      pos= %d\n", estac.carros[aux - 1].placa,aux-1);
		aux++;
	}
}

void Enfileira_ESTAC(TipoItem carro, ESTAC *estac) {
	estac->carros[estac->sul - 1] = carro;
	estac->sul++;
	estac->carros_count++;
}

void deslocar(ESTAC *estac, int posicao) {
	int aux = posicao + 1;
	while (aux < estac->sul) {
		estac->carros[aux - 1] = estac->carros[aux];
		aux++;
	}
	estac->norte = 1;
	estac->sul--;
}
void Desenfileira_ESTAC(ESTAC *estac, TipoItem *carro) {
	if (ESTAC_Vazia(estac)) {
		printf("Estacionamento vazio\n");
		return;
	} else {
		*carro = estac->carros[estac->norte - 1];
		estac->norte++;
		estac->carros_count--;
	}
}

int estacionar(ESTAC *estac, TipoItem *carro) {
	if (estac->sul == MAXTAM + 1) {
		printf("\nTodas as vagas estao ocupadas\n");
		return 0;
	} else {
		carro->manobras = 0;
		Enfileira_ESTAC(*carro, estac);
		mensagem(*carro, CHEGADA);
		Imprime(*estac);
		return 1;
	}
}

int fila_de_espera(TipoFila *Fila, TipoItem *carro, int op) {

	switch (op) {
	case CHEGADA:
		Enfileira(*carro, Fila);
		return 1;
	case SAIDA:
		if (Vazia(Fila))
			return 0;
		Desenfileira(Fila,carro);
		return 1;
	default:
		return 0;
	}
	return 0;
}

void retirar_carro(ESTAC *estac, char *placa) {

	TipoItem carro;

	if (!strcmp(estac->carros[estac->norte - 1].placa, placa)) {
		Desenfileira_ESTAC(estac, &carro);
		carro.manobras++;
		mensagem(carro, SAIDA);
		deslocar(estac, SAIDA);
		return;

	} else if (pesquisa(estac, placa)) {
		TipoFila temp;
		Inicia(&temp);
		int aux = estac->norte - 1;
		while (strcmp(estac->carros[aux].placa, placa)) {
			Desenfileira_ESTAC(estac, &carro);
			carro.manobras++;
			Enfileira(carro, &temp);
			aux++;
		}

		Desenfileira_ESTAC(estac, &carro);
		carro.manobras++;
		mensagem(carro, SAIDA);

		deslocar(estac, aux);
		aux--;

		Apontador paux = temp.tras;
		while (aux >= 0) {
			estac->carros[aux] = paux->carro;
			estac->carros_count++;
			paux = paux->Ant;
			aux--;
		}

	} else
		printf("\nPlaca %s nao encontrada\n", placa);
}

int pesquisa(ESTAC *estac, char *placa) {
	int aux = estac->norte;
	while (aux < estac->sul) {
		if (!strcmp(estac->carros[aux - 1].placa, placa)) {
			return 1;
		}
		aux++;
	}
	return 0;
}

void Inicia(TipoFila *Fila) {
	Fila->frente = (Apontador) malloc(sizeof(TipoCelula));
	Fila->tras = Fila->frente;
	Fila->tras->Ant = Fila->frente;
	Fila->frente->Prox = Fila->tras;
	Fila->tamanho = 0;
}

int Vazia(TipoFila *Fila) {
	return (Fila->frente == Fila->tras);
}

void Enfileira(TipoItem carro, TipoFila *Fila) {
	Apontador aux = Fila->tras;
	Fila->tras->Prox = (Apontador) malloc(sizeof(TipoCelula));
	Fila->tras = Fila->tras->Prox;
	Fila->tras->carro = carro;
	Fila->tras->Ant = aux;
	Fila->tras->Prox = Fila->frente;
	Fila->frente->Ant = Fila->tras;
	Fila->tamanho = Fila->tamanho + 1;
}

int Desenfileira(TipoFila *Fila, TipoItem *item) {
	if(Vazia(Fila))
		return 0;
	Apontador Aux = Fila->frente->Prox;
	*item = Aux->carro;
	Fila->frente->Prox = Aux->Prox;
	Fila->frente->Prox->Ant = Fila->frente;
	if(Fila->frente->Prox == Fila->frente)
		Fila->frente = Fila->tras;
	free(Aux);
	Fila->tamanho = Fila->tamanho - 1;
	return 1;
}

void fechar(int s) {
	char op;
	printf("\n'ENTER' - menu \n");
	op = getch();
	s = 1;
}

void mensagem(TipoItem carro, int msg) {
	switch (msg) {
	case CHEGADA:
		printf("Veiculo foi estacionado.\n");
		break;
	case SAIDA:
		printf("Veiculo  %s foi retirado.\nNumero de manobras %d\n",
				carro.placa, carro.manobras);
		break;
	default:
		printf("...");
		break;
	}
}

void Imprime_E(TipoFila Fila) {
	if(Vazia(&Fila)){
		printf("Fila de espera vazia");
		return;
	}
	Apontador aux;
	aux = Fila.frente->Prox;
	printf("|  Ant       Chave      Prox  | \n\n");
	while (aux != Fila.frente) {
		printf("%s         %s       %s\n", aux->Ant->carro.placa,
				aux->carro.placa, aux->Prox->carro.placa);
		aux = aux->Prox;
	}
}
void estacionamento(ESTAC *estac,TipoFila *espera,TipoItem *carro,int operacao){

	switch (operacao) {
		case CHEGADA:
			if(!estacionar(estac,carro))
			fila_de_espera(espera,carro,CHEGADA);
			break;
		case SAIDA:
			retirar_carro(estac,carro->placa);
			if(!Vazia(espera)){
				fila_de_espera(espera,carro,SAIDA);
					estacionar(estac,carro);
				}
			break;
		default:
			break;
	}
}

int main(int argc, char **argv) {
	ESTAC estac;
	TipoFila espera;
	TipoItem carro[15]={
			{"1",0},
			{"2",0},
			{"3",0},
			{"4",0},
			{"5",0},
			{"6",0},
			{"7",0},
			{"8",0},
			{"9",0},
			{"10",0},
			{"11",0},
			{"12",0},
			{"13",0},
			{"14",0},
			{"15",0}
			};


	Inicia_ESTAC(&estac);
	Inicia(&espera);
Imprime_E(espera);
	int i ;
	for(i=0;i<15;i++){
		estacionamento(&estac,&espera,&carro[i],CHEGADA);
	}
	Imprime(estac);
	Imprime_E(espera);
	for(i=0;i<8;i++){
		estacionamento(&estac,&espera,&carro[i],SAIDA);
	}
	Imprime(estac);
		Imprime_E(espera);

	return 0;
}

