#include <stdio.h>

int fatorial (int n){
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return (n * fatorial(n - 1));
    }
}

int main(){

    int n;
    

    scanf("%d", &n);

    printf("o fatorial de %d = %d\n", n, fatorial(n));
    
    return 0;
}