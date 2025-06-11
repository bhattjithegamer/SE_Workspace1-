#include<stdio.h>

int main(){
    char c;
    FILE *f1;
    f1 = fopen("shubham ", "r");
   while ((c = getc(f1))!=EOF)

   {
    
   printf("%c",c);
   }
   
fclose(f1);
    return 0;
}