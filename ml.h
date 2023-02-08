#include <sys/types.h>
 
/* 
 * notation: 
 * n = number of features 
 * m = number of training examples  
 * w = weight
 * b = bias 
 * j = cost function
 */

struct Model {
        size_t n;
        double b;
        double w[];
};

/* 
 * structure that stores partial derivates of cost with respect to parameters 
 * (for gradient descent algorithm) 
 */
struct Gradient {
        size_t n;
        double dj_db;
        double dj_dw[];
};

struct Gradient *alloc_gradient(size_t n);

/* create a linear regression model */ 
struct Model *alloc_model(size_t n);

/* evalute a linear function with weights w and bias b */ 
inline double evalute(int n, double *x, double *w, double b);

double cost(size_t n, size_t m, double *x, double *w, double b, double *y);

struct Gradient *compute_gradient(size_t n, size_t m, double *x, double *y, double *w, double b);

struct Model *gradient_descent(size_t n, size_t m, double *x, double *y, double w_initial,
                double b_initial, double learning_rate, size_t max_iterations);
