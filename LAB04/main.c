#include <stdio.h>
#include "vector.h"

int main() {
    int size = 10;

    // Kreiramo vektor
    double* vector = create_vector(size);

    // Provjeravamo je li memorija uspješno rezervisana
    if (vector == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Popunjavamo vektor
    fill_vector(vector, size);

    // Ispisujemo prvih 5 elemenata
    printf("First 5 elements:\n");
    print_vector(vector, 5);

    // Oslobađamo memoriju
    free_vector(vector);

    return 0;
}