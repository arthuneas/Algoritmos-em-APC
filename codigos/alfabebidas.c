#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>


// Códigos ANSI para cores padrao
#define red       "\033[0;31m"
#define green     "\033[0;32m"
#define blue      "\033[0;34m"
#define yellow    "\033[0;33m"
#define purple    "\033[0;35m" 
#define cyan      "\033[0;36m"
#define white     "\033[0;37m"
#define vermelho  "\033[1;31m"
#define verde     "\033[1;32m"
#define azul      "\033[1;34m"
#define amarelo   "\033[1;33m"  
#define roxo      "\033[1;35m" 
#define ciano     "\033[1;36m"
#define branco    "\033[1;37m"
#define reset     "\033[0m"

// fundos coloridos
#define backred   "\033[41m"
#define backgreen "\033[42m"
#define backblue  "\033[44m"

#define arquivohistorico "cliente.txt"

#define maxlancamentos 10000
#define numprodutos 26

//dados da divida como data e valor
typedef struct {

    char nome[100];
    float valor;
    char datahora[30];

} lancamento;

//dados do usuario
typedef struct {

    char nome[100];
    float debitototal;
    int qtdlancamento;
    lancamento lancamentos[maxlancamentos];

} usuario;

typedef struct {
    
    int codigo;
    char nome[50];
    float preco; 

} produto;


//definicao da struct usuario
usuario cliente;
produto catalogo[numprodutos] = {

    {1, "Cerveja Long Neck Heineken", 9.00},
    {2, "Cerveja Long Neck Sem Alcool", 10.00},
    {3, "Cerveja Long Neck Corona", 10.00},
    {4, "Cerveja Lata Amstel", 5.00},
    {5, "Cerveja Lata Brahma", 5.00},
    {6, "Cerveja Lata Antarctica", 5.00},
    {7, "Cerveja Lata Bohemia", 5.00},
    {8, "Cerveja Lata Spaten", 5.00},
    {9, "Cerveja Lata Heineken", 5.00},
    {10, "Ice", 6.00},
    {11, "Coca Lata", 5.00},
    {12, "Guaraná Antarctica 269ml", 5.00},
    {13, "Guaraná Jesus", 4.00},
    {14, "Fanta Laranja", 5.00},
    {15, "Sprite", 5.00},
    {16, "Schweppes", 5.00},
    {17, "Coca Cola 1,5lts", 8.00},
    {18, "Energético RedBull", 10.00},
    {19, "Energético Monster", 12.00},
    {20, "Energético Extra Power", 12.00},
    {21, "Gatorade", 8.00},
    {22, "Guaramix", 8.00},
    {23, "Limoneta H2O+", 4.00},
    {24, "Água Sem Gás", 3.00},
    {25, "Água Com Gás", 4.00},
    {26, "Toddy", 4.00}
};


FILE *arquivo;


void limpatela() {

    #ifdef _WIN32
        system("cls");

    #else
        system("clear");

    #endif
}


void exibircatalogo(){

    limpatela();

    printf("\t\t\t\t\t\t\t%s          === CATÁLOGO DE PRODUTOS ===%s\n\n", cyan, reset);
    printf("\t\t\t\t\t\t\t%s---------------------------------------------------%s\n", ciano, reset);
    printf("\t\t\t\t\t\t\t%s CODIGO           PRODUTO                 PRECO%s\n", branco, reset);
    printf("\t\t\t\t\t\t\t%s---------------------------------------------------%s\n", ciano, reset);
    
    for (int i = 0; i < numprodutos; i++) {
        printf("\t\t\t\t\t\t\t%s%-7d%s %s%-32s%s%sR$ %-6.2f%s\n", amarelo, catalogo[i].codigo, reset, white, catalogo[i].nome, reset, verde, catalogo[i].preco, reset);
    }
    printf("\t\t\t\t\t\t\t%s==================================================%s\n\n", ciano, reset);
}  


void salvararquivo(usuario *u){

    FILE *arquivo = fopen("cliente.bin", "ab"); 
    if (arquivo == NULL){
        printf("%sERRO AO ABRIR ARQUIVO\n%s", vermelho, reset);
        return;
    }

    fwrite(u, sizeof(usuario),1, arquivo);
    fclose(arquivo);
}


void carregarclientes() {
    FILE *arquivo = fopen("cliente.bin", "r");
    if (arquivo) {
        fread(&cliente, sizeof(usuario), 1, arquivo);
        fclose(arquivo);
    }
}


void addusuario(){

    limpatela();

    printf("\t\t\t\t\t\t\t%s--------------------------------------\n%s", green, reset);
    printf("\t\t\t\t\t\t\t%sOlá! Bem Vindo ao App da Alfa Bebidas!\n\n%s", backgreen, reset);
    printf("\t\t\t\t\t\t\t%sDigite o Nome do Cliente: %s", white, reset);
    
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

} 


float codigoparavalor (int codigo){
    for (int i = 0; i < numprodutos; i++){
        if (catalogo[i].codigo == codigo){
            return catalogo[i].preco;
        }
    }
    
    return -1;
}


char* codigoparaword (int codigo){

    for (int i = 0; i < numprodutos; i++){
        if (catalogo[i].codigo == codigo){
            return catalogo[i].nome;
        }
    }

    return "Codigo Invalido";
}


void pagamento(char *pago, size_t tamanho){

    printf("O Cliente ja efetuou o Pagamento?[s/n]");
    fgets(pago, tamanho, stdin);
    pago[strcspn(pago, "\n")] = '\0';

    if (strcmp(pago, "sim") == 0 || strcmp(pago, "SIM") == 0 || strcmp(pago, "s") == 0 || strcmp(pago, "S") == 0){
        salvararquivo(&cliente); 
    } else {
        return;
    }

}


void resumocompra(int variacaoproduto, float subtotal, int quantidadeproduto[], float preco[], char word[][50]){

    char *resposta = malloc(20);

    printf("\t\t\t\t\t\t\t%s       === RESUMO DA COMPRA ===  %s\n\n", cyan, reset);

    for (int i = 0; i < variacaoproduto; i++){
        
        printf("\t\t\t\t\t\t\t%s%d%s %sunidades de%s %s%s%s\n", azul, quantidadeproduto[i], reset, blue, reset, azul, word[i], reset);
        printf("\t\t\t\t\t\t\t%sValor Total desse Item:%s %sR$ %.2f%s\n", yellow, reset, verde, preco[i], reset);
        printf("\t\t\t\t\t\t\t%s.........................................%s\n\n", cyan, reset);

    }
    
    printf("\t\t\t\t\t\t\t%s===========================================%s\n", ciano, reset);
    printf("\t\t\t\t\t\t\t%sSubtotal da compra: %s %sR$ %.2f%s\n", branco, reset, verde, subtotal, reset);
    printf("\t\t\t\t\t\t\t%s===========================================%s\n", ciano, reset);

    pagamento(resposta, sizeof(resposta));

    free(resposta);
    
    limpatela();

}


void addprodutos(){
    
    limpatela();

    exibircatalogo();

    int variacaoproduto;
    float subtotal = 0;
    float unit;
    char entrada[20];
    
    printf("\t\t\t\t\t\t\t%s*. ^ + _  :+ * ^ .                    \n%s", ciano, reset);
    printf("\t\t\t\t\t\t\t%s------------------------------------------------\n%s", cyan, reset);
    printf("\t\t\t\t\t\t\t%sDigite a Quantidade de Produtos Comprados: %s", white, reset);
    fgets(entrada, sizeof(entrada), stdin);
    sscanf(entrada, "%d", &variacaoproduto);
        
    int *codigoproduto = malloc(variacaoproduto * sizeof(int)); //vetor que aloca memoria dinamicamente
    int *quantidadeproduto = malloc(variacaoproduto * sizeof(int));
    float *preco = malloc(variacaoproduto * sizeof(float)); 
    char (*word)[50] = malloc(variacaoproduto * sizeof(*word)); //vetor que armazena string que aloca memoria dinamicamente


    for (int i = 0; i < variacaoproduto; i++){
        
        char entrada1[20];
        char entrada2[20];
        int codigovalido = 0;

        while (!codigovalido){
            printf("\t\t\t\t\t\t\t%s------------------------------------------------%s\n", blue, reset);
            printf("\t\t\t\t\t\t\t%sDigite o Codigo do Produto: %s", white, reset);
            
            fgets(entrada1, sizeof(entrada1), stdin);

            if (sscanf(entrada1, "%d", &codigoproduto[i]) != 1 || codigoparavalor(codigoproduto[i]) == -1){
                printf("%s\t\t\t\t\t\t\tCodigo Invalido. Digite um Valido.%s\n", red, reset);

            } else {
                break;
            }
        }   

        printf("\t\t\t\t\t\t\t%sDigite as Unidades Vendidas desse Produto: %s", white, reset);
        while (quantidadeproduto[i] <=0) {
            fgets(entrada2, sizeof(entrada2), stdin);
            sscanf(entrada2, "%d", &quantidadeproduto[i]);

            if (quantidadeproduto[i] <= 0){
                printf("%s\t\t\t\t\t\t\tQuantidade Invalida. Digite uma Valida.%s\n", red, reset);
            } else {
                break;
            }
        }

        unit = codigoparavalor(codigoproduto[i]);
        strcpy(word[i], codigoparaword(codigoproduto[i]));

        if (unit == -1){
            printf("\t\t\t\t\t\t\t%sCodigo Invalido\n%s", vermelho, reset);

            preco[i] = 0;
            continue;
        }

        preco[i] = unit * quantidadeproduto[i];
        subtotal += preco[i];
    }

    limpatela();

    resumocompra(variacaoproduto, subtotal, quantidadeproduto, preco, word);


    if (subtotal > 0) {
        if (cliente.qtdlancamento < maxlancamentos) {
            time_t agora = time(NULL);
            struct tm *tm_info = localtime(&agora);
            strftime(cliente.lancamentos[cliente.qtdlancamento].datahora, 30, "%d/%m/%Y %H:%M:%S", tm_info);
            cliente.lancamentos[cliente.qtdlancamento].valor = subtotal;
            cliente.qtdlancamento++;
            cliente.debitototal += subtotal;
        }   
    }

    free(codigoproduto);
    free(quantidadeproduto);
    free(preco);
    free(word);

}


void zerarhistorico(){
    
    limpatela();
    printf("Qual o nome da pessoa que deseja zerar o histórico: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0'; 

    cliente.debitototal = 0;
    cliente.qtdlancamento = 0;
    memset(cliente.lancamentos, 0, sizeof(cliente.lancamentos));
    printf("Historico do cliente %s zerado com sucesso.\n", cliente.nome);

    FILE *arquivo = fopen("cliente.bin", "wb");
    if (arquivo == NULL) {
        printf("%sErro ao abrir arquivo para zerar histórico!%s\n", vermelho, reset);
        return;
    }   
    
    fwrite (&cliente, sizeof(usuario), 1, arquivo);
    fclose(arquivo);

    getchar();
}


void fechararquivo(){

    if (arquivo != NULL) {
        fclose(arquivo);
        arquivo = NULL;
    }
}


void exibirhistorico(){

    limpatela();

    usuario *historico = malloc(sizeof(usuario) * maxlancamentos);
    if (historico == NULL) {
        printf("Erro ao alocar memória para histórico.\n");
        return;
    }

    FILE *arquivo = fopen("cliente.bin", "rb");

    if (arquivo == NULL){
        printf("%sNenhum Cliente Esta Cadastrado\n%s", amarelo, reset);
        getchar();
        return;
    }

    int i = 0;

    while(fread(&historico[i], sizeof(usuario), 1, arquivo)){
        i++;
    }

    fclose(arquivo);

    for (int j = 0; j < i - 1; j++){
        for(int k = j + 1; k < i; k++){

            if (historico[j].debitototal < historico[k].debitototal){

                usuario temp = historico[j];
                historico[j] = historico[k];
                historico[k] = temp;
            }
        }
    }

    printf("\t\t\t\t\t\t\t%s====== Dividendos ======%s\n", roxo, reset);
    
    for (int j = 0; j < i; j++) {
        printf("\n\t\t\t\t\t\t\t%sCliente:%s %s%s%s\n", amarelo, reset, branco, historico[j].nome, reset);
        printf("\t\t\t\t\t\t\t%sDívida Total:%s %sR$ %.2f%s\n", ciano, reset, verde, historico[j].debitototal, reset);
        printf("\t\t\t\t\t\t\t%sHistórico de Compras:%s\n", azul, reset);

        for (int l = 0; l < historico[j].qtdlancamento; l++) {
            printf("\t\t\t\t\t\t\t  - %s: R$ %.2f\n", historico[j].lancamentos[l].datahora, historico[j].lancamentos[l].valor);
        }
   
    }

    free(historico);
    getchar();

}


void cadastro(){

    addusuario();
    addprodutos();
    salvararquivo(&cliente);

}


void sobre(){

    printf("\t\t\t\t\t\t\t%sApp Alfa Bebidas v1.0%s\n", yellow, reset);

    printf("\t\t\t\t\t\t\t%sDesenvolvido para gerenciar vendas e historico de clientes.%s\n\n", yellow, reset);   
    printf("\t\t\t\t\t\t\t%sTecla <enter> para proseguir%s\n", white, reset);

    getchar();
    limpatela();

}


int inicio (){

    int opcao; 
    char entrada[20];

    printf("\t\t\t\t\t\t\t%s===============================================%s\n", roxo, reset);
    printf("\t\t\t\t\t\t\t%s_ *. ^ +                                       %s\n", ciano, reset);
    printf("\t\t\t\t\t\t\t%s                  ALFA BEBIDAS                 %s\n", cyan, reset);
    printf("\t\t\t\t\t\t\t%s                                       _ + ^ .*%s\n", ciano, reset);
    printf("\t\t\t\t\t\t\t%s===============================================%s\n\n", roxo, reset); 

    printf("\t\t\t\t\t\t\t\t%s1%s - %sCadastro de Cliente%s\n", amarelo, reset, branco, reset); 
    printf("\t\t\t\t\t\t\t\t%s2%s - %sZerar Historico de Cliente%s\n", amarelo, reset, branco, reset);
    printf("\t\t\t\t\t\t\t\t%s3%s - %sExibir Historico de Cliente%s\n", amarelo, reset, branco, reset);
    printf("\t\t\t\t\t\t\t\t%s4%s - %sSobre o Aplicativo%s\n", amarelo, reset, branco, reset); 
    printf("\t\t\t\t\t\t\t\t%s5%s - %sSair%s\n\n", amarelo, reset, branco, reset);

    printf("\t\t\t\t\t\t%s   ----------------------------------------------------------%s\n", roxo, reset); 
        
    while (1){
        printf("%s\t\t\t\t\t\t\t\tDigite a Opcao Desejada: %s", white, reset);
        fgets(entrada, sizeof(entrada), stdin);

        if (sscanf(entrada, "%d", &opcao) == 1 && opcao >= 1 && opcao <= 5){  //extrai um inteiro da string e armazena em numero 
            break;
        } else {
            printf("%s\t\t\t\t\t\t\tEntrada Invalida. Tente Novamente.\n%s", vermelho, reset);
        }
    }       
       
    limpatela();   
         
    return opcao;
}


int main(){

    carregarclientes();

     while (1){

        limpatela();
        int opcao = inicio();

        switch (opcao) {

            case 1:
                cadastro();
                break;

            case 2:
                zerarhistorico();
                break;

            case 3:
                exibirhistorico();
                break;

            case 4:
                sobre();
                break;
            
            case 5:
                exit(0);

            default: 
                printf("%sOpcao Invalida%s\n", red, reset);
                break;
        }   
    }

    return 0;
}