#include <iostream>
#include <windows.h>
using namepsace std;

void calculate(float a);

main(){
int red;
cout <<"Enter no of red roses: ";
cin >> red;
int white;
cout <<"Enter no of white roses: ";
cin >> white;
int tulip;
cout <<"Enter no of tulips: ";
cin >> tulip;
float total = (2*red) + (4.10*white) + (2.5*tulip);
if (total >= 200){
 calculate(a)
}

}

void calculate(float a){
  float b = (total*20)/100;
  float ttotal = total-b;
  cout <<"Payable amount: " << ttotal;
}