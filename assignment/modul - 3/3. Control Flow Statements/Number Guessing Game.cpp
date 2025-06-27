#include <iostream>
using namespace std;

class Game {
public:
    int num, guessNum = 36, i =1;

   void display()
   {
      
       cout<<"\n Welcome to the Game! You will get 7 chance to get the correct number.";
       
       while(i<=7)
       {
            cout<<"\n Enter any Number:";
            cin>>num;
       
            if(guessNum < num)
       {
           cout<<"Too high !"<<endl;
       }
       else if(guessNum > num)
       {
           cout<<"Too low!"<<endl;
       }
       else
       {
           cout<<"You guess the correct number! Well done.";
           break;
       }
       
           i++;
       }
       
      
   }
};

int main() {
   
   Game g1 = Game();
   
   g1.display();

    return 0;
}
