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

double dot_product(size_t n, double *x, double *y)
{
        double dot = 0.0;
      
        for (int i = 0; i < n; i++)
                dot += x[i] * y[i];

        return dot;
}
