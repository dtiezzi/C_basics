# Curso Básico de Programação - Aula 7
## Daniel Tiezzi

### Ponteiros (passagem de valores por endereço)


A utilização de ponteiros é una boa prática em programação em C e possibilita trabalhar com variáveis de forma mais eficiente e segura, em especial quando uma variável tem que ser acessada em diferentes partes de um programa. Em C, o ponteiro é um tipo de variável que guarda um endereço de memória. Ou seja, em uma variável do tipo ponteiro não teremos um número inteiro (*int*) ou uma *string*. Termos um endereço de memória (memória RAM) onde está armazenado uma variável. Um ponteiro do tipo *int* só pode endereçar uma variável *int*. Ou seja, não podemos atribuir para um ponteiro o endereço de variáveis de outro tipo. 
Os ponteiros devem ser declarados também, como toda e qualquer variável em C. Para declarar que uma variável é do tipo ponteiro basta adicionar um `*` antes do nome da variável:

`int *x;` ou `char *y;`

Após declarar uma variável do tipo ponteiro, você pode atribuir à ela outra variável. O ponteiro irá armazenar o endereço de memória da variável atribuída a ele

Vamos ver o programa abaixo:

```c
#include <stdio.h>

void troca(int x, int y) {
	int aux;
	aux= x;
	x= y;
	y= aux;
}

void trocaP(int *x, int *y) {
	int aux;
	aux= *x;
	*x= *y;
	*y= aux;
}


void main(void) {
	int a, b;
	printf("Digite um número:\n");
	scanf("%d", &a);
	printf("Digite outro número:\n");
	scanf("%d", &b);
	troca(a, b);
	printf("Imprimindo os valores sem utilizar ponteiro:\n");
	printf("O valor de a= %d e b= %d\n", a, b);
	trocaP(&a, &b);
	printf("Utilizando ponteiros:\n");
	printf("O valor de a= %d e b= %d\n", a, b);
}
``` 

Veja que crie duas funções `troca()` e `trocaP`. A diferença entre elas é que a `troca()` recebe dois argumentos do tipo `int` e a `trocaP()` recebe dois argumentos do tipo ponteiro para `int`. Ou seja, a primeira irá receber dois números inteiros e a segunda irá receber endereços de memória de dois números inteiros.

Depois temos a `main()`. A `main()` começa recebendo do usuário dois valores inteiros e atribui os valores para as variáveis `a` e `b`. A seguir ela chama a função `troca()` passando os valores das variáveis `a` e `b`, que é executada. Depois ela imprime os valores das variáveis `a` e `b` na tela. 
A seguir, temos a chamada da função `trocaP()` onde é passado o endereço de memória das variáveis `a` e `b`. Veja que aqui não estamos passando os valores de `a` e `b`, e sim o endereço de memória onde os valores de `a` e `b` estão armazenados. A função `trocaP()` é executada e depois os valores de `a` e `b` são imprimidos na tela.

A saída deste programa na tela será:

```sh
dtiezzi@kushin:~$ ./troca.out 
Digite um número:
2
Digite outro número:
7
Imprimindo os valores sem utilizar ponteiro:
O valor de a= 2 e b= 7
Utilizando ponteiros:
O valor de a= 7 e b= 2
``` 

Note que a função `troca()` não modificou os valores de `a` e `b`. o que houve? Será que ela não funcionou? Bem, vamos pedir para as funções imprimirem os valores dentro delas:

```c
#include <stdio.h>

void troca(int x, int y) {
	int aux;
	aux= x;
	x= y;
	y= aux;
	printf("Imprimindo os valores dentro da função troca()\n");
	printf("o valor de a= %d e b= %d.\n", x, y);
}

void trocaP(int *x, int *y) {
	int aux;
	aux= *x;
	*x= *y;
	*y= aux;
	printf("Imprimindo os valores dentro da função trocaP()\n");
	printf("o valor de a= %d e b= %d.\n", *x, *y);
}


void main(void) {
	int a, b;
	printf("Digite um número:\n");
	scanf("%d", &a);
	printf("Digite outro número:\n");
	scanf("%d", &b);
	troca(a, b);
	printf("Imprimindo os valores som utilizar ponteiro:\n");
	printf("O valor de a= %d e b= %d\n", a, b);
	trocaP(&a, &b);
	printf("Utilizando ponteiros:\n");
	printf("O valor de a= %d e b= %d\n", a, b);
}
```
Essa seria a saída na tela:

```sh
dtiezzi@kushin:~$ ./troca.out
Digite um número:
2
Digite outro número:
7
Imprimindo os valores dentro da função troca()
o valor de a= 7 e b= 2.
Imprimindo os valores som utilizar ponteiro:
O valor de a= 2 e b= 7
Imprimindo os valores dentro da função trocaP()
o valor de a= 7 e b= 2.
Utilizando ponteiros:
O valor de a= 7 e b= 2
```

Veja que agora, dentro da função `troca()` os valores de `a` e `b` foram trocados, mas fora da função não. O mesmo não ocorre com a função `trocaP()`. Este é um exemplo bem claro de como os ponteiros funcionam em C. Vamos explicar o que aconteceu.
Lembram das variáveis locais e globais? Aqui estamos trabalhando com variáveis locais. Todas elas estão dentro de funções. A função `troca()` declara duas variáveis `int` `x` e `y`. A função `trocaP()` declara mais duas do tipo ponteiro de `int` `*x` e `*y` e a função `main()` declara mais dois `int` `a` e `b`. As variáveis locais ficam guardadas na memória somente durante a execução da função. Assim que a função termina, elas são descartadas. Ou seja, se você tentar imprimir os valores de `x` e `y` dentro da função `main()` que foram declarados na função `troca()`, o compilador vai dar um erro do tipo `error: use of undeclared identifier 'x'`. 
Assim, o que acontece é que a função `main()` atribui os valores de `a` e `b` para as variáveis `x` e `y` dentro da função `troca()`, que executa a troca. Mas a troca é feita entre as variáveis `x` e `y`, não entre `a` e `b`. Desta forma, quando a função `troca()` termina, as variáveis `x` e `y` são destruídas, e as variáveis `a` e `b` permanecem inalteradas.
Por outro lado, a `main()` passa para a função `trocaP()` os endereços de memória de `a` e `b`. Quando a função é executada, ela modifica os valores que está armazenados nos respectivos endereços. Aqui a `trocaP()` está modificando variáveis que foram declaradas fora dela. Desta forma, quando ela termina, o que é descartado são os endereços de memória armazenados em `*x` e `*y`, e não as variáveis `a` e `b`, que dentro da `main()` continuarão trocadas. 

Espero que este conceito tenha ficado claro. Na próxima aula vamos ver ponteiros para vetores.  Até a próxima! 


