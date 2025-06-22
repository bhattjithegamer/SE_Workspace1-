#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_num_palindrome(int n)
{
    int rev = 0, a = n;
    while (a != 0)
    {
        rev = rev * 10 + a % 10;
        a /= 10;
    }
    return (rev == n);
}

bool is_str_palindrome(char str[])
{
    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    int num;
    char str[100];

    printf("Enter a number to check palindrome: ");
    scanf("%d", &num);
    if (is_num_palindrome(num))
        printf("%d is a Palindrome Number.\n", num);
    else
        printf("%d is NOT a Palindrome Number.\n", num);

    printf("\nEnter a string to check palindrome: ");
    scanf("%s", str);
    if (is_str_palindrome(str))
        printf("\"%s\" is a Palindrome String.\n", str);
    else
        printf("\"%s\" is NOT a Palindrome String.\n", str);

    return 0;
}
