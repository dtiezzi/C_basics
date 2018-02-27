# Curso Básico de Programação - Aula 2
## Daniel Tiezzi

### Variáveis

Nesta aula iremos falar sobre as variáveis em C e operadores básicos. Nós vimos na aula anterior dois tipos de variáveis distintos, número inteiro (*int*) e caractere (*char*). Eles são chamados de **Tipos Primitivos** da linguagem. Em C temos os seguintes **Tipos primitivos**:

* *char*: permite guardar informações de caracteres alfanuméricos;
* *int*: de número inteiro (pertencentes aos números inteiros). Ele utiliza 2 bytes de memória, ou seja, o número inteiro pode variar de -32768 até +3276;
* *float*: de números com pontos flutuantes, ou pertencentes ao números Reais. Um número do tipo *float* ocupa 4 bytes da memória;
* *double*: uma extensão do *float*. Ele aceita números flutuantes, porém com uma precisão maior que o *float* pois ele ocupa 8 bytes de memória;
* *void*: ele representa o vazio, e é utilizado, como dissemos na alula anterior, em situações onde uma função não retorna qualquer valor.

Com excessão do *void*, os outros tipos primitivos podem ter modificadores que alteram o tamanho do tipo de dado. A tabela abaixo mostra todos os tipos e seus modificadores em C bem como o número de bytes de memória utilizado por cada um deles.

![Tipos primitivos e Modificadores](http://4.bp.blogspot.com/-MQeLEbM2JGc/Vg4sKlwvDrI/AAAAAAAAAHc/QTCmJq_kec8/s1600/5.jpg)

Você pode estar perguntando: "O que tem é essa história de bytes?". Vou fazer um parêntese aqui para explicar. A unidade de informação do computador é o bit. Como o computador trabalha com um sistema binário, a sua unidade, o bit, pode armazenar o valor 0 ou o valor 1. Um byte corresponde a 8 bits. Desta forma, podemos armazenar oito valores 0 ou 1 em um byte. Não sei se você é familiarizado com o sistema binário. Mas todos números decimais podem ser convertidos em binário. Como existe duas possibilidades para cada bit, sendo n= número de bits, a quantidade de valores em decimais que pode ser armazenados pelo computador é igual a 2^n. Em uma sequência de 3 bits temos 2^3 = 8. Vejamos abaixo a representação em binário de cada um dos 8 primeiros números naturais:

Binário  | Decimal
:------: | :-----:
000| 0
001 | 1
010 | 2
011 | 3
100 | 4
101 | 5
110 | 6
111 | 7

Ou seja, se um *int* utiliza dois bytes, serão 16 bits que é 2^16 = 65536 valores diferentes (de 0 a 65535).

Mais para a  frente você poderá criar um programa que converte números decimais em binários e vice-versa. Ainda faltam alguns conceitos de programação, em especial as estruturas de repetição, para que você consiga criar este programa.

E o *char*? Como é a alocação de memória? Se o computador só entende 0s e 1s, como ele compreende uma letra digitada no teclado? Como vimos na tabela anterior, cada caractere utiliza 1 byte (8 bits). Cada uma das 256 combinações possíveis de 0s e 1s determinam 256 caracteres distintos. A relação entre os valores binários e os respectivos caracteres é definida por uma padronização conhecida com código ASCII de *American Standard Code for Information Interchange*. Veja a tabela abaixo que mostra a relação entre os valores decimais de 0 a 255 com cada um dos 256 possíveis caracteres:

![Table ASCII](http://www.theasciicode.com.ar/american-standard-code-information-interchange/ascii-codes-table.png)

Desta forma, quando digitamos a letra `A`, o computador lê `01000001`, que é o `65` em decimal. Você não precisa decorar esta tabela, logicamente. No entanto, você verá mais para a frente que ela pode ser utilizada para checar se uma letra digitada no teclado é maiúscula ou minúscula, ou pode ser utilizada para converter as letras em maiúsculas (*all caps*) por exemplo. Note que se você somar `65` + `32` = `97`. Veja na tabela que o `97` decimal e `01100001` em binário é o `a`. Desta forma, para o C, `A` + 32 = `a`.

Agora vamos falar sobre as operações básicas em C. 

**Operadores em C:**

Aqui iremos ver os operadores básicos da linguagem em C. A tabela abaixo discrimina cada um deles:

Operadores | Descrição
:---------: | :--------:
`+` e `-` | `soma` e `adição`
`\` e `*` | `divisão` e `multiplicação`
`%` | `módulo`
`=` | `atribuição`
`==` e `!=` | `igual a` e `diferente de`
`>` e `>=` | `maior` e `maior ou igual`
`<` e `<=` | `menor` e `menor ou igual`
`&&` | `E lógico`
`||` | `Ou lógico`
`!` | `Não lógico`

Algumas coisas são importantes aqui. Não temos o sinal de exponenciação em C. A divisão de números inteiros (*int*) gera a uma divisão inteira e o sinal `=` é um sinal de atribuição. Desta forma o código `int i= 0` não quer dizer que a variável `i` é igual a `0` e sim que o valor `0` foi atribuído para a variável `i`. O sinal que expressa igualdade é `==` em C. Os valores lógicos iremos ver com mais calma na próxima aula quando estudarmos controle de fluxo.

Bem, agora vamos para a prática. Nosso objetivo é criar uma calculadora que faz todas as operações básicas em uma única vez. Vamos construir o algoritmo. Algoritmo, diferentemente do programa de computador, é uma sequência lógica de instruções escrita em linguagem natural. Então vamos lá:

```
Início:
	Escreva: Digite um número;
	Leia: número_1;
	Escreva: Digite outro número;
	Leia número_2;
	Some: número_1 e número_2;
	Subtraia: número_1 e número_2;
	Divida: número_1 e número_2;
	Multiplique: número_1 e número_2;
	Imprima:
		A soma do número_1 e número_2 é:
		A subtração do número_1 e número_2 é:
		A divisão do número_1 e número_2 é:
		A multiplicação do número_1 e número_2 é:
Fim
```

Veja que escrevemos o nosso programa em uma sequência lógica utilizando nossa linguagem natural, o Português. Agora, vamos escrever em linguagem de programação C. Crie um novo artigo com o comando `nano calculadora.c`

Escreva o código abaixo:

```c
#include <stdio.h>

void main(void) {
	float x, y, soma, sub, div, mult;
	printf("Digite um número: \n");
	scanf("%f", &x);
	printf("Digite outro número: \n");
	scanf("%f", &y);
	soma= x + y;
	sub= x - y;
	div= x / y;
	mult= x * y;
	
	printf("A soma de %f + %f eh: %f\n", x, y, soma);	printf("A subtração de %f - %f eh: %f\n", x, y, sub);
	printf("A divisão de %f / %f eh: %f\n", x, y, div);
	printf("A soma de %f + %f eh: %f\n", x, y, mult);

}
```

Agora ele está pronto para rodar. Use o comando `gcc -o calculadora.out calculadora.c` para montar o executável e depois rode o programa com `./calculadora.out`. Você terá algo como:

	Digite um número: 
	3
	Digite outro número: 
	4
	A soma de 3.00 + 4.00 eh: 7.00
	A subtração de 3.00 - 4.00 eh: -1.00
	A divisão de 3.00 / 4.00 eh: 0.75
	A soma de 3.00 + 4.00 eh: 12.00
 
Aqui temos uma coisa nova. Veja o `.2` entre o `%` e o `f` para a formatação do *float*. Este `.2` quer dizer ao computador para mostrar até duas casas decimais. Experimente aumentar ou mesmo omitir este valor. Você verá que o número de casas decimais irão aumentar no ser resultado. A outra questão aqui é, por que não usar o *int*? Lembre-se que se usarmos uma variável inteira, a divisão também será um número inteiro. Tente experimentar.

Bem, chegamos ao fim desta aula. **PARABÉNS!** Na próxima aula iremos aprender sobre controle de fluxo.
