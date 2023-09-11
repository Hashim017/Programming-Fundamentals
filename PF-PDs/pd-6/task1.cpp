#include <iostream>
using namespace std;

main()
{
    string fruit[4] = {"peach" , "apple" , "guava" , "watermelon"};
    int price[4] = {60 , 70, 40 , 30};
    int quantity;
    string fruitName;
    cout << "Enter Fruit Name: ";
    cin >> fruitName;
    cout << "Enter Quantity: ";
    cin >> quantity;
    for(int x = 0; x < 4; x++)
    {
        if(fruitName == fruit[x])
        {
            cout << "Your Total Price Is: " << price[x] * quantity;
        }
    }

}