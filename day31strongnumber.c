#include <stdio.h>

int main() {
    int num, original, remainder;
    int sum = 0, i, fact;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    while (num != 0) {
        remainder = num % 10;

        fact = 1;
        for (i = 1; i <= remain10der; i++) {
            fact = fact * i;
        }

        sum += fact;
        num /= 10;
    }

    if (sum == original)
       printf("%d is a strong Number . \n", original);
    else
      printf("%d is not a Strong Number.\n", original);

    return 0;
}