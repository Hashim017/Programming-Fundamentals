#include <iostream>
using namespace std;

main(){
int hours;
cout <<"Enter needed hours: ";
cin >> hours;
int totalHours = hours+2;
int minusHours = (totalHours*10)/100;
int finalHours = totalHours - minusHours;
cout << finalHours;


}