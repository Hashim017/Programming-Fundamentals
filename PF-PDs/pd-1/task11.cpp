#include <iostream>
using namespace std;

main(){

int number;
int total;
cout <<"Enter Five Integers: ";
cin >> number;
total = (number%10) + (number/10)%10 + (number/100)%10 + (number/1000)%10 + (number/10000)%10;
cout <<"Sum Is: " << total; 


} 