#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    system("clear");
    int a, b, c;
    char nome[500];

    printf("digite a data: ");
    scanf("%d:%d:%d", &a, &b, &c);
    getchar();

    printf("digite o seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("%s nasceu no dia %d/%d/%d\n", nome, a, b, c);
    
    return 0;
}