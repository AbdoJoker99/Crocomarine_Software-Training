#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);

    // Array for English words for numbers 1 to 9
    char *numbers[] = {
        "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"
    };

    for (int i = a; i <= b; i++) {
        if (i >= 1 && i <= 9) {
            printf("%s\n", numbers[i - 1]); // Index starts at 0
        } else {
            if (i % 2 == 0)
                printf("even\n");
            else
                printf("odd\n");
        }
    }

    return 0;
}
