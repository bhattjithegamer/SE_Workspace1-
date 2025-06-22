#include <stdio.h>

#define PI 3.1415

int main()
{
    int age = 20;
    char grade = 'A';
    float marks = 89.75;

    printf("Student Age    : %d\n", age);
    printf("Student Grade  : %c\n", grade);
    printf("Student Marks  : %.2f\n", marks);
    printf("Value of PI    : %.4f\n", PI);

    return 0;
}
