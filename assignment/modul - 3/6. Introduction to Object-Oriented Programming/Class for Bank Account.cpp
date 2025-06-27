#include <iostream>
using namespace std;
class accountno
{
private:
    int balance = 0;

public:
    void setdeposit(int z)
    {
        balance = z;
    }

    int getwithdraw()
    {

        cout << balance;
        return balance;
    }
};

int main()
{
    accountno a1 = accountno();

    a1.setdeposit(50000);

    a1.getwithdraw();
    return 0;
}