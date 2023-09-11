#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

// Function Prototypes

void header();
void mainMenuHeader();
string mainMenu();
void clearScreen();
void storeMaze();
void printMaze();
void gotoxy(int spX, int spY);
char getCharAtxy(short int x, short int y);
void color1(int color);
void printSpelunker(int spX, int spY);
void moveRight();
void moveLeft();
void moveUp();
void moveDown();
void startGame();
void loadGame();
void instructions();
void eraseSpelunkerRight(int spX, int spY);
void eraseSpelunkerLeft(int spX, int spY);
void eraseSpelunkerUp(int spX, int spY);
void eraseSpelunkerDown(int spX, int spY);
void createBullet(int spX, int spY);
void eraseBullet(int spX, int spY);
void generateBullet();
void moveBullet();
void generateBulletL();
void moveBulletL();
void addScore();
void printScore();
void moveBat();
void moveBat2();
void moveBat4();
void printGhost(int ghost2X, int ghost2Y);
void eraseGhost(int ghost2X, int ghost2Y);
void moveGhost();
void moveGhost2();
void moveGhost4();
void printLives();
void loadData();
string getField(string record, int field);
void moveBat1Bullet();
void bat1Bullet();
void moveGhostBullet();
void ghostBullet();

// Global Arrays And Variables

char spelunker[2][7] = {{' ', ' ', '_', '0', '_', '\0'},
                        {'{', '/', '|', 'H', '|', '\\', '}'}};

char ghost[2][7] = {{'/', '\\', '(', '*', ')', '/', '\\'},
                    {' ', ' ', '/', '/', '\0'}};
char bat[7] = {'/', '\\', '(', '0', ')', '/', '\\'};
char bulletX[100];
char bulletY[100];
char bulletXL[100];
char bulletYL[100];

int bat1BulletX[100];
int bat1BulletY[100];
int index1 = 0;
int ghostBulletX[100];
int ghostBulletY[100];
int index2 = 0;
int score = 0;
int spX = 10;
int spY = 3;
int batX = 40;
int batY = 3;
int bat2X = 110;
int bat2Y = 15;
int bat4X = 12;
int bat4Y = 28;
int ghostX = 4;
int ghostY = 17;
int ghost2X = 55;
int ghost2Y = 10;
int ghost4X = 53;
int ghost4Y = 28;
int bulletCount = 0;
int bulletCountL = 0;
bool gameRunning = true;
bool isBulletActive[100];
bool isBulletActiveL[100];
int timer = 0;
int bulletTimer = 0;
int mainMenuIndex = 0;
int batDie = 1;
int lives = 3;
bool removebat = false;
int ghostDie = 1;
bool removeGhost = false;
string op;

main()
{
    header();
    while (op != "4")
    {
        op = mainMenu();
        mainMenuHeader();
        if (op == "1")
        {
            system("cls");
            storeMaze();
            printMaze();
            printScore();
            printLives();
            printSpelunker(spX, spY);
            startGame();
        }
        if (op == "2")
        {
            loadData();
            loadGame();
        }
        if (op == "3")
        {
            instructions();
        }
    }
    mainMenuHeader();
    cout << endl
         << "Thanks For Playing Our Game." << endl;
    clearScreen();
}

void loadData()
{
    string record;
    fstream data;
    data.open("Data.txt", ios::in);
    while (getline(data, record))
    {
        lives = stoi(getField(record, 1));
        score = stoi(getField(record, 2));
        batDie = stoi(getField(record, 3));
        ghostDie = stoi(getField(record, 4));
        spX = stoi(getField(record, 5));
        spY = stoi(getField(record, 6));
    }
    data.close();
}

string getField(string record, int field)
{
    int commaCount = 1;
    string item = "";
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

void startGame()
{
    while (gameRunning)
    {
        if (lives <= 0)
        {
            gameRunning = false;
        }

        if (timer == 3)
        {
            if (batDie < 6)
            {
                removebat = true;
                moveBat();
                bat1Bullet();
                moveBat1Bullet();
            }
            if (batDie == 6 || batDie == 7 || batDie == 8)
            {
                removebat == false;
                gotoxy(batX - 1, batY);
                color1(2);
                cout << "$$$$$$$$$$";
                gotoxy(59, 2);
                cout << " ";
                gotoxy(59, 3);
                cout << " ";
                batDie++;
            }
            if (batDie < 14)
            {
                removebat = true;
                moveBat2();
            }
            if (batDie == 14 || batDie == 15 || batDie == 16)
            {
                removebat == false;
                gotoxy(bat2X - 1, bat2Y);
                color1(2);
                cout << "$$$$$$$+";
                batDie++;
            }
            if (batDie < 21)
            {
                removebat = true;
                moveBat4();
            }
            if (batDie == 21 || batDie == 22 || batDie == 23 || batDie == 23)
            {
                removebat == false;
                gotoxy(bat4X - 1, bat4Y);
                color1(2);
                cout << "$$$$$$$+";
                batDie++;
            }

            if (ghostDie < 6)
            {
                removeGhost = true;
                moveGhost2();
            }
            if (ghostDie == 6 || ghostDie == 7 || ghostDie == 8 || ghostDie == 9)
            {
                removeGhost == false;
                gotoxy(ghost2X - 1, ghost2Y);
                color1(2);
                cout << "$$$$$$$$$$$";
                gotoxy(ghost2X, ghost2Y + 1);
                cout << "     ";
                ghostDie++;
            }
            if (ghostDie < 14)
            {
                removeGhost = true;
                moveGhost();
                ghostBullet();
                moveGhostBullet();
            }
            if (ghostDie == 14 || ghostDie == 15 || ghostDie == 16 || ghostDie == 17)
            {
                removeGhost == false;
                gotoxy(ghostX - 1, ghostY - 1);
                color1(2);
                cout << "$$$$$$$$";
                gotoxy(ghostX, ghostY);
                cout << "     ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2]);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] - 1);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] - 2);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] - 3);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] - 4);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] - 5);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] + 1);
                cout << " ";
                ghostDie++;
            }
            if (ghostDie < 21)
            {
                removeGhost = true;
                moveGhost4();
            }
            if (ghostDie == 21 || ghostDie == 22 || ghostDie == 23 || ghostDie == 24)
            {
                removeGhost == false;
                gotoxy(ghost4X - 1, ghost4Y);
                color1(2);
                cout << "$$$$$$$$";
                gotoxy(ghost4X, ghost4Y + 1);
                cout << "     ";
                gotoxy(20, 32);
                cout << "$$$";
                gotoxy(17, 33);
                cout << "$$$$$$$$$";
                ghostDie++;
            }
            timer = 0;
            bulletTimer = 0;
        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveRight();
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveLeft();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveDown();
        }
        if (GetAsyncKeyState('S'))
        {
            color1(5);
            char nextLocation = getCharAtxy(spX + 7, spY + 1);
            if (nextLocation == ' ')
            {
                generateBullet();
            }
        }
        if (GetAsyncKeyState('A'))
        {
            color1(5);
            char nextLocation = getCharAtxy(spX - 1, spY + 1);
            if (nextLocation == ' ')
            {
                generateBulletL();
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            fstream file;
            file.open("Data.txt", ios::out);
            file << lives << "," << score << "," << batDie << "," << ghostDie << "," << spX << "," << spY;
            file.close();
            gameRunning = false;
        }

        moveBullet();
        moveBulletL();
        timer++;
        bulletTimer++;
        Sleep(70);
    }
    
    score = 0;
    lives = 3;
    batDie = 1;
    ghostDie = 1;
    spX = 10;
    spY = 3;
    gameRunning = true;
}

void loadGame()
{

    storeMaze();
    printMaze();
    printScore();
    printLives();
    printSpelunker(spX, spY);
    gameRunning = true;
    while (gameRunning)
    {
        if (lives <= 0)
        {
            gameRunning = false;
        }

        if (timer == 3)
        {
            if (batDie < 6)
            {
                removebat = true;
                moveBat();
                bat1Bullet();
                moveBat1Bullet();
            }
            if (batDie == 6 || batDie == 7 || batDie == 8)
            {
                removebat == false;
                gotoxy(batX - 1, batY);
                color1(2);
                cout << "$$$$$$$$$$";
                batDie++;
            }
            if (batDie < 14)
            {
                removebat = true;
                moveBat2();
            }
            if (batDie == 14 || batDie == 15 || batDie == 16)
            {
                removebat == false;
                gotoxy(bat2X - 1, bat2Y);
                color1(2);
                cout << "$$$$$$$+";
                batDie++;
            }
            if (batDie < 21)
            {
                removebat = true;
                moveBat4();
            }
            if (batDie == 21 || batDie == 22 || batDie == 23 || batDie == 23)
            {
                removebat == false;
                gotoxy(bat4X - 1, bat4Y);
                color1(2);
                cout << "$$$$$$$+";
                batDie++;
            }

            if (ghostDie < 6)
            {
                removeGhost = true;
                moveGhost2();
            }
            if (ghostDie == 6 || ghostDie == 7 || ghostDie == 8 || ghostDie == 9)
            {
                removeGhost == false;
                gotoxy(ghost2X - 1, ghost2Y);
                color1(2);
                cout << "$$$$$$$$$$$";
                gotoxy(ghost2X, ghost2Y + 1);
                cout << "     ";
                ghostDie++;
            }
            if (ghostDie < 14)
            {
                removeGhost = true;
                moveGhost();
                ghostBullet();
                moveGhostBullet();
            }
            if (ghostDie == 14 || ghostDie == 15 || ghostDie == 16 || ghostDie == 17)
            {
                removeGhost == false;
                gotoxy(ghostX - 1, ghostY - 1);
                color1(2);
                cout << "$$$$$$$$";
                gotoxy(ghostX, ghostY);
                cout << "     ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2]);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] - 1);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] - 2);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] - 3);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] - 4);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] - 5);
                cout << " ";
                gotoxy(ghostBulletX[index2], ghostBulletY[index2] + 1);
                cout << " ";
                ghostDie++;
            }
            if (ghostDie < 21)
            {
                removeGhost = true;
                moveGhost4();
            }
            if (ghostDie == 21 || ghostDie == 22 || ghostDie == 23 || ghostDie == 24)
            {
                removeGhost == false;
                gotoxy(ghost4X - 1, ghost4Y);
                color1(2);
                cout << "$$$$$$$$";
                gotoxy(ghost4X, ghost4Y + 1);
                cout << "     ";
                gotoxy(20, 32);
                cout << "$$$";
                gotoxy(17, 33);
                cout << "$$$$$$$$$";
                ghostDie++;
            }
            timer = 0;
            bulletTimer = 0;
        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveRight();
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveLeft();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveDown();
        }
        if (GetAsyncKeyState('S'))
        {
            color1(5);
            char nextLocation = getCharAtxy(spX + 7, spY + 1);
            if (nextLocation == ' ')
            {
                generateBullet();
            }
        }
        if (GetAsyncKeyState('A'))
        {
            color1(5);
            char nextLocation = getCharAtxy(spX - 1, spY + 1);
            if (nextLocation == ' ')
            {
                generateBulletL();
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            fstream file;
            file.open("Data.txt", ios::out);
            file << lives << "," << score << "," << batDie << "," << ghostDie << "," << spX << "," << spY;
            file.close();
            gameRunning = false;
        }

        moveBullet();
        moveBulletL();
        timer++;
        bulletTimer++;
        Sleep(70);
    }
    fstream file;
    file.open("Data.txt", ios::out);
    file << lives << "," << score << "," << batDie << "," << ghostDie << "," << spX << "," << spY;
    file.close();
    if (lives <= 0)
    {
        mainMenuHeader();
        cout << endl
             << endl
             << "There Is No Loaded Game." << endl;
        clearScreen();
    }
}

void header()
{
    system("cls");
    color1(6);
    cout << "                   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "                   ||                                                                                                                       ||" << endl;
    color1(3);
    cout << "                   ||  ##################################################################################                                   ||" << endl;
    cout << "                   ||  #                                                                                #                |\\                 ||" << endl;
    color1(2);
    cout << "                   ||  #     $$$$$    $$$$$$  $$$$$$  $       $    $  $$    $  $    $  $$$$$$  $$$$$$   #                ||  .---.          ||" << endl;
    cout << "                   ||  #    $      $  $    $  $       $       $    $  $ $   $  $  $    $       $    $   # >              || /_____\\         ||" << endl;
    cout << "                   ||  #      $$$     $$$$$$  $$$     $       $    $  $  $  $  $$      $$$$    $$$$$$   #                || ( '.' )         ||" << endl;
    cout << "                   ||  #   $      $   $       $       $       $    $  $   $ $  $  $    $       $  $     #                ||  \\-_//          ||" << endl;
    cout << "                   ||  #     $$$$$    $       $$$$$$  $$$$$$  $$$$$$  $    $$  $    $  $$$$$$  $    $   #                :-``''V'//-        ||" << endl;
    color1(3);
    cout << "                   ||  # ______________________________________________________________________________ #               / ,    |// ,\\       ||" << endl;
    cout << "                   ||  #                           | |______  |        |               |_______________ #              / /|Ll  // Ll||      ||" << endl;
    cout << "                   ||  #                           | |_____|_ |        |                    |__________ #             /_/ ||__//    ||      ||" << endl;
    cout << "                   ||  #                           | |        |        |   $                            #             \\\\/---|[  ]==|||      ||" << endl;
    cout << "                   ||  # ______________    ________|_|________|        |__$$$__________________________ #              \\/\\__/|   \\  ||      ||" << endl;
    cout << "                   ||  #              \\  /                                                              #             /\\|_   | Ll_\\ |       ||" << endl;
    cout << "                   ||  #               \\/            _________________________________________________  #             --| `^    ^`|||       ||" << endl;
    color1(5);
    cout << "                   ||  #                             /                                                  #                |    |    ||/      ||" << endl;
    cout << "                   ||  # ___________________________/                                                   #                |    |    |        ||" << endl;
    cout << "                   ||  #  ____ | ______ | ______ |                                                      #                |    |    |        ||" << endl;
    color1(4);
    cout << "                   ||  #                                                     $$                         #                |    |    |        ||" << endl;
    cout << "                   ||  # ___________________________________________________$$$$____________            #                L __l__ J          ||" << endl;
    cout << "                   ||  # |     |     |     |     |     |     |         |__________________|             #                  |_ | _|          ||" << endl;
    cout << "                   ||  # |_____|_____|_____|_____|_____|_____|_________|           |       ____________ #                 (___|___)         ||" << endl;
    color1(1);
    cout << "                   ||  #          |______|        |________|           |           |      |____________ #                  ^^^ ^^^          ||" << endl;
    cout << "                   ||  #           __||__          _||  ||_            |           |                    #                                   ||" << endl;
    cout << "                   ||  #__  ______|______|________|________|___________|___________|___________________ #                                   ||" << endl;
    color1(5);
    cout << "                   ||  #                                                   (  $$$$$$      $$$$$$$$$     #                                   ||" << endl;
    cout << "                   ||  #                                                    (    $$$$$$$     $$$$$$$    #                                   ||" << endl;
    color1(3);
    cout << "                   ||  #                                                                                #                                   ||" << endl;
    cout << "                   ||  ##################################################################################                                   ||" << endl;
    color1(6);
    cout << "                   ||                                                                                                                       ||" << endl;
    cout << "                   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    clearScreen();
}

void mainMenuHeader()
{
    system("cls");
    color1(2);
    cout << "               /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "               ||                                                                                                                                 ||" << endl;
    color1(6);
    cout << "               ||                     $$$$$$\\                      $$\\                     $$\\                                                    ||" << endl;
    cout << "               ||                    $$  __$$\\                     $$ |                    $$ |                                                   ||" << endl;
    cout << "               ||                    $$ /  \\__| $$$$$$\\   $$$$$$\\  $$ |$$\\   $$\\ $$$$$$$\\  $$ |  $$\\  $$$$$$\\   $$$$$$\\                           ||" << endl;
    cout << "               ||                    \\$$$$$$\\  $$  __$$\\ $$  __$$\\ $$ |$$ |  $$ |$$  __$$\\ $$ | $$  |$$  __$$\\ $$  __$$\\                          ||" << endl;
    cout << "               ||                     \\____$$\\ $$ /  $$ |$$$$$$$$ |$$ |$$ |  $$ |$$ |  $$ |$$$$$$  / $$$$$$$$ |$$ |  \\__|                         ||" << endl;
    cout << "               ||                    $$\\   $$ |$$ |  $$ |$$   ____|$$ |$$ |  $$ |$$ |  $$ |$$  _$$<  $$   ____|$$ |                               ||" << endl;
    cout << "               ||                    \\$$$$$$  |$$$$$$$  |\\$$$$$$$\\ $$ |\\$$$$$$  |$$ |  $$ |$$ | \\$$\\ \\$$$$$$$\\ $$ |                               ||" << endl;
    cout << "               ||                     \\______/ $$  ____/  \\_______|\\__| \\______/ \\__|  \\__|\\__|  \\__| \\_______|\\__|                               ||" << endl;
    cout << "               ||                               $$ |                                                                                              ||" << endl;
    cout << "               ||                               $$ |                                                                                              ||" << endl;
    cout << "               ||                               \\__|                                                                                              ||" << endl;
    color1(2);
    cout << "               ||                                                                                                                                 ||" << endl;
    cout << "               /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    color1(3);
}

string mainMenu()
{
    string option;
    mainMenuHeader();
    cout << endl
         << endl
         << "                                                                    Press One of The Fololwing Keys." << endl
         << endl;
    color1(2);
    cout << "                                                                            1- Start Game." << endl;
    color1(6);
    cout << "                                                                            2- Load Game." << endl;
    color1(3);
    cout << "                                                                            3- Instructions." << endl;
    color1(4);
    cout << "                                                                            4- Exit." << endl
         << endl;
    color1(1);
    cout << "                                                                     Your Option: ";
    cin >> option;
    return option;
}

void instructions()
{
    mainMenuHeader();
    cout << endl
         << endl;
    cout << "Use Arrow Keys To Move Player." << endl
         << endl;
    color1(2);
    cout << "Press 'S' Key To Fire On Right Side." << endl
         << endl;
    color1(4);
    cout << "Press 'A' Key To Fire On Left Side." << endl
         << endl;
    color1(11);
    cout << "Fire On Bats And Ghosts To Kill Them." << endl
         << endl;
    color1(6);
    cout << "Kill All Enemies And Reach To The House At The Bottom Left Corner Of Maze To Win The Game." << endl
         << endl;
    color1(10);
    cout << "Kill The Bats In The Boxes To Get An Extra Life." << endl
         << endl;
    color1(4);
    cout << "Press Escape To Save And Exit The Game." << endl
         << endl;
    clearScreen();
}

void clearScreen()
{
    color1(5);
    cout << endl
         << endl;
    cout << "                                                                        Press Any Key To Continue.";
    getch();
    system("cls");
}

void storeMaze()
{
    fstream data;
    data.open("maze.txt", ios::out);
    color1(6);
    data << "##################################################################################################################################       " << endl;
    data << "##################################################################################################################################       " << endl;
    data << "##                                                                                                                              ##       " << endl;
    color1(2);
    data << "##                                                                                                                              ##       " << endl;
    data << "##-----'|                      %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                                          ##       " << endl;
    color1(1);
    data << "##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                             ##       " << endl;
    data << "##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                             ##       " << endl;
    color1(6);
    data << "##                                                                                                                              ##       " << endl;
    data << "##                                                                                                                              ##       " << endl;
    data << "##                                                                                                                              ##       " << endl;
    data << "##                                                                                                                              ##       " << endl;
    data << "##                                                                                                                              ##       " << endl;
    color1(1);
    data << "##                                                                                            %%%%         %%%%%%%%%%%%%%%%%%%%%##       " << endl;
    data << "##                                                                                            %%%%         %%%%%%%%%%%%%%%%%%%%%##       " << endl;
    data << "##                                                                                            %%%%                              ##       " << endl;
    data << "##                                                                                            %%%%                              ##       " << endl;
    data << "##                                                                                            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##       " << endl;
    color1(6);
    data << "##                                                                                                                              ##       " << endl;
    data << "##                                                                                                                              ##       " << endl;
    data << "##                                                                                                                              ##       " << endl;
    data << "##                                                                                                                              ##       " << endl;
    data << "##                                                                                                                              ##       " << endl;
    color1(13);
    data << "##            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                                                  ##       " << endl;
    data << "##                                                         %%%                                                                  ##       " << endl;
    data << "##                                                         %%%                                                                  ##       " << endl;
    data << "##                                                         %%%                                                                  ##       " << endl;
    data << "##           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##       " << endl;
    color1(6);
    data << "##                                         %%%%%                                                                                ##       " << endl;
    data << "##                                         %%%%%                                                                                ##       " << endl;
    data << "##                                         %%%%%                                                                                ##       " << endl;
    color1(1);
    data << "##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            ##       " << endl;
    data << "##                                                                                                                %%            ##       " << endl;
    color1(2);
    data << "##   _ /\\ _                                                                                                                     ##       " << endl;
    data << "##  |  $$  |                                                                                                                    ##       " << endl;
    color1(6);
    data << "##################################################################################################################################       " << endl;
    data << "##################################################################################################################################       " << endl;
    color1(7);
    data.close();
}

void printMaze()
{
    string line;
    int test = 0;
    fstream data;
    data.open("maze.txt", ios::in);
    while (getline(data, line))
    {
        if (test == 0)
        {
            color1(6);
        }
        cout << line << endl;
        test++;
        if (test == 3)
        {
            color1(2);
        }
        if (test == 5)
        {
            color1(1);
        }
        if (test == 7)
        {
            color1(6);
        }
        if (test == 12)
        {
            color1(1);
        }
        if (test == 17)
        {
            color1(6);
        }
        if (test == 22)
        {
            color1(13);
        }
        if (test == 27)
        {
            color1(6);
        }
        if (test == 30)
        {
            color1(1);
        }
        if (test == 32)
        {
            color1(2);
        }
        if (test == 34)
        {
            color1(6);
        }
    }
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

void gotoxy(int spX, int spY)
{
    COORD coordinates;
    coordinates.X = spX;
    coordinates.Y = spY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void color1(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printSpelunker(int spX, int spY)
{
    color1(3);
    gotoxy(spX, spY);
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 7; col++)
        {
            cout << spelunker[row][col];
        }
        gotoxy(spX, spY + 1);
    }
    color1(7);
}

void moveRight()
{
    char nextLocation = getCharAtxy(spX + 7, spY + 1);
    char anotherLocation = getCharAtxy(spX + 5, spY);
    if ((nextLocation == ' ' || nextLocation == '$' || nextLocation == '.') && (anotherLocation == ' ' || anotherLocation == '$' || anotherLocation == '.'))
    {
        eraseSpelunkerRight(spX, spY);
        spX = spX + 1;
        printSpelunker(spX, spY);
    }
    if (nextLocation == '$' || anotherLocation == '$')
    {
        score = score + 10;
        printScore();
    }
    if (nextLocation == '+' || anotherLocation == '+')
    {
        lives++;
        gotoxy(spX + 7, spY + 1);
        cout << " ";
        gotoxy(spX + 5, spY);
        cout << " ";
        printLives();
    }
    if (nextLocation == '/' || nextLocation == '\\' || anotherLocation == '/' || anotherLocation == '\\')
    {
        lives--;
        printLives();
    }
}

void moveLeft()
{
    char nextLocation = getCharAtxy(spX - 1, spY + 1);
    char anotherLocation = getCharAtxy(spX - 1, spY);
    if ((nextLocation == ' ' || nextLocation == '$' || nextLocation == '.') && (anotherLocation == ' ' || anotherLocation == '$' || anotherLocation == '.'))
    {
        eraseSpelunkerLeft(spX, spY);
        spX = spX - 1;
        printSpelunker(spX, spY);
    }
    if (nextLocation == '$' || anotherLocation == '$')
    {
        score = score + 10;
        printScore();
    }
    if (nextLocation == '+' || anotherLocation == '+')
    {
        lives++;
        gotoxy(spX - 1, spY + 1);
        cout << " ";
        gotoxy(spX - 1, spY);
        cout << " ";
        printLives();
    }
    if (nextLocation == '/' || nextLocation == '\\' || anotherLocation == '/' || anotherLocation == '\\')
    {
        lives--;
        printLives();
    }
}

void moveUp()
{
    char nextLocation = getCharAtxy(spX + 2, spY - 1);
    char anotherLocation = getCharAtxy(spX + 3, spY - 1);
    char ann = getCharAtxy(spX + 5, spY - 1);
    char annn = getCharAtxy(spX + 1, spY - 1);
    char annnn = getCharAtxy(spX, spY - 1);
    char annnnn = getCharAtxy(spX + 7, spY);
    if ((nextLocation == ' ' || nextLocation == '$' || nextLocation == '.') && (anotherLocation == ' ' || anotherLocation == '$' || anotherLocation == '.') && (ann == ' ' || ann == '$' || ann == '.') && (annn == ' ' || annn == '$' || annn == '.') && (annnn == ' ' || annnn == '$' || annnn == '.') && (annnnn == ' ' || annnnn == '$' || annnnn == '.'))
    {
        eraseSpelunkerUp(spX, spY);
        spY = spY - 1;
        printSpelunker(spX, spY);
    }
    if (nextLocation == '$')
    {
        score = score + 10;
        printScore();
    }
    if ((nextLocation == '/' || nextLocation == '\\') || (anotherLocation == '/' || anotherLocation == '\\'))
    {
        lives--;
        printLives();
    }
}

void moveDown()
{
    char nextLocation = getCharAtxy(spX + 5, spY + 2);
    char anLocation = getCharAtxy(spX + 3, spY + 2);
    char annLocation = getCharAtxy(spX + 6, spY + 2);
    char anotherLocation = getCharAtxy(spX, spY + 2);
    if ((nextLocation == ' ' || nextLocation == '$' || nextLocation == '.') && (anotherLocation == ' ' || anotherLocation == '$' || anotherLocation == '.') && (annLocation == ' ' || annLocation == '$' || annLocation == '.'))
    {
        eraseSpelunkerDown(spX, spY);
        spY = spY + 1;
        printSpelunker(spX, spY);
    }
    if (nextLocation == '$' || anotherLocation == '$' || anLocation == '$' || annLocation == '$')
    {
        score = score + 10;
        printScore();
    }
    if ((nextLocation == '/' || nextLocation == '\\') || (anLocation == '/' || anLocation == '\\') || (anotherLocation == '/' || anotherLocation == '\\') || (annLocation == '/' || annLocation == '\\'))
    {
        lives--;
        printLives();
    }
}

void eraseSpelunkerRight(int spX, int spY)
{
    gotoxy(spX, spY);
    cout << " ";
    gotoxy(spX, spY + 1);
    cout << " ";
}

void eraseSpelunkerLeft(int spX, int spY)
{
    gotoxy(spX + 4, spY);
    cout << " ";
    gotoxy(spX + 6, spY + 1);
    cout << " ";
}

void eraseSpelunkerUp(int spX, int spY)
{
    gotoxy(spX, spY);
    cout << " ";
    gotoxy(spX, spY + 1);
    cout << "       ";
}

void eraseSpelunkerDown(int spX, int spY)
{
    gotoxy(spX, spY);
    cout << "     ";
    gotoxy(spX + 3, spY + 1);
    cout << "    ";
}

void createBullet(int spX, int spY)
{
    gotoxy(spX, spY);
    cout << ".";
}

void eraseBullet(int spX, int spY)
{
    gotoxy(spX, spY);
    cout << " ";
}

void generateBullet()
{
    bulletX[bulletCount] = spX + 7;
    bulletY[bulletCount] = spY + 1;
    isBulletActive[bulletCount] = true;
    gotoxy(spX + 7, spY + 1);
    cout << ".";
    bulletCount++;
}

void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            char another = getCharAtxy(bulletX[x] + 4, bulletY[x]);
            if (next == '\\' || next == '#' || next == '%' || next == '$' || next == '_' || next == '/')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                isBulletActive[x] = false;
            }
            if (next == '\\' || next == '/')
            {
                addScore();
                printScore();
            }
            if (next == ' ' || next == '<' || next == '^')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x] = bulletX[x] + 1;
                createBullet(bulletX[x], bulletY[x]);
            }

            if (another == '0')
            {
                batDie++;
            }
            if (another == '*')
            {
                ghostDie++;
            }
        }
    }
}

void generateBulletL()
{
    bulletXL[bulletCountL] = spX - 1;
    bulletYL[bulletCountL] = spY + 1;
    isBulletActiveL[bulletCountL] = true;
    gotoxy(spX - 1, spY + 1);
    cout << ".";
    bulletCountL++;
}

void moveBulletL()
{
    for (int x = 0; x < bulletCountL; x++)
    {
        if (isBulletActiveL[x] == true)
        {
            char next = getCharAtxy(bulletXL[x] - 1, bulletYL[x]);
            char another = getCharAtxy(bulletXL[x] - 4, bulletYL[x]);
            if (next == '\\' || next == '#' || next == '%' || next == '$' || next == '_' || next == '/')
            {
                eraseBullet(bulletXL[x], bulletYL[x]);
                isBulletActiveL[x] = false;
            }
            if (next == '\\' || next == '/')
            {
                addScore();
                printScore();
            }
            else if (next == ' ' || next == '<' || next == '^')
            {
                eraseBullet(bulletXL[x], bulletYL[x]);
                bulletXL[x] = bulletXL[x] - 1;
                createBullet(bulletXL[x], bulletYL[x]);
            }
            if (another == '0')
            {
                batDie++;
            }
            if (another == '*')
            {
                ghostDie++;
            }
        }
    }
}

void bat1Bullet()
{
    bat1BulletX[index1] = batX - 2;
    bat1BulletY[index1] = batY;
    gotoxy(bat1BulletX[index1], bat1BulletY[index1]);
    cout << "<";
    index1++;
}

void moveBat1Bullet()
{
    color1(4);
    for (int i = 0; i < index1; i++)
    {
        char next = getCharAtxy(bat1BulletX[i] - 1, bat1BulletY[i]);
        if (next == ' ')
        {
            gotoxy(bat1BulletX[i], bat1BulletY[i]);
            cout << " ";
            bat1BulletX[i]--;
            gotoxy(bat1BulletX[i], bat1BulletY[i]);
            cout << "<";
        }
        if (next == '_' || next == '}')
        {
            lives--;
            printLives();
        }
        if (next != ' ')
        {
            gotoxy(bat1BulletX[i], bat1BulletY[i]);
            cout << " ";
            for (int j = i; j < index1 - 1; j++)
            {
                bat1BulletX[j] = bat1BulletX[j + 1];
                bat1BulletY[j] = bat1BulletY[j + 1];
            }
            index1--;
        }
    }
}

void ghostBullet()
{
    ghostBulletX[index2] = ghostX + 4;
    ghostBulletY[index2] = ghostY - 7;
    gotoxy(ghostBulletX[index2], ghostBulletY[index2]);
    cout << "^";
    index2++;
}

void moveGhostBullet()
{
    color1(5);
    for (int i = 0; i < index2; i++)
    {
        char next = getCharAtxy(ghostBulletX[i], ghostBulletY[i] - 1);
        if (next == ' ')
        {
            gotoxy(ghostBulletX[i], ghostBulletY[i]);
            cout << " ";
            ghostBulletY[i]--;
            gotoxy(ghostBulletX[i], ghostBulletY[i]);
            cout << "^";
        }
        if (next == '{' || next == '}' || next == '|' || next == 'H')
        {
            lives--;
            printLives();
        }
        if (next != ' ')
        {
            gotoxy(ghostBulletX[i], ghostBulletY[i]);
            cout << " ";
            for (int j = i; j < index2 - 1; j++)
            {
                ghostBulletX[j] = ghostBulletX[j + 1];
                ghostBulletY[j] = ghostBulletY[j + 1];
            }
            index2--;
        }
    }
}

void moveBat()
{
    color1(4);
    char nextL = getCharAtxy(batX - 1, batY);
    char nextR = getCharAtxy(batX + 7, batY);
    gotoxy(batX - 1, batY);
    cout << "       ";
    gotoxy(batX, batY);
    for (int x = 0; x < 7; x++)
    {
        cout << bat[x];
    }
    if (batX < 53)
    {
        batX = batX + 1;
    }
    if (batX == 53)
    {
        gotoxy(batX - 1, batY);
        cout << "       ";
        batX = 40;
    }
    
    if (nextL == '}')
    {
        lives--;
        printLives();
    }
    if (nextR == '{' || nextR == '_')
    {
        lives--;
        printLives();
    }
    color1(2);
}

void moveBat2()
{
    color1(4);
    char nextL = getCharAtxy(bat2X - 1, bat2Y);
    char nextR = getCharAtxy(bat2X + 7, bat2Y);
    gotoxy(bat2X - 1, bat2Y);
    cout << "       ";
    gotoxy(bat2X, bat2Y);
    for (int x = 0; x < 7; x++)
    {
        cout << bat[x];
    }
    if (bat2X < 122)
    {
        bat2X++;
    }
    if (bat2X == 122)
    {
        gotoxy(bat2X - 1, bat2Y);
        cout << "       ";
        bat2X = 110;
    }
    if (nextL == '}')
    {
        lives--;
        printLives();
    }
    if (nextR == '{')
    {
        lives--;
        printLives();
    }
    color1(2);
}

void moveBat4()
{
    char nextL = getCharAtxy(bat4X - 1, bat4Y);
    char nextR = getCharAtxy(bat4X + 7, bat4Y);
    color1(4);
    gotoxy(bat4X - 1, bat4Y);
    cout << "       ";
    gotoxy(bat4X, bat4Y);
    for (int x = 0; x < 7; x++)
    {
        cout << bat[x];
    }
    if (bat4X < 30)
    {
        bat4X++;
    }
    if (bat4X == 30)
    {
        gotoxy(bat4X - 1, bat4Y);
        cout << "       ";
        bat4X = 12;
    }
    if (nextL == '}')
    {
        lives--;
        printLives();
    }
    if (nextR == '{')
    {
        lives--;
        printLives();
    }
    color1(2);
}

void moveGhost()
{
    color1(8);
    char next = getCharAtxy(ghostX, ghostY - 1);
    char another = getCharAtxy(ghostX + 1, ghostY - 1);
    char an = getCharAtxy(ghostX + 2, ghostY - 1);
    char ann = getCharAtxy(ghostX + 3, ghostY - 1);
    char annn = getCharAtxy(ghostX + 4, ghostY - 1);
    char annnn = getCharAtxy(ghostX + 5, ghostY - 1);
    char annnnn = getCharAtxy(ghostX + 6, ghostY - 1);
    gotoxy(ghostX, ghostY - 1);
    cout << "       ";
    gotoxy(ghostX, ghostY);
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 7; col++)
        {
            cout << ghost[row][col];
        }
        gotoxy(ghostX, ghostY + 1);
    }
    if (ghostY < 25)
    {
        ghostY++;
    }
    if (ghostY == 25)
    {
        gotoxy(ghostX, ghostY - 1);
        cout << "       ";
        gotoxy(ghostX, ghostY);
        cout << "       ";
        ghostY = 17;
    }
    if (next == '{' || another == '/' || an == '|' || ann == 'H' || annn == '|' || annnn == '\\' || annnnn == '}')
    {
        lives--;
        printLives();
    }
    color1(2);
}

void printGhost(int ghost2X, int ghost2Y)
{
    gotoxy(ghost2X, ghost2Y);
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 7; col++)
        {
            cout << ghost[row][col];
        }
        gotoxy(ghost2X, ghost2Y + 1);
    }
}

void eraseGhost(int ghost2X, int ghost2Y)
{
    gotoxy(ghost2X, ghost2Y);
    for (int x = 0; x < 7; x++)
    {
        cout << " ";
    }
    gotoxy(ghost2X, ghost2Y + 1);
    for (int x = 0; x < 4; x++)
    {
        cout << " ";
    }
}

void moveGhost2()
{
    color1(8);
    if (ghost2X < spX)
    {
        char next = getCharAtxy(ghost2X + 7, ghost2Y);
        char another = getCharAtxy(ghost2X + 4, ghost2Y + 1);
        if (next == ' ' && another == ' ')
        {
            eraseGhost(ghost2X, ghost2Y);
            ghost2X++;
            printGhost(ghost2X, ghost2Y);
        }
        if (next == '{' || next == '_')
        {
            lives--;
            printLives();
        }
    }
    else if (ghost2X > spX)
    {
        char next = getCharAtxy(ghost2X - 1, ghost2Y);
        char another = getCharAtxy(ghost2X - 1, ghost2Y + 1);
        if (next == ' ' && another == ' ')
        {
            eraseGhost(ghost2X, ghost2Y);
            ghost2X--;
            printGhost(ghost2X, ghost2Y);
        }
        if (next == '}' || next == '_')
        {
            lives--;
            printLives();
        }
    }
    else if (ghost2Y < spY)
    {
        char next = getCharAtxy(ghost2X + 2, ghost2Y + 2);
        char another = getCharAtxy(ghost2X + 3, ghost2Y + 2);
        if (next == ' ' && another == ' ')
        {
            eraseGhost(ghost2X, ghost2Y);
            ghost2Y++;
            printGhost(ghost2X, ghost2Y);
        }
        if (next == '0' || another == '0')
        {
            lives--;
            printLives();
        }
    }
    else if (ghost2Y > spY)
    {
        char next = getCharAtxy(ghost2X + 3, ghost2Y - 1);
        if (next == ' ')
        {
            eraseGhost(ghost2X, ghost2Y);
            ghost2Y--;
            printGhost(ghost2X, ghost2Y);
        }
        if (next == 'H')
        {
            lives--;
            printLives();
        }
    }
    color1(2);
}

void                     moveGhost4()
{
    color1(8);
    char nextL = getCharAtxy(ghost4X - 1, ghost4Y);
    char nextR = getCharAtxy(ghost4X + 7, ghost4Y);
    char next = getCharAtxy(ghost2X + 2, ghost2Y + 2);
    char another = getCharAtxy(ghost2X + 3, ghost2Y + 2);
    gotoxy(ghost4X - 1, ghost4Y);
    cout << "       ";
    gotoxy(ghost4X, ghost4Y);
    cout << "       ";
    gotoxy(ghost4X, ghost4Y);
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 7; col++)
        {
            cout << ghost[row][col];
        }
        gotoxy(ghost4X, ghost4Y + 1);
    }
    if (ghost4X < 85)
    {
        ghost4X++;
    }
    if (ghost4X == 85)
    {
        gotoxy(ghost4X - 1, ghost4Y);
        cout << "       ";
        gotoxy(ghost4X, ghost4Y + 1);
        cout << "       ";
        ghost4X = 53;
    }
    if (nextL == '}' || nextL == '_' || next == '0' || another == '0')
    {
        lives--;
        printLives();
    }
    if (nextR == '{' || nextR == '_')
    {
        lives--;
        printLives();
    }
    color1(2);
}

void addScore()
{
    score++;
}

void printScore()
{
    gotoxy(142, 6);
    color1(5);
    cout << "Score: " << score;
}

void printLives()
{
    gotoxy(142, 8);
    color1(3);
    cout << "Lives: " << lives;
}