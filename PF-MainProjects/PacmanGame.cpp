#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y);
void printMaze();
void playerMove(int x, int y);
void erase(int x, int y);
void printPacman(int x, int y);
char getCharAtxy(short int x, short int y);
void color1(int color1)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
}

main()
{
  system("cls");
  int time = 3;
  printMaze();
  int pacx = 21;
  int pacy = 1;
  int x = 27;
  int y = 13;
  bool gameRunning = true;
  printPacman(pacx, pacy);

  while (gameRunning)
  {
    if (time = 3)
    {
      playerMove(x, y);
      if (x < 80)
      {
        x = x + 1;
      }
      if (x == 80)
      {
        gotoxy(x - 1, y);
        cout << " ";
        x = 22;
      }
      time = 0;
    }

    if (GetAsyncKeyState(VK_LEFT))
    {
      char nextLocation = getCharAtxy(pacx - 1, pacy);
      if (nextLocation == ' ' || nextLocation == '.')
      {
        erase(pacx, pacy);
        pacx = pacx - 1;
        printPacman(pacx, pacy);
      }
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
      char nextLocation = getCharAtxy(pacx + 1, pacy);
      if (nextLocation == ' ' || nextLocation == '.')
      {
        erase(pacx, pacy);
        pacx = pacx + 1;
        printPacman(pacx, pacy);
      }
    }
    if (GetAsyncKeyState(VK_UP))
    {
      char nextLocation = getCharAtxy(pacx, pacy - 1);
      if (nextLocation == ' ' || nextLocation == '.')
      {
        erase(pacx, pacy);
        pacy = pacy - 1;
        printPacman(pacx, pacy);
      }
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
      char nextLocation = getCharAtxy(pacx, pacy + 1);
      if (nextLocation == ' ' || nextLocation == '.')
      {
        erase(pacx, pacy);
        pacy = pacy + 1;
        printPacman(pacx, pacy);
      }
    }
    if (GetAsyncKeyState(VK_ESCAPE))
    {
      gameRunning = false;
    }
    Sleep(90);
    time++;
  }
}

void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void printMaze()
{
  color1(3);

  cout << "                   ###############################################################################" << endl;
  cout << "                   ||.. .............................................................  ...... ..||" << endl;
  cout << "                   ||.. %%%%%%%%%%%%%%%%            ...       %%%%%%%%%%%%%%%%  |%|..   %%%%    ||  " << endl;
  cout << "                   ||..    |%|     |%|           |%|...       |%|          |%|  |%|..    |%|    ||" << endl;
  cout << "                   ||..    |%|     |%|           |%|...       |%|          |%|  |%|..    |%|    ||" << endl;
  cout << "                   ||..    %%%%%%%%%%%  . . . .  |%|...       %%%%%%%%%%%%%%%%     ..   %%%%    ||" << endl;
  cout << "                   ||..    |%|          . . . .  |%|...                            ..         ..||" << endl;
  cout << "                   ||..    %%%%%%%%%%%  . . . .  |%|...       ................ |%| ..         ..||" << endl;
  cout << "                   ||..             |%| . . . .               %%%%%%%%%%%%%    |%| ..   %%%%  ..||  " << endl;
  cout << "                   ||..    .........|%| . . . .               |%|.......       |%| ..    |%|  ..||" << endl;
  cout << "                   ||..|%|    |%|%%%%%%|%| . . |%|            |%|..........|%|     ..    |%|  ..||" << endl;
  cout << "                   ||..|%|    |%|      |%| . . %%%%%%%%%%%%%%%%%%%  .......|%|     ..    |%|  ..||" << endl;
  cout << "                   ||..|%|    |%|      |%| . .            .... |%|      %%%%%%  |%|..    |%|  ..||" << endl;
  cout << "                   ||                                                           |%|..    |%|  ..||" << endl;
  cout << "                   ||..|%|    %%%%%%%%%%%%%%%%%%%         .... |%|%%%%%%%%%%%   |%|.. ......  ..||" << endl;
  cout << "                   ||........................................................   |%|..         ..||" << endl;
  cout << "                   ||     ..............................................              ......  ..||" << endl;
  cout << "                   ||..|%| |%|  |%|..          %%%%%%%%%%%%%    .....|%|        |%|   ..|%|   ..|| " << endl;
  cout << "                   ||..|%| |%|  |%|..                 ...|%|      %%%%%%    ....|%|   ..|%|   ..|| " << endl;
  cout << "                   ||                                                           |%|   ..|%|   ..||" << endl;
  cout << "                   ||..|%| %%%%%%%%%%%%%              ...|%|%%%%%%%%%%%   ......|%|   ..%%%%  ..||" << endl;
  cout << "                   ||...................................................        |%|   ......  ..||" << endl;
  cout << "                   ||   ............................................         ................   ||" << endl;
  cout << "                   ###############################################################################" << endl;
}

void playerMove(int x, int y)
{
  gotoxy(x - 1, y);
  cout << " ";
  gotoxy(x, y);
  color1(4);
  cout << "G";
  Sleep(200);
}

void erase(int x, int y)
{
  gotoxy(x, y);
  cout << " ";
}

void printPacman(int x, int y)
{
  color1(6);
  gotoxy(x, y);
  cout << "P";
}

char getCharAtxy(short int x, short int y)
{
  CHAR_INFO ci;
  COORD xy = {0, 0};
  SMALL_RECT rect = {x, y, x, y};
  COORD coordBufSize;
  coordBufSize.X = 1;
  coordBufSize.Y = 1;
  return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}