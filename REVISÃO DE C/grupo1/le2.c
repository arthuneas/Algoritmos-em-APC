#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){

    int mult;

    for (int i = 1; i <= 10; i++){
        printf(" \n");

        for (int j = 1; j <= 10; j++){
            mult = i * j;
            printf("%d x %d = ", i, j);
            printf("%d  ", mult);
        }
    }

    return 0;
}