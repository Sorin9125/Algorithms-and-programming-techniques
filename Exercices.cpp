#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int maxim(int* v, int st, int dr) {
	int a, b, m;
	if (st == dr) {
		return v[st];
	}
	else {
		m = (st + dr) / 2;
		a = maxim(v, st, m);
		b = maxim(v, m + 1, dr);
		if (a > b) {
			return a;
		}
		else {
			return b;
		}
	}
}

void countSort(int* a, int n) {
	int* frecvente, *aux;
	frecvente = (int*)malloc(sizeof(int) * n);
	aux = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		frecvente[i] = 0;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				frecvente[i]++;
			}
			else {
				frecvente[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		aux[frecvente[i]] = a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] = aux[i];
	}
	free(frecvente);
}

void mergeSort(int* a, int st, int dr, int* tmp) {
	int m;
	if (st < dr) {
		m = (st + dr) / 2;
		mergeSort(a, st, m, tmp);
		mergeSort(a, m + 1, dr, tmp);
		int i = st, j = m + 1, k = 0;
		while (i <= m && j <= dr) {
			if (a[i] < a[j]) {
				tmp[k++] = a[i++];
			}
			else {
				tmp[k++] = a[j++];
			}
		}
		while (i <= m) {
			tmp[k++] = a[i++];
		}
		while (j <= dr) {
			tmp[k++] = a[j++];
		}
		for (i = st, j = 0; i <= dr; i++, j++) {
			a[i] = tmp[j];
		}
	}
}

void quickSort(int* a, int st, int dr) {
	int m;
	if (st < dr) {
		m = (st + dr) / 2;
		int pivot = a[st];
		int i = st + 1, j = dr;
		while (i <= j) {
			while (i <= dr && a[i] < pivot) {
				i++;
			}
			while (a[j] > pivot) {
				j--;
			}
			if (i <= j) {
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
				i++;
				j--;
			}
		}
		int aux = a[st];
		a[st] = a[j];
		a[j] = aux;
		quickSort(a, st, j - 1);
		quickSort(a, j + 1, dr);
	}
}

void shellSort(int* a, int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int aux = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > aux; j -= gap) {
				a[j] = a[j - gap];
			}
			a[j] = aux;
		}
	}
}

void selectionSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (a[i] > a[j]) {
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}
}

void bubbleSort(int* a, int n) {
	int ok = 1;
	do
	{
		ok = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (a[j] > a[j + 1]) {
					ok = 1;
					int aux = a[j];
					a[j] = a[j + 1];
					a[j + 1] = aux;
				}
			}
		}
	} while (ok == 1);
}

void insertionSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int aux = a[i], p = i - 1;
		while (p >= 0 && a[p] > aux) {
			a[p + 1] = a[p];
			p--;
		}
		a[p + 1] = aux;
	}
}

int main() {
	FILE* f;
	f = fopen("numere.txt", "r");
	int* a, n;
	int* tmp;
	
	if (!f) {
		printf("Fisierul text nu s-a deschis");
	}
	else {
		fscanf(f, "%d", &n);
		printf("Numarul de elemente este: %d\n", n);
		tmp = (int*)malloc(sizeof(int) * n);
		a = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			fscanf(f, "%d", &a[i]);
			printf("a[%d] = %d\n", i, a[i]);
		}
		
		/*
			
		*/
countSort(a, n);
		/*
			mergeSort(a, 0, n - 1, tmp);
		*/
		
		/*
			quickSort(a, 0, n - 1);
		*/
		
		/*
			shellSort(a, n);
		*/
		
		/*
			selectionSort(a, n);
		*/

		/*
			bubbleSort(a, n);
		*/
		
		/*
			insertionSort(a, n);
		*/
		
		
		printf("Vectorul sortat este: ");
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		free(a);
		free(tmp);
	}
	return 0;
}
