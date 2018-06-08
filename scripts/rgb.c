#include <stdio.h>

typedef struct{
	int r[256];
	int g[256];
	int b[256];
} RBG;

void loadRgb(RGB *y) {
	for (int i= 0; i<= 255; i++) {
		y->r= y->g= y->b= i;
	}
}

void main(void) {
	RGB y;
	loadRgb(*y);
	int x, y, z;
	printf("Type RGB values separateb by comma (,):\n");
	scanf("%d,%d,%d", &x, &y, &z)
	printf("%d,%d,%d\n", x, y, z);
}