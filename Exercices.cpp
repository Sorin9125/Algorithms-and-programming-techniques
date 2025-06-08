#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Generarea tuturor permutarilor
int posibil_permutari(int* a, int i) {
	int r = 1;
	for (int j = 0; j < i; j++) {
		if (a[i] == a[j]) {
			r = 0;
		}
	}
	return r;
}

void retine_solutia_permutari(int* a, int num, int n) {
	printf("\nSolutia numarul %d este ", num);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

int permutari(int* a, int n, int i, int nr) {
	if (i == n) {
		retine_solutia_permutari(a, ++nr, n);
	}
	else {
		for (int j = 1; j <= n; j++) {
			a[i] = j;
			if (posibil_permutari(a, i) != 0) {
				nr = permutari(a, n, i + 1, nr);
			}
		}
	}
	return nr;
}

// Generearea tuturor aranjamentelor

int posibil_aranjamente(int* a, int i) {
	int r = 1;
	for (int j = 0; j < i; j++) {
		if (a[i] == a[j]) {
			r = 0;
		}
	}
	return r;
}

void retine_solutia_aranjamente(int* a, int num, int k) {
	printf("\nSolutia nuamrul %d este ", num);
	for (int i = 0; i < k; i++) {
		printf("%d ", a[i]);
	}
}

int aranjamente(int* a, int n, int i, int nr, int k) {
	if (i == k) {
		retine_solutia_aranjamente(a, ++nr, k);
	}
	else {
		for (int j = 1; j <= n; j++) {
			a[i] = j;
			if (posibil_aranjamente(a, i) != 0) {
				nr = aranjamente(a, n, i + 1, nr, k);
			}
		}
	}
	return nr;
}

// Generarea tuturor combinarilor

void retine_solutia_combinari(int* a, int num, int k) {
	printf("\nSolutia numarul %d este ", num);
	for (int i = 0; i < k; i++) {
		printf("%d ", a[i]);
	}
}

int combinari(int* a, int n, int i, int nr, int k, int start) {
	if (i == k) {
		retine_solutia_combinari(a, ++nr, k);
	}
	else {
		for (int j = start; j <= n; j++) {
			a[i] = j;
			nr = combinari(a, n, i + 1, nr, k, j + 1);
		}
	}
	return nr;
}

// Problema celor 8 regine

int posibil_regine(int* a, int i) {
	int p = 1;
	for (int j = 0; j < i; j++) {
		if (a[i] == a[j] || abs(i - j) == abs(a[i] - a[j])) {
			p = 0;
		}
	}
	return p;
}

void retine_solutia_regine(int* a, int nr, int n) {
	printf("Solutia numarul %d este\n", nr);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == j) {
				printf("R ");
			}
			else {
				printf("X ");
			}
		}
		printf("\n");
	}
}

int regine(int n) {
	int* x, nr = 0, r, i = 0;
	x = (int*)malloc(sizeof(int) * n);
	for (int j = 0; j < n; j++) {
		x[j] = -1;
	}
	while (i >= 0) {
		r = 0;
		while(x[i] < n && r == 0) {
			x[i]++;
			r = posibil_regine(x, i);
		}
		if (r == 0) {
			x[i] = -1;
			i--;
		}
		else {
			if (i == n - 1) {
				retine_solutia_regine(x, ++nr, n);
				x[i] = -1;
				i--;
			}
			else {
				i++;
				x[i] = -1;
			}
		}
	}
	return nr;
}

// Plata suma cu bancnote

int posibil_plata(int* a, int i, int n, int s, int c) {
	if (i == n) {
		return s == c;
	}
	else {
		return s >= c;
	}
}

void retine_solutia_plata(int* t, int* a, int n, int ns) {
	int s = 0;
	printf("\nSolutia numarul %d este", ns);
	for (int i = 0; i < n; i++) {
		printf("\n%d * %d = %d, suma = %d", t[i], a[i], t[i] * a[i], s += t[i] * a[i]);
	}
}

int plata(int suma, int scrt, int* t, int* q, int n, int ns, int i, int* a) {
	if (i == n + 1) {
		retine_solutia_plata(t, a, n, ++ns);
	}
	else {
		for (int j = 0; j <= q[i]; j++) {
			a[i] = j;
			scrt += t[i] * j;
			if (posibil_plata(a, i, n, suma, scrt) != 0) {
				ns = plata(suma, scrt, t, q, n, ns, i + 1, a);
			}
			scrt -= t[i] * j;
		}
	}
	return ns;
}

int main() {
	int*a, n, nr, k;
	printf("n = ");
	scanf("%d", &n);
	/*printf("k = ");
	scanf("%d", &k);
	a = (int*)malloc(sizeof(int) * k);*/
	//permutari(a, n, 0, 0);
	//aranjamente(a, n, 0, 0, k);
	//combinari(a, n, 0, 0, k, 1);
	regine(n);
	return 0;
}