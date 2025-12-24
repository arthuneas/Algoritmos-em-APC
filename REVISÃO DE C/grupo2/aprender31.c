#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
char descricao[20];
} TipoPoder;


typedef struct {
int id;
char nome[20];
float forca;
TipoPoder poder;
} TipoLutador;


void limpatela(){
system("clear");
}


void fight (const TipoLutador* timeA, const TipoLutador* timeB, int n, TipoLutador* vencedores){

for (int i = 0; i < n; i++){
if (timeA[i].forca == timeB[i].forca){
vencedores[i].id = 0;
} else if (timeA[i].forca > timeB[i].forca){
vencedores[i] = timeA[i];
} else {
vencedores[i] = timeB[i];
}

}
}


void cadastramento(int n, TipoLutador time[]){

for (int i = 0; i < n; i++){

// aqui definimos o id
time[i].id = i + 1;
// aqui pegamos os nomes
printf("digite o nome %d: ", i + 1);
fgets(time[i].nome, 20, stdin);
time[i].nome[strcspn(time[i].nome, "\n")] = '\0';

// aqui pegamos a forca;
printf("digite a forca do lutador %s: ", time[i].nome);
scanf("%f", &time[i].forca);
getchar();

// aqui definimos as descricoes das pessoas
printf("digite o poder do individuo %d: ", i + 1);
fgets(time[i].poder.descricao, sizeof(time[i].poder.descricao), stdin);
time[i].poder.descricao[strcspn(time[i].poder.descricao, "\n")] = '\0';
limpatela();

}

}


int main(){

int n;
printf("digite a quantidade de lutadores: ");
scanf("%d", &n);
getchar();

TipoLutador timeA[n];
TipoLutador timeB[n];
TipoLutador vencedores[n];

limpatela();

//cadastramento do time A.

printf("--------------------------------\n");
printf("hora do cadastramento do time A \n");
printf("--------------------------------\n");

cadastramento(n, timeA);
limpatela();

//cadastramento do time B.

printf("--------------------------------\n");
printf("hora do cadastramento do time B \n");
printf("--------------------------------\n");

cadastramento(n, timeB);
limpatela();

// aqui faremos a condição de vitoria;
fight(timeA, timeB, n, vencedores);

// printar os ganhadores
for (int i = 0; i < n; i++){
printf("%d, %s, %.2f, %s\n", vencedores[i].id, vencedores[i].nome, vencedores[i].forca, vencedores[i].poder.descricao);
}

return 0;
}