#include <stdio.h>

int main()
{
    char str1[] = "Good Morning";
    char str2[20];
    stringCopy(str2, str1);
    printf("Copied string: %s\n", str2);

    char str3[] = " World";
    stringConcat(str2, str3);
    printf("Concatenated string: %s\n", str2);

    printf("Length of str2: %d\n", stringLength(str2));

    char str4[] = "Hello Bhatt Ji";
    printf("Comparison result: %d\n", stringCompare(str2, str4));

    stringReverse(str2);
    printf("Reversed string: %s\n", str2);

    return 0;
}