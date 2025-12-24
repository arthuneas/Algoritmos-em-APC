#include <stdio.h>
#include <string.h>

int main() {
 
    char tipo[30], filo[30], comida[30];
    
    scanf("%s", tipo);
    scanf("%s", filo);
    scanf("%s", comida);

    if (strcmp(tipo, "vertebrado") == 0){
        if (strcmp(filo, "ave") == 0){
            if (strcmp(comida, "carnivoro") == 0){
                printf("aguia\n");
            } else {
                printf("pomba\n");
            }
        }
    }
   
    if (strcmp(tipo, "vertebrado") == 0){
        if (strcmp(filo, "mamifero") == 0){
            if (strcmp(comida, "onivoro") == 0){
                printf("homem\n");
            } else {
                printf("vaca\n");
            }
        }
    }
    
    if (strcmp(tipo, "invertebrado") == 0){
        if (strcmp(filo, "inseto") == 0){
            if (strcmp(comida, "hematofago") == 0){
                printf("pulga\n");
            } else {
                printf("lagarta\n");
            }
        }
    }
    
    if (strcmp(tipo, "invertebrado") == 0){
        if (strcmp(filo, "anelideo") == 0){
            if (strcmp(comida, "hematofago") == 0){
                printf("sanguessuga\n");
            } else {
                printf("minhoca\n");
            }
        }
    }
    

    
    
    return 0;
}