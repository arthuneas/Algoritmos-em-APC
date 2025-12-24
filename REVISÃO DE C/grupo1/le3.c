#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    printf("digite um numero: ");
    scanf("%d", &n);

    printf("octal: %o\n", n);
    printf("hexa: %X\n", n);

    return 0;
}