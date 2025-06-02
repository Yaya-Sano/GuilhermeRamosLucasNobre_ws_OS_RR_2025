#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "utils.h"

typedef struct {
    int id;
    int n;
    int num_threads;
    int** A;
    int** B;
    int** C;
} ThreadArgs;

void* multiplicar_linha(void* arg) {
    ThreadArgs* args = (ThreadArgs*) arg;
    int tid = args->id;
    int n = args->n;
    int num_threads = args->num_threads;

    for (int i = tid; i < n; i += num_threads) {
        for (int j = 0; j < n; j++) {
            args->C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                args->C[i][j] += args->A[i][k] * args->B[k][j];
            }
        }
    }
    return NULL;
}

double tempo_execucao(struct timeval inicio, struct timeval fim) {
    return (double)(fim.tv_sec - inicio.tv_sec) + (double)(fim.tv_usec - inicio.tv_usec) / 1e6;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Uso: %s <tamanho> <num_threads>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int num_threads = atoi(argv[2]);

    if (num_threads < 1) {
        printf("Número de threads deve ser >= 1\n");
        return 1;
    }

    int** A = alocar_matriz(n, n);
    int** B = alocar_matriz(n, n);
    int** C = alocar_matriz(n, n);

    preencher_matriz(A, n, n);
    preencher_matriz(B, n, n);

    pthread_t* threads = malloc(num_threads * sizeof(pthread_t));
    ThreadArgs* args = malloc(num_threads * sizeof(ThreadArgs));

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for (int i = 0; i < num_threads; i++) {
        args[i].id = i;
        args[i].n = n;
        args[i].num_threads = num_threads;
        args[i].A = A;
        args[i].B = B;
        args[i].C = C;

        pthread_create(&threads[i], NULL, multiplicar_linha, (void*) &args[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&fim, NULL);
    printf("Tempo paralelo (%d threads): %.6f segundos\n", num_threads, tempo_execucao(inicio, fim));

    liberar_matriz(A, n);
    liberar_matriz(B, n);
    liberar_matriz(C, n);

    free(threads);
    free(args);

    return 0;
}
