#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CRIANCAS 50
#define NOTAS 5

int main() {
    int notas[TOTAL_CRIANCAS];
    int contagem[NOTAS] = {0};
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Gera notas aleatórias entre 1 e 5
    for (int i = 0; i < TOTAL_CRIANCAS; i++) {
        notas[i] = rand() % NOTAS + 1;
    }
    
    // Conta a frequência de cada nota
    for (int i = 0; i < TOTAL_CRIANCAS; i++) {
        contagem[notas[i] - 1]++;
    }
    
    // Exibe o resultado
    printf("Resultado da pesquisa de mercado:\n");
    for (int i = 0; i < NOTAS; i++) {
        printf("Nota %d: %d vezes\n", i + 1, contagem[i]);
    }
    
    return 0;
}
