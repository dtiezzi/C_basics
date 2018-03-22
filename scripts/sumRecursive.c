#include <stdio.h>

int somatorio(int);

int somatorio(int x) {
	if (x == 1)
		return 1;
	else
		return x + somatorio(x - 1);
}

void main(void) {
	int n;
	printf("Digite um numero:\n");
	scanf("%d", &n);
	printf("%d\n", somatorio(n));
}