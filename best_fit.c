#include "best_fit.h"

int bestFit(int* array, int N, int disk_max) {
	int n = 0;
	Bst* bst = init_bst(disk_max);
	for (int i = 0; i <= N - 1; i++) {
		int res = find_bst(bst, array[i]);
		if (res == 0) {
			bst = insert_bst(bst, disk_max - array[i]);
			n = n + 1;
		} else {
			bst = delete_bst(bst, res);
			bst = insert_bst(bst, res - array[i]);
		}
	}
	free_bst(bst);
	return ++n;
}

Bst* init_bst(int size) {
	Bst* bst = (Bst*)malloc(sizeof(*bst));
	bst->data = size;
	bst->l = bst->r = NULL;
	return bst;
}

int find_bst(Bst* bst, int element) {
	if (bst->data >= element) {
		if (bst->l == NULL) {
			return bst->data;
		} else {
			int elem = find_bst(bst->l, element);
			if (elem > 0) {
				return elem;
			} else {
				return bst->data;
			}
		}
	} else {
		if (bst->r == NULL) {
			return 0;
		} else {
			return find_bst(bst->r, element);
		}
	}
}

Bst* insert_bst(Bst* bst, int data) {
	if (bst == NULL) {
		return init_bst(data);
	}
	if (data < bst->data) {
		bst->l = insert_bst(bst->l, data);
	} else {
		bst->r = insert_bst(bst->r, data);
	}
	return bst;
}

Bst* delete_bst(Bst* bst, int data) {
	if (bst == NULL) {
		return bst;
	}
	if (data < bst->data) {
		bst->l = delete_bst(bst->l, data);

	} else if (data > bst->data) {
		bst->r = delete_bst(bst->r, data);
	} else {
		if (bst->l == NULL) {
			Bst* aux = bst->r;
			free(bst);
			return aux;
		} else if (bst->r == NULL) {
			Bst* aux = bst->l;
			free(bst);
			return aux;
		}
		Bst* aux = bst->r;
		while (aux->l != NULL) {
			aux = aux->l;
		}
		bst->data = aux->data;
		bst->r = delete_bst(bst->r, aux->data);
	}
	return bst;
}

void free_bst(Bst* bst) {
	if (bst == NULL) {
		return;
	}
	free_bst(bst->l);
	free_bst(bst->r);
	free(bst);
}