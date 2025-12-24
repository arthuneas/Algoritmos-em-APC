#include <stdio.h>

int main(){

    int diai, horai, mini, segi;
    int diaf, horaf, minf, segf;

    int dia, hora, min, seg;

    printf("insira os dados iniciais: ");
    scanf("%d %d:%d:%d", &diai, &horai, &mini, &segi);

    printf("insira os dados finais: ");
    scanf("%d %d:%d:%d", &diaf, &horaf, &minf, &segf);

    dia = diaf - diai;
    hora = horaf - horai;
    min = minf - mini;
    seg = segf - segi;

    if (dia < 0) {
        printf("Data Invalida !\n");

    } else {
        printf("%d dia(s)\n", dia);
        printf("%d horas(s)\n", hora);
        printf("%d minutos(s)\n", min);
        printf("%d segundo(s)\n", seg);

    }

    return 0;
}