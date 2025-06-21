#include <iostream>
using namespace std;

class Vehicle
{
public:
    string brand = "mahindra brand";
};

class car : public Vehicle
{
public:
    string name;
    int model;
    int door;

    int display()
    {

        cout << "brand name is  : " << brand << endl;
        cout << "enter car name :  ";
        cin >> name;

        cout << "enter model : ";
        cin >> model;

        cout << "how many door : ";
        cin >> door;

        cout << name << endl
             << model << endl
             << door << endl;
    }
};

class bike : public Vehicle
{
public:
    string name;
    int model;
    int door;

    int display()
    {

        cout << "enter bike name :  ";
        cin >> name;

        cout << "enter model : ";
        cin >> model;

        cout << "how many door : ";
        cin >> door;

        cout << name << endl
             << model << endl
             << door << endl;
    }
};

int main()
{

   
    car c1;
    bike b1;

    car* car = &c1;
    bike* bike = &b1;

    car->display();
    bike->display();

    return 0;
   
}