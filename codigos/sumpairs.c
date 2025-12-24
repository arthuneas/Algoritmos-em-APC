#include <stdio.h>
 int main(){

        int k, n;
        int cont; 

        cont = 0;

        scanf("%d", &n);
        scanf("%d", &k);

        int ar[n];
        
        for (int i = 0; i < n; i++){
            scanf("%d", &ar[i]);
        }  
        
        
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if( (ar[i] + ar[j]) % k == 0){
                    cont++;
                }
            }
        }

        printf("%d\n", cont);

    return 0;
 }