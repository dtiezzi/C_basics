#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int n;
	printf("Digite o número de pessoas:\n");
	scanf("%d", &n);
	char *vp[n];
	for (int i= 0; i< n; i++)
		vp[i] = NULL;

	char name[30];
	printf("Digite o nome do aluno:\n");
	scanf(" %s", &name);
	system("clear");
	vp[n-1] = name;

	for (int i= 0; i< n; i++) {
		printf("%s\n", vp[i]);
	}
	printf("\n");
}