#include <iostream>
using namespace std;

main()
{
    string movies[5] = {"gladiator", "starwars", "terminator", "takinglives" , "tombrider"};
    string movieName;
    cout << "Enter Movie Name: ";
    cin >> movieName;
    int price = 500;
    for(int x = 0; x < 5; x++)
    {
        int result;
        if(movieName == movies[x] && x%2 == 0)
        {
            result = price*0.1;
            cout <<"Your Payable Amount Is: " << price - result;
        }
        else if(movieName == movies[x] && x%2 != 0)
        {
            result = price*0.05;
            cout <<"Your Payable Amount Is: " << price - result;
        }
    }
}