#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define INF 100000000

void transformare_matrice_orientat_neponderat(int*** a, int* noduri, int* muchii) {
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
		*a = (int**)malloc(sizeof(int*) * (*noduri + 1));
		for (int i = 1; i <= *noduri; i++) {
			(*a)[i] = (int*)malloc(sizeof(int) * (*noduri + 1));
		}

		for (int i = 1; i <= *noduri; i++) {
			for (int j = 1; j <= *noduri; j++) {
				(*a)[i][j] = 0;
			}
		}
		for (int i = 1; i <= *muchii; i++) {
			int n1, n2;
			fscanf(f, "%d", &n1);
			fscanf(f, "%d", &n2);
			(*a)[n1][n2] = 1;
		}
	}
	fclose(f);
}

void transformare_matrice_neorientat_neponderat(int*** a, int* noduri, int* muchii) {
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
		*a = (int**)malloc(sizeof(int*) * (*noduri + 1));
		for (int i = 1; i <= *noduri; i++) {
			(*a)[i] = (int*)malloc(sizeof(int) * (*noduri + 1));
		}

		for (int i = 1; i <= *noduri; i++) {
			for (int j = 1; j <= *noduri; j++) {
				(*a)[i][j] = 0;
			}
		}
		for (int i = 1; i <= *muchii; i++) {
			int n1, n2;
			fscanf(f, "%d", &n1);
			fscanf(f, "%d", &n2);
			(*a)[n1][n2] = 1;
			(*a)[n2][n1] = 1;
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

int grad_interior_minim(int** a, int noduri, int** grad_minim, int* nr_noduri) {
	int minim = INF;
	*grad_minim = (int*)malloc(sizeof(int) * noduri);
	for (int j = 2; j <= noduri; j += 2) {
		int k = 0;
		for (int i = 1; i <= noduri; i++) {
			if (a[i][j] != 0) {
				k++;
			
			}
		}
			if (k < minim) {
				minim = k;
				*nr_noduri = 0;
				(*grad_minim)[(*nr_noduri)++] = j;
			}
			else {
				if (k == minim) {
					(*grad_minim)[(*nr_noduri)++] = j;
				}
			}
			
	}
	return minim;
}

void noduri_adiacente(int** a, int noduri, int** adiacente, int nod, int* k) {
	*adiacente = (int*)malloc(sizeof(int) * (noduri - 1));
	*k = 0;
	for (int i = 0; i < noduri - 1; i++) {
		(*adiacente)[i] = 0;
	}
	for (int i = 1; i <= noduri; i++) {
		if (a[nod][i] != 0) {
			(*adiacente)[(*k)++] = i;
		}
	}
}

void afisare_matrice_adiacenta(int** matrice, int noduri) {
	for (int i = 1; i <= noduri; i++) {
		for (int j = 1; j <= noduri; j++) {
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}

void royWarshall(int** matrice, int n, int*** royWarshall) {
	*royWarshall = (int**)calloc(n + 1, sizeof(int*));
	for (int i = 1; i <= n; i++) {
		(*royWarshall)[i] = (int*)calloc(n + 1, sizeof(int));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			(*royWarshall)[i][j] = matrice[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((*royWarshall)[i][k] == 1 && (*royWarshall)[k][j] == 1) {
					(*royWarshall)[i][j] = 1;
				}
			}
		}
	}
}

void royFloyd(int** matrice, int n, int*** royFloyd) {
	*royFloyd = (int**)calloc(n + 1, sizeof(int*));
	for (int i = 1; i <= n; i++) {
		(*royFloyd)[i] = (int*)calloc(n + 1, sizeof(int));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			(*royFloyd)[i][j] = matrice[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((*royFloyd)[i][k] + (*royFloyd)[k][j] < (*royFloyd)[i][j]) {
					(*royFloyd)[i][j] = (*royFloyd)[i][k] + (*royFloyd)[k][j];
				}
			}
		}
	}
}
int main() {
	int** matrice, noduri, muchii;
	
	int** drumuri, k = 0, nod, ok = 0;
	
	/* Noduri adiacente
		transformare_matrice_neorientat_neponderat(&matrice, &noduri, &muchii);
		afisare_matrice_adiacenta(matrice, noduri);
		printf("Introduceti nodul: ");
		scanf("%d", &nod);
		noduri_adiacente(matrice, noduri, &grad, nod, &k);
		for (int i = 0; i < k; i++) {
			if (grad[i] != 0 && k == 0) {
				printf("Nodurile adiacente lui %d sunt: ", nod);
				printf("%d ", grad[i]);
			}
			else {
				if (grad[i] != 0) {
					printf("%d ", grad[i]);
				}
			}
		}
	*/
	
	/* Gradul interior 
		transformare_matrice_orientat_neponderat(&matrice, &noduri, &muchii);
		afisare_matrice_adiacenta(matrice, noduri);
		grad_interior(matrice, noduri, &grad);
		for (int i = 1; i <= noduri; i++) {
			if (grad[i] != 0 && k == 0) {
				printf("Nodurile impare cu gradul interior egal cu 2 sunt: ");
				printf("%d ", i);
				k = 1;
			}
			else {
				if (grad[i] != 0) {
					printf("%d ", i);	
				}
			}
		}
		if (k == 0) {
			printf("Nu exista noduri impare care au gradul interior egal cu 2");
		}
	*/

	/*
		transformare_matrice_orientat_neponderat(&matrice, &noduri, &muchii);
		afisare_matrice_adiacenta(matrice, noduri);
		int minim = grad_interior_minim(matrice, noduri, &grad, &k);
		printf("Gradul minim este %d si nodurile care-l au sunt: ", minim);
		for (int i = 0; i < k; i++) {
			printf("%d ", grad[i]);
		}
	*/
	
	/*
	
	*/

	transformare_matrice_orientat_neponderat(&matrice, &noduri, &muchii);
	afisare_matrice_adiacenta(matrice, noduri);
	royWarshall(matrice, noduri, &drumuri);
	printf("Matricea drumurilor este\n");
	for (int i = 1; i <= noduri; i++) {
		for (int j = 1; j <= noduri; j++) {
			printf("%d ", drumuri[i][j]);
		}
		printf("\n");
	}
	for (int i = 1; i <= noduri; i++) {
		free(matrice[i]);
	}
	free(matrice);

	for (int i = 1; i <= noduri; i++) {
		free(drumuri[i]);
	}
	free(drumuri);
	return 0;
}
