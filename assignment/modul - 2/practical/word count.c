#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], word[50], longest[50] = "";
    int i = 0, j = 0, wordCount = 0, maxLen = 0;

    printf("Enter a sentence: ");
    gets(str);

    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\0')
        {
            word[j++] = str[i];
        }
        if (str[i] == ' ' || str[i + 1] == '\0')
        {
            word[j] = '\0';
            wordCount++;

            if (strlen(word) > maxLen)
            {
                maxLen = strlen(word);
                strcpy(longest, word);
            }
            j = 0;
        }
        i++;
    }

    printf("Total number of words: %d\n", wordCount);
    printf("Longest word: %s (Length: %d)\n", longest, maxLen);

    return 0;
}
