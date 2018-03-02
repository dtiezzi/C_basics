#include <stdio.h>

int menu() {
	int res;
	printf("Digite 1 para conversão decimal para binário ou 2 para binário para decimal\n: ");
	scanf("%d", &res);
	return res;
}

void dec2bin(int x) {
	int count= 0;
	int vector[100];
	
	while (x > 0) {
		vector[count] = x % 2; 
		x = x / 2; 
		count++;
	}
	
	for (int i= count-1; i>= 0; i--) {
		printf("%d",vector[i]);
	}
	printf("\n");
}

void bin2dec(int x) {
	int  dec = 0, base = 1, r;
	while (x > 0)
    {
        r = x % 10;
        dec = dec + (r * base);
        x = x / 10 ;
        base = base * 2;
    }
    printf("%d\n", dec);
	
}

void main() {
	int r, n;
	r= (menu());
	if (r == 1) {
		printf("Digite um número em decimal: \n");
		scanf("%d", &n);
		dec2bin(n);
	} else {
		printf("Digite um número em binário: \n");
		scanf("%d", &n);
		bin2dec(n);
	}
}
