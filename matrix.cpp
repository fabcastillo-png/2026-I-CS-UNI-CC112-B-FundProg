#include "matrix.h"
#include <iostream>


using namespace std;

void DemoMatrix1(){
    size_t rows, cols;
     TP **pMat = nullptr;

    cout << "Demostracion de matrizes" << endl;
    cout << "Ingrese nro de filas: ";
    cin >> rows;
    cout << "Ingrese nro de columnas: ";
    cin >> cols;
    
     CreateMatrix(pMat, rows, cols);
     ReadMatrix(pMat, rows, cols);
     PrintMatrix(pMat, rows, cols);
     DeleteMatrix(pMat, rows);
}
void CreateMatrix(TP**& matrix, size_t rows, size_t cols) {
    matrix = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
}

void ReadMatrix(TP** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << "Ingrese [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void PrintMatrix(TP** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void DeleteMatrix(TP**& matrix, size_t rows) {
    if (matrix != nullptr) {
        for (size_t i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;
    }
}