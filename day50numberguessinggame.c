#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;

    //Random number generate
    srand(time(0));
    number = rand() % 100 + 1;

    printf("Number Guessing Game\n");
    printf("Guess a number between 1 to 100\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess > number) {
            printf("Too high!\n");
        }
        else if (guess > number) 
        {
            printf("Too low!\n");
        } else {
            printf("Correct! you guessed in %d attempts.\n, attempts");
        }
    } while (guess != number);

    return 0;
}