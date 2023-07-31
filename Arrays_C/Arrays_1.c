#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

int meter(double* mas, int n) { //counter for negative elements of array
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] < 0) { k++; }
	}
	return k;
}

void main() {

	double* mas1, * mas2;
	int n1, n2;
	printf("Enter the number of elements of massive 1\n");
	scanf_s("%d", &n1);

	mas1 = (double*)(calloc(n1, sizeof(double)));

	if (!mas1) {
		printf("Out of memory. Press any key: ");
		_getch();
		exit(1);
	}
	else {
		printf("Enter the elements of mas1\n");

		for (int i1 = 0; i1 < n1; i1++) {
			printf("[%d]= ", i1);
			scanf_s("%lf", mas1 + i1);
		}

	}

	printf("Enter the number of elements of mas2\n");
	scanf_s("%d", &n2);

	mas2 = (double*)(calloc(n2, sizeof(double)));

	if (!mas2) {
		printf("Out of memory. Press any key: ");
		_getch();
		exit(1);
	}
	else {
		printf("Enter the elements of massive 2\n");

		for (int i2 = 0; i2 < n2; i2++) {
			printf("[%d]= ", i2);
			scanf_s("%lf", mas2 + i2);
		}
	}

	printf("------------------------\n");

	if (meter(mas1, n1) < meter(mas2, n2)) {
		printf("Massive 1\n");
		for (int i1 = 0; i1 <= (n1 - 1); ++i1) {
			printf("[%d]=%lf\n", i1, mas1[i1]);
		}
		printf("Massive 2\n");
		for (int i2 = 0; i2 <= (n2 - 1); ++i2) {
			printf("[%d]=%lf\n", i2, mas2[i2]);
		}
	}
	else if (meter(mas1, n1) > meter(mas2, n2)) {
		printf("Massive 2\n");
		for (int i2 = 0; i2 <= (n2 - 1); ++i2) {
			printf("[%d]=%lf\n", i2, mas2[i2]);
		}
		printf("Massive 1\n");
		for (int i1 = 0; i1 <= (n1 - 1); ++i1) {
			printf("[%d]=%lf\n", i1, mas1[i1]);
		}
	}
	else { printf("Incorrect value\n"); }

	free(mas1);
	free(mas2);
	_getch();
}
