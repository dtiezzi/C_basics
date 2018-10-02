#include <stdio.h>
#include <stdlib.h>


int createVector(int *vec, int l);
void printVector(int *vec, int l);


void main(void) {

	int *v;
	int n;
	printf("Prease, type the vector's lenght: ");
	scanf("%d", &n);
	v = (int*)malloc(n*sizeof(int));
	system("clear");

	printf("Your vector will be allocated at: %p\n", v);
	if (v == NULL) {
		printf("Sem memória.\n");
		exit(1);
	}
	createVector(v, n);
	printVector(v, n);

}


int createVector(int *vec, int l) {

	for (int i = 0; i < l; i++) {
		printf("Type a integer:\n");
		scanf("%d", vec);
		vec++;
	}

}


void printVector(int *vec, int l) {

	system("clear");
	printf("\n######################\n");

	printf("\nYour vector is: ");
	for(int i = 0; i < l; i++) {
		if (i < l - 1)
			printf("%d, ", *vec);
		else
			printf("%d\n", *vec);
		vec++;
	}
	printf("\n######################\n");

}
