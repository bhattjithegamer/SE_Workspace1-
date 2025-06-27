#include <iostream>
using namespace std;

int main()
{
    int a[2][2] = {{2, 3}, {4, 5}};

    int i, j, sum = 0;
    float avg = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            sum += a[i][j];
        }
    }
    avg = sum / 4.0;
    cout << "avg is : " << i + 1 << avg;
}