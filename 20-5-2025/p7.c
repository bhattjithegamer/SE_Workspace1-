#include<stdio.h>
#include<conio.h>

void main()
{
    int a;
    
    printf("enter any number : ");
    scanf("%d",&a);
    
    
    switch(a)
    {
        
        case 1: printf("sun");
        break;
        case 2: printf("mon");
        break;
        case 3: printf("tue");
        break;
        case 4: printf("wed");
        break;
        case 5: printf("thu");
        break;
        case 6: printf("fri");
        break;
        case 7: printf("sat");
        break;
        default : printf("there is nothing to see");
    }
}