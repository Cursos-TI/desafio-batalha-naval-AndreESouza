#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5

// Função para imprimir o tabuleiro //
void ImprimirTabuleiro(int Tabuleiro[TAM_TAB][TAM_TAB]) {
    int i, j;
    for (i = 0; i < TAM_TAB; i++) {
        for (j = 0; j < TAM_TAB; j++) {
            printf("%d ", Tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar uma habilidade no tabuleiro //
void AplicarHabilidade(
    int Tabuleiro[TAM_TAB][TAM_TAB],
    int Habilidade[TAM_HAB][TAM_HAB],
    int OrigemLinha,
    int OrigemColuna
) {
    int i, j;
    int Offset = TAM_HAB / 2;

    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {

            if (Habilidade[i][j] == 1) {
                int LinhaTab = OrigemLinha + i - Offset;
                int ColunaTab = OrigemColuna + j - Offset;

                // Verifica limites do tabuleiro //
                if (LinhaTab >= 0 && LinhaTab < TAM_TAB &&
                    ColunaTab >= 0 && ColunaTab < TAM_TAB) {

                    // Marca área afetada (sem sobrescrever navios) //
                    if (Tabuleiro[LinhaTab][ColunaTab] == 0) {
                        Tabuleiro[LinhaTab][ColunaTab] = 5;
                    }
                }
            }
        }
    }
}

int main() {
    int Tabuleiro[TAM_TAB][TAM_TAB] = {0};
    int Cone[TAM_HAB][TAM_HAB];
    int Cruz[TAM_HAB][TAM_HAB];
    int Octaedro[TAM_HAB][TAM_HAB];

    int i, j;

    // Exemplo de navios //
    Tabuleiro[2][2] = 3;
    Tabuleiro[5][5] = 3;
    Tabuleiro[7][3] = 3;

    // =============== Construção da habilidade CONE =============== //
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i)) {
                Cone[i][j] = 1;
            } else {
                Cone[i][j] = 0;
            }
        }
    }

    // =============== Construção da habilidade CRUZ =============== //
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                Cruz[i][j] = 1;
            } else {
                Cruz[i][j] = 0;
            }
        }
    }

    // =============== Construção da habilidade OCTAEDRO (losango) =============== //
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if ((i - TAM_HAB / 2) + (j - TAM_HAB / 2) <= TAM_HAB / 2) {
                Octaedro[i][j] = 1;
            } else {
                Octaedro[i][j] = 0;
            }
        }
    }

    // Aplicando habilidades no tabuleiro //
    AplicarHabilidade(Tabuleiro, Cone, 3, 3);
    AplicarHabilidade(Tabuleiro, Cruz, 6, 6);
    AplicarHabilidade(Tabuleiro, Octaedro, 8, 2);

    // Exibindo resultado final //
    printf("Tabuleiro final:\n");
    ImprimirTabuleiro(Tabuleiro);
    printf("\n");

    return 0;
}
