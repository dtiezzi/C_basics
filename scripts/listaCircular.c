#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int RA;
    char nome[20];
    struct Lista *prox;
} Lista;


void menu();
void inserir(Lista **ini);
void listar(Lista *ini);
Lista* localizar(Lista *ini);
//Lista* remover(Lista **ini, int *v);

void main(void) {

    Lista *inicio = NULL;
    char op;
    do {
        menu();
        scanf(" %c", &op);
        switch (op) {
            case '1':
                inserir(&inicio);
                break;
            case '2': 
                listar(inicio);
                break;
            case '3':
                localizar(inicio);
                break;
            case '4':
                exit(0);
                break;
        }

    } while (op != '4');
}


void menu() {

    printf("\n1 - Inserir novo registro.");
    printf("\n2 - Listar registros existentes.");
    printf("\n3 - Localiza registro.");
    printf("\n4 - Sair.");
    printf("\nDigite a opção desejada:");
    printf("\n");
    
}

void inserir(Lista **ini) {

    Lista *novo = (Lista*)malloc(sizeof(Lista));

    if (*ini == NULL) {
        printf("\nRA: ");
        scanf("%d" , &novo->RA);
        printf("\nNome: ");
        scanf(" %[^\n]s", &novo->nome);
        novo->prox = novo;
        
    } else {
        printf("\nRA: ");
        scanf("%d" , &novo->RA);
        printf("\nNome: ");
        scanf(" %[^\n]s", &novo->nome);   
        novo->prox = (*ini)->prox;
        (*ini)->prox = novo;
    }
    *ini = novo;
}

void listar(Lista *ini) {

    Lista *aux = ini;
    do {
        printf("\nRA: %d", aux->RA);
        printf("\nNome: %s\n", aux->nome);
        aux = aux->prox;
    } while(aux != ini);
}

Lista* localizar(Lista *ini) {

    int v;
    printf("\nDigite o registro que deseja localizar: ");
    scanf("%d", &v);
    if (ini->RA == v) {
        printf("\nRA: %d localizado!\n", v);
        return ini;
    } else {
        Lista *aux = ini;
        int n;
        while (aux->prox->RA != v) {
            aux = aux->prox;
            if (aux->prox == ini) {
                printf("\nRegistro não encontrado!\n");
                return NULL;
            } 
        }
        printf("\nRA: %d localizado!\n", v);
        return aux->prox;
    }
}

/*
Lista* remover(Lista *ini, int *v) {

    printf("\nDigite o registro que deseja remover: ");
    scanf("%d", v);
    localiza(ini, *v);

}*/