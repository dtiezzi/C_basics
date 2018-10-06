# Listas encadeadas

## Daniel Tiezzi

As listas encadeadas podem ser utilizadas para criar um sistema de arquivo de dados. Para isso é necessário utilizar uma estrutura para o armazenamento de dados e um ponteiro para criar um *link* entre os elementos. Uma lista encadeada pode ser formada como um sistema de fila (*first in, first out*) ou uma pilha (*first in, last out*).

Para a criação da lista encadeada vamos utilizar uma estrutura do tipo `struct` e um ponteiro.

Vamos imaginar que precisamos criar um sistema para gerenciar uma linha de produção. O sistema tem que armazenar o número de série e o lote do produto e a data em que foi produzido. Os produtos serão embalados e depois vendidos, sendo que o primeiro a ser produzido será o primeiro a ser vendido, e assim consequentemente. Ele também tem que ter uma subrotina para listar os produtos e para remover aqueles que foram vendidos uma a um.

Assim, podemos utilizar  a `struct` para armazenar dados de tipos primitivos diferentes. Desta forma vamos criar uma `struct` do tipo `Produto`.

**Estrutura para armazenamento de dados:**

```c
typedef struct Produto {
	int serie;
	int lote;
	char data[10];
	struct Produto *prox;
} Produto;
```

Veja que a estrutura pode armazenar todas as variáveis e criamos um ponteiro do tipo `Produto` dentro da estrutura que irá fazer o *link* entre os elementos.

Como precisamos ordenar os produtos em número de série, sendo o último produzido terá o maior número de série e o primeiro a ser produzido será o primeiro a ser vendido, podemos criar uma estrutura do tipo lista.

**Vamos criar os protótipos das subrotinas:**

```c
void menu(); //menu de escolha das subrotinas
void push(Produto **ini, Produto **f, int *n); // insere um produto na lista.
void view(Produto *ini); // lista os produtos produzidos e não vendidos
Produto* pop(Produto *ini); // remove o produto vendido, que será o que foi produzido antes
```


**Vamos criar nosso bloco principal:**

```c
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
```

Vamos implementar as rotinas. 

**Menu de opções:**

```c
void menu() {
	printf("Selecione uma das opções abaixo: \n");
	printf("\n1- Inserir\n");
	printf("2- Listar\n");
	printf("3- Remover\n");
	printf("4- Sair\n");
}

```
**Procedimento para inserir na lista:**

```c

void push(Produto **ini, Produto **f, int *n) {

	Produto *novo=(Produto*)malloc(sizeof(Produto)); // cria um ponteiro novo e faz alocação dinâmica de memória para armazenar todas as variáveis necessárias
	
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

```


**Listar os elementos:**

```c
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

```


**Remover elementos da lista:**

```c
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

```
