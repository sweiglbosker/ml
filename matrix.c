#include <stdlib.h>
#include <string.h>

#include "matrix.h"

inline double *alloc_matrix(size_t rows, size_t cols)
{
        return calloc(rows * cols, sizeof(double));
}

double *matrix_from_array(size_t rows, size_t cols, double arr[rows][cols])
{
        double *matrix = alloc_matrix(rows, cols);

        if (!matrix)
                return NULL;
    
        for (int row = 0; row < rows; row++)
                memcpy(matrix, arr[row * cols], cols);

        return matrix;
}

void matrix_fill(double *matrix, double value, size_t n)
{
        for (int i = 0; i < n; i++) {
                matrix[n] = value;
        }
}

double dot_product(size_t n, double *x, double *y)
{
        double dot = 0.0;
      
        for (int i = 0; i < n; i++)
                dot += x[i] * y[i];

        return dot;
}

/* OVERWRITES a WITH PRODUCT (maybe be more clear?) */ 
void matrix_mul(double *a, double *b, size_t n)
{
        for (int i = 0; i < n; i++)
                a[i] *= b[i]; 
}

void matrix_mul_scalar(double *matrix, double scalar, int n)
{
        for (int i = 0; i < n; i++)
                matrix[i] *= scalar;
}
