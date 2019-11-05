#include <stdio.h>
#include <math.h>
#include "vector_operations.h"

int q1() {
    double testArray[] = {1,2,3,4,5};
    double testArray2[] = {5,4,3,2,1};
    print_vector(testArray, 5);
    printf("Scalar Prod: %lf\n", scalar_prod(testArray, testArray2, 5));
    printf("Norm2: %lf", norm2(testArray, 5));
    return 0;
}


void print_vector(double array[], int size){
    printf("Printing vector: ");
    for (int i = 0; i < size; ++i) { //iterate through size of array
        printf("%lf", array[i]); //print element i
        if(i != size-1) //dont print comma if last element
            printf(", ");
    }
    printf("\n");
}

void add_vectors( double vector1[], double vector2[], double vector3[], int n) {
    for (int i = 0; i < n; ++i) {   //iterates through size of array
        vector3[i] = vector1[i] + vector2[i]; //add elements of vectors togethers
    }
}

double scalar_prod(double vector1[], double vector2[], int n){
    double sum = 0;
    for (int i = 0; i < n; ++i) { //iterates through size of array
        sum += vector1[i]*vector2[i]; //add product of each component to sum
    }
    return sum;
}

double norm2(double vector1[], int n){
    return sqrt(scalar_prod(vector1, vector1, n)); //takes the square root of the scalar product of itself
}
