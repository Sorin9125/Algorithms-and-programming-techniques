#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int maxim(int* pare, int st, int dr) {
	int a, b, m;
	if (st == dr) {
		return pare[st];
	}
	else {
		m = (st + dr) / 2 ;
		a = maxim(pare, st, m);
		b = maxim(pare, m + 1, dr);
		if (a > b) {
			return a;
		}
		else {
			return b;
		}
	}
}

int suma(int* a, int n) {
	if (n > 0) {
		if (a[n] % 3 == 0) {
			return a[n] + suma(a, n - 1);
		}
		else {
			return suma(a, n - 1);
		}
	}
	else {
		if (a[n] % 3 == 0) {
			return a[n];
		}
		else {
			return 0;
		}
	}
}

int main() {
	int* a, n;
	printf("Introduceti numarul de elemente: ");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}

	/* Prima problema
	int* pare, m = 0;
	if (n % 2 == 0) {
		pare = (int*)malloc(sizeof(int) * (n / 2));
	}
	else {
		pare = (int*)malloc(sizeof(int) * (n / 2 + 1));
	}
	for (int i = 0; i < n; i = i + 2) {
		pare[m++] = a[i];
	}
	printf("Maximul de pe pozitiile pare este: %d", maxim(pare, 0, m - 1));
	free(pare);
	*/

	/* A doua problema
	printf("Suma elementelor divizibile cu 3 este: %d", suma(a, n - 1));
	*/
	free(a);
	
	return 0;
}