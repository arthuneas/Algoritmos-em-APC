#include <stdio.h>

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    if (b > a){
        printf("%d\n", b);
        printf("%d\n", a);
    } else {
        printf("%d\n", a);
        printf("%d\n", b);
    }

    if (a == b){
        printf("iguais\n");
    } else {
        printf("diferentes\n");
    }
    
    return 0;
}