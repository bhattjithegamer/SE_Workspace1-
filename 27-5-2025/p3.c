#include <stdio.h>

int main()
{

    int a;

    printf("enter up to 50000");
    scanf("%d", &a);

    if (a >= 40000)
    {
        printf("u got mac");

        if (a >= 40000)
        {
            printf("u got keboard free");
        }
        goto shubham;
    }

    
    else if (a >= 30000)

    {
        printf("u got leptop");

        if (a >= 30000)
        {
            printf("u got mousse free");
           
        }
    }

    else if (a >= 20000)
    {
        printf("u got watch");

        if (a >=20000)
        {
            printf("u hot buds free");
        }
    }

    else
    {
        printf("nothing to see there");
    }

     shubham:printf("u got mouse free");

    return 0;
}