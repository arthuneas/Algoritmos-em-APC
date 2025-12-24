#include <stdio.h>
#include <string.h>
 
int main() {
 
    int n;
    scanf("%d", &n);  //numero de teste

    while(n--) {
        int k; //numero de pessoas no grupo
        scanf("%d", &k); 

        char idioma[k][21]; //lista de idiomas
        int unico = 1;

        scanf("%s", idioma[0]);

        for (int i = 1; i < k; i++){
            scanf("%s", idioma[i]);
            if (strcmp(idioma[0], idioma[i]) != 0){
                unico = 0;
            }

        }
    

        if (unico) {
            printf("%s\n", idioma[0]);
        } else {
            printf("ingles\n");
        }
 
    }

    return 0;
}