#include <stdio.h>

int main()
{

    int a;

    printf("enter your salary up to 20,000  :   ");
    scanf("\n %d", &a);

    if (a>=5000 &&  a <=10000)
    {
        printf(" primium = 600");
    }
    else if (a <=15000)
    {
        printf("primium = 1000;");
    }

    else if (a<=20000)
    {
       printf("primium = 1500");
    }

    else{
      printf("u need rupiya");
    }
    

    return 0;
}