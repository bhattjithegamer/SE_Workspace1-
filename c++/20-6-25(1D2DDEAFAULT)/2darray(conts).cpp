#include <iostream>
using namespace std;
const int ROW = 4;
const int COLUMN = 3;

int main()
{
    int i, j;
    int a[ROW][COLUMN];

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COLUMN; j++)
        {
            cout << "Enter value of Row " << i + 1;
            cout << ",Column " << j + 1 << ":";
            cin >> a[i][j];
        }
    }
    cout << "\n\n\n";
    cout << " COLUMN\n";
    cout << " 1 2 3";
    for (i = 0; i < ROW; i++)
    {
        cout << "\nROW " << i + 1 << endl;
        for (j = 0; j < COLUMN; j++)
            cout << a[i][j];
    }
}