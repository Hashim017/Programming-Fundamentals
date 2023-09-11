#include <iostream>
using namespace std;

main()
{
    char word1[100];
    char word2[100];
    cout << "Enter First Word: ";
    cin >> word1;
    cout << "Enter Second Word : ";
    cin >> word2;
    int count = 0;
    for(int x = 0; word1[x] != '\0'; x++)
    {
        for(int y = 0; word2[y] != '\0'; y++)
        {
            if(word2[y] == word1[x])
            {
                count ++;
                cout << word2[y];
            }
        }
    }
    cout << count;
}
