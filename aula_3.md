# Curso Básico de Programação - Aula 3

## Daniel Tiezzi

### Controle de Fluxo

Até agora nós criamos dois programas: i) imprime o nome e a idade na tela; ii) calculadora. Em ambos, o fluxo de instruções foi sempre linear. Ou seja, cada instrução foi realizada de forma sequencial e todas as instruções que estavam no programa foram realizadas. Você concorda? Nesta aula iremos ver estruturas que alteram o fluxo sequencial e permitem definir se um certo bloco de códigos, ou mesmo todo programa, irá ou não ser executado.

Em C existem duas estruturas que podem ser utilizadas para controlar o fluxo de programação. São as estruturas **condicionais** onde o fluxo é direcionado **SE** uma condição for satisfeita, e o chamado _**switch/case**_. O teste _**switch**_ compara uma expressão com diversos valores que podem estar associados com blocos de código diferentes. Então, vamos ver como cada uma destas estruturas funcionam após uma breve introdução à lógica de computação.

### Estruturas lógicas

Nós vimos na aula anterior que existem alguns operadores lógicos em C. São eles:
	* `&&` = "E" lógico
	* `||` = "OU" lógico
	* `!` = "NÃO" lógico

Na lógica de programação teremos sempre um expressão **VERDADEIRA** (**V**) ou **FALSA** (**F**). Em C, o valor= 0 sempre é **F**, enquanto os valores diferentes de 0 serão **V**. Os operadores lógicos aplicados à mais de uma expressão resultam sempre em **V** ou **F**. Vamos ver como:

Para o "E" lógico temos:

Condição 1 | Operador | Condição 2 | Resultado
:--------: | :------: | :--------: | :--------:
`V` | `&&` | `V` | Verdadeiro
`V` | `&&` | `F` | Falso
`F` | `&&` | `V` | Falso
`F` | `&&` | `F` | Falso

Ou seja, uma expressão onde existe um operador lógico `&&` somente resultará em **V** se todas as condições forem **V**.

No caso do "OU" lógico, se uma das condições for **V**, o resultado final será **V**:

Condição 1 | Operador | Condição 2 | Resultado
:--------: | :------: | :--------: | :--------:
`V` | `||` | `V` | Verdadeiro
`V` | `||` | `F` | Verdadeiro
`F` | `||` | `V` | Verdadeiro
`F` | `||` | `F` | Falso

Já o operador `!`, "NÃO" lógico, ele inverte a condição:

Operador | Condição 2 | Resultado
:------: | :--------: | :--------:
`!` | `V` | Falso
`!` | `F` | Verdadeiro

Nós vimos na aula anterior que existem alguns operadores que chamamos de relacionais. São eles o `==`, `!=`, `>`, `>=`, `<` e `<=`. Eles expressam a relação entre valores de duas variáveis ou entre uma variável e um valor qualquer. Então podemos usar esses operadores relacionais em uma condicional única ou em múltiplas utilizando operadores lógicos entre elas. Por exemplo:

Criamos duas variáveis numéricas:

	int x, y;
	x= 5;
	y= 7;

Então vejamos as expressões:

* `x < y` = Verdadeiro
* `x == y` = Falso
* `x != y` = Verdadeiro
* `x != y && x > 10` = Falso
* `x != y || x > 10` = Verdadeiro

Veja que podemos combinar variáveis como operadores lógicos e relacionais para descrever expressões lógicas. Com essas expressões, podemos fazer controle de fluxo do programa colocando ela dentro de estruturas condicionais. É o que vamos ver a seguir.

### Condicional - if / else if / else

O teste **if** compara uma condição e desvia o fluxo conforme a condição seja **V** ou **F**. Veja a figura abaixo:

![If statement C](https://cdn.programiz.com/sites/tutorial2program/files/flowchart-if-programming_0.jpg)

A seta define a direção do fluxo do programa. Existe um teste que verifica se uma condição é **V** ou **F**. Se **V**, um bloco de código inserido na estrutura da condicional é executado. Caso contrário, o programa desvia o fluxo e e continua a execução após este bloco de instruções. Vamos criar um programa com uma condicional simples usando o `if / else` (se /então). O programa vai receber um número do usuário e vai multiplicar por 2 se o número for maior que 7 ou dividir por 2 se for menor ou igual. Vamos lá.

```c
#include <stdio.h>

void main(void) {
	float num;
	printf("Digite um número: \n");
	scanf("%f", &num);
	
	if (num > 7) {
		num= num * 2.0;
		printf("O dobro do número digitado é %.1f\n", num);
	} else {
		num= num / 2.0;
		printf("A metade do número digitado é %.1f\n", num);
	}
}
```

Nós podemos colocar mais condições. Vamos colocar para ele multiplicar por 2 se o número estiver entre 7 e 15 e ele vai subtrair o dobro dele se for maior que 15.

```c
#include <stdio.h>

void main(void) {
	float num;
	printf("Digite um número: \n");
	scanf("%f", &num);
	
	if (num > 15) {
		num= num - (num * 2);
		printf("A subtração do dobro do número digitado é %.1f\n", num);
	} else if (num > 7 && num <= 15) {
		num= num * 2;
		printf("O dobro do número digitado é %.1f\n", num);
	} else {
		num= num / 2;
		printf("A metade do número digitado é %.1f\n", num);
	}
}
```

Veja que o programa agora pode executar 3 diferentes blocos de códigos conforme cada uma das condições. Nós podemos utilizar utilizar também variáveis do tipo *char* para as condicionais:

```c
#include <stdio.h>

void main(void) {
	float num;
	printf("Digite um número: \n");
	scanf("%f", &num);
	char resposta;
	printf("Deseja continuar (s/n)? \n");
	scanf(" %c", &resposta);
	if (resposta == 's') {
		if (num > 15) {
			num= num - (num * 2);
			printf("A subtração do dobro do número digitado é %.1f\n", num);
		} else if (num > 7 && num <= 15) {
			num= num * 2;
			printf("O dobro do número digitado é %.1f\n", num);
		} else {
			num= num / 2;
			printf("A metade do número digitado é %.1f\n", num);
		}
	} else {
		printf("Até logo!\n");
	}
}
```
Neste caso, se o usuário deseja sair do programa, ele digita qualquer coisa que não seja o `s` e todo o resto do programa deixa de ser executado, com excessão do `printf("Até logo!\n");`.

### *Switch/Case*

O *switch/case* é utilizado para diminuir a complexidade de muitas condicionais. Ele funciona bem como uma estrutura de menu. 

Esta é a sintaxe básica:

	switch (variável) {
   		case constante1:
     		Instruções;
   			break;

   		case constante2:
     		Instruções;
   			break;

   		default
    		Instruções;
	}



A figura abaixo exemplifica como o *switch/case* funciona:


![switch/case](https://www.programtopia.net/sites/default/files/switch.png)

Ou seja, a partir do valor de uma variável, o programa irá executar uma de cada possibilidade (case). Vamos montar esta estrutura dentro da calculadora. Assim, o usuário pode definir qual o tipo de cálculo ele quer realizar.

```c
#include <stdio.h>

void main(void) {
	float n1, n2, res;
	char op;

	printf("Digite o primeiro número: \n");
	scanf("%f", &n1);
	printf("Digite o segundo número: \n");
	scanf("%f", &n2);

	printf("Digite a operação desejada (+, -, *, /): \n");
	scanf(" %c", &op);

	switch (op) {
		case '+':
			res = n1 + n2;
			printf("O resultado da soma é %.2f\n", res);
			break;
		case '-':
			res = n1 - n2;
			printf("O resultado da subtração é %.2f\n", res);
			break;
		case '*':
			res = n1 * n2;
			printf("O resultado da multiplicação é %.2f\n", res);
			break;
		case '/':
			res = n1 / n2;
			printf("O resultado da divisão é %.2f\n", res);
			break;
		default:
			printf("Opção inválida!\n"); 
	}	
}
```
Veja que para cada `op` temos um `case`. Se a opção de um `case` for verdadeira, o bloco de código é executado e temos um `break`. O `break` faz com que a execução da estrutura termine. No caso aqui, o *switch/case*, e desta forma, as outras opções não são executadas. Caso não haja nenhuma opção válida, o bloco de código padrão `default` é executado.

Vamos melhorar nossa calculadora. Sabemos que no caso da divisão, o divisor não pode ser igual a 0. Desta forma, vamos colocar uma condicional dentro do `case` da divisão.

```c
#include <stdio.h>

void main(void) {
	float n1, n2, res;
	char op;

	printf("Digite o primeiro número: \n");
	scanf("%f", &n1);
	printf("Digite o segundo número: \n");
	scanf("%f", &n2);

	printf("Digite a operação desejada (+, -, *, /): \n");
	scanf(" %c", &op);

	switch (op) {
		case '+':
			res = n1 + n2;
			printf("O resultado da soma é %.2f\n", res);
			break;
		case '-':
			res = n1 - n2;
			printf("O resultado da subtração é %.2f\n", res);
			break;
		case '*':
			res = n1 * n2;
			printf("O resultado da multiplicação é %.2f\n", res);
			break;
		case '/':
			if (n2 == 0) {
				printf("O divisor não pode ser 0!\n");
				break;
			} else {
				res = n1 / n2;
				printf("O resultado da divisão é %.2f\n", res);
				break;
			}	
		default:
			printf("Opção inválida!\n"); 
	}	
}
```

Veja que agora temos uma condicional dentro do `case` da divisão e o bloco só irá ser executado ser o divisor for diferente de 0. Note que usei um `break` dentro da condicional também.

Na próxima aula entraremos em um novo assunto que são as estruturas de repetição. Em programação, essas estruturas são formas eficientes de executar tarefas repetidas vezes com algumas linhas de código.
