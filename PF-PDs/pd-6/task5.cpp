#include <iostream>
using namespace std;

main()
{
    string element[4];
    for(int x = 0; x < 4; x++)
    {
    cout << "Enter Elements: ";
    cin >> element[x];
    }
    if((element[0] == element[1]) && (element[0] == element[2]) && (element[0] == element[3]))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}