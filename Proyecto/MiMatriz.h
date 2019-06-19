#ifndef PROYECTO_MIMATRIZ_H
#define PROYECTO_MIMATRIZ_H

#include <iostream>

template <class T>
class Mimatriz {
    T** arr;
    int row;
    int col;

    void allocate( const int& row, const int& col )
    {
        //save
        this->row = row;
        this->col = col;

        // Allocate.
        arr = new T*[row];
        for ( int i = 0; i < row; i++ )
        {
            arr[i] = new T[col];
        }
    }

public:
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
        for (int f=0;f<this->row;f++) {
            for (int c = 0; c < this->col; c++) {
                std::cin >> arr[f][c];
            }
        }
    }
    void mostrarMatriz(){
        std::cout << "Mostrar matriz: " << std::endl;
        for (int f=0;f<this->row;f++) {
            for (int c = 0; c < this->col; c++) {
                std::cout << arr[f][c] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    Mimatriz<T> operator+(Mimatriz<T> m2){
        Mimatriz<int> m3(this->row,this->col);
        std::cout << "Ejecucion de suma: " << std::endl;
        for (int f=0;f<this->row;f++) {
            for (int c = 0; c < this->col; c++) {
                std::cout << arr[f][c] + m2.arr[f][c]<< " ";
                m3.arr[f][c] = arr[f][c] + m2.arr[f][c];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return m3;
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