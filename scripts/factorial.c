#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial(int *);

int factorial(int *x) {
	int f = *x;
	int i= *x - 1;
	 if (f == 0 || f == 1) {
		f= 1;
	} else {
		for(i; i > 0; i--) {
		f = f * i;
		}
	}
	return f;
}

void main(void) {
	clock_t tic = clock();
	int x;
	printf("Type a integer:\n");
	scanf("%d", &x);
	system("clear");
	if (x < 0) {
		printf("ERRO! Digite um valor maior ou igual a 0.\n\n");
	} else {
		printf("O valor fatorial de %d = %d\n\n", x, factorial(&x));
	}
	clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
} 