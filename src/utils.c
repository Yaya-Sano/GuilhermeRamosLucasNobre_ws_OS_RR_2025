#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int** alocar_matriz(int linhas, int colunas) {
    int** matriz = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }
    return matriz;
}

void liberar_matriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void preencher_matriz(int** matriz, int linhas, int colunas) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 10; // números entre 0 e 9
        }
    }
}

bool comparar_matrizes(int** A, int** B, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}
