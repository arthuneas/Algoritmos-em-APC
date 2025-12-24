#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float n1, n2;
    float a, b, c, d, e, f;

    printf("digite o n1 e n2: ");
    scanf("%f %f", &n1, &n2);

    a = n1 + n2;
    b = n1 * pow(n2, 2);
    c = pow(n1, 2);
    d = sqrt(pow(n1, 2) + pow(n2, 2));
    e = sin(n1 - n2);
    f = fabsf(n1);

    printf(" %.2f\n %.2f\n %.2f\n %.2f\n %.2f\n %.2f\n", a, b, c, d, e, f);


    return 0;
}