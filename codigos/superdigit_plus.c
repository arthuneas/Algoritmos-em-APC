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


int super_digit(char p[], int k){

    int total, soma;
    char buffer[20];

    soma = sum_plus_chartoint(0, p, strlen(p));
    total = soma * k;
  
    if (total > 9) {
        inttochar(buffer, total);
        return super_digit(buffer, 1);
    } else {
        return total;
    }
}


int main(){
    char p[1000000];
    int k;
    int resultado;

    fgets(p, 1000000, stdin);
    p[strcspn(p, "\n")] = '\0';

    scanf("%d", &k);

    resultado = super_digit(p, k);
    printf("%d", resultado);

    return 0;
}

/*

Método 1: Concatenar
Concatena p 4 vezes: "9875987598759875"
Soma dos dígitos:
9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5
= (9+8+7+5) * 4
= 29 * 4
= 116
Depois calcula o super dígito de "116":
1 + 1 + 6 = 8 (super dígito final)


Método 2: Soma e multiplica
Soma dos dígitos de p:
9 + 8 + 7 + 5 = 29
Multiplica pela quantidade k:
29 * 4 = 116
Calcula o super dígito de 116 (como acima):
1 + 1 + 6 = 8

*/