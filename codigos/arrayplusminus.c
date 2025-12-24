#include <stdio.h>
#include <stdlib.h>

int main(){

    float minus, plus, zeros;
    float nminus, nplus, nzeros;

    minus = 0;
    plus = 0;
    zeros = 0;

    int n;
    scanf("%d", &n);
    
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        
        scanf("%d", &arr[i]);

        if(arr[i] < 0){
            minus++;
        } else if (arr[i] == 0){
            zeros++;
        } else {
            plus++;
        }

    }

    nplus = plus / n;
    nminus  = minus / n;
    nzeros = zeros / n;

    printf("%.6f\n", nplus);
    printf("%.6f\n", nminus);
    printf("%.6f\n", nzeros);

    return 0;
}

/* 
int *arr = malloc(n * sizeof(int));
como alocar tamanho de memoria com seguranca
*/