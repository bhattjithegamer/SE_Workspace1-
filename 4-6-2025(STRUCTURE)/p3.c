#include <stdio.h>

struct a10
{
    char name[50];
    char surname[50];
};

struct a11
{
    char add[50];
    int pin;
    struct a10 a;
} a1[50];

int main()
{
    int i, user;

    printf("enter how many u want : ");
    scanf("%d", &user);

    for (i = 0; i < user; i++)
    {
        printf("\n enter ur name : ");
        scanf("%s", &a1[i].a.name);

        printf("\n enter ur surname : ");
        scanf("%s", &a1[i].a.surname);

        printf("\n enter ur add : ");
        scanf("%s", &a1[i].add);

        printf("\n enter ur pin : ");
        scanf("%d", &a1[i].pin);
    }

    for (i = 0; i < user; i++)
    {
        printf("\n your name is %s", a1[i].a.name);
        printf("\n your surnmae is %s", a1[i].a.surname);
        printf("\n your add is %s", a1[i].add);
        printf("\n your pin is %d", a1[i].pin);
    }

    return 0;
}