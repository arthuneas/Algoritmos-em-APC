#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char pais[100];
    char local[100];
    int qtvisitas;
} tipolocal;

int main() {
    int qtdlocais;
    tipolocal locais[100];

    printf("Digite a quantidade de lugares visitados: ");
    scanf("%d", &qtdlocais);
    getchar(); // Limpa o \n pendente

    // Leitura dos dados
    for (int i = 0; i < qtdlocais; i++) {
        printf("Digite o nome do país: ");
        fgets(locais[i].pais, sizeof(locais[i].pais), stdin);
        locais[i].pais[strcspn(locais[i].pais, "\n")] = '\0';

        printf("Digite o nome do local: ");
        fgets(locais[i].local, sizeof(locais[i].local), stdin);
        locais[i].local[strcspn(locais[i].local, "\n")] = '\0';

        locais[i].qtvisitas = 0;  // inicializa
    }

    // Conta visitas por país e armazena em qtvisitas da primeira ocorrência
    for (int i = 0; i < qtdlocais; i++) {
        int contador = 1;

        if (locais[i].qtvisitas == -1) {
            continue; // já contabilizado
        }

        for (int j = i + 1; j < qtdlocais; j++) {
            if (strcmp(locais[i].pais, locais[j].pais) == 0) {
                contador++;
                locais[j].qtvisitas = -1; // marca como já contado
            }
        }

        locais[i].qtvisitas = contador; // armazena no primeiro
    }

    // Exibe resultado: país e total de visitas
    printf("\nTotal de visitas por país:\n");
    for (int i = 0; i < qtdlocais; i++) {
        if (locais[i].qtvisitas > 0) {
            printf("%s: %d visita(s)\n", locais[i].pais, locais[i].qtvisitas);
        }
    }

    return 0;
}