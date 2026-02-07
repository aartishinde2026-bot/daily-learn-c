#include <stdio.h>

int main() {
    FILE *fd;
    char text[100];

    fd = fopen("data.txt", "w");

    if (fd == NULL) {
        printf("File could not be created.\n");

        return 0;
    }

    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);

    fputs(text, fd);

    fclose(fd);

    printf("Data written to file successfully.\n");

    return 0;
}