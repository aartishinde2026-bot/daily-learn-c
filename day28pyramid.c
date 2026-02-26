#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        //print spaces
        for (j = 1; j <= n-1; j++) {
            printf(" ");
        }

        //print numbers increasing
        for (k = 1; k <= i; k++) {
            printf("%d", k);
        }

        //print number decresing
        for (k = i - 1; k >= 1; k--) {
            printf("%d", k);
        }
        printf("\n");
    }
    return 0;
}