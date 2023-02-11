#include <sys/types.h>

double *alloc_matrix(size_t rows, size_t cols); 

void print_matrix(double *matrix, size_t nrows, size_t ncols);

void print_vector(double *vector, size_t size);

/* 
 * creates a contiguous matrix from 2d array (double[][] || double **) 
 * might seem like overhead, but will be useful for extendable backends. 
 */
double *matrix_from_array(size_t rows, size_t cols, double arr[rows][cols]);

void vector_fill(double *matrix, double value, size_t n);

void vetor_mul(double *a, double *b, size_t n);

void vector_mul_scalar(double *matrix, double scalar, int n);

void vector_sub(double *a, double *b, size_t n);

double dot_product(size_t n, double *x, double *y);


