#include <sys/types.h>

inline double *alloc_matrix(size_t rows, size_t cols); 

/* 
 * creates a contiguous matrix from 2d array (double[][] || double **) 
 * might seem like overhead, but will be useful for extendable backends. 
 */
double *matrix_from_array(size_t rows, size_t cols, double arr[rows][cols]);

double dot_product(size_t n, double *x, double *y);
