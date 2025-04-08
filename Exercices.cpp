#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char is;
	int nrMat;
	char numeStudent[25];
	int grupa;
	char an;
	typedef struct {
		char tip;
		char nrAbsente;
	} situatie;
	situatie absente[15];
} student;

typedef struct {
	int nrm;
	char nume[30];
	int grupa;
	char pp;
	char teme[10];
	char ex;
	char is;
} STUDENT;

void afisare(char* fisierBinar, char* fisierText) {
	FILE* f, * g;
	student s;
	f = fopen(fisierBinar, "rb");
	if (!f) {
		printf("Fisierul binar nu s-a deschis");
	}
	else {
		g = fopen(fisierText, "w");
		if (!g) {
			printf("Fisierul text nu s-a deschis");
		}
		else {
			fprintf(g, "Nr Nume student %25s Grupa An Absente", "");
			for (int i = 0; i < 15; i++) {
				fprintf(g, " %2d", i + 1);
			}
			fread(&s, sizeof(student), 1, f);
			while (!feof(f)) {
				if (s.is == 1) {
					fprintf(g, "\n%3d %-25s %12s %d %d %9s",s.nrMat, s.numeStudent, "", s.grupa, s.an, "");
					for (int i = 0; i < 15; i++) {
						fprintf(g, "%2d ", s.absente[i].nrAbsente);
					}
				}
				fread(&s, sizeof(student), 1, f);
			}
		}
		fclose(g);
	}
	fclose(f);
}

void schimbatAbsente(char* fisierBinar) {
	FILE* f;
	student s;
	f = fopen(fisierBinar, "r+b");
	if (!f) {
		printf("Fisierul binar nu s-a deschis");
	}
	else {
		int nrMat;
		printf("Introduceti numarul matricol: ");
		scanf("%d", &nrMat);
		fseek(f, nrMat * sizeof(student), SEEK_SET);
		fread(&s, sizeof(student), 1, f);
		while (!feof(stdin)) {
			fseek(f, nrMat * sizeof(student), SEEK_SET);
			fread(&s, sizeof(student), 1, f);
			if (s.is == 1) {
				int materie, absente;
				char tip;
				printf("Care este materia la care schimbam absentele? ");
				scanf("%d", &materie);
				printf("Este curs sau seminar?(0/1) ");
				scanf("%d", &tip);
				printf("Cate absente are acum studentul? ");
				scanf("%d", &absente);
				s.absente[materie].nrAbsente = absente;
				fseek(f, nrMat * sizeof(student), SEEK_SET);
				fwrite(&s, sizeof(student), 1, f);
			}
			else {
				printf("Articolul nu exista");
			}
			printf("\nIntroduceti urmatorul cod matricol ");
			scanf("%d", &nrMat);
		}
	}
	fclose(f);
}

void noteTeme(char* fisierBinar) {
	FILE* f;
	STUDENT s;
	f = fopen(fisierBinar, "r+b");
	if (!f) {
		printf("Fisierul binar nu s-a deschis");
	}
	else {
		int nrMat;
		printf("Introduceti numarul matricol ");
		scanf("%d", &nrMat);
		while (!feof(stdin)) {
			(f, nrMat * sizeof(STUDENT), SEEK_SET);
			fread(&s, sizeof(STUDENT), 1, f);
			if (s.is == 1) {
				int tema;
				char rezultat;
				printf("Ce tema este notata? ");
				scanf("%d", &tema);
				printf("Ce nota a obtinut? ");
				scanf("%d", &rezultat);
				s.teme[tema] = rezultat;
			}
			else {
				printf("Articolul nu exista");
			}
			fseek(f, nrMat * sizeof(STUDENT), SEEK_SET);
			fwrite(&s, sizeof(STUDENT), 1, f);
			printf("Introduceti urmatorul cod matricol ");
			scanf("%d", &nrMat);
		}
	}
	fclose(f);
}

int main() {
	char fisierBinar[] = "Fis_relativ_abs.dat", fisierText[] = "Student.txt";
	schimbatAbsente(fisierBinar);
	afisare(fisierBinar, fisierText);
	return 0;
}