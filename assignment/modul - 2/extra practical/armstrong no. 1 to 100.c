#include <stdio.h>
#include <math.h>

int main()
{
    int number, oNum, remainder, final, n;

    printf("Armstrong numbers between 1 and 1000 are:\n");

    for (number = 1; number <= 1000; number++)
    {
        oNum = number;
        final = 0;
        n = 0;

        int temp = oNum;
        while (temp != 0)
        {
            temp /= 10;
            n++;
        }

        temp = oNum;
        while (temp != 0)
        {
            remainder = temp % 10;
            final += pow(remainder, n);
            temp /= 10;
        }

        if (final == oNum)
        {
            printf("%d ", oNum);
        }
    }

    printf("\n");
    return 0;
}