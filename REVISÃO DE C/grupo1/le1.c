#include <stdio.h>
#include <stdlib.h>

int main(){

    float metro;
    float deci, cen, mili;

    printf("digite um valor em metros: ");
    scanf("%f", &metro);

    deci = metro * 10;
    cen = metro * 100;
    mili = metro * 1000;

    printf("OS VALORES EM: \n");
    printf("DECIMETROS: %.2f\n", deci);
    printf("CENTIMENTROS: %.2f\n", cen);
    printf("MILIMETROS: %.2f\n", mili);

    return 0;
}