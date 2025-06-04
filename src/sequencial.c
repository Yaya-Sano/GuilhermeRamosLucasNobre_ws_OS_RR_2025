#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "utils.h"

double tempo_execucao(struct timeval inicio, struct timeval fim) {
    return (double)(fim.tv_sec - inicio.tv_sec) + (double)(fim.tv_usec - inicio.tv_usec) / 1e6;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamanho>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int** A = carregar_matriz("A.txt", n, n);
    int** B = carregar_matriz("B.txt", n, n);
    int** C = alocar_matriz(n, n);

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    gettimeofday(&fim, NULL);
    printf("Tempo sequencial: %f segundos\n", tempo_execucao(inicio, fim));

    liberar_matriz(A, n);
    liberar_matriz(B, n);
    liberar_matriz(C, n);

    return 0;
}
