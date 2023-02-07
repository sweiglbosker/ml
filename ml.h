#include <sys/types.h>

struct Model {
    size_t nfeatures;
    double b;
    double w[];
};

/* create a linear regression model */ 
struct Model *create_model(size_t nfeatures);

/* evalute a linear function with weights w and bias b */ 
inline double evalute(int n, double *x, double *w, double b);

double cost(size_t n, size_t m, double *x, double *w, double b, double *y);

struct Model *gradient_descent(size_t n, size_t m, double *x, double *y, double w_initial,
        double b_initial, double learning_rate, size_t max_iterations)
