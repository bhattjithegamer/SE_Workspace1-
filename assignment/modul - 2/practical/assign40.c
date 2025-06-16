#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    const int MAX_ATTEMPTS = 7; 
    srand(time(0)); 

    number = (rand() % 100) + 1; 

    printf("🎮 Welcome to the Number Guessing Game!\n");
    printf("Guess the number between 1 and 100\n");
    printf("You have %d attempts.\n\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == number) {
            printf("🎉 Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        } else if (guess < number) {
            printf("📉 Too low! Try a higher number.\n");
        } else {
            printf("📈 Too high! Try a lower number.\n");
        }

        printf("Attempts left: %d\n\n", MAX_ATTEMPTS - attempts);
    }

    if (attempts == MAX_ATTEMPTS && guess != number) {
        printf(" Out of attempts! The number was: %d\n", number);
    }

    return 0;
}
