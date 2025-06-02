#ifndef UTILS_H
#define UTILS_H

int** alocar_matriz(int linhas, int colunas);
void liberar_matriz(int** matriz, int linhas);
void preencher_matriz(int** matriz, int linhas, int colunas);
void salvar_matriz(const char* nome_arquivo, int** matriz, int linhas, int colunas);
int** carregar_matriz(const char* nome_arquivo, int linhas, int colunas);

#endif