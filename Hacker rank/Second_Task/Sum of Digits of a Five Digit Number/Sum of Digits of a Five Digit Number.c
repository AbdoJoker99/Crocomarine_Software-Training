#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);

    while (n > 0) {
        sum += n % 10; // Add last digit
        n /= 10;       // Remove last digit
    }

    printf("%d", sum);
    return 0;
}
