#include<iostream>
using namespace std;

class rbi
{
    public:
    virtual add()
    {
        return 0.0;
    }
};

    class sbi : public rbi
    {
    public:
    int add()
    {
        return 5.0;
    }
    };

    class axis : public rbi
    {
    public:
    int add()
    {
        return 10.0;
    }
    };

    class hdfc : public rbi
    {
    public:
    int add()
    {
        return 15.0;
    }
};

int main()
{
    rbi* r ;
    
    r = new sbi();
    cout<<r->add()<<endl;

    r = new axis();
    cout<<r->add()<<endl;

    r =new hdfc();
    cout<<r->add()<<endl;

}
