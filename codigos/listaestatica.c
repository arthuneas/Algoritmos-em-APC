#include <stdio.h>

#define TAM 100

typedef struct {
    int dados[TAM];
    int tamanho;
} Lista;

void inicializa(Lista *l) {
    l->tamanho = 0;
}

void insere(Lista *l, int valor) {
    if (l->tamanho < TAM) {
        l->dados[l->tamanho] = valor;
        l->tamanho++;
    } else {
        printf("Lista cheia!\n");
    }
}

void imprime(Lista *l) {
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

int main() {
    Lista l;
    inicializa(&l);

    insere(&l, 10);
    insere(&l, 20);
    insere(&l, 30);

    imprime(&l);

    return 0;
}
