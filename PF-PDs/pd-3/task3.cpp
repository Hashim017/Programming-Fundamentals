#include <iostream>
using namespace std;

main(){
float price;
cout <<"Enter price: ";
cin >> price;
char type;
cout <<"Enter vehicle type in bold letter: ";
cin >> type;
if(type=='M'){
  int tax = (price*6)/100;
  int finalAmount = price+tax;
  cout << "The final price of the vehicle of type motorcycle after adding tax is " << finalAmount << "$";
}
if(type=='E'){
  int tax = (price*8)/100;
  int finalAmount = price+tax;
  cout << "The final price of the vehicle of type electric after adding tax is " << finalAmount << "$";
}
if(type=='S'){
  int tax = (price*10)/100;
  int finalAmount = price+tax;
  cout << "The final price of the vehicle of type sedan after adding tax is " << finalAmount << "$";
}
if(type=='V'){
  int tax = (price*12)/100;
  int finalAmount = price+tax;
  cout << "The final price of the vehicle of type sedan after adding tax is " << finalAmount << "$";
}
if(type=='T'){
  int tax = (price*6)/100;
  int finalAmount = price+tax;
  cout << "The final price of the vehicle of type truck after adding tax is " << finalAmount << "$";
}
 
}