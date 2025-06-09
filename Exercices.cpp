#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int suma10(int* s, int n, int** sol, int* k) {
	*sol = (int*)malloc((sizeof(int) * n));
	int* cifre;
	cifre = (int*)calloc(10, sizeof(int));
	for (int i = 0; i < n; i++) {
		if (s[i] == 1 || s[i] == 3 || s[i] == 5 || s[i] == 7 || s[i] == 9) {
			cifre[s[i]] = s[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] % 2 == 0) {
			(*sol)[(*k)++] = s[i];
		}
	}
	if (cifre[1] != 0 && cifre[9] != 0) {
		(*sol)[(*k)++] = cifre[1];
		(*sol)[(*k)++] = cifre[9];
		return 1;
	}
	else {
		if (cifre[3] != 0 && cifre[7] != 0) {
			(*sol)[(*k)++] = cifre[3];
			(*sol)[(*k)++] = cifre[7];
			return 1;
		}
		else {
			return 0;
		}
	}
	
}

int main() {
	int* s, * sol, n, k = 0;
	printf("Introduceti numarul de elemente: ");
	scanf("%d", &n);
	s = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		printf("s[%d] = ", i);
		scanf("%d", &s[i]);
	}
	int rez = suma10(s, n, &sol, &k);
	if (rez == 0) {
		printf("Imposibil");
	}
	else {
		for (int i = 0; i < k; i++) {
			printf("%d ", sol[i]);
		}
	}
	free(s);
	free(sol);
	return 0;
}