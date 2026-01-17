#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com água (0) //
void InicializarTabuleiro(int Tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            Tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se uma posição é válida e não está ocupada //
int PosicaoValida(int Tabuleiro[TAM][TAM], int Linha, int Coluna) {
    if (Linha < 0 || Linha >= TAM || Coluna < 0 || Coluna >= TAM)
        return 0;

    if (Tabuleiro[Linha][Coluna] != AGUA)
        return 0;

    return 1;
}

// Função para posicionar um navio //
// deltaLinha e deltaColuna definem a direção (horizontal, vertical ou diagonal) //
int PosicionarNavio(int Tabuleiro[TAM][TAM], int Linha, int Coluna,
                     int DeltaLinha, int DeltaColuna) {

    // Primeiro valida todas as posições //
    for (int i = 0; i < TAM_NAVIO; i++) {
        int NovaLinha = Linha + i * DeltaLinha;
        int NovaColuna = Coluna + i * DeltaColuna;

        if (!PosicaoValida(Tabuleiro, NovaLinha, NovaColuna)) {
            return 0; // posição inválida ou sobreposição
        }
    }

    // Depois posiciona o navio //
    for (int i = 0; i < TAM_NAVIO; i++) {
        int NovaLinha = Linha + i * DeltaLinha;
        int NovaColuna = Coluna + i * DeltaColuna;
        Tabuleiro[NovaLinha][NovaColuna] = NAVIO;
    }

    return 1;
}

// Função para exibir o tabuleiro //
void ExibirTabuleiro(int Tabuleiro[TAM][TAM]) {
    printf("Tabuleiro 10x10:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", Tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int Tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro //
    InicializarTabuleiro(Tabuleiro);

    // Posiciona dois navios horizontais/verticais //
    PosicionarNavio(Tabuleiro, 1, 1, 0, 1); // Horizontal
    PosicionarNavio(Tabuleiro, 4, 3, 1, 0); // Vertical

    // Posiciona dois navios diagonais //
    PosicionarNavio(Tabuleiro, 6, 0, 1, 1);  // Diagonal principal
    PosicionarNavio(Tabuleiro, 0, 8, 1, -1); // Diagonal secundária

    // Exibe o tabuleiro //
    ExibirTabuleiro(Tabuleiro);
    printf("\n");
    
    return 0;
}
