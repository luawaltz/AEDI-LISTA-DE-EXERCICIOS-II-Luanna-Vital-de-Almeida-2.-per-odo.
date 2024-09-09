#include <stdio.h>

// Função para realizar a busca binária
int busca_binaria(int arr[], int tamanho, int x) {
    int esquerda = 0, direita = tamanho - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (arr[meio] == x)
            return meio;
        if (arr[meio] < x)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }
    return -1;
}

int main() {
    // Array dos números primos de 1 a 100
    int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int tamanho = sizeof(primos) / sizeof(primos[0]);
    int numero;

    // Solicita ao usuário que informe um número
    printf("Digite um número de 1 a 100: ");
    scanf("%d", &numero);

    // Verifica se o número está na lista de primos usando busca binária
    int resultado = busca_binaria(primos, tamanho, numero);

    if (resultado != -1)
        printf("O número %d é primo e está na posição %d do array.\n", numero, resultado);
    else
        printf("O número %d não é primo.\n", numero);

    return 0;
}
