#include <iostream>
using namespace std;

int dots(int number);

main()
{
 int number;
 cout <<"Enter number: ";
 cin >> number;
 int result = dots(number);
 cout << result;
}

int dots(int number)
{
 int result;
 int half = number/2;
 if(number%2 == 0)
 {
  result = number*half + half;
 }
  if(number%2 != 0)
 {
  result = number*half + number;
 }
 return result;
}