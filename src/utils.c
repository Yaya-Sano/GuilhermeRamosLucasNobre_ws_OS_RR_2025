#include <stdio.h>
#include <stdlib.h>
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
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void salvar_matriz(const char* nome_arquivo, int** matriz, int linhas, int colunas) {
    FILE* f = fopen(nome_arquivo, "w");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fprintf(f, "%d ", matriz[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

int** carregar_matriz(const char* nome_arquivo, int linhas, int colunas) {
    FILE* f = fopen(nome_arquivo, "r");
    int** matriz = alocar_matriz(linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fscanf(f, "%d", &matriz[i][j]);
        }
    }
    fclose(f);
    return matriz;
}
