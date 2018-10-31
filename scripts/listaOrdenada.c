#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int RA;
    char nome[20];
    struct Lista *prox;
} Lista;

void menu();
void insere(Lista **ini, Lista **f);


void main(void) {

    Lista *inicio = NULL, *fim;

    char op;
    do {
        menu();
        scanf("%c", &op);
        switch(op) {
            case '1':
                insere(&inicio, &fim);
                break;
            case '5':
                exit(0);
        }
    } while(op != '5');
}

void menu() {

    printf("\n1 - Insere registro.");
    printf("\n5 - Sair.\n");
    printf("\nDigite a opcao desejada: ");

}

void insere(Lista **ini, Lista **f) {

    Lista *novo = (Lista*)malloc(sizeof(Lista));

    if (*ini == NULL) {
        *ini = *f = novo;
        novo->prox = NULL;
    } else {
        printf("teste");
    }
}
