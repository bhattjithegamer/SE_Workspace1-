#include <stdio.h>

int main()
{
    FILE *fp;
    char text[100] = "Hello! This is a file handling example in C.";
    char buffer[100];

    fp = fopen("myfile.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file for writing.\n");
        return 1;
    }

    fprintf(fp, "%s", text);
    fclose(fp);

    printf("Data written to file successfully.\n");

    fp = fopen("myfile.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("\nReading data from file:\n");

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fp);
    return 0;
}
