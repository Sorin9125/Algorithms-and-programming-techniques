#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int nrMat;
	char numeStudent[30];
	char an;
	int grupa;
	char tip;
	typedef struct {
		char zi;
		char luna;
		int an;
	} data;
	typedef struct {
		char ora;
		char minut;
	} ora;
	data dat;
	ora oraIntrare;
	ora oraIesire;
} student;

void afisare(char* fisierBinar, char* fisierText) {
	FILE* f, * g;
	student s;
	f = fopen(fisierBinar, "rb");
	if (!f) {
		printf("Fisierul binar din afisare nu s-a deschis");
	}
	else {
		g = fopen(fisierText, "w");
		if (!g) {
			printf("Fisierul text nu s-a deschis");
		}
		else {
			fprintf(g, "Nr mat Nume student %30s An Grupa Tip %s Data %3s Ora intrare %s Ora iesire", "", "", "", "");
			fread(&s, sizeof(student), 1, f);
			while (!feof(f)) {
				fprintf(g, "\n%3d %-30s %15s %d %d %s %c %s %d.%d.%d %s %d:%d %5s %d:%d", s.nrMat, s.numeStudent, "", s.an, s.grupa, "", s.tip, "", s.dat.zi,
					s.dat.luna, s.dat.an, "", s.oraIntrare.ora, s.oraIntrare.minut, "", s.oraIesire.ora, s.oraIesire.minut);
				fread(&s, sizeof(student), 1, f);
			}
		}
		fclose(g);
	}
	fclose(f);
}

void stergereElemente(char* fisierBinar) {
	FILE* f, * g;
	student s;
	f = fopen(fisierBinar, "rb");
	if (!f) {
		printf("Fisierul binar nu s-a deschis");
	}
	else {
		g = fopen("Auxiliar", "wb");
		if (!g) {
			printf("Fisierul auxiliar nu s-a deschis");
		}
		else {
			fread(&s, sizeof(student), 1, f);
			while (!feof(f)) {
				if (s.an == 1) {
					fwrite(&s, sizeof(student), 1, g);
				}
				fread(&s, sizeof(student), 1, f);
			}
			fclose(f);
			fclose(g);
			remove(fisierBinar);
			rename("Auxiliar", fisierBinar);
		}
	}
}

int nr(FILE* f, int i) {
	int n;
	long p;
	p = ftell(f);
	fseek(f, 0, SEEK_END);
	n = ftell(f) / i;
	fseek(f, p, SEEK_SET);
	return n;
}

void sortare(char* fisierBinar) {
	FILE* f;
	student s1, s2;
	f = fopen(fisierBinar, "r+b");
	if (!f) {
		printf("Fisierul binar nu s-a deschis");
	}
	else {
		int ok = 1, n = nr(f, sizeof(student));
		while (ok == 1) {
			ok = 0;
			for (int i = 0; i < n - 1; i++) {
				fseek(f, i * sizeof(student), SEEK_SET);
				fread(&s1, sizeof(student), 1, f);
				fread(&s2, sizeof(student), 1, f);
				if ((s1.an > s2.an) || ((s1.an == s2.an) && (s1.grupa > s2.grupa))) {
					ok = 1;
					fseek(f, i * sizeof(student), SEEK_SET);
					fwrite(&s2, sizeof(student), 1, f);
					fwrite(&s1, sizeof(student), 1, f);
				}
			}
		}
	}
	fclose(f);
}

int main() {
	char fisierBinar[] = "SecvStud.dat", fisierText[] = "Student.txt";
	sortare(fisierBinar);
	afisare(fisierBinar, fisierText);
	return 0;
}