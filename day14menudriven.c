#include <stdio.h>

int main() {
    int choice;
    int a, b;

    printf("-----Menu-----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 4) {
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
    }

    switch (choice) {
        case 1:
            printf("Addition = %d\n", a + b);
            break;

        case 2:
            printf("Subtraction = %d\n", a - b);
            break;

        case 3:
            printf("Multiplication = %d\n", a * b);
            break;

        case 4:
           if (b != 0)
               printf("Division = %d\n", a / b);

           else
               printf("Division by zero not allowed\n");
            break;
            
        case 5:
           printf("Exiting program...\n");
           break;

        default:
           printf("Invalid choice\n");
    }

    return 0;
}