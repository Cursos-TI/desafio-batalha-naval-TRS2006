#include <stdio.h>

#define TAMANHO 10  // Define o tamanho do tabuleiro
#define NAVIO 3     // Valor que representa um navio no tabuleiro
#define TAM_NAVIO 3 // Tamanho fixo dos navios

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro com coordenadas (A-J e 1-10)
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n   A B C D E F G H I J\n"); // Cabeçalho com letras das colunas
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1); // Numeração das linhas de 1 a 10
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe valores do tabuleiro
        }
        printf("\n");
    }
}

// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    if (direcao == 'H') { 
        if (coluna + TAM_NAVIO > TAMANHO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] == NAVIO) return 0;
        }
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (direcao == 'V') { 
        if (linha + TAM_NAVIO > TAMANHO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) return 0;
        }
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else {
        return 0;
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Definição fixa das coordenadas (exemplo)
    int linha1 = 2, coluna1 = 3;  // Navio horizontal em (3, D)
    int linha2 = 5, coluna2 = 6;  // Navio vertical em (6, G)

    if (!posicionarNavio(tabuleiro, linha1, coluna1, 'H')) {
        printf("Erro ao posicionar o navio horizontal.\n");
    }
    if (!posicionarNavio(tabuleiro, linha2, coluna2, 'V')) {
        printf("Erro ao posicionar o navio vertical.\n");
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
