#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("student.txt", "r");   //open file in read mode

    if (fp == NULL) {
        printf("File not found\n");
        return 1;
    }

    printf("Reading file content:\n\n");

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);

    return 0;
}