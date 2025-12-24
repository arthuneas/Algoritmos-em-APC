#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
    if (n == 0) {
        return n;
    }
    if (n == 1) {
        return n;
    }
    return n * fatorial(n - 1);
} 

int main(){
    
    int n, x;
    printf("digite o numero: ");
    scanf("%d", &n);

    x = fatorial(n);
    printf("%d\n", x);

}