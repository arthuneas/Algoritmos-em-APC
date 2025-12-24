/*
------------------STRINGS-------------------------
//biblioteca com funções para manipular strings
#include <string.h> 

//retorna o tamanho da string 
- strlen(char str[]); 

//copia um string para outra
- strcpy (char destino[], char fonte); 

//copia string com quantidade
- strncpy(char destino[], char fonte, int qtdchar); 

//compara strings 
- strcmp (char str1[], char str2[]);
     // Retorna:
        0, quando iguais
        > 0, quando str1 maior
        < 0, quando str1 menor

//compara strings com quantidade
- strncmp (char str1[], char str2[], int qtdChar);

//concatena ("soma") duas strings
- strcat (char destino[], char fonte[]);

//concatena strings com quantidade
strncat(char destino[], char fonte[], int qtdChar);

*/

#include <stdio.h>
#include <string.h>

int main(){

    char nome1[100];
    char nome2[100];
    
    scanf("%s", nome1);
    scanf("%s", nome2);

    printf("string a: %s\n", nome1);
    printf("string b: %s\n", nome2);
    printf("valor da primeira comparação:%d\n\n", strcmp(nome1, nome2));

    
    char nome3[100];
    char nome4[100];
    
    scanf("%s", nome3);
    scanf("%s", nome4);

    printf("string a: %s\n", nome3);
    printf("string b: %s\n", nome4);
    printf("valor da primeira comparação:%d\n\n", strcmp(nome3, nome4));


    if(strcmp(nome1, nome2) == 0){
        printf("as strings 1 e 2 são iguais\n");
    } else {
        printf("as strings 1 e 2 não são iguais\n");
    }

    if(strcmp(nome3, nome4) == 0){
        printf("as strings 3 e 4 são iguais\n");
    } else {
        printf("as string 3 e 4 não são iguais\n");
    }

    return 0;
}