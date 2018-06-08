#include <stdio.h>

typedef struct{
	int r[256];
	int g[256];
	int b[256];
} RBG;

void loadRgb(void) {
	for (int i= 0; i<= 255, i++) {
		r= g= b= i;
	}
}

void main(void) {
	loadRgb();
	printf("Type RGB values separateb by comma (,):\n");
	scanf("%d,%d,%d", &r, &g, &b)
	printf("%d,%d,%d\n", r, g, b);
}