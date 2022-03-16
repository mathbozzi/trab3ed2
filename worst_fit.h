#ifndef WORST_FIT_H
#define WORST_FIT_H

typedef struct max_heap {
	int* elmt;
	int n;
} Max_Heap;

int worstFit(int* array, int N, int disk_max);

Max_Heap* init_max_heap(int N);

void free_max_heap(Max_Heap* max_heap);

void insert_max_heap(Max_Heap* mh, int size);

int delete_max_heap(Max_Heap* mh);

#endif /* WORST_FIT_H */