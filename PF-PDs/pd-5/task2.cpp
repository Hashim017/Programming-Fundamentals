#include <iostream>
using namespace std;

main()
{
 int rows;
 cout <<"Enter rows: ";
 cin >> rows;
 for(int x = 1; x <= rows; x++)
 {
  for(int y = rows; y >= x; y--)
  {
   cout <<"*";
  }
  cout <<endl;
 }
}