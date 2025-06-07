#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

void transformare_matrice(int*** a, int* noduri, int* muchii) {
	FILE* f;
	f = fopen("lista.txt", "r");
	if (!f) {
		printf("Fisierul text nu s-a putut deschide.");
	}
	else {
		fscanf(f, "%d", noduri);
		printf("Numarul de noduri este %d\n", *noduri);
		fscanf(f, "%d", muchii);
		printf("Numarul de muchii este %d\n", *muchii);
		*a = (int**)malloc(sizeof(int*) * *noduri);
		for (int i = 0; i < *noduri; i++) {
			(*a)[i] = (int*)malloc(sizeof(int) * *noduri);
		}

		for (int i = 0; i < *noduri; i++) {
			for (int j = 0; j < *noduri; j++) {
				(*a)[i][j] = 0;
			}
		}
		for (int i = 0; i < *muchii; i++) {
			int n1, n2;
			fscanf(f, "%d", &n1);
			fscanf(f, "%d", &n2);
			(*a)[n1 - 1][n2 - 1] = 1;
		}
		for (int i = 0; i < *noduri; i++) {
			for (int j = 0; j < *noduri; j++) {
				printf("%d ", (*a)[i][j]);
			}
			printf("\n");
		}
	}
	fclose(f);
}

void grad_interior(int** a, int noduri, int** grad) {
	*grad = (int*)malloc(sizeof(int) * noduri);
	for (int i = 0; i < noduri; i++) {
		(*grad)[i] = 0;
	}
	for (int j = 0; j < noduri; j += 2) {
		int k = 0;
		for (int i = 0; i < noduri; i++) {
			if (a[i][j] == 1) {
				k++;
			}
		}
		if (k == 2) {
			(*grad)[j] = 1;
		}
	}
}

int main() {
	int** matrice, noduri, muchii;
	transformare_matrice(&matrice, &noduri, &muchii);
	int* grad, k = 0;
	grad_interior(matrice, noduri, &grad);
	for (int i = 0; i < noduri; i++) {
		if (grad[i] != 0 && k == 0) {
			printf("Nodurile impare cu gradul interior egal cu 2 sunt: ");
			printf("%d ", i + 1);
			k = 1;
		}
	}
	if (k == 0) {
		printf("Nu exista noduri impare care au gradul interior egal cu 2");
	}
	for (int i = 0; i < noduri; i++) {
		free(matrice[i]);
	}
	free(matrice);
	free(grad);
	return 0;
}
