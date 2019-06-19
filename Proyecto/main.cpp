#include <bits/stdc++.h>
using namespace std;

// Tamaño máximo de la matriz
#define MAX 4

// Máximo número de hilos
#define MAX_THREAD 4

int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i = 0;

void* multi(void* arg) {
    int core = step_i++;

    // Cada hilo va a calcular 1/4 de la multiplicación
    for (int i = core * MAX / 4; i < (core + 1) * MAX / 4; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main() {
    // Se generan valores aleatorios (0-9) para las matrices A y B
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matA[i][j] = rand() % 10;
            matB[i][j] = rand() % 10;
        }
    }

    // Se imprime la matriz A
    cout << endl
         << "Matrix A" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << matA[i][j] << " ";
        cout << endl;
    }

    // Se imprime la matriz B
    cout << endl
         << "Matrix B" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << matB[i][j] << " ";
        cout << endl;
    }

    // Se declaran los 4 hilos
    pthread_t threads[MAX_THREAD];

    // Se crean 4 hilos, cada uno calcula 1 fila del resultado
    for (int i = 0; i < MAX_THREAD; i++) {
        int* p;
        pthread_create(&threads[i], NULL, multi, (void*)(p));
    }

    // Espera a que todos los hilos terminen
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);

    // Se imprime el resultado de la matriz
    cout << endl
         << "Multiplication of A and B" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << matC[i][j] << " ";
        cout << endl;
    }
    return 0;
}