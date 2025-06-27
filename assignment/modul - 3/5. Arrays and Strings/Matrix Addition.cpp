#include<iostream>
using namespace std;

int main()
{
    int met[2][2],i,j,met1[2][2],a[2][2];

    cout<<"enter first : ";
    for ( i = 0; i < 2; i++)
    {
       for ( j = 0; j < 2; j++)
       {
            
            cin>>met[i][j];    
       }
    }

     cout<<"enter sec : ";
    for ( i = 0; i < 2; i++)
    {
       for ( j = 0; j < 2; j++)
       {
           
            cin>>met1[i][j];    
       }
    }

    for ( i = 0; i < 2; i++)
    {
       for ( j = 0; j < 2; j++)
       {
           a[i][j] = met[i][j] + met1[i][j];    
       }
    }

    for ( i = 0; i < 2; i++)
    {
       for ( j = 0; j < 2; j++)
       {
           cout<<a[i][j]<<" ";    
       }
       cout<<endl;
    }
    
}