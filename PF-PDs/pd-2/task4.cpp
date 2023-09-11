#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y);
void printMaze();
void playerMove(int x, int y);
void erase(int x, int y);
void printPacman(int x, int y);
void getCharAtxy(short int x, short int y);

main(){
  system("cls");
  printMaze();
  int x = 22;
  int y = 1;
  while(true){
  playerMove(x,y);
  if(x < 80){
  x = x + 1;
  }
  if(x == 80){
  gotoxy(x-1, y);
  cout <<" ";
  x = 22;
  }
}
}

void gotoxy(int x, int y){
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void printMaze(){

cout <<"                   ###############################################################################" <<endl;
cout <<"                   ||.. .............................................................  ...... ..||" <<endl;
cout <<"                   ||.. %%%%%%%%%%%%%%%%            ...       %%%%%%%%%%%%%%%%  |%|..   %%%%    ||  " <<endl;                  
cout <<"                   ||..    |%|     |%|           |%|...       |%|          |%|  |%|..    |%|    ||" <<endl;
cout <<"                   ||..    |%|     |%|           |%|...       |%|          |%|  |%|..    |%|    ||" <<endl;
cout <<"                   ||..    %%%%%%%%%%%  . . . .  |%|...       %%%%%%%%%%%%%%%%     ..   %%%%    ||" <<endl;
cout <<"                   ||..    |%|          . . . .  |%|...                            ..         ..||" <<endl;
cout <<"                   ||..    %%%%%%%%%%%  . . . .  |%|...       ................ |%| ..         ..||" <<endl;
cout <<"                   ||..             |%| . . . .               %%%%%%%%%%%%%    |%| ..   %%%%  ..||  " <<endl;
cout <<"                   ||..    .........|%| . . . .               |%|.......       |%| ..    |%|  ..||" <<endl;
cout <<"                   ||..|%|    |%|%%%%%%|%| . . |%|            |%|..........|%|     ..    |%|  ..||" <<endl;
cout <<"                   ||..|%|    |%|      |%| . . %%%%%%%%%%%%%%%%%%%  .......|%|     ..    |%|  ..||" <<endl;
cout <<"                   ||..|%|    |%|      |%| . .            .... |%|      %%%%%%  |%|..    |%|  ..||" <<endl;
cout <<"                   ||..|%|                 . .             ... |%|              |%|..    |%|  ..||" <<endl;
cout <<"                   ||..|%|    %%%%%%%%%%%%%%%%%%%         .... |%|%%%%%%%%%%%   |%|.. ......  ..||" <<endl;
cout <<"                   ||........................................................   |%|..         ..||" <<endl;
cout <<"                   ||     ..............................................              ......  ..||" <<endl;
cout <<"                   ||..|%| |%|  |%|..          %%%%%%%%%%%%%    .....|%|        |%|   ..|%|   ..|| " <<endl;
cout <<"                   ||..|%| |%|  |%|..                 ...|%|      %%%%%%    ....|%|   ..|%|   ..|| " <<endl;
cout <<"                   ||..|%|         ..                 ...|%|                    |%|   ..|%|   ..||" <<endl;
cout <<"                   ||..|%| %%%%%%%%%%%%%              ...|%|%%%%%%%%%%%   ......|%|   ..%%%%  ..||" <<endl;
cout <<"                   ||...................................................        |%|   ......  ..||" <<endl;
cout <<"                   ||   ............................................         ................   ||" <<endl;
cout <<"                   ###############################################################################" <<endl;
}

void playerMove(int x, int y){
  gotoxy(x-1, y);
  cout <<" ";
  gotoxy(x, y);
  cout <<"P";
  Sleep(200);
}

void erase(int x, int y){
  gotoxy(x,y);
  cout <<" ";
}

void printPacman(int x, int y){
  gotoxy(x,y);
  cout <<"P";
}