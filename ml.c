#include <stdlib.h>

#include "ml.h"

struct Model *create_model(size_t nfeatures) 
{
    struct Model *model = malloc(sizeof(*model) + (sizeof(double) * nfeatures)); 
    model->nfeatures = nfeatures;

    return model;
}


struct Model *gradient_descent
(double **x, double *y, size_t nfeatures, size_t m, double w_initial,
double b_initial, double learning_rate, size_t max_iterations) 
{
    struct Model *model = create_model(nfeatures);


    return model;
}
