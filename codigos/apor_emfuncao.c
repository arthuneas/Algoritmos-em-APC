#include <stdio.h>
#include <stdlib.h>

int contar_frutas(int iniciocasa, int fimcasa, int qtd, int posarvore, int frutas[]){
    int contador = 0;
    int queda;
    
    for (int i = 0; i < qtd; i++){
        queda = posarvore + frutas[i];

        if(queda >= iniciocasa && queda <= fimcasa){
            contador++; 
        }
    }

    return contador;
}

int main(){

    int a, b, s, t, m, n;
    int qtdlaranja, qtdmaca;
    qtdlaranja = 0;
    qtdmaca = 0;

    printf("digite a distancia inicial (s) da casa: ");
    scanf("%d %d", &s, &t);
 
    printf("digite a distancia inicial (t) da casa: ");
    scanf("%d %d", &a, &b);

    //quantidade de maca e armazenar as posicoes de queda
    printf("qual a quantidade de macas: ");
    scanf("%d", &m);
    int vetormaca[m];
    for(int i = 0; i < m; i++){
        scanf("%d", &vetormaca[i]);
    }

   qtdmaca = contar_frutas(s, t, a, m, vetormaca);

    //quantidade de laranjas e armazenar as posicoes de queda
    printf("qual a quantidade de laranjas: ");
    scanf("%d", &n);
    int vetorlaranja[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetorlaranja[i]);
    }

    qtdlaranja = contar_frutas(s, t, b, n, vetorlaranja);
   

    printf("%d\n", qtdmaca);
    printf("%d\n", qtdlaranja);
    

    return 0;
}