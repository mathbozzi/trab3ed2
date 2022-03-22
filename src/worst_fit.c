#include "worst_fit.h"

#include <stdio.h>
#include <stdlib.h>

int worstFit(int* array, int N, int disk_max) {
	Max_Heap* mh = init_max_heap(N);
	insert_max_heap(mh, disk_max);

	for (int i = 0; i <= N - 1; i++) {
		if (array[i] > mh->elmt[1]) {  // elemento maior que o maior valor da heap
			insert_max_heap(mh, disk_max - array[i]);
		} else {
			int oldMax = delete_max_heap(mh);
			int max = oldMax - array[i];
			insert_max_heap(mh, max);
		}
	}
	int n = mh->n;
	free_max_heap(mh);

	return n;
}

Max_Heap* init_max_heap(int N) {
	Max_Heap* max_heap = malloc(sizeof(*max_heap));
	max_heap->n = 0;
	max_heap->elmt = malloc(N * sizeof(int*));
	return max_heap;
}

void insert_max_heap(Max_Heap* mh, int size) {
	mh->n++;
	mh->elmt[mh->n] = size;
	int i = mh->n;
	while ((mh->elmt[i / 2] < mh->elmt[i]) && i > 1) {  // filho maior que o pai, entao troca
		int aux = mh->elmt[i];
		mh->elmt[i] = mh->elmt[i / 2];
		mh->elmt[i / 2] = aux;
		i = i / 2;
	}
}

int delete_max_heap(Max_Heap* mh) {
	int h = 1;
	int oldMax = mh->elmt[1];
	int aux = mh->elmt[1];
	mh->elmt[1] = mh->elmt[mh->n];
	mh->elmt[mh->n] = aux;
	mh->n = mh->n - 1;        //retira o maior elemento
	while (2 * h <= mh->n) {  // reordena o heap
		int j = 2 * h;
		if ((mh->elmt[j] < mh->elmt[j + 1]) && (j < mh->n)) {
			j++;
		}
		if (mh->elmt[h] > mh->elmt[j]) {
			break;
		}
		int aux2 = mh->elmt[h];
		mh->elmt[h] = mh->elmt[j];
		mh->elmt[j] = aux2;
		h = j;
	}
	return oldMax;
}

void free_max_heap(Max_Heap* max_heap) {
	free(max_heap->elmt);
	free(max_heap);
}