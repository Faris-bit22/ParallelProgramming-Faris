#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 10;
    int *arr = malloc(n * sizeof(int));

    if (arr == NULL) {
        return 1;
    }
    arr[0] = 0;

    printf("First element: %d\n", arr[0]);


    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    printf("Last element: %d\n", arr[n - 1]);

    free(arr);

    return 0;
}