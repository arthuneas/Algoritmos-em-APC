#include <stdio.h>

void angry (int n, int k){

    int contlate;
    
    contlate = 0;
    
    int a[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);

        if (a[i] <= 0){
            contlate++;
        } 

    }

    if (contlate < k) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

}


int main(){

    int nro_casos, k, n;

    scanf("%d", &nro_casos);

    for (int i = 0; i < nro_casos; i++){
        scanf("%d", &n);
        scanf("%d", &k);
        
        angry(n, k);
    }

    return 0;
}