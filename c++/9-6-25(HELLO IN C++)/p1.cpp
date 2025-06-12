#include<iostream>
using namespace std;

int main(){
    int marks;

    cout<<"enter your marks : ";
    cin>>marks;
    if (marks >= 35)
    {
        if (marks >50)
        {
            cout<<"nice";
        }
        
       cout<<"u are pass " ;
    }
    else{
         if (marks > 20)
        {
            cout<<"can do better";
        }
        cout<<"fail";
    }
    
}