#include <stdio.h>

int main() {
    int num, square, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    square = num * num;
    temp = num;

    while (temp != 0) {
        if (temp % 10 != square % 10) {
            printf("%d is not an Automorphic number.\n", num);
            return 0;
        }

        temp /= 10;
        square /= 10;
    }

    printf("%d is an Automorphic number.\n", num);

    return 0;
}