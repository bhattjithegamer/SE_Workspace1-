#include<iostream>
using namespace std;

int main()
{
    int age[50],i,max = 0,sum = 0 , min = 100 ,avg = 0;

    for ( i = 0; i < 5; i++)
    {
       cout<<"enter age of student : ";
       cin>>age[i];

        sum+=age[i];
       if (age[i]>max)
       {
      
        max = age[i];
       }
       
       if (age[i]<min)
       {
        min = age[i];
       }
    }
           avg = sum/5;
cout<<"avg is : "<<avg <<endl;
cout<<"max is : "<<max<<endl;
cout<<"min is : "<<min;
    
}