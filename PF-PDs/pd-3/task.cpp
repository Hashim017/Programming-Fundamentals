#include <iostream>
using namespace std;

float centiM(float length, float width, float height);
float meters(float length, float width, float height);
float milliM(float length, float width, float height);
float kiloM(float length, float width, float height);

main(){
float length;
cout <<"Enter length: ";
cin >> length;
float width;
cout <<"Enter width: ";
cin >> width;
float height;
cout <<"Enter height: ";
cin >> height;
string unit;
cout <<"Enter output unit: ";
cin >> unit;
if(unit=="centimeters"){
 centiM(length, width, height);
 int centiMe = centiM(length, width, height);
 cout << centiMe <<" cubic centimeters";
}
if(unit=="meters"){
 meters(length, width, height);
 int meterS = meters(length, width, height);
 cout << meterS <<" cubic meters";
}
if(unit=="millimeters"){
 milliM(length, width, height);
 int milliMe = milliM(length, width, height);
 cout << milliMe <<" cubic millimeters";
}
if(unit=="kilometers"){
 kiloM(length, width, height);
 int kiloMe = kiloM(length, width, height);
 cout << kiloMe <<" cubic kilometers";
}

}

float centiM(float length, float width, float height){
  int centiMe = length*width*height*100;
  return centiMe;
}
float meters(float length, float width, float height){
  int meters = length*width*height;
  return meters;
}
float milliM(float length, float width, float height){
  int milliMe = length*width*height*10000;
  return milliMe;
}
float kiloM(float length, float width, float height){
  int kiloMe = (length*width*height)/10000;
  return kiloMe;
}


