#include <stdio.h>
#include <stdlib.h>

#include "ml.h"


#define NFEATURES 2 
#define DATA_SIZE 5

int main(int argc, char *argv[])
{
    double x_data[NFEATURES][DATA_SIZE] = {
    /* size in square feet */                   { 2104, 1600, 2400, 1416, 3000 },
    /* number of bedrooms */                    { 3,    3,    3,    2,    4,  }
                                             };

    double y_data[DATA_SIZE] = { 399900, 329900, 369000, 232000, 539900 };
    


    struct Model *model = gradient_descent(x_data, y_data, NFEATURES, DATA_SIZE, 0, 0, 0.05, 1000);
    free(model);
}
