#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxim_pare(int* pare, int st, int dr) {
	int a, b, m;
	if (st == dr) {
		return pare[st];
	}
	else {
		m = (st + dr) / 2 ;
		a = maxim_pare(pare, st, m);
		b = maxim_pare(pare, m + 1, dr);
		if (a > b) {
			return a;
		}
		else {
			return b;
		}
	}
}

int suma3(int* a, int n) {
	if (n > 0) {
		if (a[n] % 3 == 0) {
			return a[n] + suma3(a, n - 1);
		}
		else {
			return suma3(a, n - 1);
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

int suma5(int* a, int n) {
	if (n > 0) {
		if (a[n] % 10 == 5) {
			return a[n] + suma5(a, n - 1);
		}
		else {
			return suma5(a, n - 1);
		}
	}
	else {
		if (a[n] % 10 == 5) {
			return a[n];
		}
		else {
			return 0;
		}
	}
}

int suma_para(int* a, int n) {
	if (n > 0) {
		if (a[n] % 2 == 0) {
			return a[n] + suma_para(a, n - 1);
		}
		else {
			return suma_para(a, n - 1);
		}
	}
	else {
		if (a[n] % 2 == 0) {
			return a[n];
		}
		else {
			return 0;
		}
	}
}

int numar0(long n) {
	if (n / 10 > 0) {
		if (n % 10 == 0) {
			return 1 + numar0(n / 10);
		}
		else return numar0(n / 10);
	}
	else {
		if (n == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

float equation(float x) {
	return x * x - 2;
}

void bisection(float a, float b, float eps, int n, float(*f)(float), float* x) {
	if ((*f)(a) == 0) {
		*x = a;
	}
	else {
		if ((*f)(b) == 0) {
			*x = b;
		}
		else {
		if ((*f)(a) * (*f)(b) > 0) {
				printf("Solutia nu se afla in intervalul [%f, %f]", a, b);
			}
			else {
				while (n != 0) {
					*x = (a + b) / 2;
					if ((*f)(*x) == 0) {
						n = 0;
					}
					else {
						if (fabsf(a - b) < eps) {
							n = 0;
						}
						else {
							if ((*f)(*x) * (*f)(a) < 0) {
								b = *x;
							}
							else {
								a = *x;
							}
						n--;
						}
						
					}
				}
			}
		}
	}
}

int main() {
	float a = 0, b = 2, eps = 0.1, x;
	int n = 100;
	bisection(a, b, eps, n, equation, &x);
	printf("Solutia ecuatiei este: %f", x);
	/*a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}*/

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
	printf("Maximul de pe pozitiile pare este: %d", maxim_pare(pare, 0, m - 1));
	free(pare);
	*/

	/* A doua problema
	printf("Suma elementelor divizibile cu 3 este: %d", suma3(a, n - 1));
	*/


	/* A treia problema
	printf("Suma elementelor cu ultima 5 este: %d", suma5(a, n - 1));
	*/
	
	/*
	printf("Suma elementelor pare este: %d", suma_para(a, n - 1));
	*/
	
	
	/*
	printf("Numarul de 0 al numarului %ld este: %d", n, numar0(n));
	*/

	/*
		free(a);
	*/
	
	return 0;
}