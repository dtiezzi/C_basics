#include <stdio.h>
#include <stdlib.h>

typedef struct Produto {
	int serie;
	int lote;
	char data[10];
	struct Produto *prox;
} Produto;

void menu(); //menu de escolha das subrotinas
void push(Produto **ini, Produto **f, int *n); // insere um produto na lista.
void view(Produto *ini); // lista os produtos produzidos e não vendidos
Produto* pop(Produto *ini); // remove o produto vendido, que será o que foi produzido antes



void main(void) {

	Produto *inicio = NULL, *fim = NULL; // criamos dois ponteiros para o início e o fim da fila
	char op;
	int ns = 0; // contador para o número de série

	// iniciamos o menu de opções
	do {
		menu();
		scanf(" %c", &op);
		switch(op) {
			case '1':
				push(&inicio, &fim, &ns);
				break;
			case '2':
				view(inicio);
				break;	
			case '3':
				inicio = pop(inicio);
				break;
			case '4':
				exit(0);
			default:
				printf("Opção inválida!\n");
				break;
			}
	} while (op != '4');
}

void menu() {
	printf("Selecione uma das opções abaixo: \n");
	printf("\n1- Inserir\n");
	printf("2- Listar\n");
	printf("3- Remover\n");
	printf("4- Sair\n");
}

void push(Produto **ini, Produto **f, int *n) {

	Produto *novo=(Produto*)malloc(sizeof(Produto)); // cria um ponteiro novo e faz allocação dinâmica de memória para armazenar todas as variáveis necessárias
	
	if (novo == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	} // checa se existe memória suficiente para armazenar o dado
	
	*n = *n + 1;
	novo->serie = *n; // novo.serie recebe o número de série
	printf("Lote: \n");
	scanf("%d", &novo->lote);
	printf("Data fabricação: \n");
	scanf(" %[^\n]s", &novo->data);
	novo->prox = NULL;
	// Checar se a lista está vazia
	if (*ini == NULL)
		*ini = novo;
	else
		(*f)->prox = novo;
	*f = novo;
}


void view(Produto *ini) {

	if (ini == NULL)
		printf("Arquivo vazio!\n");
	else {
		while (ini != NULL) {
			printf("Serie: %d\n", ini->serie);
			printf("Lote: %d\n", ini->lote);
			printf("Data de fabricação: %s\n", ini->data);
			ini = ini->prox;
		}
	}
}

Produto* pop(Produto *ini) {

	if (ini == NULL) {
		printf("Arquivo vazio!\n");
		return NULL;
	}
	else {
		Produto *aux = ini->prox;
		free(ini);
		return aux;
	}
}