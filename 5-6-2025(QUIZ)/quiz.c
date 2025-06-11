#include <stdio.h>
#include <stdlib.h>
void start(int score, int rating)
{
    char name[50];
    int ans;

    printf("\n enter your name : ");
    scanf("%s", &name);

    /*// file
    FILE *f1;

    f1 = fopen("Game", "a");
    if (f1 == NULL)
    {
        printf("ek fere to ram");
    }

    fprintf(f1, "\n name is : %s \t score is : %d ", name, score);

    fclose(f1);*/

    printf("You have entered the \"Quiz game in C Welcome to the game\" \"%s\" \n The quiz game will be started now. Get ready to answer the questions !! ALL THE BEST !!   ", name);

    if (name != NULL)
    {

        printf("\n\n   Question 1: \n  In the following given characteristics, which one is not related to the federal government ? \n\n 1. Flexible Constitution                \t 2. Written Constitution                \n 3. Independent Judiciary               \t 4. Supremacy of the Constitution ");
        printf("enter ans : ");
        scanf("%d", &ans);
        if (ans == 1)
        {
            printf("\n nice job");

            score = score + 5;
            rating += 1;
        }

        else
        {
            printf("sarkhu vach to ja pachi come back kr ");
        }

        printf("\n\n   Question 2: \n  In the following given characteristics, which one is not related to the federal government ? \n\n 1. Flexible Constitution                \t 2. Written Constitution                \n 3. Independent Judiciary               \t 4. Supremacy of the Constitution ");
        printf("enter ans : ");
        scanf("%d", &ans);
        if (ans == 2)
        {
            printf("\n nice job");

            score = score + 5;
            rating += 1;
        }

        else
        {
            printf("sarkhu vach to ja pachi come back kr ");
        }

        printf("\n\n   Question 3: \n  In the following given characteristics, which one is not related to the federal government ? \n\n 1. Flexible Constitution                \t 2. Written Constitution                \n 3. Independent Judiciary               \t 4. Supremacy of the Constitution ");
        printf("enter ans : ");
        scanf("%d", &ans);
        if (ans == 3)
        {
            printf("\n nice job");

            score = score + 5;
            rating += 1;
        }

        else
        {
            printf("sarkhu vach to ja pachi come back kr ");
        }

        printf("\n\n   Question 4: \n  In the following given characteristics, which one is not related to the federal government ? \n\n 1. Flexible Constitution                \t 2. Written Constitution                \n 3. Independent Judiciary               \t 4. Supremacy of the Constitution ");
        printf("enter ans : ");
        scanf("%d", &ans);
        if (ans == 4)
        {
            printf("\n nice job");

            score = score + 5;
            rating += 1;
        }

        else
        {
            printf("sarkhu vach to ja pachi come back kr ");
        }

        printf("\n\n   Question 5: \n  In the following given characteristics, which one is not related to the federal government ? \n\n 1. Flexible Constitution                \t 2. Written Constitution                \n 3. Independent Judiciary               \t 4. Supremacy of the Constitution ");
        printf("enter ans : ");
        scanf("%d", &ans);
        if (ans == 1)
        {
            printf("\n nice job");

            score = score + 5;
            rating += 1;
        }

        else
        {
            printf("\n sarkhu vach to ja pachi come back kr ");
        }
    }

    printf("\n Score is: %d \n", score);
    printf("\n rating is: %d \n", rating);

    FILE *f1;
    f1 = fopen("Game", "a");
    if (f1 == NULL)
    {
        printf("u need to play one time ");
    }
    else
    {

        fprintf(f1, "\n name is: %s \n", name);
        fprintf(f1, "\n score is : %d", score);
        fprintf(f1, "\n rating is: %d \n", rating);
        // fclose(f1);
    }
    fclose(f1);
}
int main()
{

    int choice, score = 0, rating = 0;

    printf("Please enter 1 to start the game \n Please enter 2 to the high scores \n Please enter 3 to seek help \n Please enter 0 to exit \n\n Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        start(score, rating);
    }

    else if (choice == 2)
    {
        int score[] = {0}, i, j, z;

        for (i = 0; i < score; i++)
        {
            for (j = 0; j < score; j++)
            {
                if (score[i] > score[j])
                {
                    z = score[i];
                    score[i] = score[j];
                    score[j] = z;
                }
            }
        }

        for (i = 0; i < score; i++)
        {
            printf("%d", score[i], score[j]);
        }

        // file
        FILE *f1;

        f1 = fopen("Game", "r");
        if (f1 == NULL)
        {
            printf("u need to play one time");
        }

        else
        {

            char ch;
            while ((ch = fgetc(f1)) != EOF)
            {
                putchar(ch);
            }
            fclose(f1);
        }
    }

    else if (choice == 3)
    {
        int user;

        printf("Instructions that are supposed to be followedwhile playing this game: \n Quiz Game in C \n ......................................................\n  You are supposed to answer 20 questions in this game !! \n  There will be 4 options given for each questions which are marked with a serial number starting from 1 to 4. \n For each correct answer, you will be awarded with 5 points !! \n As soon as you answer a question, you will be directed to the next question without any pause. \n If your answer is wrong, no marks will be deducted from your score !! \n\n !! Wish you all the best !! \n \n Do you still wish to continue playing ? If yes, then press 1. Else, press 0 : \n ");
        scanf("%d", &user);

        if (user == 1)
        {
            start(score, rating);
        }

        else
        {
            exit;
        }
    }

    else if (choice == 0)
    {

        exit(0);
    }

    else
    {
        printf("aa 4 mathi j select kr");
    }

    return 0;
}
