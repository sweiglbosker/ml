#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "ml.h"

#define NFEATURES 2 
#define DATA_SIZE 5

int main(int argc, char *argv[])
{
    double x_data[NFEATURES][DATA_SIZE] = {
        { 2104, 1600, 2400, 1416, 3000 },
        { 3,    3,    3,    2,    4,  }
    };
   

    double *x = matrix_from_array(NFEATURES, DATA_SIZE, x_data);
    double y_data[DATA_SIZE] = { 399900, 329900, 369000, 232000, 539900 };
    


    struct Model *model = gradient_descent(NFEATURES, DATA_SIZE, x, y_data,  0, 0, 0.05, 1000);
    free(model);
}
