#include <iostream>
using namespace std;

main(){

cout <<"Enter Number: ";
int number;
cin >> number;
int number2;
number2 = number % 10;
int a;
a = number / 10;
int number3;
number3 = a % 10;
int b;
b = number / 100;
int number4;
number4 = b % 10;
int c;
c = number / 1000;
int number5;
number5 = c % 10;
int tnumber;
tnumber = number2 + number3 + number4 + number5;
cout <<"Result Is: " << tnumber;

}