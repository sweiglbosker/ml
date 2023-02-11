#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

double *alloc_matrix(size_t rows, size_t cols)
{
        return calloc(rows * cols, sizeof(double));
}

double *matrix_from_array(size_t rows, size_t cols, double arr[rows][cols])
{
        double *matrix = alloc_matrix(rows, cols);
    
        for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++)
                         matrix[(row * cols) + col] = arr[row][col];
        }
        
        return matrix;
}

void vector_fill(double *matrix, double value, size_t n)
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
void vector_mul(double *a, double *b, size_t n)
{
        for (int i = 0; i < n; i++)
                a[i] *= b[i]; 
}

void vector_mul_scalar(double *matrix, double scalar, int n)
{
        for (int i = 0; i < n; i++)
                matrix[i] *= scalar;
}

void vector_sub(double *a, double *b, size_t n) {
        for (int i = 0; i < n; i++) 
                a[i] -= b[i];
}

void print_matrix(double *matrix, size_t nrows, size_t ncols)
{
        for (int i = 0; i < nrows; i++) {
                printf("[%i] | ", i);
                for (int j = 0; j < ncols; j++)
                        printf(" %lf ", matrix[(i * ncols) + j]);

                putchar('\n');
        }
}

void print_vector(double *vector, size_t size)
{
        for (int i = 0; i < size; i++) 
                printf(" %lf ", vector[i]);
}

