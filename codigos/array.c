#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanho, soma;
    soma = 0;

    printf("digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    int vetor[tamanho]; 

    for (int i = 0; i < tamanho; i++){
        printf("qual o valor do vetor [%d]: ", i);
        scanf("%d", &vetor[i]);
        
        soma += vetor[i];

    }

    printf("%d\n", soma);

    return 0;
}