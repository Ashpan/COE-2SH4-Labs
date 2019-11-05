#include <stdio.h>
#include <math.h>
#include "vector_operations.h"

int main() {
    double testArray[] = {0,2.3,4.5,6};
    double testArray2[] = {8.45, 4.64544, 45.5,6};
    print_vector(testArray, 4);
    printf("%lf\n", scalar_prod(testArray, testArray2, 4));
    printf("%lf", norm2(testArray, 4));
    return 0;
}


void print_vector(double array[], int size){
    for (int i = 0; i < size; ++i) {
        printf("%lf", array[i]);
        if(i != size-1)
            printf(", ");
    }
    printf("\n");
}

void add_vectors( double vector1[], double vector2[], double vector3[], int n) {
    for (int i = 0; i < n; ++i) {
        vector3[i] = vector1[i] + vector2[i];
    }
}

double scalar_prod(double vector1[], double vector2[], int n){
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += vector1[i]*vector2[i];
    }
    return sum;
}

double norm2(double vector1[], int n){
    return sqrt(scalar_prod(vector1, vector1, n));
}
