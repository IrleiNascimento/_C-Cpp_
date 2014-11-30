/*
 * heap.c
 *
 *  Created on: 22/07/2013
 *      Author: Irlei
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct {
	char dado;
/*outros componentes*/
} TipoItem;
typedef struct {
	int tamanho; /* tamanho maximo do heap */
	int ultimo; /*proxima posição disponivel no vetor*/
	int *ptItem; /*ponteiro para um vetor de endereços dos itens*/
	int *prioridade; /*ponteiro para um vetor das prioridades */
} Heap;
Heap *constroi_Heap(int tam);
void heap_insere(Heap* heap, TipoItem *item, int prioridade);
TipoItem *heap_remove(Heap* heap);
TipoItem *find_max(Heap* heap);
void corrige_abaixo(Heap* heap, int posicao);
void corrige_acima(Heap *heap, int posicao);
void troca(int a, int b, Heap* heap);
void altera_prioridade(Heap* heap, int posicao, int pdNova);
Heap *merge_heap(Heap *h1, Heap *h2);
void heapSort(Heap* heap);
void imprime(Heap *heap);
int main() {
	printf("ok!\n\n");
	Heap *h = constroi_Heap(20);
	TipoItem it[20] = { 'A', 'B', 'C', 'D', 'F', 'G', 'H', 'H', 'I', 'J', 'L',
			'M', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
	int i;
	for (i = 0; i < 20; i++) {
		heap_insere(h, &it[i], i + 1);
	}

	Heap *h2 = constroi_Heap(10);
	TipoItem it2[10] = { '9', '7', '4', '1', '3', '8', '6', 'H', '0', 'J' };

	for (i = 0; i < 10; i++) {
		heap_insere(h2, &it2[i], i + 1);
	}
	imprime(h);

	altera_prioridade(h, 6, -3);
heapSort(h);
	imprime(h);

}
void imprime(Heap *heap) {
	printf("\n dado          pri        posição\n");
	int i;
	for (i = 0; i < heap->ultimo; i++) {
		TipoItem *temp = heap->ptItem[i];
		printf("%c              %d             %d\n", temp->dado,
				heap->prioridade[i], i);
	}

}
Heap *constroi_Heap(int tam) {
	Heap* heap = (Heap*) malloc(sizeof(Heap));
	heap->ptItem = (int*) malloc(tam * sizeof(int));
	heap->prioridade = (int*) malloc(tam * sizeof(int));
	heap->tamanho = tam;
	heap->ultimo = 0;
	return heap;
}
void heap_insere(Heap* heap, TipoItem *item, int prioridade) {
	if (heap->ultimo < heap->tamanho) {
		heap->prioridade[heap->ultimo] = prioridade;
		heap->ptItem[heap->ultimo] = item;
		corrige_acima(heap, heap->ultimo);
		heap->ultimo++;
	} else
		printf("Heap CHEIO!\n");
}
TipoItem *heap_remove(Heap* heap) {
	if (heap->ultimo > 0) {
		TipoItem *raiz = heap->ptItem[0];
		heap->ptItem[0] = heap->ptItem[heap->ultimo - 1];
		heap->prioridade[0] = heap->prioridade[heap->ultimo - 1];
		heap->ultimo--;
		corrige_abaixo(heap, 1);
		return raiz;
	} else {
		printf("Heap VAZIO!");
		return -1;
	}
}
TipoItem *find_max(Heap* heap) {
	if (heap->ultimo == 0) {
		printf("Heap VAZIO!");
		return -1;
	}
	TipoItem *item = heap->ptItem[0];
	return item;
}
void troca(int a, int b, Heap* heap) {
	TipoItem* it = heap->ptItem[a];
	heap->ptItem[a] = heap->ptItem[b];
	heap->ptItem[b] = it;
	int pd = heap->prioridade[a];
	heap->prioridade[a] = heap->prioridade[b];
	heap->prioridade[b] = pd;
}
void corrige_acima(Heap *heap, int posicao) {
	while (posicao > 0) {
		int pai = posicao / 2;
		if (heap->prioridade[pai] < heap->prioridade[posicao]) {
			troca(posicao, pai, heap);
		} else
			break;
		posicao = pai;
	}
}
void corrige_abaixo(Heap* heap, int posicao) {
	int pai=0 ,esq=0, dir=0,filho,i;
		for(i=posicao; i*2 < heap->ultimo - 1 ;i++){
			pai =i ,  esq= i*2 ,  dir =i*2+1;
			if(heap->prioridade[esq] < heap->prioridade[dir])
				filho=dir;
			else
				filho=esq;
			 if (heap->prioridade[pai] < heap->prioridade[filho])
				troca(pai,filho,heap);
		}
}
void altera_prioridade(Heap* heap, int posicao, int pdNova) {
	if (posicao >= heap->ultimo) {
		printf("Posicao não existe");
		return;
	} else if (heap->prioridade[posicao] == pdNova) {
		printf("A prioridade é igual a %d ", pdNova);
	}
	int temp = heap->prioridade[posicao];
	heap->prioridade[posicao] = pdNova;
	if (pdNova < temp) {
		corrige_abaixo(heap, posicao);
	} else {
		corrige_acima(heap, posicao);
	}
}
Heap *merge_heap(Heap *h1, Heap *h2) {
	Heap *h = constroi_Heap(h1->tamanho + h2->tamanho);
	int aux = h1->ultimo;
	while (aux > 0) {
		int pd = h1->prioridade[0];
		heap_insere(h, heap_remove(h1), pd);
		aux--;
	}
	aux = h2->ultimo;
	while (aux > 0) {
		int pd = h2->prioridade[0];
		heap_insere(h, heap_remove(h2), pd);
		aux--;
	}
	corrige_abaixo(h, 1);
	return h;
}
void heapSort(Heap* heap) {
	corrige_abaixo(heap,0);
}

