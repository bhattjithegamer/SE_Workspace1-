#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int i = 0, word_count = 0, length = 0;
    char longest_word[50], current_word[50];

    printf("Enter a sentence: ");
    scanf(" %[^\n]", str); 

    int max_len = 0, curr_index = 0;

    while (1) {
        char ch = str[i];

       
        if (ch != ' ' && ch != '\0') {
            current_word[curr_index++] = ch;
        } else {
            if (curr_index > 0) {
                current_word[curr_index] = '\0';  
                word_count++;

                if (curr_index > max_len) {
                    max_len = curr_index;
                    strcpy(longest_word, current_word);
                }

                curr_index = 0;
            }
        }

        if (ch == '\0') break;
        i++;
    }

   
    printf("\nTotal words: %d\n", word_count);
    printf("Longest word: %s (Length: %d)\n", longest_word, max_len);

    return 0;
}
