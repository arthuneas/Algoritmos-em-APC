#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b, s, t, m, n;
    int qtdlaranja, qtdmaca;
    qtdlaranja = 0;
    qtdmaca = 0;

    //distancia da arvore a
    printf("digite a distancia inicial (s) da casa: ");
    scanf("%d", &s);

    //distancia da arvore b
    printf("digite a distancia inicial (t) da casa: ");
    scanf("%d", &t);

    //posicao da arvore a
    printf("digite a posicao da arvore a: ");
    scanf("%d", &a);

    //posicao da arvore b 
    printf("digite a posicao da arvore b: ");
    scanf("%d", &b);

    //quantidade de maca e armazenar as posicoes de queda
    printf("qual a quantidade de macas: ");
    scanf("%d", &m);
    int vetormaca[m];

    for (int i = 0; i < m; i++){
        
        printf("digite a posicao da maca [%d]: ", i + 1);
        scanf("%d", &vetormaca[i]);
        vetormaca[i] += a;

        if(vetormaca[i] >= s && vetormaca[i] <= t){
            qtdmaca++; 
        }
    
    }

    //quantidade de laranjas e armazenar as posicoes de queda
    printf("qual a quantidade de laranjas: ");
    scanf("%d", &n);
    int vetorlaranja[n];
    
    for (int i = 0; i < n; i++){
        
        printf("digite a posicao da laranja [%d]: ", i + 1);
        scanf("%d", &vetorlaranja[i]);
        vetorlaranja[i] += b; 

        if(vetorlaranja[i] >= s && vetorlaranja[i] <= t){
            qtdlaranja++;
        }

    }

    printf("%d\n", qtdmaca);
    printf("%d\n", qtdlaranja);
    

    return 0;
}