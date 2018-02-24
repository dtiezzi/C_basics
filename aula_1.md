# Curso Básico de Programação - Aula 1
## Daniel Tiezzi


A proposta deste curso é fornecer noções básicas de programação para pessoas com mínimo ou nenhum conhecimento de programação. Como a idéia é de fornecer um curso completamente gratuito, minha proposta é utilizar somente ferramente de código aberto, também denominadas de *open source* em inglês. Desta forma, o sistema operacional que irei me basear é o linux e a linguagem de programaçao será o C. Programas em C podem ser interpretados em qualquer sistema operacional. A maioria das versões lives do linux já vem com o interpretador / compilador do C instalados. No sistema operacional da Apple também. Caso você esteja utilizando o Windows, é necessário instalar um programa que tenha o compilador. Uma opção gratuita é o Code Blocks (<http://www.codeblocks.org>).

O compilador é um *software* que interpreta a linguagem de programação, que nós humanos compreendemos (ou iremos crompreender) e transforma ela em linguagem de computador. Como existem diversas linguagens de programação, é necessário diversos compiladores para compreeder cada uma das linguagens. Em C, iremos utilizar o compilador denominado gcc, que interpreta a linguagem em C.

##O que é um programa de computador ou *software*?

*Software* pode ser definido como uma sequência de instruções escritas em linguagem de programação e que tem o objetivo de executar tarefas específicas.

Desta forma, qualquer pedaço de código que possa ser interpretado por um computador e que execute uma tarefa é por definição um *software*.


###Escrevendo seu primeiro *software*

Para começarmos, você precisa de duas ferramentas em seu computador para escrever o seu *software* em C e executá-lo:

* Um terminal de comando. Abra uma janela do Terminal. O terminal é uma interface de comunicação entre o usuário (você) e seu computador. Nele, você precisa escrever códigos em linguagem de programação para que o computador entenda o seu comando e execute alguma tarefa. No linux vc pode abrir uma janela do terminal precionando as teclas `Ctr` + `Alt` + `T`.
*  Um editor de texto. Pode ser qualquer editor. No entanto, iremos utilizar um editor que será acessado diretamente do Terminal e que é chamado `nano`.

Desta forma, só precisamos de uma janela do Terminal aberta. Nada mais.

Na tela você verá algo similar a isto escrito na tela:

	dtiezzi@kushin:~$

Precisamos saber alguns comandos do *shell*, que é o interpretador de comandos do linux.

Vamos por partes. O que isso significa `dtiezzi@kushin:~$`? `dtiezzi` é o nome do usuário que está utilizando a máquina. No caso, você deve estar vendo algo parecido com o seu nome ou um nome qualquer que você ou alguém estabeleceu quando a conta de usuário foi criada. O `@` significa *at* do inglês e o `kushin` é o nome da máquina que foi definida pela pessoa que instalou o sistema operacional. Ou seja, o '`dtiezzi@kushin` quer dizer que o usuário dtiezzi está utizando a máquina kushin. Já o `:~` mostra o diretório que o usuário está trabalhando. No linux, o diretário `~` representa o diretório do usuário. No linux existe um diretório denominado *root* (raíz) que é representdo por `/`. Existem vários diretórios do sistema no `/`, dentre eles o `/home`. No diretório `home` encontra-se todos os diretórios de cada usuário, que é o `~`. O comando `pwd`, de *print work directory* mostra o diretório que você está. Então, vamos tentar. Digite `pwd` e tecle `enter` (sempre um comando e `enter` para executá-lo) e verá algo assim:

	dtiezzi@kushin:~$pwd
	/home/dtiezzi
	
O `$` é chamado de *prompt* de comando. Ele mostra que o computador está pronto para receber um comando. Ou seja, se você está vendo o cursor piscar na tela e não tem o *prompt* `$` antes dele, não adianta digitar um comando e teclar o `enter` que o computador não está pronto para executar, CERTO?

Outro comando importante é o `ls`. O `ls` lista os componentes do diretório. Então digite `ls` e verá algo assim:

	dtiezzi@kushin:~$ls
	Desktop    Downloads  Pictures  R         Templates
	Documents  Music      Public    Software  Videos

Cada um dos nomes que apareceram é um diretório.

Outro comando é o `cd`, de *change directory*. Com o `cd` você pode navegar pela estrutura de diretórios. Então, vamos mudar para o diretório `Documents`. Então digitamos `cd Documents` e veremos algo como:

		dtiezzi@kushin:~$cd Documents
		dtiezzi@kushin:~/Documents$

Veja que agora estamos no diretório `:~/Documents`, que é o `/home/dtiezzi/Documents` (teste um `pwd` para confirmar).

Agora iremos criar um novo diretório onde iremos trabalhar. O comando para criar o diretório é `mkdir`, de *make directory*. Vamos chamar ele de C_scripts, OK? Então, digite `mkdir C_scripts` e depois ls:

 	dtiezzi@rgo-brca:~/Documents$mkdir C_script
 	dtiezzi@rgo-brca:~/Documents$ls
 	C_script
 
 Então mudaremos para o diretório novo que criamos:
 
 	dtiezzi@rgo-brca:~/Documentscd C_script
 	dtiezzi@rgo-brca:~/Documents/C_script$pwd
 	/home/dtiezzi/Documents/C_script
 	
 Tudo certo até aqui?
 
 E o nosso primeiro *software*? Vamos lá.
 
 Agora tudo que criarmos irá ocorrer ou ser salvo no diretório que estamos trabalhando. Vamos iniciar o editor de texto *nano*. Então, somente escreva o comando `nano primeiro.c` e tecle `enter` (não vou mais escrever o `enter` para dizer que precisa dele para executar o comando que você escreveu, OK?)
 
 Você deverá ver algo assim:
 
 ![nano display](http://www.linuxandubuntu.com/uploads/2/1/1/5/21152474/how-to-launch-nano-in-linux_orig.png)

 
 Caso isso não occorra, é porque você não tem o editor *nano* instalado. Para instalar é muito fácil. Somente escreva o comando `sudo apt-get install nano`
 
 O `sudo` é um comando para que você execute um outro comando como o administrador. O `apt-get install` é o comando para instalr o software *nano* em destribuições do *Debian*. Se você estiver utilizando um sistema linux que não é derivado do *Debian*, o comando para instalação deve ser outro, como o `yum` nas distribuição *Red Hat*. Faça uma pesquisa na internet. Como você digitou o `sudo`, o sistema irá pedir a senha do administrador e você precisa digitar. Lembre-se de que no linux a digitação da senha não é mostrada na tela. Ou seja, você não verá nada que está digitando. Somente digite a senha corretamente e tecle `enter`. O program será instalado. Pode ser que ele perquente se quer continuar `(Y/y)`. Então, tecle `y` e pronto. Assim que o `$` aparecer tecle `nano` e `enter`.
 
 Vamos lá. A tela do *nano* é uma tela para edição de texto. Você pode escrever o texto que quiser aqui. Nós vamos escrever o primeiro programa. 
 
 Nosso *software* irá ser bem simples. Ele vai mostrar uma imagem na tela pedindo que o usuário escreva o seu nome. Em seguida, ele vai pedir que ele digite a sua idade. No final, o nosso *softaware* irá mostrar na tela a sequinte mensagem:
 
 	$Daniel, você nasceu há 45 anos

Este será o código que iremos escrever no *nano*:

```csharp
#include <stdio.h>

void main (void) {

   char nome[100];
   int idade;

   printf("Qual o seu nome?\n");
   scanf("%s", nome); 
   printf("Qual a sua idade?\n");
   scanf("%d", &idade);
   printf("%s, você nasceu há %d anos\n\n", nome, idade);
   
}
```

Escreva da forma que está acima. Lembre-se, **ESCREVA**. Não é para copiar e colar, **CERTO**?

**Vamos entender o código**

`#include <stdio.h>` - o `#include` é utlizado no início de todo *software* em C. Ele executa uma função que é a de importar bibliotecas. O que é isso? As bibliotecas comtém códigos já escritos por outras pessoas. Assim, muitas funções em C podem ser executadas com apenas um comando, sem que você tenha que escrever aquela função (iremos falar como criar funções mais adiante). aqui estamos inportando a biblioteca `stdio.h`, que significa *standard input/output*. É uma biblioteca padrão do C e necessária para receber infromaçõe do teclado (*input*) e mostrar o resultado na tela (*output*). Ou seja, quase todo programa em C irá começar com isso.

`void main { }` - aqui temos um conjunto de palavras que vão sempre estar juntas. O `void`, o `main` e 0 `{ }`. Esta é a estrutura básica da função do nosso programa e ela sempre vai existir em C. O `main` do inglês *principal* é o nome padrão da função principal do programa em C. O `{ }` é o local onde todas as instruções que iremos passar para o computador será escrita. E o `void`? O `void` quer dizer que a sua função principal não irá retornar nada. Se a sua função for retornal algo, você irá utilizar outra palvra que não o `void`. Vou te explicar.

Toda função executa alguma coisa e pode ou não retornar algo. Vamos fazer uma analogia: 

Estamos em um escritório de mineração de ouro e vou escrever duas funções para dois de meus funcionários:

Para o Carlos:

~~~
void main {
	vá até a mina;
	desça até o fundo da mina;
	cave até achar outro;
	volte para o escritório;
}
~~~

Para o Antonio:

~~~
ouro main {
	vá até a mina;
	desça até o fundo da mina;
	cave até achar outro;
	volte para o escritório;
	retorne com o ouro;
}
~~~

Veja que a intrução para o Carlos é somente para achar ouro. Ele não precisa trazer o ouro para mim. Já o Antonio, tem que achar o ouro e retornar com ele para o escritório.

Em C, antes de declarar a função, você deve definir se aquela função irá retornar algo ou não. No nosso caso, a nossa função ela não retorna nenhum objeto. O que ela faz é imprimir uma frase na tela. O conteúdo desta frase não pode ser usado por uma outra função ou outro *software*. Por isso usamos o `void`.

	char nome[100];
	int idade;
	
`nome` e `idade` são as minhas variáveis. Em C, toda variável deve ser declarada antes de que um valor seja atribuído à ela. Existem vários tipos de variáveis em C. Aqui estamos vendo dois. O `nome`, que é uma palavra, uma variável qualitativa, um conjunto de caracteres. A idade é um número inteiro, uma variável qualitativa. Em C, sempre que se declara uma variável, você deve definir que tipo de variável é esta. Por isso usamos `char` de *character* (caractere) e o `int` de *integer* (número inteiro). Então, sempre você ira declarar variáveis desse modo. Primeiro o tipo, depois o nome da variável. E que é o `[100]`? Porque na idade não tem isso?
Em C, quando uma variável é declarada, o que o computador entende é que ele deve reservar em sua memória principal (memória RAM) um espaço para receber os valores referentes à cada variável. Desta forma, ele reserva um local na memória. No caso do `int`, o espaço de memória que ele reserva para alocar o valor daquela variável é fixo. Para caracteres, você precisa definir até quantos caracteres a sua variável pode ter. Aqui colocamos 100, representado pelo `[100]`. Assim, o processador reserva na memória um espaço onde pode ser armazenado até 100 caracteres. Chamos de um conjunto de caracteres de *string*, OK? 

Agora temos isso:

	printf("Qual o seu nome?\n");
   scanf("%s", nome); 
   printf("Qual a sua idade?\n");
   scanf("%d", &idade);
   
 É uma sequência de dois comandos `printf` seguido de `scanf`, certo?
 
 `printf()` imprime ou mostra algo na tela. Algo que esteja entre os parênteses. Um exemplo "Qual o sue nome?\n". Veja que toda palavra ou frase que você quer que seja mostrada pelo `printf` deve estar entre aspas. O que o `\n` significa? Ele é apenas um sinal para que o cursor da tela mude de linha. Ele pode ser omitido, mas esteticamente não fica bom. Depois que rodarmos o programa, você pode tirar os `\n\`s para ver como fica.
 
 O `scanf()` é uma função que pega o que foi digitado no teclado. Então, o `printf` pede que você digite e o `scanf` captura o que foi digitado e armazena os valores no local de memória reservado previamente para uma variável definida. Veja que temos depois do `printf("Qual o seu nome?\n");` o `scanf("%s", nome);`. O `scanf` está pegando a informação que veio do teclado e está armazenando esta infromação no local de memória destinado para a variável `nome`. E o que é este `%s` antes? Este sinal define o tipo de variável. Neste caso `%s`, o s é de *string*. Ou seja, estamos dizendo pro `scanf` que o usuário vai digitar uma sequência de caracteres. No `scanf("%d", &idade);`, o `%d` é utilizado para variáveis numéricas interiras (números naturais). Mas o que é esse `&` antes da idade? 
 
 o `&` conhecido como `e` comercial ele significa **no endereço destinado a**. O que ele faz aqui é dizer para o processador guardar o valor no endereço de memória destinado à variável idade. Mas, por que ele não aparece antes do 'nome' no 'scanf' anterior? Isto é uma questão relacionada ao conceito de **ponteiros** em C. Este conceito será abordado mais para frente. Mas para responcer a pergunta, quando você declarou a variável `char nome[100]`, você criou o que chamos de vetor em C ( denominado *array* em iglês). 
 O vetor é uma estrutura de dados indexados que pode armazenar uma determinada quantidade de valores. No caso aqui, 100. Em C, o vetor funciona como um ponteiro, e o que o computador compreende é que a variável `nome` corresponde ao endereço da memória onde será armazenado o primeiro valor de uma estrutura que suporta até 100 valores. Por isso não é necessário dizer para o processador que o valor digitado será armazenado no endereço `nome` pois o `nome` já é o endereço. No caso do `int idade`, o processador cria uma variável que contem alguma informação lá. No exercícios vamos exemplificar isso. 
 
 Por fim, `printf("%s, você nasceu há %d anos\n\n", nome, idade);`. Estamos imprimindo na tela os valores refentes as variáveis `nome` e `idade`. Veja que `%s` e o `%d` estão colocados na frase no local onde eles irão aparecer e, depois da `,`, vem os nomes das variávies. Note que eles estão na mesma sequência em que aparecem na frase. Você não poderia colocar assi: `printf("%s, você nasceu há %d anos\n\n", idade, nome);` , pois o computador iria entender que você está passando um variável do tipo `int` chamda de `idade` para um local que está esperando uma *string* `%s`.
 
 **IMPORTANTE** E o que são os vários `;`s. Lembrese que em C, cada comando TEM que ser finalizado com o `;`. Se não colocar o `;`, terá um erro, pois cada instrução só termina quando o compilador encontra o `;`.
 
 **Agora vamos salvar o nosso programe e ver se ele vai funcionar!**
 
 Para salvar no `nano`, pressione as teclas `crt` + `x`, depois `y` e tecle `enter`
 
 Digite o comando `ls`. Você deverá ver um arquivo chamado `primeiro.c` no seu diretório de trabalho. Veja que todo programa escrito em C deve ter a extensão `.c`. Desta forma, o compilador gcc entende que o que está escrito lá é uma sequencia de comandos escritos na linguagem C.
 
 Agoras temos que compilar o nosso código. Ou seja, temos que transformar a nossa instrução que está em linguagem de programção para a linguagem de máquina. O gcc irá fazer isso.
 
 Para executar o gcc, basta digitar `gcc`. Mas se digitar só isso, vai encontrar uma mensagem de erro do tipo:
 
 	gcc: fatal error: no input files
	compilation terminated.

A compilação terminou. Houve um erro fatal. Não tem o arquivo de *input*. Ou seja, esquecemos de dizer para o gcc qual é o programa que ele deve compilar, que no caso é o `primeiro.c`, certo?

Então, aúnica coisa que precisamos fazer é digitar:

	$gcc primeiro.c
	
Mas não faça isso ainda. Se fizer isso, o gcc cria um novo arquivo que é o arquivo executável com um nome padrão, que é `a.out`. Teste se quiser ver se é isso mesmo.

O comando gcc recebe alguns argumentos. um deles é o `-o`, que quer dizer *output*, ou seja, o nome do arquivo de saída. Então podemos definir o nome do arquivo executável que ele irá criar:

	$gcc primeiro.c -o primeiro.out

Se digitar o `ls`, tem que ter um arquivo com o nome `primeiro.out`. Se não tiver, ou se apareceram mensagens de erro durante a compilação, volte no editor e reveja se não tem nenhum erro de digitação. As mensagens de erro te dão uma idéia de qual pode ser o problema.

**PRONTO!** Agora temos o nosso program executável em C. Para rodarmos o programa basta digitar:

	$./primeiro.out

Assim deve ser o nosso primeiro programa:

	dtiezzi@kushin:~/Documents/C_script$ ./a.out 
	Qual o seu nome?
	Daniel
	Qual a sua idade?
	45
	Daniel, você nasceu há 45 anos

	dtiezzi@kushin:~/Documents/C_script$
	
Se você chegou até aqui:
	
**PARABENS!** Você acaba de escrever seu primerio *software*
