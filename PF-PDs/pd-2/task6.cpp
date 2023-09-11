#include <iostream>
#include <windows.h>
using namespace std;

void a();
void b();
void c();
void d();
void e();
void gotoxy(int x, int y);

main(){
  a();
  b();
  c();
  d();
  e();
}
void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void a(){
  gotoxy(55, 15);
  cout <<"A";
}

void b(){
  gotoxy(55, 16);
  cout <<"W";
}

void c(){
  gotoxy(55, 17);
  cout <<"A";
}

void d(){
  gotoxy(55, 18);
  cout <<"I";
}

void e(){
  gotoxy(55, 19);
  cout <<"S";
}