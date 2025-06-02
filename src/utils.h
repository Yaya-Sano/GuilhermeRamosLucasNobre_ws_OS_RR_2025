#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

int** alocar_matriz(int linhas, int colunas);
void liberar_matriz(int** matriz, int linhas);
void preencher_matriz(int** matriz, int linhas, int colunas);
bool comparar_matrizes(int** A, int** B, int linhas, int colunas);

#endif // UTILS_H
