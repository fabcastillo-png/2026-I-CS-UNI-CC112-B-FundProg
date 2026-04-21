#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "types.h"
#include <cstddef>

void DemoMatrix1();
void CreateMatrix(TP**& matrix, size_t rows, size_t cols);
void ReadMatrix(TP** matrix, size_t rows, size_t cols);
void PrintMatrix(TP** matrix, size_t rows, size_t cols);
void DeleteMatrix(TP**& matrix, size_t rows);


#endif // __MATRIX_H__