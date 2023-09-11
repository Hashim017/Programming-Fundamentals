#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void PrintGame(char game[5][5], int gameX, int gameY);
void timeTick(int times, bool gravity, char game[5][5], bool isBlackHole);
void gotoxy(int x, int y);
void color(int color1)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
}

main()
{
    system("cls");
    color(6);
    cout << "::'######:::'########:::::'###::::'##::::'##:'####:'########:'##:::'##:" << endl;
    cout << ":'##... ##:: ##.... ##:::'## ##::: ##:::: ##:. ##::... ##..::. ##:'##::" << endl;
    cout << "::##:::..::: ##:::: ##::'##:. ##:: ##:::: ##:: ##::::: ##:::::. ####:::" << endl;
    cout << "::##::'####: ########::'##:::. ##: ##:::: ##:: ##::::: ##::::::. ##::::" << endl;
    cout << "::##::: ##:: ##.. ##::: #########:. ##:: ##::: ##::::: ##::::::: ##::::" << endl;
    cout << "::##::: ##:: ##::. ##:: ##.... ##::. ## ##:::: ##::::: ##::::::: ##::::" << endl;
    cout << ".::######::: ##:::. ##: ##:::: ##:::. ###::::'####:::: ##::::::: ##::::" << endl;
    cout << ":......::::..:::::..::..:::::..:::::...:::::....:::::..::::::::..:::::" << endl;
    int gameX = 20;
    int gameY = 10;
    int time;
    bool gravity = true;
    string BlackHole;
    bool isBlackHole = true;
    char game[5][5] = {{'-', '#', '-', '-', '#'},
                       {'#', '-', '#', '-', '#'},
                       {'-', '-', '#', '-', '-'},
                       {'#', '#', '-', '#', '#'},
                       {'#', '-', '-', '-', '#'}};
    color(5);
    for (int x = 0; x < 5; x++)
    {
        gotoxy(gameX, gameY);
        for (int y = 0; y < 5; y++)
        {
            cout << game[x][y] << "\t";
        }
        cout << endl;
        gameY++;
    }
    color(3);
    cout << endl
         << "Enter number of times you want to make the objects fall:";
    cin >> time;
    cout << "Enter if black whole should be (t/f):";
    cin >> BlackHole;
    if (BlackHole == "t")
    {
        isBlackHole = true;
    }
    if (BlackHole == "f")
    {
        isBlackHole = false;
    }
    timeTick(time, gravity, game, isBlackHole);
    PrintGame(game, gameX, gameY);
}

void PrintGame(char game[5][5], int gameX, int gameY)
{
    color(2);
    int x = gameX;
    int y = 20;
    for (int i = 0; i < 5; i++)
    {
        gotoxy(x, y);
        for (int j = 0; j < 5; j++)
        {
            cout << game[i][j];
            cout << "\t";
        }
        y++;
    }
    cout << endl;
    getch();
}
void timeTick(int time, bool gravity, char game[5][5], bool isBlackHole)
{
    char row4[1][5];
    int count = 0;
    if (gravity)
    {
        if (isBlackHole)
        {
            while (count < time)
            {
                for (int i = 0; i < 5; i++)
                {
                    row4[1][i] = game[4][i];
                }

                for (int i = 4; i >= 0; i--)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (i != 0)
                        {
                            game[i][j] = game[i - 1][j];
                        }
                        else
                        {
                            game[i][j] = row4[1][j];
                        }
                    }
                }
                count++;
            }
        }
        else
        {
            while (count < time)
            {
                for (int i = 3; i >= 0; i--)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (game[i][j] == '#')
                        {
                            if (game[i + 1][j] == '-')
                            {
                                game[i + 1][j] = '#';
                                game[i][j] = '-';
                            }
                        }
                    }
                }
                count = count + 1;
            }
        }
    }
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}