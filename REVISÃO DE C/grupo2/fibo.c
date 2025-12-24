#include <stdio.h>
#include <stdlib.h>

#define NUM 500

void fibo(int n){
    if (n < 0) {
        printf("0\n");
        return;
    }
    if (n <= 2){
        printf("1\n");
        return;
    } 

    int soma_coluna = 0, digito = 0;

    int anterior[NUM] = {1};
    int antes_anterior[NUM] = {1};
    int atual[NUM] = {0};
    int resto = 0;

    for (int i = 1; i < NUM; i++){
        anterior[i] = 0;
        antes_anterior[i] = 0;
    }

    for (int i = 3; i <= n; i++){
        resto = 0;

        for (int j = 0; j < NUM; j++){
            soma_coluna = anterior[j] + antes_anterior[j] + resto;
            digito = soma_coluna % 10;
            resto = soma_coluna / 10;
            atual[j] = digito;
        }

        for (int k = 0; k < NUM; k++){
            antes_anterior[k] = anterior[k];
        }

        for (int k = 0; k < NUM; k++){
            anterior[k] = atual[k];
        }
    }

    int digito_encontrado = 0;

    for (int i = NUM - 1; i >= 0; i--){
        if (atual[i] != 0){
            digito_encontrado = 1;
        }
        if (digito_encontrado){
             printf("%d", atual[i]);
        }
    }
    printf("\n");
}

int main (){
    int n;
    
    printf("digite um número: ");
    scanf("%d", &n);

    fibo(n);

    return 0;
}