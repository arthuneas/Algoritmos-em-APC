#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nome[100];
    int ano, mes, dia;

    scanf("%d %d %d", &dia, &mes, &ano);
    getchar();

    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    printf("%s nasceu no dia %d/%d/%d\n", nome, dia, mes, ano);

}