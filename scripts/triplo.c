#include <stdio.h>


// define my prototype

int triplo(int *);

int triplo(int *x) {
	return (3 * *x);
}

void main(void)
{
	printf("Digite um número:\n");
	int a;
	scanf("%d", &a);
	printf("O triplo do valor eh %d.\n",triplo(&a));
}