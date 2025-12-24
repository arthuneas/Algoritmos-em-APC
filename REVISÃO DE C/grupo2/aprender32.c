#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long int calc(char* tipo, long long int n1, long long int n2){
    if(strcmp(tipo, "SOMA") == 0){
        return n1 + n2;

    } else if (strcmp(tipo, "SUBTRACAO") == 0){
        return n1 - n2;

    } else if (strcmp(tipo, "MULTIPLICACAO") == 0){
        return n1 * n2;
    
    } else if (strcmp(tipo, "DIVISAO") == 0){
        return llabs(n1 / n2);
    
    } else {
        return 0;

    }
}


int main(){

    char tipo[20];
    long long int n1, n2;
    
    fgets(tipo, 20, stdin);
    tipo[strcspn(tipo, " \n")] = '\0';

    
    scanf("%lld", &n1);
    scanf("%lld", &n2);

    printf("%lld\n", calc(tipo, n1, n2));
    
    return 0;
}