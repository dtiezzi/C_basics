# Curso Básico de Programação - Aula 6

## Daniel Tiezzi

### Funções e procedimentos

Nós vimos anteriormente que o programa é executado dentro de uma função principal chamada de _**main**_. No entanto, é possível que o usuário crie funções. Em programas muito extensos, criar funções e procedimentos fazem parte da boa prática. Essa técnica, que pode ser denominada de modularização (divisão em partes) diminui repetições de código facilitando sua leitura e manutenção.

A diferença de uma função e um procedimento é que os procedimentos não retornam valores. A declaração de uma função ou de um procedimento é semelhante e consiste de um cabeçalho e um corpo. A estrutura básica é:

```
tipo_de_retorno nome_função (parâmetros) {

	instruções;

}
```

As funções são executadas dentro do programa principal (_**main**_).Por exemplo, vamos criar uma função que soma e uma que multiplica dois números.

```c
#include <stdio.h>

int soma(int x, int y) {
	return x + y;
}

int mult(int x, int y) {
	return x * y;
}

void main() {
	int n1, n2;
	printf("Digite o primeiro número: \n");
	scanf("%d", &n1);
	printf("Digite o segundo número: \n");
	scanf("%d", &n2);
	printf("O resultado de %d + %d = %d\n", n1, n2, soma(n1, n2));
	printf("O resultado de %d x %d = %d\n", n1, n2, mult(n1, n2));
}
```

Então, veja que eu criei duas funções que recebem dois parâmetros do tipo `int`. A função `soma()` retorna a soma dos valores e a função `mult()` retorna o produto. Depois eu criei a função `main()` que recebe dois valores inteiros e imprime na tela a saída de cada uma das funções em meio a um texto. Ou seja, imagine um programa que irá utilizar várias vezes a soma e a multiplicação de números inteiros. Eu posso passar os parâmetros para essas funções repetidas vezes ao longo do programa sem ter que escrever o código novamente. O outro benefício é que, se eu estiver tendo um erro decorrente de uma função, eu já sei onde preciso corrigir. Desta forma, a estrutura modular facilita a manutenção do programa.

Como nós já criamos um programa para transformar números decimais em binários, o desafio agora é criar duas funções, uma que transforma de decimal para binário e outra que faz o oposto.
Uma solução estará no código em anexo.

Nossa próxima aula irá focar no conceito e uso de ponteiros em C.
