#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y){
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

main(){
  cout <<"My name is Hashim";
  gotoxy(15,15);
  cout <<"My roll no is 18";

}