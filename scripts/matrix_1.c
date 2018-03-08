#include <stdio.h>

int rows, cols;

int createMatrix(int m[rows][cols]) {
	for (int i= 0; i< rows; i++) {
		for (int j= 0; j< cols; j++) {
			printf("Digite um número:\n");
			scanf("%d", &m[i][j]);
		}
	}
	return m;
}

void printMatrix(int m[rows][cols]) {
	printf("A matrix digitada foi:\n\n");
	for (int i= 0; i< rows; i++) {
		for (int j= 0; j< cols; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void printDiagSum(int m[rows][cols]) {
	int sum1= 0;
	for (int i= 0; i< rows; i++) {
		for (int j= 0; j< cols; j++) { 
			if (i == j) {
				sum1 += m[i][j];
			}
		}
	}	
	printf("A soma da diagonal é: %d\n", sum1);
}

void printCounterDiagSum(int m[rows][cols]) {
	int sum2= 0;
	for (int i= 0; i< rows; i++) {
		for (int j= 0; j< cols; j++) { 
			if ((i + j) == ((rows + 1)-2)) {
				sum2 += m[i][j];
			}
		}
	}	
	printf("A soma da diagonal inversa é: %d\n", sum2);
}

void printOffDiagSum(int m[rows][cols]) {
	int sum3= 0;
	for (int i= 0; i< rows; i++) {
		for (int j= 0; j< cols; j++) { 
			if ((i != j) & ((i + j) != ((rows + 1)-2))) {
				sum3 += m[i][j];
			}
		}
	}	
	printf("A soma dos números fora das diagonais é: %d\n", sum3);
}


void main() {

	printf("Digine o número de colunas para uma matriz quadrada: \n");
	scanf("%d", &rows);
	cols= rows;
	int matrix[rows][cols];
	createMatrix(matrix);
	printMatrix(matrix);
	printDiagSum(matrix);
	printCounterDiagSum(matrix);
	printOffDiagSum(matrix);
}