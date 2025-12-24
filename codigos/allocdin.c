#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 10090

int main(){

char* profissao = malloc(TAM * sizeof(char));
fgets(profissao, TAM, stdin);
profissao[strcspn(profissao, "\n")] = '\0';

//se eu quiser ver o endereco de memoria
void* ponteiro = malloc(TAM * sizeof(char));

int bites = sizeof(char);

printf("%s\n", profissao);
printf("%p\n", ponteiro);
printf("%d\n", bites);

free(profissao);

return 0;
}
