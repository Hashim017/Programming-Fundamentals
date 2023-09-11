#include <iostream>
#include <windows.h>
using namespace std;

void chalenge();
void notChalenge();

main(){
int speed;
cout <<"Enter speed: ";
cin >> speed;
if (speed >= 100){
chalenge();
}
if (speed < 100){
notChalenge();
}
}

void chalenge(){
  cout <<"You are challenged";
}
void notChalenge(){
  cout <<"Perfect you are going good";
}

