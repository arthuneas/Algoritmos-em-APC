#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* retorna (char *palavra, int tamanho){

    fgets(palavra, tamanho, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    return palavra;
}


int main(){

    int tamanho = 1000;

    char (*palavra) = malloc (tamanho * sizeof(palavra));

    printf("%s\n", retorna(palavra, tamanho));

    free(palavra);

    return 0;
}