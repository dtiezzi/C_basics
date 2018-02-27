# Curso Básico de Programação - Aula 5

## Daniel Tiezzi

### Vetores

Vetores, também conhecidos como *arrays* é uma coleção de variáveis do mesmo tipo. Ou seja, podemos criar um vetor de números inteiros ou de caracteres. Em C, to palavra ou *string* armazenada é na verdade um vetor de caracteres.
Todo vetor é indexado de forma numérica e o índice sempre começa pelo 0. Desta forma, um conjunto de números `{3,5,7,10,2}` é um vetor com 5 valores onde o índice 0 é o valor `3` e o índice 4 é o valor `2`.
Os vetores tem que ser declarados e a sintaxe é:

```c
	int vetor1[5];
	int vetor1[5] = {3,5,7,10,2}
	char vetor2[3] = "dgt"
	char vetor3[3] = {'d', 'g', 't'}
```

Desta forma, podemos criar um vetor para armazenar valores. Vamos criar um vetor e imprimir o resultado:

```c
#include <stdio.h>

void main(void) {
	int vetor[5];
	for (int i= 0; i< 5; i++) {
		printf("Digite um número para o índice %d: \n", i);
		scanf("%d", &vetor[i]);
	}
	for (int i= 0; i< 5; i++) {
		printf("%d", vetor[i]);
	}
	printf("\n");
}
```


**Vamos utilizar um vetor juntamente com estruturas de repetição para convertermos valores decimais em binário?** 

Para converter um número decimal em binário, uma das formas é fazer a divisão inteira por 2 e armazenar o resto e dividir novamente até que a divisão inteira termine. Os restos da divisão por 2 vão formar o número binário.

Vamos usar o número 13:

- Dividimos 13 / 2:
	- A divisão inteira é 6 e o resto é 1;
- Dividimos 6 / 2:
	- A divisão inteira é 3 e o resto é 0;
- Dividimos 3 / 2:
	- A divisão inteira é 1 e o resto é 1;
- Dividimos 1 / 2:
	- A divisão inteira é 0 e o resto é 1;

Então temos um conjunto de restos `{1, 0, 1, 1}`. Se imprimirmos o inverso dele `1101` temos o número 13 em binário.

Fica aqui o desafio. Criar um programa em C que converta números decimais em binários. Uma possível resolução está em anexo.


### Matrizes

Um matriz em C nada mais é que um vetor em duas dimensões. Desta forma, teremos uma variável com duas indexações, criando espacialmente uma matriz. Desta forma, par declarar uma matrix utilizamos duas dimensões sendo a primeira o número de linhas e a segunda o número de colunas. Vamos pensar na seguinte matriz:

 Index | 0 | 1 | 2 | 3 |
:-: | :-: | :-: | :-: | :-: |
0 | 10 | 8 | 12 | 8
1 | 5 | 9 | 18 | 9
2 | 7 | 11 | 7 | 12
3 | 2 | 7 | 9 | 6

Temos então uma matriz com 4 linhas e 4 colunas. Para declarar a matriz seria `int matrix[4][4]` e para preencher a matriz seria:

```c
int matrix[4][4] = {{10,8,12,8},{5,9,18,9},{7,11,7,12},{2,7,9,6}}
```

Então vamos colocar em um programa e imprimir a matriz na tela:

```c
#include <stdio.h>

void main(void) {
	
	int matrix[4][4] = {{10,8,12,8},{5,9,18,9},{7,11,7,12},{2,7,9,6}};
	for (int i= 0; i< 4; i++) {
		for (int j= 0; j< 4; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
```

