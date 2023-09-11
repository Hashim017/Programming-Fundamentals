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
   cout <<" ";
  }
 for(int y = 1; y <= x; y++)
 {
  cout <<"*";
 }
 cout <<endl;
 }
 for(int x = 1; x <= rows; x++)
 {
  for(int y = 1; y <= x; y++)
  {
   cout <<" ";
  }
 for(int y = rows; y >= x; y--)
 {
  cout <<"*";
 }
 cout <<endl;
 }
}