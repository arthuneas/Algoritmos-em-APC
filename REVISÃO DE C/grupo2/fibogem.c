#include <stdio.h>

// 1. TAMANHO FIXO: Usamos um tamanho fixo (constante) grande o suficiente para o resultado.
#define DIGITOS 210

// 2. FUNÇÃO VOID: A função não retorna um valor, ela mesma imprime o resultado.
void fibo(int n) {
    // Casos base
    if (n <= 0) {
        printf("0\n");
        return; 
    }
    if (n <= 2) {
        printf("1\n");
        return; 
    }

    // Vetores com tamanho fixo e inicialização correta
    int antes_do_anterior[DIGITOS] = {1}; 
    int anterior[DIGITOS] = {1};
    int atual[DIGITOS] = {0};

    // 3. LAÇO PRINCIPAL: Vai de 3 até "n" (inclusive) para calcular o n-ésimo termo.
    for (int i = 3; i <= n; i++) {
        int vai_um = 0;

        // 4. LAÇO DA SOMA: Percorre TODOS os dígitos para garantir que o "vai-um" se propague.
        for (int j = 0; j < DIGITOS; j++) {
            int soma_coluna = antes_do_anterior[j] + anterior[j] + vai_um;
            atual[j] = soma_coluna % 10;
            vai_um = soma_coluna / 10;
        }

        // 5. LAÇOS DE ATUALIZAÇÃO: Seus dois laços separados, agora com o limite correto.
        for (int k = 0; k < DIGITOS; k++) {
            antes_do_anterior[k] = anterior[k];
        }
        for (int k = 0; k < DIGITOS; k++) {
            anterior[k] = atual[k];
        }
    }

    // 6. LAÇO DE IMPRESSÃO: Imprime o resultado, que está no vetor 'atual'.
    int primeiro_digito_encontrado = 0;
    printf("O termo F(%d) da sequencia de Fibonacci eh:\n", n);

    // Percorre o vetor do final para o começo para imprimir na ordem correta
    for (int i = DIGITOS - 1; i >= 0; i--) {
        // Encontra o primeiro dígito que não é zero para começar a imprimir
        if (atual[i] != 0) {
            primeiro_digito_encontrado = 1;
        }
        // Se já encontramos o primeiro dígito, imprime todos os seguintes
        if (primeiro_digito_encontrado) {
            printf("%d", atual[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("digite um número (ex: 1000): ");
    scanf("%d", &n);

    // Apenas chama a função fibo, que agora é responsável por tudo.
    fibo(n);

    return 0;
}