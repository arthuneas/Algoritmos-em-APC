#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inttochar(char valor_em_string[], int valor_inteiro){

    sprintf(valor_em_string, "%d", valor_inteiro);

}


int sum_plus_chartoint(int valor_transformado, char valor_em_string[], int size_new_string){

        int valor; 
    for (int i = 0; i < size_new_string; i++) {
        valor = valor_em_string[i] - '0';
        valor_transformado += valor;
    }

    return valor_transformado;
}


void concat(char string_concatenada[], char parte_string[], int quantidade_concatencao){

    for (int i = 0; i < quantidade_concatencao; i++) {

        strcat(string_concatenada, parte_string);

    }

}

int super_digit(char p[], int k){

    int size, valor, soma;
    char buffer[20];
    char new_string[1000000];
    new_string[0] = '\0';

    concat(new_string, p, k);

    size = strlen(new_string);
    soma = sum_plus_chartoint(0, new_string, size);
    
    if (soma > 9) {
        inttochar(buffer, soma);
        return super_digit(buffer, 1);
    } else {
        return soma;
    }
}


int main(){
    char p[10000];
    int k;
    int resultado;

    fgets(p, 10000, stdin);
    p[strcspn(p, "\n")] = '\0';

    scanf("%d", &k);

    resultado = super_digit(p, k);
    printf("%d", resultado);

    return 0;
}