#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_VETOR 10
#define TAMANHO_MATRIZ 10

// Função para imprimir o tabuleiro 2D
void imprimirTabuleiro(int tabuleiro[TAMANHO_MATRIZ][TAMANHO_MATRIZ]) {
    printf("   ");
    for (int j = 0; j < TAMANHO_MATRIZ; j++) printf("%2d", j);
    printf("\n");

    for (int i = 0; i < TAMANHO_MATRIZ; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_MATRIZ; j++) {
            if (tabuleiro[i][j] == 1)
                printf(" N");
            else if (tabuleiro[i][j] == 2)
                printf(" X");
            else
                printf(" ~");
        }
        printf("\n");
    }
}

// Módulo 1 - Vetor 1D
void moduloNovato() {
    int tabuleiro[TAMANHO_VETOR] = {0};

    // Posiciona navios em posições fixas
    tabuleiro[2] = 1;
    tabuleiro[5] = 1;
    tabuleiro[7] = 1;

    printf("\n--- Módulo Novato (Vetor 1D) ---\n");
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        if (tabuleiro[i] == 1)
            printf(" N");
        else
            printf(" ~");
    }
    printf("\n");
}

// Módulo 2 - Matriz 2D com navios horizontais, verticais e diagonais
void moduloAventureiro() {
    int tabuleiro[TAMANHO_MATRIZ][TAMANHO_MATRIZ] = {0};

    // Navio horizontal
    for (int j = 1; j <= 3; j++)
        tabuleiro[2][j] = 1;

    // Navio vertical
    for (int i = 4; i <= 6; i++)
        tabuleiro[i][4] = 1;

    // Navio diagonal
    for (int i = 0; i < 3; i++)
        tabuleiro[i][i] = 1;

    printf("\n--- Módulo Aventureiro (Matriz 2D) ---\n");
    imprimirTabuleiro(tabuleiro);
}

// Módulo 3 - Habilidade especial com área de efeito (cruz)
void moduloMestre() {
    int tabuleiro[TAMANHO_MATRIZ][TAMANHO_MATRIZ] = {0};
    int x = 5, y = 5;

    // Posiciona um navio no centro
    tabuleiro[x][y] = 1;

    // Habilidade especial: marca cruz
    for (int i = 0; i < TAMANHO_MATRIZ; i++) tabuleiro[i][y] = 2;
    for (int j = 0; j < TAMANHO_MATRIZ; j++) tabuleiro[x][j] = 2;

    // Mantém o navio visível
    tabuleiro[x][y] = 1;

    printf("\n--- Módulo Mestre (Área de Efeito: Cruz) ---\n");
    imprimirTabuleiro(tabuleiro);
}

// Menu principal
int main() {
    int opcao;

    do {
        printf("\n=== BATALHA NAVAL ===\n");
        printf("1. Módulo Novato (Vetor 1D)\n");
        printf("2. Módulo Aventureiro (Matriz 2D)\n");
        printf("3. Módulo Mestre (Área de Efeito)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                moduloNovato();
                break;
            case 2:
                moduloAventureiro();
                break;
            case 3:
                moduloMestre();
                break;
            case 0:
                printf("Saindo do jogo. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
