#include <stdio.h>
#include <stdlib.h>


void createMatrix(int *mat, int l);
void printMatrix(int *mat, int l);

void main(void) {
	int n;
	printf("Please, type the size of matrix: ");
	scanf("%d", &n);
	int m[n][n];
	int *pm = m[0][0];
	pm = (int*)malloc(n * n * sizeof(int));
	system("clear");

	printf("Your matrix wiil be allocated at: %p\n", pm);

	createMatrix(pm, n);
	printMatrix(pm, n);

}


void createMatrix(int *mat, int l) {

	for (int i = 0; i < (l * l); i++) {
			printf("Type an integer: ");
			scanf("%d", mat);
			mat++;
	}
}

void printMatrix(int *mat, int l) {

	for (int i = 0; i < (l * l); i++) {
		printf("%d ", *mat);
		mat++;
	}
	printf("\n");
}
