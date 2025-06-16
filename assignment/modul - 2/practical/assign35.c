#include <stdio.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0, digits = 0, specials = 0;
    int i;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);  

    for (i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' || ch == 'A' ||
            ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowels++;
        }

       
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            consonants++;
        }

        
        else if (ch >= '0' && ch <= '9') {
            digits++;
        }

       
        else {
            specials++;
        }
    }

    
    printf("\nVowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", specials);

    return 0;
}
