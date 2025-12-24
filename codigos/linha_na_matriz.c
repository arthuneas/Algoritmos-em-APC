#include <stdio.h>
 
int main() {
 
    float mat[12][12];
    int linha;
    char t;
    float result = 0;

    //leitura da linha da matriz
    printf("digite a linha da matriz: ");
    scanf("%d", &linha);

    //leitura para conferir o tipo de operação
    printf("digite o tipo de calculo[S/M]: ");
    scanf(" %c", &t);

    //leitura de dados em uma matriz
    for (int i = 0; i < 12; i++){ //linhas
        for (int j = 0; j < 12; j++){ //colunas
            printf("digite o valor [%d][%d]: ", i, j);
            scanf("%f", &mat[i][j]);
        } 
    }
   
    //condições para os calculos de media ou soma
        
    for (int j = 0; j < 12; j++){
        result += mat[linha][j];
    }    
   
   if (t == 'M') {
       printf("resultado eh %.1f \n", result / 12); 
   
   } else if (t == 'S'){
       printf("resultado eh %.1f \n", result);
   }            
    
 
    return 0;
}