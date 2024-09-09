#include <stdio.h>

int buscaBinaria(int contas[], int tamanho, int contaProcurada, int *comparacoes) {
    int esquerda = 0;
    int direita = tamanho - 1;
    *comparacoes = 0;

    while (esquerda <= direita) {
        (*comparacoes)++;
        int meio = (esquerda + direita) / 2;

        if (contas[meio] == contaProcurada) {
            return meio; // Conta encontrada
        } else if (contas[meio] < contaProcurada) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return -1; // Conta não encontrada
}

int main() {
    int contas[] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, // Exemplo de contas
                    1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020,
                    // Adicione mais contas até ter pelo menos 100
                    1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098, 1099, 1100};
    int tamanho = sizeof(contas) / sizeof(contas[0]);
    int contaProcurada;
    int comparacoes;

    printf("Digite o número da conta a ser procurada: ");
    scanf("%d", &contaProcurada);

    int resultado = buscaBinaria(contas, tamanho, contaProcurada, &comparacoes);

    if (resultado != -1) {
        printf("Conta encontrada na posição %d\n", resultado);
    } else {
        printf("Conta não encontrada\n");
    }

    printf("Número de comparações: %d\n", comparacoes);

    return 0;
}
