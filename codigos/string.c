#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char dna[1000000];
    int qtd_iguais, tamanho_dna, recorrente;

    recorrente = 0;
    qtd_iguais = 0;

    scanf("%[^\n]", dna); 

    tamanho_dna = strlen(dna);

    for (int i = 0; i < tamanho_dna - 1; i++){
       
        if (dna[i] == dna[i+1]){
            qtd_iguais++;
        }
        if (qtd_iguais > recorrente){
            recorrente = qtd_iguais;
        
        }
        if (dna[i] != dna[i + 1]){
            qtd_iguais = 0;

        } 

    }
    
    printf("%d\n", recorrente + 1);

    return 0;

}