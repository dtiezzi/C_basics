# Lista encadeada em C

## Daniel Tiezzi


Uma lista encadeada é uma estrutura linear e dinâmica composta por "células" que apontam para o próximo elemento da lista. Ela tem uma grande vantagem que é a alocação dinâmica de memória. Desta forma, a lista encadeada pode alocar dados até que haja espaço na meméria principal automaticamente.

###Estrutura da lista encadeada:

A lista encadeada consiste de 3 estruturas básicas que estão interligadas entre si:

>**Estrutura de dados:** onde serão armazenados os dados que o usuário necessita. Vamos denominar esta estrutura de `Database`;
> 
> **Estrutura de indexação da estrutura de dados:** esta estrutura é a base do encadeamento da lista onde temos uma estrutura que guarda o endereço de memória (ponteiro) da próxima estrutura. Vamos denominar de `Link`;
> 
> **Estrura da lista:** ela guarda a informação do tamanho da lista encadeada e faz a sua indexação. Vamos denominar esta estrutura de `Lista`.

<br/>
Desta forma, vamos começar implementando as três estruturas em C para guardar endereços de pessoas:

```c
// cria a estrutura DataBase
typedef struct batabase {
	char nome[20];
	char rua[20];
	int numero;
} DataBase;

// cria a estrutura Link
typedef struct link {
	DataBase data;
	struct link* next; // ponteiro para a próxima estrutura na lista
} Link;

//cria a estrutura Lista
typedef struct lista {
	int tam; // faz a indexação dos elementos na lista
	Link* head; // ponteiro para a última estutura da lista
} Lista;
```
<br/>

A Figura abaixo resume a estrutura da de nossa lista encadeada:

![listaencadeada](/Users/dtiezzi/C_Scripts/listaEncadeada.png)
<br/>

Nós agoras iremos implementar três funções básicas para a criação de nossa lista encadeada:

>Criar lista: esta função cria uma lista vazia. Será denominada `criarLista`;
>
>Insere a estrutura de dados na lista: esta função 'alimenta a lista com os dados. Iremos denominar de função `push`;
>
>Imprime os dados da lista: esta fução mostrará na tela os dados que estão 'guardados' na lista. Iremos denominar de `imprimeLista`.

<br/>

```c
Lista* criarLista(); // cria uma lista vazia
void push(Lista* lista, DataBase data); // alimenta a lista
void imprimeLista(Lista* lista); // mostra os dados na tela

Lista* criarLista() {

	// solicitar espaço para alocação dinâmica de memória para a Lista
	Lista* lista = (Lista*)malloc(sizeof(Lista));
	
	// criar uma lista vazia para inicialização
	lista->tam = 0; // cria o índice 0
	lista->head = NULL; // cria o topo da lista como vazio
	
	return lista;
	
}

void push(Lista* lista, DataBase data) {
	
	// solicitar espaço para alocação dinâmica de memória para o Link
	Link* link = (Link*)malloc(sizeof(Link));
	
	link->data = data;
	link->next = lista->head; // passa o endetreço do next para o topo da lista
	lista->head = link; // passa o endereço do top da lista para o próximo link
	lista->tam++; // incrementa o tamanho da lista
	
}


void imprimeLista(Lista* lista) {

	Link* ponteiro = lista->head; // cria um ponteiro para o topo da lista que é NULL.
	//Ou seja, iremos imprimir a lista até que o ponteiro aponte para um dado vazio
	
	if (ponteiro == NULL) // se a lista for vazia 
		printf("A lista está vazia!\n");
	
	while (ponteiro) { // enquento o ponteiro não for NULL
		printf("Nome: %s\n", ponteiro->data.nome);
		printf("Rua %s, %d\n", ponteiro->data.rua, ponteiro->data.numero);
		printf("\n==============================\n");
		ponteiro = ponteiro->next; // modifica o endereço do ponteiro para o próximo dado
	}
	
}
```

<br/>
Para finalizar precisamos criar a função `main`:

```c

void main(void) {
	
	Lista* l = criarLista(); // cria uma estrutura do tipo Lista
	DataBase data; // declara uma estrutura do tipo DataBase
	int loop = 1;
	
	while (loop) {
		printf("Digite seu nome: ");
		scanf(" %[^\n]s", &data.nome);
		printf("Digite o nome da rua: ");
		scanf(" %[^\n]s", &data.rua);
		printf("Digite o número da rua: ");
		scanf(" %d", &data.numero);
		push(l, data); // alimenta o banco de dados
		printf("Deseja inserir novo registro? (1= SIM/0= NÃO) ");
		scanf(" %d", &loop);
		if (loop != 1)
			loop = 0;
	}
	
	printf("Segue abaixo os registros no seu banco de dados:\n\n");
	imprimeLista(l);

}	

```

[**Link para o código completo**](http://143.107.196.146:3000/listaEncadeada.c)