#include <stdio.h>
#include <string.h>

int main() {
    char text[200], word[50];
    int i, found = 0;

    printf("Enter a sentence: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter word to search: ");
    scanf("%s", word);

    char *ptr = strstr(text, word);

    if (ptr != NULL) {
        printf("Word found in the sentence.\n");
    } else {
        printf("Word not found.\n");
    }

    return 0;
}