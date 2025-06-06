#include <stdio.h>

struct intern
{
    char name[50];
    int salary;
};

struct employee
{
    char name[50];
    int salary;
    struct intern i;
};

struct manager
{
    char name[50];
    int salary;
    struct employee e;
};

struct boss
{
    char name[50];
    int salary;
    char department[50];
    struct manager m;

} a[100];

int main()
{

    int user, pasword, department;

    printf("who r u : \n 1 boss \t 2 manager \n 3 employee \t 4 intern \n:");
    scanf("%d", &user);

    struct boss a = {"shubham bhatt", 120000, "HR", {"jadeja \t", 130000, {"veshvi", 1400, {"hiren", 1500}}}};
    struct boss b = {"shubham bhatt", 120000, "TECH", {"rutvi \t", 19000, {"gaurang", 16000, {"prakruti ben", 18000}}}};

    if (user == 1)
    {
        printf("enter password : ");
        scanf("%d", &pasword);

        if (pasword == 1)
        {
            printf("\n boss is :  %s", a.name);
            printf("\t salary is :  %d", a.salary);

            printf("\n manager of HR is : %s", a.m.name);
            printf(" salary is : %d", a.m.salary);

            printf("\n manager of TECH is : %s", b.m.name);
            printf(" salary is : %d", b.m.salary);

            printf("\n employee of HR is :  %s", a.m.e.name);
            printf("\t salary is %d", a.m.e.salary);
            
            printf("\n employee of TECH is :  %s", b.m.e.name);
            printf("\t salary is %d", b.m.e.salary);

            printf("\n intern of HR is : %s", a.m.e.i.name);
            printf("\t salary is %d", a.m.e.i.salary);

            printf("\n intern of HR is : %s", b.m.e.i.name);
            printf("\t salary is %d", b.m.e.i.salary);
        }
    }

    if (user == 2)
    {
        printf("which department : 1 HR \n 2 TECH");
        scanf("%d", &department);

        printf("enter password : ");
        scanf("%d", &pasword);

        if (pasword == 2)
        {
            if (department == 1)
            {
                printf("\n manager of HR is : %s", a.m.name);
                printf("\t salary is : %d", a.m.salary);
                printf("\n employee of HR is : %s", a.m.e.name);
                printf("\t salary is : %d", a.m.e.salary);
                printf("\n intern of HR is : %s", a.m.e.i.name);
                printf("\t salary is : %d", a.m.e.i.salary);
            }
            if (department == 2)
            {
                printf("\n manager of TECH is : %s", b.m.name);
                printf("\t salary is %d", b.m.salary);
                printf("\n employee of TECH is : %s", b.m.e.name);
                printf("\t salary is %d", b.m.e.salary);
                printf("\n intern of TECH is : %s", b.m.e.i.name);
                printf("\t salary is %d", b.m.e.i.salary);
            }
        }
    }

    if (user == 3)
    {
        printf("which department : 1 HR \t 2 TECH");
        scanf("%d", &department);

        printf("enter password : ");
        scanf("%d", &pasword);

        if (pasword == 3)
        {
            if (department == 1)
            {
                printf("\n employee of HR is : %s", a.m.e.name);
                printf("\t salary is : %d", a.m.e.salary);
                printf("\n intern of HR is : %s", a.m.e.i.name);
                printf("\t salary is : %d", a.m.e.i.salary);
            }
            if (department == 2)
            {
                  printf("\n employee of TECH is : %s", b.m.e.name);
                printf("\t salary is %d", b.m.e.salary);
                printf("\n intern of TECH is : %s", b.m.e.i.name);
                printf("\t salary is %d", b.m.e.i.salary);
            }
        }
    }

    if (user == 4)
    {
        printf("which department : 1 HR \n 2 TECH");
        scanf("%d", &department);

        printf("enter password : ");
        scanf("%d", &pasword);

        if (pasword == 4)
        {
            if (department == 1)
            {

                printf("\n intern of HR is : %s", a.m.e.i.name);
                printf("\t salary is : %d", a.m.e.i.salary);
            }
            if (department == 2)
            {

               printf("\n intern of TECH is : %s", b.m.e.i.name);
                printf("\t salary is %d", b.m.e.i.salary);
            }
        }
    }

    return 0;
}