#include <stdio.h>

int main() {
    int num, i, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += 1;
        }
    }

    if (sum == num && num !=0)
       printf("%d is a prefect Number . \n", num);
    else
       printf("%d is not a prefect Number. \n", num);

    return 0;
}