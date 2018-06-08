#include <stdio.h>
#include <string.h>

typedef struct {
	char titulo[100];
	int ano;
} Livro;

void main(void) {
	Livro x;
	//strcpy(x.titulo, "Teste");
	//x.ano= 2000;
	printf("Digite o título:\n");
	scanf("%[^\n]s", x.titulo);
	printf("Digite o ano:\n");
	scanf("%d", &x.ano);
	printf("Título %s, ano %d", x.titulo, x.ano);
}