#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void divisores(int n){

    for (int i = n; i >= 1; i--){
        if(n % i == 0) {
            printf("%d ", i);
        }
    }
}

int main(){

    int n;
    scanf("%d", &n);

    divisores(n);

    return 0;
}