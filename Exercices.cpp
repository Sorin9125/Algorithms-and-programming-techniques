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

void numarare(int* a, int n) {
	int* frecvente, m;
	m = maxim(a, 0, n - 1);
	frecvente = (int*)malloc(sizeof(int) * (m + 1));
	for (int i = 0; i <= m; i++) {
		frecvente[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		frecvente[a[i]]++;
	}
	int j = 0;
	for (int i = 0; i <= m; i++) {
		while (frecvente[i] != 0) {
			a[j++] = i;
			frecvente[i]--;
		}
	}
	free(frecvente);
}


int main() {
	FILE* f;
	f = fopen("numere.txt", "r");
	int* a, n;
	if (!f) {
		printf("Fisierul text nu s-a deschis");
	}
	else {
		fscanf(f, "%d", &n);
		printf("Numarul de elemente este: %d\n", n);
		a = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			fscanf(f, "%d", &a[i]);
			printf("a[%d] = %d\n", i, a[i]);
		}
		
		/* Sortare prin numarare
			numarare(a, n);
		*/
		
		printf("Vectorul sortat este: ");
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		free(a);
	}
	return 0;
}
