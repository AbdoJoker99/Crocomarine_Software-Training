#include <stdio.h>
#include <stdlib.h>

void showPointer() {
    int a = 10;
    int *ptr = &a;

    printf("\n--- Pointer Example ---\n");
    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", &a);
    printf("Pointer ptr holds: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);
}

int main() {
  
    int age = 0;
    float score = 0.0;
    char grade = 'A';
    char name[30];

  
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your score: ");
    scanf("%f", &score);

  
    printf("\n--- Your Info ---\n");
    printf("Name: %s", name); 
    printf("Age: %d\n", age);
    printf("Score: %.2f\n", score);
    printf("Grade: %c\n", grade);

  
    if (score >= 50) {
        printf("Status: Pass\n");
    } else {
        printf("Status: Fail\n");
    }


    printf("\n--- Counting 1 to 5 ---\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");


    int numbers[3] = {10, 20, 30};
    printf("\n--- Array Example ---\n");
    for (int i = 0; i < 3; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

  
    showPointer();

    return 0;
}
