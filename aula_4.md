# Curso Básico de Programação - Aula 4

## Daniel Tiezzi

### Estruturas de repetição

As estruturas de repetição são utilizadas em programação para a execução repetitiva de tarefas. Imagine uma situação onde você deseja calcular a média das notas de 100 alunos e que cada aluno tenha feito 5 provas. Se não existisse as estruturas de repetição, o código ficaria algo assim:

```c
#include <stdio.h>

void main(void) {
	float n1, n2, n3, n4, n5;
	char nome[30];

	printf("Digite o nome do aluno:\n");
	scanf(" %s", nome);

	printf("Digite a nota 1: \n");
	scanf("%f", &n1);

	printf("Digite a nota 2: \n");
	scanf("%f", &n2);

	printf("Digite a nota 3: \n");
	scanf("%f", &n3);

	printf("Digite a nota 4: \n");
	scanf("%f", &n4);

	printf("Digite a nota 5: \n");
	scanf("%f", &n5);

	printf("A média é %.2f\n", (n1+n2+n3+n4+n5)/5);
}
```

E você teria que repetir todo esse bloco de código 100 vezes, um para cada aluno. Com uma estrutura de repetição, podemos escrever em poucas linhas de código a mesma tarefa para que ela seja executada quantas vezes quisermos. Então vamos lá.

Em C, existem três tipos de estruturas de repetição. Aa estruturas de repetição também são conhecidas como laço, ou do inglês, *loop*. Temos os laços do tipo `for`, `while` e `do while`. O laço `for` é utilizado para executar um número pré-determinado de tarefas. Por exemplo, no caso das notas, se temos 5 notas, podemos usá-lo pra executar o código 5 vezes. Já o `while` e o `do while` são utilizados quando não temos um número definido de vezes em que a tarefa será executada. Por exemplo, se cada ano temos um número diferente de alunos por classe. A diferença entre o `while` e o `do while` nós vamos ver com mais detalhe e de forma mais clara quando executarmos o código. Porém, o que acontece é que o while a condição para que o bloco de código seja executado é testada antes da execução. Já o `do while`, o bloco é executado e depois a condição é testada. Vamos estudar cada um deles agora.

### Laço *for* ou *for loop*:

A figura abaixo exemplifica como o *for loop* funciona. Veja que uma condição é testada e se ela for verdadeira o bloco de código é executado. Caso contrário, o fluxo sai da estrutura de repetição:

![for loop](https://cdn.programiz.com/sites/tutorial2program/files/for-loop.jpg)

A sintaxe para o *for loop* é:

```c
for (int x= 0; x<= 10; x++) 
	instrução;
```

Então temos o `for` e temos 3 instruções dentro dos parênteses. Lembre-se que as instruções devem ser separadas por `;` aqui. A primeira `int x= 0`, declara a variável `x` e atribui o valor 0 para ela. `x` é a variável de controle. Pode ser usado qualquer nome para esta variável, não precisa ser exatamente `x`. E você define qual o o valor inicial dela. No caso aqui é 0. A segunda parte `x<= 10` é uma condicional onde o laço será executado se e somente se esta condição for verdadeira. Aqui no caso, sempre que o o valor de `x` for menor ou igual a 10, o bloco de código dentro do `for` será executado. A terceira instrução `x++` é o incremento. `x++` em C é o mesmo que escrever `x= x + 1`. Ou seja, após cada execução do bloco de código, o valor do `x` será incrementado. Ou seja, esta estrutura irá repetir o bloco de código 11 vezes (de 0 até 10). Vamos ver ela funcionando:

```c
#include <stdio.h>

void main(void) {

	for (int x= 0; x<= 10; x++)
		printf("x= %d\n", x);

}
```
Se rodarmos este código teremos:

	./for.out 
	x= 0
	x= 1
	x= 2
	x= 3
	x= 4
	x= 5
	x= 6
	x= 7
	x= 8
	x= 9
	x= 10

Uma coisa importante para a sintaxe das estruturas de repetição. Se o bloco de código da estrutura tem uma única instrução, então não é preciso colocar a instrução entre `{}`. No entanto, se houver mais de uma instrução, temos que colocar entre chaves. Faça um teste com os seguintes códigos:


```c
#include <stdio.h>

void main(void) {
	int x= 0;
	for (x; x<= 10; x++)
		printf("x= %d\n", x);
		printf("x * 2= %d\n", x * 2);

}
```


A saída é:


	x= 0
	x= 1
	x= 2
	x= 3
	x= 4
	x= 5
	x= 6
	x= 7
	x= 8
	x= 9
	x= 10
	x * 2= 22

Agora:

```c
#include <stdio.h>

void main(void) {
	int x= 0;
	for (x; x<= 10; x++) {
		printf("x= %d\n", x);
		printf("x * 2= %d\n", x * 2);
	}
}
```

A saída é:

	x= 0
	x * 2= 0
	x= 1
	x * 2= 2
	x= 2
	x * 2= 4
	x= 3
	x * 2= 6
	x= 4
	x * 2= 8
	x= 5
	x * 2= 10
	x= 6
	x * 2= 12
	x= 7
	x * 2= 14
	x= 8
	x * 2= 16
	x= 9
	x * 2= 18
	x= 10
	x * 2= 20


Veja que no primeiro código, somente a primeira linha após o `for` foi executada de forma repetitiva. No segundo, como colocamos as duas instruções entre `{}`, ambas são executadas pelo laço.

**Lembre-se que não é necessário sempre incrementar o valor dentro do *for*. Podemos decrementar. Podemos também incrementar de 2 em dois. Por exemplo, se quisermos imprimir somente os números pares**

Agora vamos aplicar o `for` para calcular a média das 5 notas. O código ficaria assim:

```c
#include <stdio.h>

void main(void) {
	float n, t;
	char nome[30];

	printf("Digite o nome do aluno:\n");
	scanf(" %s", nome);
	t= 0;
	for (int i= 1; i<= 5; i++) {
		printf("Digite a nota %d: \n", i);
		scanf("%f", &n);
		t= t + n;
	}
	printf("A média é %.2f\n", t/5);
}
```


Veja que aqui criamos uma variável `t`, que chamamos de **acumulador**. Cada repetição do `for` nós somamos o valor da nota digitada pelo usuário e atribuímos o valor à `t`. Veja qu coloquei o valor inicial de `i` como 1 para que possamos imprimir `printf("Digite a nota %d: \n", i);` valores diferentes a cada repetição.

### Laço *while* ou *while loop*:

O *while* funciona de forma semelhante, mas como disse anteriormente, podemos criar uma estrutura que será executada quantas vezes forem necessário. A figura abaixo exemplifica o funcionamento dele:

![while loop](https://cdn.programiz.com/sites/tutorial2program/files/c-while-loop.jpg)

Veja que uma condição é testada e se resultar em verdadeiro o bloco de códigos é executado. Caso contrário, o fluxo sai do *loop*. A sintaxe básica é:

```c
	while (condição)
		instrução
```

Temos então o `while` que significa enquanto em português e temos uma condição. Enquanto ela for **V**, executa o código. 

Então vamos colocar ela junto com o programa para cálculos da média. Como temos salas com número diferentes de alunos, vamos criar um laço *while* para que o professor possa ir calculando as médias de cada aluno até o último aluno, independente se tiver 3 ou 100 alunos. Vamos lá:

```c
#include <stdio.h>

void main(void) {
	float n, t;
	char nome[30];
	char novo= 's';

	while (novo == 's' || novo == 'S') {

		printf("Digite o nome do aluno:\n");
		scanf(" %s", nome);
		t= 0;

		for (int i= 1; i< 6; i++) {
			printf("Digite a nota %d: \n", i);
			scanf("%f", &n);
			t= t + n;
		}

		printf("A média final do aluno %s é %.2f\n\n", nome, t/5);
		printf("Deseja calcular a média de outro aluno (s/n)?\n");
		scanf(" %c", &novo);
	}
}
```

Veja que agora o programa vai executar toda vez que a variável `novo` for igual à `s` ou `S`. Desta forma, o usuário pode calcular a média dos alunos quantas vezes for necessário. 

Vou usar este momento para introduzir um conceito de constante em C. Uma constante não pode ser modificada. Diferente das variáveis que estamos utilizando, onde a atribuição de um novo valor modifica a variável. A constante também tem que ser declarada e ele é declarada antes do início da função utilizando a sintaxe:

```c
#define N 5
```
o `#define N` declara a constante `N` e o `5` atribui o valor para a constante. Veja que não é colocado o `;` após a expressão aqui. Por convenção, usamos letras maiúsculas para nomear as constantes. 

Desta forma, podemos utilizar uma constante em nosso programa para definir o número de provas por alunos. Vejamos:

```c
#include <stdio.h>
#define N 5

void main(void) {
	float n, t;
	char nome[30];
	char novo= 's';

	while (novo == 's' || novo == 'S') {

		printf("Digite o nome do aluno:\n");
		scanf(" %s", nome);
		t= 0;

		for (int i= 1; i<= N; i++) {
			printf("Digite a nota %d: \n", i);
			scanf("%f", &n);
			t= t + n;
		}

		printf("A média final do aluno %s é %.2f\n\n", nome, t/5);
		printf("Deseja calcular a média de outro aluno (s/n)?\n");
		scanf(" %c", &novo);
	}
}
```

Veja que agora temos a constante `N` de valor 5 que é utilizada no `for`. Vamos ver mais a frente que as constantes são úteis quando temos várias funções utilizando ela dentro de um mesmo programa.

### Laço *do while* ou *do while loop*:

Ele é bem semelhante ao *while*, porém o bloco de código é executado pelo menos uma vez antes da condição ser testada. Veja na figura abaixo que exemplifica ele:

![do while loop](https://cdn.programiz.com/sites/tutorial2program/files/c-do-while-loop.jpg)

A sintaxe é:

```c
	do
		instrução
	while (condição);
```

Ou seja, podemos usar ele no nosso programa de médias substituindo o *while*:

```c
#include <stdio.h>
#define N 5

void main(void) {
	float n, t;
	char nome[30];
	char novo;

	do {

		printf("Digite o nome do aluno:\n");
		scanf(" %s", nome);
		t= 0;

		for (int i= 1; i<= N; i++) {
			printf("Digite a nota %d: \n", i);
			scanf("%f", &n);
			t= t + n;
		}

		printf("A média final do aluno %s é %.2f\n\n", nome, t/5);
		printf("Deseja calcular a média de outro aluno (s/n)?\n");
		scanf(" %c", &novo);

	} while (novo == 's' || novo == 'S');
}
```

Veja que agora o programa executa o *loop* mesmo sem que o valor `s` ou `S` tenha sido atribuído à variável `novo`.

Agora que aprendemos como as estruturas de repetição funcionam, na próxima aula iremos ver como criamos vetores e matrizes em C.

**Até a próxima aula!**
