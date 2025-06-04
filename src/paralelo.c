#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "utils.h"

#define MAX_THREADS 8

typedef struct {
    int id;
    int n;
    int** A;
    int** B;
    int** C;
} ThreadArgs;

void* multiplicar_linha(void* arg) {
    ThreadArgs* args = (ThreadArgs*) arg;
    int tid = args->id;
    int n = args->n;

    for (int i = tid; i < n; i += MAX_THREADS) {
        for (int j = 0; j < n; j++) {
            args->C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                args->C[i][j] += args->A[i][k] * args->B[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

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

    pthread_t threads[MAX_THREADS];
    ThreadArgs args[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        args[i].id = i;
        args[i].n = n;
        args[i].A = A;
        args[i].B = B;
        args[i].C = C;
    }

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, multiplicar_linha, (void*) &args[i]);
    }
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&fim, NULL);
    printf("Tempo paralelo (8 threads): %f segundos\n", tempo_execucao(inicio, fim));

    liberar_matriz(A, n);
    liberar_matriz(B, n);
    liberar_matriz(C, n);

    return 0;
}