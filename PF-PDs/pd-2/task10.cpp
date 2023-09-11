#include <iostream>
#include <windows.h>
using namespace std;

void pak(string country, float price);
void ire(string country, float price);
void ind(string country, float price);
void eng(string country, float price);
void can(string country, float price);

main(){
 while(true){
string country;
cout <<"Enter Country: ";
cin >> country;
float price;
cout <<"Enter ticket price: ";
cin >> price;
if(country == "pakistan"){
pak(country, price);
}
if(country == "ireland"){
ire(country, price);
}
if(country == "india"){
ind(country, price);
}
if(country == "england"){
eng(country, price);
}
if(country == "canada"){
can(country, price);
}
 }
}

void pak(string country, float price){
  float c = (price*5)/100;
  float ptotal = price-c;
  cout <<"Payable amount: " << ptotal <<endl; 
}

void ire(string country, float price){
  float d = (price*10)/100;
  float itotal = price-d;
  cout <<"Payable amount: " << itotal <<endl;
}

void ind(string country, float price){
  float e = (price*20)/100;
  float iTotal = price-e;
  cout <<"Payable amount: " << iTotal <<endl;
}

void eng(string country, float price){
  float f = (price*30)/100;
  float etotal = price-f;
  cout <<"Payable amount: " << etotal <<endl;
}

void can(string country, float price){
  float g = (price*45)/100;
  float ctotal = price-g;
  cout <<"Payable amount: " << ctotal <<endl;
}