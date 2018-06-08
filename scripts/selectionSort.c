#include <stdio.h>
#include <string.h>
#include <time.h>

void selectionsort(char *item, int count);

void main(void) {
	char f[100];
	int l;
	float t;
	printf("Digite uma frase:\n");
	scanf(" %[^\n]s", &f);
	l= strlen(f);
	t= clock();
	selectionsort(f, l);
	printf("%f\n", clock() - t);
} 

void selectionsort(char *item, int count) {
	int a,b,c, troca;
	char t;
	for (a= 0; a< count; ++a) {
		troca= 0;
		c= a;
		t= item[a];
		for (b= a+1; b< count; ++b) {
			if (item[b] < t) {
				c= b;
				t= item[b];
				troca= 1;
			}
		}
		if (troca) {
			item[c] = item[a];
			item[a] = t;
		}
	}
	printf("%s\n", item);
}
