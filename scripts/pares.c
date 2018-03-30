#include <stdio.h>


int main (void) {
	int pares[6];
	for(int i= 0; i<= 5; i++) {
		pares[i] = 2*(i+1); 
	}

	for (int i= 0; i<= 5; i++) {
		printf("%d ", pares[i]);
	}
	printf("\n");
}