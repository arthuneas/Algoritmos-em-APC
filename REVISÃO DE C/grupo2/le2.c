#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loop (int value) {

    for (int i = 0; i <= value; i++){
        printf("%d \n", i);
    }
}

int main(){

    int lim;

    printf("digite um limite: ");
    scanf("%d", &lim);

    loop(lim);

    return 0;
}