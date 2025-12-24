#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b;

    scanf("%d %d", &a, &b);

    system("clear");

    if (a < b) {
        printf("%d > %d\n", b, a);
    } else {
        printf("%d < %d\n", b, a);
    }
    
    return 0;
}