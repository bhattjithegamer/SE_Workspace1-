#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindromeString(char str[])
{
    int i = 0, j = strlen(str) - 1;

    while (i < j)
    {

        while (!isalnum(str[i]) && i < j)
            i++;
        while (!isalnum(str[j]) && i < j)
            j--;

        if (tolower(str[i]) != tolower(str[j]))
            return 0;

        i++;
        j--;
    }

    return 1;
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    if (isPalindromeString(str))
        printf("\"%s\" is a palindrome string.\n", str);
    else
        printf("\"%s\" is not a palindrome string.\n", str);

    return 0;
}
