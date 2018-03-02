#include <stdio.h>

void main(void) {
	int count, num;
	int vector[100];
	printf("Digite um número inteiro: \n");
	scanf("%d", &num);
	count= 0;
	while (num > 0) {
		vector[count] = num % 2; // pega o resto da divisão e atribui ao vetor
		num = num / 2; // faz a divisão inteira do número
		count++;
	}
	// imprimi o vetor ao contrário
	
	for (int i= count-1; i>= 0; i--) {
		printf("%d",vector[i]);
	}
	printf("\n");

}
