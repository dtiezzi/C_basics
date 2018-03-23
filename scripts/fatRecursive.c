#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial(int n) {
	if ((n == 0) || (n == 1))
		return 1;
	else
		return (n * factorial(n - 1));
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
		printf("O valor fatorial de %d = %d\n\n", x, factorial(x));
	}
	clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}