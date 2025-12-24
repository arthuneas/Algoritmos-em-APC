#include <stdio.h>
#include <stdlib.h>

int main(){

    int play;
    
    printf("quantos loops voc6e quer fazer: ");
    scanf("%d", &play);

    for (int i = 0; i < play + 1; i++){

        printf("%d\n", i);
        
    }

    return 0;
}