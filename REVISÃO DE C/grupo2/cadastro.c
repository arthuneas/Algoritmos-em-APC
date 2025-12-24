#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int idade;
    char endereco[30];
} Cadastro;


struct Cadastro* criarvetor (int n){



}


int main(){

    int n;
    printf("qual o numero de cadastramentos: ");
    scanf("%d", &n);

     Cadastro* vetor = criarvetor(n);    

    printf("%d", criarvetor(n));
    
    free(vetor);

    return 0;
}