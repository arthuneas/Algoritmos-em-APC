#include <stdlib.h>
#include <stdio.h>

int main(){

    double f, c;

    printf("DIGITE UM VALOR EM FAHRENHEIT: ");
    scanf("%lf", &f);

    c = (f - 32) * (5.0/9.0);

    printf("o valor convertido para celsius é: %.2lf", c);

    return 0;
}