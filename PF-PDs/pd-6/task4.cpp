#include <iostream>
using namespace std;

main()
{
    int arrSize;
    cout << "Enter Strength of Numbers: ";
    cin >> arrSize;

    int number[arrSize];

    for(int x = 0; x < arrSize; x++)
    {
        cout << "Enter A Number: ";
        cin >> number[x];
    }

    for(int x = 0; x < arrSize; x++)
    {
        if(number[x]%10 == 7)
        {
            cout << "Boom";
        }
    }
}