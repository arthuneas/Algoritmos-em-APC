#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;


int remover(No **inicio, int valor) {
    No *atual = *inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return 0; // Não encontrado

    if (anterior == NULL) {
        *inicio = atual->prox;  // Remover primeiro
    } else {
        anterior->prox = atual->prox;  // Remover do meio/fim
    }

    free(atual);  // Libera o nó removido
    return 1;
}


void insere(No **inicio, int valor) {
    No *novo = malloc(sizeof(No));
    novo -> valor = valor;
    novo -> prox = *inicio;
    *inicio = novo;
}


void imprime(No *inicio){
    No *atual = inicio;
    while (atual != NULL){
        printf("%d -> ", atual -> valor);
        atual = atual -> prox;
    }
    printf("NULL\n");
}


void insertinicio(No **inicio, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *inicio;
    *inicio = novo;
}


void insertfim(No **inicio, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No *atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}


No* buscar(No *inicio, int valor) {
    while (inicio != NULL) {
        if (inicio->valor == valor)
            return inicio;
        inicio = inicio->prox;
    }
    return NULL; // Não encontrado
}


void liberarlista(No **inicio) {
    No *atual = *inicio;
    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}


int main(){

    No *lista = NULL;

    int entrada;
    int posicaorem;
    int posicaobusca;

    printf("digite a quantidade de dados para inserir: ");
    scanf("%d", &entrada);

    int *listagem = malloc(entrada * sizeof(int));

    for (int i = 0; i < entrada; i++){
        scanf("%d", &listagem[i]);
        insere(&lista, listagem[i]);
    }

    printf("lista atual: ");
    imprime(lista);

    printf("digite qual elemento voce quer remover: ");
    scanf("%d", &posicaorem);
    remover(&lista, listagem[posicaorem]);
    printf("lista após remover elemento %d: ", posicaorem);
    imprime(lista);

    printf("digite qual elemento voce quer buscar: ");
    scanf("%d", &posicaobusca);
    No *achado = buscar(lista, listagem[posicaobusca]);
    if (achado != NULL){
        printf("Valor %d encontrado na lista.\n", achado -> valor);
    } else {
        printf("Valor nao encontrado.\n");
    }

    insertinicio(&lista, 789);
    insertfim(&lista, 90);
    imprime(lista);

    liberarlista(&lista);

    return 0;
}