#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int createRow_1(int);
int createColumn_1(int);


int createRow_1(int rLen) {
	int row_1[rLen];
	for (int i= 0; i< rLen; i++) {
		row_1[i]= 0;
	}
	return row_1;
}

int createColumn_1(int cLen) {
	int col_1[cLen];
	for (int i= 0; i< cLen; i++) {
		col_1[i]= 0;
	}
	return col_1;
}

void printRow (char x[]) {
	for (int i= 0; i< rLen; i++) {
		printf("%d", row_1[i]);
	}
}

void main(void) {
	int rLen, cLen;
	char str1[100], str2[100];
	printf("Type the first string:\n");
	gets(str1);
	printf("Type the second string:\n");
	gets(str2);
	rLen= strlen(str1);
	cLen= strlen(str2);
	createRow_1(rLen);
	createColumn_1(cLen);
	printRow(row_1[rLen]);
}