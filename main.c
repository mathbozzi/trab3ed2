#include <stdio.h>
#include <stdlib.h>

#include "best_fit.h"
#include "worst_fit.h"
#define DISK_SIZE 1000000

int cmpfunc(const void* a, const void* b) {
	return (*(int*)b - *(int*)a);  // desc
}

int main(int argc, char const* argv[]) {
	if (argc != 2) {
		printf("Execução: ./trab3 caminho_arquivo\n");
		return 0;
	}
	FILE* arqv_de_entrada = fopen(argv[1], "r");

	if (arqv_de_entrada == NULL) {
		printf("Erro ao abrir o arquivo de entrada\n");
		return 0;
	}

	char inputFile[50];
	fgets(inputFile, sizeof(inputFile), arqv_de_entrada);
	int N = atoi(inputFile);

	int* array = malloc(N * sizeof(int));
	int i = 0;
	while ((fgets(inputFile, sizeof(inputFile), arqv_de_entrada)) != NULL) {
		array[i] = atoi(inputFile);
		i++;
	}

	int worst_fit = worstFit(array, N, DISK_SIZE);
	printf("%d\n", worst_fit);
	int best_fit = bestFit(array, N, DISK_SIZE);
	printf("%d\n", best_fit);

	qsort(array, N, sizeof(int), cmpfunc);

	int worst_fit_desc = worstFit(array, N, DISK_SIZE);
	printf("%d\n", worst_fit_desc);
	int best_fit_desc = bestFit(array, N, DISK_SIZE);
	printf("%d\n", best_fit_desc);

	free(array);
	fclose(arqv_de_entrada);

	return 0;
}