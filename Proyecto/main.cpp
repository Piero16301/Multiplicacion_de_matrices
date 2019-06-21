#include <bits/stdc++.h>
#include "MiMatriz.h"

using namespace std;
using TipoDato = int;

// Tamaño máximo de la matriz Columnas y Filas
#define MAX 4

// Máximo número de hilos
#define MAX_THREAD 4

Mimatriz<TipoDato> matA(MAX,MAX);
Mimatriz<TipoDato> matB(MAX,MAX);
Mimatriz<TipoDato> matC(MAX,MAX);

int step_i = 0;

void* multi(void* arg) {
    int core = step_i++;

    // Cada hilo va a calcular 1/4 de la multiplicación
    for (int i = core * MAX / 4; i < (core + 1) * MAX / 4; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                matC.arr[i][j] += matA.arr[i][k] * matB.arr[k][j];
            }
        }
    }
}

int main() {

    //Multiplicacion con algoritmo concurrente
    cout << "ALGORITMO CONCURRENTE" << endl;

    // Se generan valores aleatorios (0-9) para las matrices A y B
    srand(time(NULL));
    clock_t inicio, fin;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matA.arr[i][j] = 1+rand()%(9+1-1);
            matB.arr[i][j] = 1+rand()%(9+1-1);
        }
    }

    // Se imprime la matriz A
    cout << endl << "Matriz A" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << setw(4) << matA.arr[i][j] << " ";
        cout << endl;
    }

    // Se imprime la matriz B
    cout << endl << "Matriz B" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << setw(4) << matB.arr[i][j] << " ";
        cout << endl;
    }

    // Se declaran los 4 hilos
    pthread_t threads[MAX_THREAD];

    // Se crean 4 hilos, cada uno calcula 1 fila del resultado
    inicio = clock();
    for (int i = 0; i < MAX_THREAD; i++) {
        int* p;
        pthread_create(&threads[i], NULL, multi, (void*)(p));
    }

    // Espera a que todos los hilos terminen
    for (int i = 0; i < MAX_THREAD; i++) {
        pthread_join(threads[i], NULL);
    }
    fin = clock();

    // Se imprime el resultado de la matriz
    cout << endl << "Multiplicacion de A y B" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << setw(4) << matC.arr[i][j] << " ";
        cout << endl;
    }

    double secs = (double)(fin-inicio)/CLOCKS_PER_SEC;
    cout << endl << "Tiempo de ejecucion de la multiplicacion: " << secs*1000 << " milisegundos" << endl << endl;

    //Multiplicacion con algoritmo NO concurrente
    cout << "ALGORITMO NO CONCURRENTE" << endl;

    //int m1_row, m1_col, m2_row, m2_col;

    clock_t t0, t1;

    /*cout << "Ingresar filas de m1: ";
    cin >> m1_row;

    cout << "Ingresar columnas de m1: ";
    cin >> m1_col;

    cout << "Ingresar filas de m2: ";
    cin >> m2_row;

    cout << "Ingresar columnas de m2: ";
    cin >> m2_col;*/

    Mimatriz<TipoDato> m1(4,4);
    Mimatriz<TipoDato> m2(4,4);

    cout << endl << "Matriz A" << endl;
    m1.llenarMatriz();
    m1.mostrarMatriz();

    cout << endl << "Matriz B" << endl;
    m2.llenarMatriz();
    m2.mostrarMatriz();

    Mimatriz<TipoDato> m3(4,4);
    t0 = clock();
    m3 = m1 * m2;
    t1 = clock();

    cout << endl << "Multiplicacion de A y B" << endl;
    m3.mostrarMatriz();

    double time = (double)(t1-t0)/CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de la multiplicacion: " << time*1000 << " milisegundos" << endl;

    return 0;
}