#include<stdio.h>
#include<conio.h>
void main()
{
   
    int maths,sci,gu,hi,en,total;
    float per;
    
    printf("Enter Marks for Maths: ");
    scanf("%d",&maths);
    
    printf("Enter Marks for Science: ");
    scanf("%d",&sci);
    
    printf("Enter Marks for Gujarati: ");
    scanf("%d",&gu);
    
    printf("Enter Marks for Hindi: ");
    scanf("%d",&hi);
    
    printf("Enter Marks for English: ");
    scanf("%d",&en);
    
    total = maths+sci+gu+hi+en;
    per = total/5;
    printf("\n Your Total is %d",total);
    printf("\n Your Percentage is %f",per);
  
   
    
    getch();
   
}