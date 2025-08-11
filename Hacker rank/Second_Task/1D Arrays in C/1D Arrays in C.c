#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);

    // Allocate dynamic array
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        // Allocation failed
        return 1;
    }

    // Read elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Print sum
    printf("%d\n", sum);

    // Free memory
    free(arr);

    return 0;
}
