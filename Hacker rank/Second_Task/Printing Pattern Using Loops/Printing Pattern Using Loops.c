#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
    
    int size = 2 * n - 1; // total rows and columns
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Minimum distance from any edge
            int minDist = i;
            if (j < minDist) minDist = j;
            if (size - 1 - i < minDist) minDist = size - 1 - i;
            if (size - 1 - j < minDist) minDist = size - 1 - j;

            printf("%d ", n - minDist);
        }
        printf("\n");
    }
    return 0;
}
