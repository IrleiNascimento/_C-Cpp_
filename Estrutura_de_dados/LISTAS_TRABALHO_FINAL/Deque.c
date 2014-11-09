#include<stdio.h>
#define MAXTAM 20
typedef int TipoChave;

typedef struct {
	TipoChave chave;
} TipoItem;

typedef struct {
	TipoItem itens[MAXTAM];
	int left;
	int right;
} Deque;

void inicia_deque(Deque *deque);

int deque_Vazio(Deque deque);

void insertRight(TipoItem x, Deque *deque);
void insertLeft(TipoItem x, Deque *deque);
void removLeft(Deque *deque, TipoItem *item);
void removRight(Deque *deque, TipoItem *item);

void inicia_deque(Deque *deque) {
	deque->left = -1;
	deque->right = MAXTAM;
}

int deque_Vazio(Deque deque) {
	return (deque.left == -1 && deque.right == MAXTAM);
}

void insertRight(TipoItem x, Deque *deque) {
	int t = deque->left;
	if (deque->right - 1 == deque->left) {
		printf("Deque cheio\n");
		return;
	} else {
		deque->right--;
		deque->itens[deque->right] = x;
	}
	deque->left = t;
}

void insertLeft(TipoItem x, Deque *deque) {
	if (deque->left + 1 == deque->right) {
		printf("Deque cheio\n");
		return;
	} else {
		deque->left++;
		deque->itens[deque->left] = x;
	}
}
void removLeft(Deque *deque, TipoItem *item) {

	if (deque_Vazio(*deque)) {
		printf("Erro   pilha esta  Vazia\n");
	} else {
		*item = deque->itens[deque->left];
		deque->left--;
	}
}
void removRight(Deque *deque, TipoItem *item) {
	if (deque_Vazio(*deque)) {
		printf("Deque vazio\n");
	} else {
		*item = deque->itens[deque->right];
		deque->right++;
	}

}

void imprime(Deque deque) {
	if (deque_Vazio(deque)) {
		printf("Deque vazio\n");
		return;
	}
	int aux = 0;
	aux = deque.left;
	while (aux > -1) {
		printf("Chave : %d       inserido pela esquerda\n", deque.itens[aux].chave);
		aux--;
	}
	aux = deque.right;
	while (aux < MAXTAM) {
		printf("Chave : %d       inserido pela DIREITA\n", deque.itens[aux].chave);
		aux++;
	}
}

int main() {
    printf("\nTESTE COM TENTATIVA DE INSERCAO DE 30 ITENS  NO DEQUE\nObs: O TAMANHO MAX DO DEQUE E 20\n");
	TipoItem its[15] = { 1, 2, 3, 4, 5 ,6,7,8,9,10,11,12,13,14,15};
	TipoItem it1s[15] = { 1, 2, 3, 4, 5 ,6,7,8,9,10,11,12,13,14,15};
	Deque dq;
	inicia_deque(&dq);
	int i;
	for (i = 0; i < 15; i++) {
		insertLeft(its[i], &dq);
		insertRight(it1s[i], &dq);
	}
 printf("\nDEQUE COMPLETO\n\n");
	TipoItem it;
	imprime(dq);

	 printf("\nREMOCAO DE 3 ITENS PELA ESQUERDA\n\n");
	removLeft(&dq,&it);
	removLeft(&dq,&it);
	removLeft(&dq,&it);
	imprime(dq);
	 printf("\nREMOCAO DE 3 ITENS PELA DIREITA\n\n");
	removRight(&dq,&it);
	removRight(&dq,&it);
	removRight(&dq,&it);


	imprime(dq);
}
