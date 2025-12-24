#include <stdio.h>
int main(){

    int linha, coluna;
    scanf("%d %d" , &linha, &coluna);

    int mat[linha][coluna];

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){  
            scanf("%d", &mat[i][j]);
        }
    }

    
    
    
    if  ((mat[linha - 1][coluna] = 0) || (mat[linha][coluna] = 0)){
       
       
       
        printf("S\n");
    } else {
        printf("N\n");
    }
    
    
    
    
    
    return 0;
}