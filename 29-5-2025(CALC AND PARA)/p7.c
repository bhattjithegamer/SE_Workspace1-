#include <stdio.h>

int self()
{
    int a = 5;
    int b = 10;
    int c = a + b;
    return c;
}

int main()
{

    printf("%d",self());
    return 0;
}