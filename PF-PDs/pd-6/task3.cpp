#include <iostream>
using namespace std;

main()
{
    char word[100];
    cout << "Enter A Word: ";
    cin >> word;
    int count = 0;
    for(int x = 0; word[x] != '\0'; x++)
    {
        count++;
    }
    if(count%2 == 0)
    {
        cout << "Even";
    }
    else
    {
        cout << "Odd";
    }
}