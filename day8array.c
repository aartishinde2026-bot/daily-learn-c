#include <stdio.h>

int main() {
    int number[5];
    int i;

    printf("Enter 5 number:\n");

    for (i = 0; i < 5; i++){
        scanf("%d", &number[i]);
    }

    printf("You entered:\n");

    for (i = 0; i < 5; i++) {
        printf("%d\n", number[i]);
    }

    return 0;
}