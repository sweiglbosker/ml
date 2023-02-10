#include <stdlib.h>
#include <string.h>

#include "ml.h"
#include "matrix.h"

struct Model *alloc_model(size_t n) 
{
        struct Model *model = malloc(sizeof(*model) + (sizeof(double) * n)); 
        model->n = n;

        memset(model + sizeof(*model), 0, sizeof(double) * n);
        return model;
}

struct Gradient *alloc_gradient(size_t n) 
{
        struct Gradient *gradient = malloc(sizeof(*gradient) + (sizeof(double) * n));
        gradient->n = n;
        
        memset(gradient + sizeof(*gradient), 0, sizeof(double) * n);
        return gradient;
}

inline double evalute(int n, double *x, double *w, double b) 
{
        return (dot_product(n, x, w) + b); 
}

double cost(size_t n, size_t m, double *x, double *w, double b, double *y)
{
        double cost = 0.0;
        for (int i = 0; i < m; i++) {
                double d = evalute(n, &(x[i*n]), w, b) - y[i];
                cost += d * d;
        }
        return (1.0/(2.0 * m)) * cost; 
}

struct Gradient *compute_gradient(size_t n, size_t m, double *x, double *y, double *w, double b, struct Gradient *gradient)
{
	if (gradient->n != n)
		return NULL;

        for (int i = 0; i < m; i++) {
                double d = evalute(n, &(x[i * n]), w, b) - y[i];

                for (int j = 0; j < n; j++)
                        gradient->dj_dw[j] += d * x[i * j];

                gradient->dj_db += d;
        }

        for (int i = 0; i < n; i++)
                gradient->dj_dw[i] /= m;

        gradient->dj_db /= m;
        return gradient;
}

struct Model *gradient_descent(size_t n, size_t m, double *x, double *y, double w_initial, 
                double b_initial, double learning_rate, size_t max_iterations)
{
        struct Model *model = alloc_model(n);
        struct Gradient *gradient = alloc_gradient(n);
        
        matrix_fill(n, w_initial, model->w); 
        model->b = b_initial;

        for (int i = 0; i < max_iterations; i++) {
                compute_gradient(n, m, x, y, model->w, model->b, gradient); 
                model->w -= matrix_mul_scalar(gradient->dj_dw, learning_rate, n);
                model->b -= learning_rate * gradient->dj_db;
        }
        return model;
}
