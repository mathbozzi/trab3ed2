#ifndef BEST_FIT_H
#define BEST_FIT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct bst {
	int data;
	struct bst* r;
	struct bst* l;
} Bst;

int bestFit(int* array, int N, int disk_max);

Bst* init_bst(int size);

int find_bst(Bst* bst, int element);

Bst* insert_bst(Bst* bst, int data);

Bst* delete_bst(Bst* bst, int data);

void free_bst(Bst* bst);

#endif /* BEST_FIT_H */