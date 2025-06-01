#include <stdio.h>

int main()
{

    char email[50];
    int password = 123 ;

    char id[50];
    

    strcpy(id, "sbha6482@gmail.com");

    printf("enter your email");
    scanf("%s", &email);

    printf("enter your password");
    scanf("%d", &password);

    printf("\n this is your email %s", email);
    printf("\n this is your pass %d  ", password);

    if (strcmp(id, email) == 0)
    {

        if (password == 123)
    {
         printf("correct");
    }

    else
    {
        printf("incorect pass");
    }
    }

    else
    {
        printf("email is incorrect");
    }

    
    
    return 0;
}