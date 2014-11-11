/*
 * Estacionamento_de_Bashemin.c
 *
 *  Created on: 21/07/2013
 *      Author: Irlei
 
  O Estacionamento de Bashemin contém uma única alameda
  que guarda até dez carros. Existe apenas uma entrada/saída no estacionamento,
  em uma extremidade da alameda. Se chegar um cliente para retirar um carro
  que não seja o mais próximo da saída, todos os carros bloqueando seu caminho 
  sairão do estacionamento, o carro do cliente será manobrado para fora do estacionamento, 
  e os outros carros voltarão a ocupar a mesma sequência inicial. 
  Escreva um programa que processe um grupo de linhas de entrada. Cada linha de entrada contém um 'E',
  de entrada, ou um 'S', de saída, e o número da placa do carro. Presume-se que os carros
  cheguem e partam na ordem especificada pela entrada. O programa deve imprimir uma mensagem
  sempre que um carro chegar ou sair. Quando um carro chegar, a mensagem deve especificar se existe 
  ou não vaga para o carro no estacionamento. Se não houver vaga, o carro partirá sem entrar no estacionamento.
  Quando um carro sair do estacionamento, a mensagem deverá incluir o 
 número de vezes em que o carro foi manobrado para fora do estacionamento para permitir que outros carros saíssem.
 */
#include<stdio.h>
#define MAXTAM 10
#define CHEGADA 1
#define SAIDA 0
typedef int Apontador;
typedef char TipoChave;
typedef struct TipoItem;

typedef struct {
    TipoChave placa[10];
    int manobra;
} TipoItem;

typedef struct {
    TipoItem Item[MAXTAM];
    Apontador E;
} TipoPilha;

void Inicia(TipoPilha *Pilha);
int Vazia(TipoPilha Pilha) ;
void Empilha(TipoItem x, TipoPilha *Pilha);
void Desempilha(TipoPilha *Pilha, TipoItem *Item);
void Imprime (TipoPilha Pilha);

void retirar_carro(TipoPilha *Pilha,char *placa);
int estacionar(TipoPilha *Pilha,TipoItem *carro);
void mensagem(TipoItem carro,int msg);

int pesquisa(TipoPilha *Pilha,char *placa);

void Inicia(TipoPilha *Pilha) {
    Pilha ->E = -1;
}

int Vazia(TipoPilha Pilha) {
    return (Pilha.E == -1);
}

void Empilha(TipoItem x, TipoPilha *Pilha) {
    if (Pilha ->E == MAXTAM-1)
        printf(" Erro   pilha esta  cheia\n");
    else {
        Pilha->E++;
        Pilha->Item[Pilha->E] = x;
    }
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item) {
    if (Vazia(*Pilha))
        printf(" Erro   pilha esta  vazia\n");
    else {
        *Item = Pilha->Item[Pilha->E];
        Pilha->E--;
    }
}


int estacionar(TipoPilha *Pilha,TipoItem *carro){
	 if (Pilha ->E == MAXTAM-1){
		 printf("Todas as vagas estao ocupadas");
		 return -1;
	 }else{
		 carro->manobra=0;
		 Empilha(*carro,Pilha);
		 mensagem(*carro,CHEGADA);
		 return CHEGADA;
	 }
}

void retirar_carro(TipoPilha *Pilha,char *placa){

	TipoItem carro;

	if(!strcmp(Pilha->Item[Pilha->E].placa,placa)){
		Desempilha(Pilha,&carro);
mensagem(carro,SAIDA);
	}else if(pesquisa(Pilha,placa)){
		Apontador aux=Pilha->E;
		TipoPilha temp;
		Inicia(&temp);
		while(strcmp(Pilha->Item[Pilha->E].placa,placa)){
			Desempilha(Pilha,&carro);
			carro.manobra++;
			Empilha(carro,&temp);
			aux--;
		}
Desempilha(Pilha,&carro);
mensagem(carro,SAIDA);
while(temp.E >= 0){
			Desempilha(&temp,&carro);
			Empilha(carro,Pilha);
		}
	}	else
printf("\nPlaca %s nao encontrada\n",placa);
}

int pesquisa(TipoPilha *Pilha,char *placa){

	Apontador aux = Pilha->E;
	while(aux>=0){
		if(!strcmp(Pilha->Item[aux].placa,placa)){
			return 1;
		}
		aux--;
	}
	return 0;
}


void mensagem(TipoItem carro,int msg){
	switch(msg){
	case CHEGADA :
		printf("Veiculo foi estacionado.\n");
		break;
	case SAIDA:
		printf("Veiculo foi retirado.\nNumero de manobras %d\n",carro.manobra);
			break;
	default :
		printf("...");
		break;
	}

}
void Imprime (TipoPilha Pilha) {
    if(Vazia(Pilha)){
    printf("\nEstacionamento vazio.\n");
    return;
    }
    Apontador Aux;

    for (Aux = Pilha.E; Aux >= 0; Aux--)
        printf("Placa:  %s\n", Pilha.Item[Aux].placa);
    printf("\n");
}
void fechar(int s){
    char op;
printf(" \n1 - menu \n");
printf(" 2 - sair \n");
op = getch();
switch(op){
    case '2':
     s =1;
    break;
    	default :
s =0;
break;
}
}
int main(){
    system("cls");
    int s=0;
char op=0;
    	TipoItem carro;
    	TipoPilha ESTAC;
	Inicia(&ESTAC);

do{
    system("cls");
    printf("\n           Estacionamento de Bashemin    \n");
printf("1- Estacionar:\n");
printf("2- Retirar:\n");
printf("3- Listar:\n\n");
op=getch();

switch(op){
case '1':
printf("Placa: ");
gets(carro.placa);
	estacionar(&ESTAC,&carro);
	fechar(s);
break;
case '2':
if(!Vazia(ESTAC)){
	printf("Placa: ");gets(carro.placa);
		retirar_carro(&ESTAC,carro.placa);
}else
    printf("\nEstacionamento vazio.\n");
fechar(s);
	break;
	case '3':
	Imprime(ESTAC);
		fechar(s);
	break;
	default :
s =0;
break;
}
}while(!s);
}

