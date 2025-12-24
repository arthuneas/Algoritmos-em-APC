#include <stdio.h>
#include <stdlib.h>

void semana(int n){

    switch(n){

        case 1:
            printf("segunda-feira\n");
            break;
        
        case 2:
            printf("terca-feira\n");
            break;

        case 3:
            printf("quarta-feira\n");
            break;

        case 4:
            printf("quinta-feira\n");
            break;

        case 5:
            printf("sexta-feira\n");
            break;

        case 6:
            printf("sabado\n");
            break;

        case 7:
            printf("domingo\n");
            break;

    }

}

int main (){

    int n;

    scanf("%d", &n);

    semana(n);

    return 0;
}