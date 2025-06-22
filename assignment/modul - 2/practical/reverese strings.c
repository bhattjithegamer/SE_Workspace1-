#include <stdio.h>

void reverseString(char str[])
{
    int l = 0, i;
    char a;

    while (str[l] != '\0')
    {
        l++;
    }

    for (i = 0; i < l / 2; i++)
    {
        a = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = a;
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    gets(str);

    reverseString(str);

    printf("Reversed String: %s\n", str);

    return 0;
}
