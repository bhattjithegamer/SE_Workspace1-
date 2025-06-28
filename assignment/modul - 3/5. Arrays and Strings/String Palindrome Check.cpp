#include<iostream>
#include<string.h>
using namespace std;

int main()
{
  char string[100],rev[100];
  int i , l = 0;

  cout<<"enter any string : ";
  cin>>string;

  while (string[l] != '\0')
  {
   l++;
  }
  
  for ( i = 0; i < l; i++)
  {
   rev[i] = string[l - 1 - i];
  }

  rev [l] = '\0';

  if (strcmp(string,rev) == 0)
  {
   cout<<"it is palindrome ";
  }
  else
  {
   cout<<"it is not palindrome ";
  }
  return 0;
  
  

    
}