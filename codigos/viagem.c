#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char pais[100];
    char local[100];
    int qtvisitas;

} tipolocal;


int main(){

    int qtdlocais;

    tipolocal locais[100];

    printf("digite a quantidade de lugares visitados: ");
    scanf("%d", &qtdlocais);

    getchar();
    
    for (int i = 0; i < qtdlocais; i++){
        printf("digite o nome do país: ");
        fgets(locais[i].pais, sizeof(locais[i].pais), stdin);
        locais[i].pais[strcspn(locais[i].pais, "\n")] = '\0';

        printf("digite o nome do local: ");
        fgets(locais[i].local, sizeof(locais[i].local), stdin);
        locais[i].local[strcspn(locais[i].local, "\n")] = '\0';

        locais[i].qtvisitas = 0;

    }

    for (int i = 0; i < qtdlocais; i++){
        
        int contador = 0;

        for(int j = i + 1; j < qtdlocais; j++){
            
            if(locais[i].qtvisitas == -1){
                continue;
            }
            
            if (strcmp(locais[i].pais, locais[j].pais) == 0){
                contador++;
                locais[i].qtvisitas = -1;
            } 
        }

        locais[i].qtvisitas = contador;
    }


    for(int i = 0; i < qtdlocais; i++){
            printf("%s: %d visitas\n", locais[i].pais, locais[i].qtvisitas);
        
    }

    return 0;
}

/* fgets(locais[i].pais, sizeof(locais[i].pais), stdin);
    locais[i}.local[strscpn(locais[i].local, "\n")] = '\0'
    
    como limpar o \n da string que o fgets() adiciona no final da string.
*/