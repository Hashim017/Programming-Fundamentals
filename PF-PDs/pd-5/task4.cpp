#include <iostream>
using namespace std;

void numberr(int number);

main()
{
 int number;
 cout <<"Enter number: ";
 cin >> number;
 numberr(number);
}

void numberr(int number)
{
 for(int x = 1; x <= number; x++)
 {
  if(x%4 == 0)
  {
   cout << x*10 <<endl;
  }
  if(x%4 != 0 && x%4 != 10)
  {
  cout << x <<endl;
  }
 }
}