#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Number, guess, attempts = 0, Attempts = 7;

    srand(42);

    Number = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n\n", Attempts);

    while (attempts < Attempts)
    {
        printf("Attempt %d: Enter your guess: ", attempts + 1);
        scanf("%d", &guess);
        attempts++;

        if (guess == Number)
        {
            printf("Congratulations! You guessed the correct number %d in %d attempts!\n", Number, attempts);
            break;
        }
        else if (guess < Number)
        {
            printf("Too low! Try a higher number.\n");
        }
        else
        {
            printf("Too high! Try a lower number.\n");
        }
    }

    if (guess != Number)
    {
        printf("\nSorry! You've used all %d attempts. The number was %d.\n", Attempts, Number);
    }

    return 0;
}
