#include<iostream>
#include<string.h>
using namespace std;

int main()
{
  char string[100],revstring[100];
  int i , length = 0;

  cout<<"enter any string : ";
  cin>>string;

  while (string[length] != '\0')
  {
   length++;
  }
  
  for ( i = 0; i < length; i++)
  {
   revstring[i] = string[length - 1 - i];
  }

  revstring [length] = '\0';

  if (strcmp(string,revstring) == 0)
  {
   cout<<"the given string is palindrome ";
  }
  else
  {
   cout<<"the given string is not palindrome ";
  }
  return 0;
  
  

    
}