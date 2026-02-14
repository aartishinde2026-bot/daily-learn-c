#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *ptr;
    int sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    //Allocate memory dynamically
    ptr = (int *)malloc(n *sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    for (i = 0; i < n; i++) {
        sum += ptr[i];
    }

    printf("Sum = %d\n", sum);

    free(ptr);  //free memory

    return 0;
}