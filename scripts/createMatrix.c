#include <stdio.h>
#define ROWS 3
#define COLS 3



int createMatrix(int m[ROWS][COLS]) {
	for (int i= 0; i< ROWS; i++) {
		for (int j= 0; j< COLS; j++) {
			printf("Digite um número:\n");
			scanf("%d", &m[i][j]);
		}
	}
	return m;
}

void printMatrix(int m[ROWS][COLS]) {
	for (int i= 0; i< ROWS; i++) {
		for (int j= 0; j< COLS; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printDiagSum(int m[ROWS][COLS]) {
	int sum1= 0;
	for (int i= 0; i< ROWS; i++) {
		for (int j= 0; j< COLS; j++) { 
			if (i == j) {
				sum1= sum1 + m[i][j];
			}
		}
	}	
	printf("A soma da diagonal é: %d\n", sum1);
}

void printCounterDiagSum(int m[ROWS][COLS]) {
	int sum2= 0;
	for (int i= 0; i< ROWS; i++) {
		for (int j= 0; j< COLS; j++) { 
			if ((i + j) == ((ROWS + 1)-2)) {
				sum2= sum2 + m[i][j];
			}
		}
	}	
	printf("A soma da diagonal inversa é: %d\n", sum2);
}



void main() {
	int matrix[ROWS][COLS];
	createMatrix(matrix);
	printMatrix(matrix);
	printDiagSum(matrix);
	printCounterDiagSum(matrix);
}
