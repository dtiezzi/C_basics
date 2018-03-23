#include <stdio.h>

void troca1(int, int);
void troca2 (int *, int *);

void troca1(int a, int b) {
	int tmp;
	tmp= a;
	a= b;
	b= tmp;
	printf("a= %d e b= %d\n", a, b);
}

void troca2 (int *a, int *b) {
	int tmp;
	tmp= *a;
	*a= *b;
	*b= tmp;
	printf("a= %d e b= %d\n", *a, *b);
}

void main(void)
{
	printf("Digite dois números separados por espaço:\n");
	scanf("%d %d", &a, &b);
	troca1(a, b);
	troca2(&a, &b);
	printf("a= %d e b= %d\n", a, b);
}