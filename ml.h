#include <sys/types.h>

struct Model {
    size_t nfeatures;
    double b;
    double w[];
};

/* create a linear regression model */ 
struct Model *create_model(size_t nfeatures);

struct Model *gradient_descent
(double **x, double *y, size_t nfeatures, size_t m, double w_initial,
double b_initial, double learning_rate, size_t max_iterations);
