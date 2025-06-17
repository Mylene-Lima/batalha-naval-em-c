#include <stdio.h>
#include <stdlib.h>

#define TAM 8

int tabuleiro[TAM][TAM];

// Posições possíveis do cavalo (movimento em L)
int movimentos[8][2] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

// Função recursiva para simular movimentos do cavalo
void moverCavalo(int linha, int coluna, int profundidade)
{
    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM || profundidade < 0)
        return;

    tabuleiro[linha][coluna] = 1;

    for (int i = 0; i < 8; i++)
    {
        int novaLinha = linha + movimentos[i][0];
        int novaColuna = coluna + movimentos[i][1];
        moverCavalo(novaLinha, novaColuna, profundidade - 1);
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro()
{
    printf("\n--- Tabuleiro ---\n");
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int linhaInicial, colunaInicial, maxProfundidade;

    // Zera o tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    printf("Posição inicial do cavalo (linha e coluna de 0 a 7): ");
    scanf("%d %d", &linhaInicial, &colunaInicial);

    printf("Máximo de jogadas (profundidade): ");
    scanf("%d", &maxProfundidade);

    moverCavalo(linhaInicial, colunaInicial, maxProfundidade);
    imprimirTabuleiro();

    return 0;
}
