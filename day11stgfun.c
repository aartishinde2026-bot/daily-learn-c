#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50];

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);

    //remove newline character
    str1[strcspn(str1, "\n")] = '\0';

    //string leangth
    printf("Lenght of string: %lu\n",strlen(str1));

    //string copy
    strcpy(str2, str1);

    printf("Copied string: %s\n", str2);

    return 0;
}