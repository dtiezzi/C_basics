#include <stdio.h>
#include <string.h>
#include <time.h>

void insert(char *item, int count);

void main(void) {
	char f[100];
	int l;
	float t;
	printf("Digite uma frase:\n");
	scanf(" %[^\n]s", &f);
	l= strlen(f);
	t= clock();
	insert(f, l);
	printf("%f\n", clock() - t);
}

void insert(char *item, int count) {
	int a,b;
	char t;
	for (a= 1; a< count; ++a) {
		t= item[a];
		for (b= a-1; b>=0 && t< item[b]; b--) {
			item[b + 1] = item[b];
			item[b]= t;
		}
	} 
	printf("%s\n", item);
}
