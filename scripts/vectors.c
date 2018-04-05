#include <stdio.h>


char c[5] = "abcde";
int in[5] = {1,2,3,4,5};
float ft[5] = {1.0, 2.0, 3.0, 4.0, 5.0};

void main(void) {

	// Pode increntar o index

	for (int i= 0; i<= 4; i++) {
		printf("%c", c[i]);
	}
	printf("\n\n\n");

	for (int i= 0; i<= 4; i++) {
		printf("%d, ", in[i]);
	}
	printf("\n\n\n");

	for (int i= 0; i<= 4; i++) {
		printf("%f, ", ft[i]);
	}
	printf("\n\n\n");

	// Pode criar um ponteiro para seu vetor e incrementar o endereço

	char *p= c;
	int *p1= in;
	float *p2= ft;

	for (int i= 0; i<= 4; i++) {
		printf("%c, ", *p);
		printf("%d\n", p);
		p++;
	}
	printf("\n");

	for (int i= 0; i<= 4; i++) {
		printf("%d, ", *p1);
		printf("%d\n", p1);
		p1++;
	}
	printf("\n");

	for (int i= 0; i<= 4; i++) {
		printf("%f, ", *p2);
		printf("%d\n", p2);
		p2++;
	}
	printf("\n");
}