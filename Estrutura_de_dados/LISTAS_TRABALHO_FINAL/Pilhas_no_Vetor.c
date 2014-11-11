/*
 * 
 *
 *  
 *      Author: Irlei
 
 Elabore um método para manter duas pilhas dentro de um 
 único vetor linear de modo que nenhuma das pilhas incorra em 
 estouro até que toda a memória seja usada, e uma pilha inteira 
 nunca seja deslocada para outro local dentro do vetor. Escreva rotinas em C, push1, push2, 
 pop1 e pop2, para manipular as duas pilhas. (Dica: as duas pilhas crescem na direção da outra
 */
#include<stdio.h>
#define MAXTAM 10
#define p system("pause")
typedef int TipoChave;

typedef struct{
  TipoChave chave;
} TipoItem;

typedef struct{
   TipoItem itens[MAXTAM];
    int topo,fundo;
    int tamanho;
} TipoPilha;

void Inicia_Pilhas(TipoPilha *P1,TipoPilha *P2);
int Vazia(TipoPilha Pilha);
void push1(TipoItem item, TipoPilha *P1,TipoPilha *P2);
void push2(TipoItem item, TipoPilha *P2,TipoPilha *P1);
void pop1(TipoPilha *P1,TipoItem *item);
void pop2(TipoPilha *P2,TipoItem *item);
void imprime(TipoPilha Pilha);

void Inicia_Pilhas(TipoPilha *P1,TipoPilha *P2){
	P1->topo = -1;
	P1->fundo = P1->topo;
	P1->tamanho=0;
	P2->topo = MAXTAM;
	P2->fundo=P2->topo;
	P2->tamanho=0;
}

int Vazia(TipoPilha Pilha) {
    return (Pilha.tamanho == 0);
}


void push1(TipoItem item, TipoPilha *P1,TipoPilha *P2) {
	 if (P1 -> topo+1 == P2->topo){
        printf("Erro memoria cheia!\n");}
    else {
        P1->topo++;
        P1->itens[P1->topo] = item;
        P1->tamanho++;
    }
}
void push2(TipoItem item, TipoPilha *P2,TipoPilha *P1) {
	if (P2->topo-1 == P1->topo){
        printf("Erro memoria cheia!\n");
    return;
    }
        P2->topo--;
        P2->itens[P2->topo] = item;
        P2->tamanho++;
}

void pop1(TipoPilha *P1,TipoItem *item){
    if (Vazia(*P1))
        printf(" Erro   pilha esta  Vazia\n");
    else {
        *item = P1->itens[P1->topo];
        P1->topo--;
    }
}

void pop2(TipoPilha *P2,TipoItem *item){
    if (Vazia(*P2))
        printf(" Erro   pilha esta  Vazia\n");
    else {
        *item = P2->itens[P2->topo];
        P2->topo++;
    }
}

 int main(int argc, char **argv) {
	 int op,OP, valor=0;
	 TipoItem item;
	 TipoPilha p1,p2;
	 Inicia_Pilhas(&p1,&p2);
	 do{
OP_Invalida:system("cls");
printf(" TESTE PILHAS NO VETOR  \n\n");
printf("\n1 =  INSEIR ITEM");
printf("\n2 =  IMPRIMIR PILHA 1");
printf("\n3 =  IMPRIMIR PILHA 2");
printf("\n4 =  IMPRIMIR TODAS");
printf("\n5 =  SAIR\n");
 OP = getch();
fflush(stdin);
switch (OP){
case '1':
printf("\nDigite um valor inteiro para a chave do item:  ");
scanf("%d",&item.chave);
fflush(stdin);
opInvalida:printf("\nInseir na PILHA ?(1/2) ");
 op = getch();
fflush(stdin);
switch (op) {
	case '1':
		push1(item,&p1,&p2);
		printf("%c Ok!\n\n",op);
		p;
		break;
	case '2':
		push2(item,&p2,&p1);
			printf("%c Ok!\n\n",op);
		p;
		break;
	default:
		printf("\nOpcao Invalida");
		p;
		 goto opInvalida;
		break;
}
break;
case '2':
imprime(p1);
p;
break;
case '3':
imprime(p2);
p;
break;
case '4':
	imprime(p1);
	imprime(p2);
	p;
	break;
case '5':
	exit(0);
default:
		printf("\nOpcao Invalida");
		 goto OP_Invalida;
		break;
}
	 }while(OP!=5);
	return 0;
}


 void imprime(TipoPilha Pilha){
	if(Vazia(Pilha)) {
		printf("\nPilha Vazia\n");
		return;
	}
		int aux ;
		if(Pilha.fundo>0){
			printf("\nPILHA 2\n");
		for(aux=Pilha.topo;aux<Pilha.fundo;aux++)
		printf("Item = %d   Posicao = %d\n",Pilha.itens[aux].chave,aux);
		printf("\n");

	}else{
		printf("\nPILHA 1\n");
		for(aux=Pilha.topo;aux>=0;aux--)
			printf("Item = %d   Posicao = %d\n",Pilha.itens[aux].chave,aux);
		printf("\n");
	}
 }
