#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void sum(double* mas, int n) {
	int i, k = 0;
	double sum = 0;
	for (i = n - 1; i >= 0; i--) if (*(mas + i) < 0) k++;
	if (k != 0)
	{
		for (i = n - 1; i >= 0; i--)
		{
			k++;
			if (*(mas + i) >= 0.) sum += *(mas + i);
			else
			{
				if (i == n - 1)
				{
					sum = 0;
					break;
				}
				break;
			}
		}
	}
	else { printf("Negative elements do not exist"); }
	printf("Sum=%lf\n", sum);
}

void bouble(double* mas, int n) {
	int i, j, k = 0;
	double tmp;
	for (i = 0; i < n; i++) {
		for (j = i; j > 0; j--) {
			k++;
			if (mas[j] < mas[j - 1]) {
				tmp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = tmp;
			}
		}
	}
	printf("Bouble sorted array:\n");
	for (int i = 0; i < n; i++)
		printf("%.4lf ", mas[i]);
	printf("\n");
	printf("Iterations %d\n", k);
}

int quicksort(double* arr, int left, int right) {
	int i = left, j = right, count = 0;
	int tmp;
	int m = arr[(left + right) / 2];
	do {
		while (*(arr + i) < m) i++;
		while (*(arr + j) > m) j--;
		if (i <= j) {
			if (*(arr + i) > *(arr + j)) {
				tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
				count++;
			}
			i++;
			j--;
		}

	} while (i <= j);

	if (left < j) quicksort(arr, left, j);
	if (i < right) quicksort(arr, i, right);
	return (count);
}


void main() {
	int n;
	double* mas;
	printf("Enter the number of elements of massive\n");
	scanf_s("%d", &n);
	mas = new double[n];
	if (!mas) {
		printf("Out of memory. Press any key");
		_getch();
		exit(1);
	}
	else {
		printf("Enter the elements of massive\n");

		for (int i = 0; i < n; i++) {
			printf("[%d]= ", i);
			scanf_s("%lf", mas + i);
		}
	}
	sum(mas, n);
	bouble(mas, n);
	quicksort(mas, 0, n - 1);
	printf("Quick sorted array:\n");
	for (int i = 0; i < n; i++)
		printf("%.4lf ", mas[i]);
	printf("\n");
	printf("Iterations %lf\n", quicksort(mas, 0, n - 1));
	_getch();
	delete[]mas;
}

