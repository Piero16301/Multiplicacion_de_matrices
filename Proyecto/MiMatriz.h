#ifndef PROYECTO_MIMATRIZ_H
#define PROYECTO_MIMATRIZ_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

template <class T>
class Mimatriz {

public:
    T** arr;
    int row;
    int col;

    void allocate( const int& row, const int& col ) {
        //save
        this->row = row;
        this->col = col;

        // Allocate.
        arr = new T*[row];
        for ( int i = 0; i < row; i++ ) {
            arr[i] = new T[col];
        }
    }

    Mimatriz() : arr{nullptr}, row{0}, col{0} {
        std::cout << "Template de clase generica" << std::endl;
    }

    Mimatriz(const int& row, const int& col ){
        allocate(row, col);
    }

    T get_column() {
        //std::cout << "hello col" << std::endl;
        return this->col;
    }

    T get_row() {
        return this->row;
    }

    void llenarMatriz(){
        srand(time(NULL));
        int num = 0;
        for (int f=0;f<this->row;f++) {
            for (int c = 0; c < this->col; c++) {
                num = 1+rand()%(9+1-1); //Numeros aleatorios entre 1 y 9
                //std::cout << "M[" << f << "][" << c << "]: " << num << std::endl;
                arr[f][c] = num;
                //std::cin >> arr[f][c];
            }
        }
    }

    void mostrarMatriz(){
        for (int f=0;f<this->row;f++) {
            for (int c = 0; c < this->col; c++) {
                std::cout << std::setw(4) << arr[f][c] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    Mimatriz<T> operator*(Mimatriz<T> m2) {
        Mimatriz<T> m3(this->row, this->col);
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                for (int k = 0; k < this->row; k++) {
                    m3.arr[i][j] += arr[i][k] * m2.arr[k][j];
                }
            }
        }
        return m3;
    }

    ~Mimatriz() {
        /*for (int i = 0; i < row; i++)
            delete arr[i];
        delete [] arr;*/
    }

};

template <class T>
bool verifica(T m1, T m2) {
    int row_m1 = m1.get_row();
    int col_m1 = m1.get_column();
    int row_m2 = m2.get_row();
    int col_m2 = m2.get_column();
    return row_m1 == row_m2 && col_m1 == col_m2;
}

#endif //PROYECTO_MIMATRIZ_H