#include <stdio.h>
#include <math.h>

void solve(int p, int q, int r, float *d1, float *d2) {
	float delta, x, y;
	delta= pow(q,2) - (4 * p * r);
	if (delta == 0) {
		*d1 = *d2 = -q / (2 * p);
	} else if (delta < 0) {
		printf("A equação não tem velores reais!\n");
		*d1= *d2 = 0;
	} else {
		*d1 = (-q + sqrt(delta)) / (2 * p);
		*d2 = (-q - sqrt(delta)) / (2 * p);
	}
}


void main() {
	
	int a, b, c;
	float x1, x2;
	printf("Digite os valores de a, b e c separados por espaço:\n");
	scanf("%d %d %d", &a, &b, &c);
	solve(a, b, c, &x1, &x2);
	printf("Os valores de x1 e x2 são: %.1f e %.1f.\n", x1, x2);
}