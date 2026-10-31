#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

double* create_vector(int size) {
    if (size <= 0) {
        return NULL;
    }

    double* vector = malloc(size * sizeof(double));

    return vector;
}

void fill_vector(double* vector, int size) {
    for (int i = 0; i < size; i++) {
        vector[i] = i * 2.0;
    }
}

void print_vector(double* vector, int count) {
    for (int i = 0; i < count; i++) {
        printf("%.2f\n", vector[i]);
    }
}

void free_vector(double* vector) {
    free(vector);
}