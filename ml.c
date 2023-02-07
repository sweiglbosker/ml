#include <stdlib.h>

#include "ml.h"
#include "matrix.h"

struct Model *create_model(size_t nfeatures) 
{
    struct Model *model = malloc(sizeof(*model) + (sizeof(double) * nfeatures)); 
    model->nfeatures = nfeatures;

    return model;
}

inline double evalute(int n, double *x, double *w, double b) 
{
   return (dot_product(n, x, w) + b); 
}

double cost(size_t n, size_t m, double **x, double *w, double b, double *y)
{
    double cost = 0.0;
    for (int i = 0; i < m; i++) {
        double d = evalute(n, x[i], w, b) - y[i];
        cost += d * d;
    }
    return (1.0/(2.0 * m)) * cost; 
}

struct Model *gradient_descent(size_t n, size_t m, double *x, double *y, double w_initial,
        double b_initial, double learning_rate, size_t max_iterations)
{
    struct Model *model = create_model(n);

    
    return model;
}
