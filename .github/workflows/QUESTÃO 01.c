#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TENTATIVAS 12
#define TAMANHO_PALAVRA 10

void exibirForca(int tentativas) {
    printf("Tentativas restantes: %d\n", tentativas);
}

int main() {
    char palavra[TAMANHO_PALAVRA + 1];
    char palavraOculta[TAMANHO_PALAVRA + 1];
    char letra;
    int tentativas, acertos = 0;
    int tamanhoPalavra;

    printf("Digite uma palavra de até %d caracteres: ", TAMANHO_PALAVRA);
    scanf("%s", palavra);

    tamanhoPalavra = strlen(palavra);
    tentativas = tamanhoPalavra + 2;

    for (int i = 0; i < tamanhoPalavra; i++) {
        palavraOculta[i] = '_';
    }
    palavraOculta[tamanhoPalavra] = '\0';

    while (tentativas > 0 && acertos < tamanhoPalavra) {
        printf("\nPalavra: %s\n", palavraOculta);
        exibirForca(tentativas);

        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);

        int encontrou = 0;
        for (int i = 0; i < tamanhoPalavra; i++) {
            if (tolower(palavra[i]) == letra && palavraOculta[i] == '_') {
                palavraOculta[i] = palavra[i];
                acertos++;
                encontrou = 1;
            }
        }

        if (!encontrou) {
            tentativas--;
        }
    }

    if (acertos == tamanhoPalavra) {
        printf("\nParabéns! Você acertou a palavra: %s\n", palavra);
    } else {
        printf("\nVocê perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
