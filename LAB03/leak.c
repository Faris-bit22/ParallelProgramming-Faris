#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 50;

    double *numbers = malloc(size * sizeof(double));

    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        numbers[i] = i * 2.5;
    }

    printf("First 3 numbers:\n");

    for (int i = 0; i < 3; i++) {
        printf("%.2f\n", numbers[i]);
    }


    return 0;
}