#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <tkMacOSX.h> 

typedef struct{
    int codigo;
    char *nome;
} Profissao;



Profissao* aloca_profissao(unsigned int tamanho_nome){
    Profissao *p = (Profissao*) malloc(sizeof(Profissao));
    p -> nome = (char*) malloc(tamanho_nome * sizeof(char));
    if (p -> nome == NULL){
        free(p);
        exit(1);
    }
    return p;
}

int main(){

    printf("");

    return 0;
}