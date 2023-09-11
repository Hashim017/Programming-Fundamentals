#include <iostream>
#include <windows.h>
using namespace std;

void true();
void false();

main(){
cout <<"Enter statement: ";
string a;
cin >> a;
if(a == "true"){
  true();
}
if(a != "false"){
  false();
}
}

void true(){
  cout <<"false";
}

void false(){
  cout <<"true";
}