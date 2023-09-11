#include <iostream>
using namespace std;

main(){
string fruit, day;
cout <<"Enter fruit name: ";
cin >> fruit;
cout <<"Enter day: ";
cin >> day;
float quantity;
cout <<"Enter quantity: ";
cin >> quantity;

float result;
if(day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday"){
 if(fruit == "banana"){
  result = 2.50*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "apple"){
  result = 1.20*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "orange"){
  result = 0.85*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "grapefruit"){
  result = 1.45*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "kiwi"){
  result = 2.70*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "pineapple"){
  result = 5.50*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "grapes"){
  result = 3.85*quantity;
  cout <<"Your price is: " << result;
}
}
if(day == "saturday" || day == "sunday"){
 if(fruit == "banana"){
  result = 2.70*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "apple"){
  result = 1.25*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "orange"){
  result = 0.90*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "grapefruit"){
  result = 1.60*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "kiwi"){
  result = 3.00*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "pineapple"){
  result = 5.60*quantity;
  cout <<"Your price is: " << result;
}
 if(fruit == "grapes"){
  result = 4.20*quantity;
  cout <<"Your price is: " << result;
}
}
}