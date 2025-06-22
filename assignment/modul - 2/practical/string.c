#include <stdio.h>
#include <string.h>

void reverseString(char *str)
{
  int length = strlen(str);
  int i, j;
  char change;
  for (i = 0, j = length - 1; i < j; i++, j--)
  {
    change = str[i];
    str[i] = str[j];
    str[j] = change;
  }
}

int main()
{
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);
  reverseString(str);
  printf("Reversed string: %s\n", str);
  return 0;
}