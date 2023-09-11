#include <iostream>
using namespace std;

main()
{
    int number[3];
    for(int x = 0; x < 3; x++)
    {
        cout << "Enter Array Numbers: ";
        cin >> number[x];
    }
    int value;
    cout << "Enter Execution Times: ";
    cin >> value;

    for(int x = 0; x < 3; x++)
    {
        if(number[x]%2 == 0)
        {
           cout << number[x] - (value * 2) << "   ";
        }
        else if(number[x]%2 != 0)
        {
           cout << number[x] + (value * 2) << "   ";
        }
    }

}