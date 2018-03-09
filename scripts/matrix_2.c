#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rows, cols;

int createMatrix(int m[rows][cols]) {
	srand(time(NULL));
	for (int i= 0; i< rows; i++) {
		for (int j= 0; j< cols; j++) {
			m[i][j] = rand() % 100;
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

void printMatrixSum(int m[rows][cols]) {
	int sum0= 0;
	for (int i= 0; i< rows; i++) {
		for (int j= 0; j< cols; j++) {
			sum0 += m[i][j];
		}
	}
	printf("A soma dos valores da matrix é: %d\n\n", sum0);
}

void printDiagSum(int m[rows][cols]) {
	int sum1= 0;
	for (int i= 0; i< rows; i++) {
		int j= i;
			sum1 += m[i][j];
		}	
	printf("A soma da diagonal é: %d\n\n", sum1);
}

void printCounterDiagSum(int m[rows][cols]) {
	int sum2= 0;
	for (int i= 0; i< rows; i++) {
		int j= (rows - 1) - i;
		sum2 += m[i][j];
	}	
	printf("A soma da diagonal inversa é: %d\n\n", sum2);
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
	printf("A soma dos números fora das diagonais é: %d\n\n", sum3);
}

void printEvensInDiag(int m[rows][cols]) {
	int evens= 0;
	int sum4= 0;
	for (int i= 0; i< rows; i++) {
		int j= i;
		if (m[i][j] % 2 == 0){
			evens++;
			sum4 += m[i][j];
		}
	}
	printf("O número de valores pares na diagonal principal é %d.\n\n", evens);
	printf("A soma dos valores pares na diagonal principal é %d.\n\n", sum4);
}

void printMultipleIf(int m[rows][cols]) {
	int evens= 0;
	int sum5= 0;
	int sum6= 0;
	int multiple;
	for (int i= 0; i< rows; i++) {
		for (int j= 0; j< cols; j++) {
			sum5 += m[i][j];
			if (m[i][j] % 2 == 0) {
				evens++;
			} else {
				sum6 += m[i][j];
			}
		}
	}
	if (evens >= 5) {
		multiple= 3 * sum5;
		printf("O triplo da soma dos valores da matriz é %d.\n\n", multiple);
	} else {
		multiple= 2 * sum6;
		printf("O dobro da soma dos valores impares da matriz é %d.\n\n", multiple);
	}
}

void main() {

	printf("Digine o número de colunas para uma matriz quadrada: \n");
	scanf("%d", &rows);
	cols= rows;
	int matrix[rows][cols];
	createMatrix(matrix);
	printMatrix(matrix);
	printMatrixSum(matrix);
	printDiagSum(matrix);
	printCounterDiagSum(matrix);
	printOffDiagSum(matrix);
	printEvensInDiag(matrix);
	printMultipleIf(matrix);

}