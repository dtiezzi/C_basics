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
void consultar(Lista *ini);
Lista* localizar(Lista *ini, int v);
Lista* remover(Lista **ini);

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
                consultar(inicio);
                break;
            case '4':
                remover(&inicio);
                break;
            case '5':
                exit(0);
                break;
        }

    } while (op != '5');
}


void menu() {

    printf("\n1 - Inserir novo registro.");
    printf("\n2 - Listar registros existentes.");
    printf("\n3 - Localiza registro.");
    printf("\n4 - Remove registro.");
    printf("\n5 - Sair.");
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

    if (ini == NULL)
        printf("\nNao há registros no arquivo!\n");
    else {
        Lista *aux = ini;
        do {
            printf("\nRA: %d", aux->RA);
            printf("\nNome: %s\n", aux->nome);
            aux = aux->prox;
        } while(aux != ini);
    }
}

void consultar(Lista *ini) {

    if (ini == NULL)
        printf("\nNao há registros no arquivo!\n");
    else {
        int v;
        printf("\nDigite o registro que deseja localizar: ");
        scanf("%d", &v);
        if (ini->RA == v) {
            printf("\nRA: %d localizado!\n", v);
        } else {
            Lista *aux = ini;
            int n;
            while (aux->prox->RA != v) {
                aux = aux->prox;
                if (aux->prox == ini) {
                    printf("\nRegistro %d não encontrado!\n", v);
                } 
            }
            printf("\nRA: %d localizado!\n", v);
        }
    }
}

Lista* localizar(Lista *ini, int v) {

        Lista *aux = ini;
        int n;
        do {
            aux = aux->prox; 
            if (aux->prox->RA == v)
                return aux;
        } while (aux != ini);
        return NULL;
}

Lista* remover(Lista **ini) {

    if (*ini == NULL)
        printf("\nNao há registros no arquivo!\n");
    else {
        if ((*ini)->prox == *ini) {
            char op;
            printf("\nO único registro no banco é o RA: %d.\n", (*ini)->RA);
            printf("Tem ceteza que deseja remove-lo?\nDigite 1 para SIM ou 0 para nao.");
            scanf(" %c", &op);
            if (op == '1') {
                Lista *aux = *ini;
                free(aux);
                *ini = NULL;
            }
        } else {
            int rg;
            printf("\nDigite o registro que deseja remover: ");
            scanf("%d", &rg);
            Lista *pre = localizar(*ini, rg);
            Lista *aux = pre->prox;
            if (aux == NULL)
                printf("\nRegistro nao encontrado no banco de dados!\n");
            else {
                if (aux == *ini) {
                    pre->prox = aux->prox;
                    *ini = pre;
                    free(aux);
                } else {
                    pre->prox = aux->prox;
                    free(aux);
                }
            }
        }
    }
}
