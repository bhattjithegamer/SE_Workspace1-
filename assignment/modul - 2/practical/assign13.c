#include <stdio.h>

int main()
{
    FILE *fp;
    char str[100];

    fp = fopen("shubham.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Enter a string to write into the file: ");
    gets(str);

    fprintf(fp, "%s", str);
    fclose(fp);

    fp = fopen("myfile.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("\nContents of the file:\n");

    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);

    return 0;
}
