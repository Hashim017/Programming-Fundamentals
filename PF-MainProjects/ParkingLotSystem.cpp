#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <cmath>

using namespace std;

void inputParkingConfiguration(int parking[3][5]);
void printParkingLot(int parking[3][5]);
void findCarPosition(int &carCol, int &carRow, int parking[3][5]);
void findStairPosition(int &stairCol2, int &stairCol1, int parking[3][5]);
void inputParkingConfiguration(int parking[3][5]);
void outputDirection(int diff, int down);

main() {
    int parking[3][5];
    //   = { {1, 0, 0, 0, 0},
    //       {0, 0, 1, 0, 0},
    //       {0, 0, 0, 2, 0} };

    inputParkingConfiguration(parking);
    system("cls");
    printParkingLot(parking);
    int exitCol = 4;
    int exitRow = 2;
    int carCol;
    int carRow;
    int stairCol2;
    int stairCol1;
    int down = 0;

    findCarPosition(carCol, carRow, parking);
    findStairPosition(stairCol2, stairCol1, parking);
    if (carRow == 0) {
        down = 2;
        int diff1 = carCol - stairCol2;
        outputDirection(diff1, down);
        down--;
        int diff2 = stairCol2 - stairCol1;
        outputDirection(diff2, down);
        down--;
        int diff3 = stairCol1 - exitCol;
        outputDirection(diff3, down);

    }
    else if (carRow == 1) {
        down = 1;
        int diff2 = carCol - stairCol1;
        outputDirection(diff2, down);
        down--;
        int diff3 = stairCol1 - exitCol;
        outputDirection(diff3, down);
    }
    else if (carRow == 2) {
        down = 0;
        int diff3 = carCol - exitCol;
        outputDirection(diff3, down);
    }
}
int differenceCalculator(int carCol, int stairCol) {
    return carCol - stairCol;
}
void outputDirection(int diff, int down) {
    if (diff != 0) {
        if (diff < 0) {
            cout << "Right: " << abs(diff) << endl;
        }
        else {
            cout << "Left: " << abs(diff) << endl;
        }
        if (down > 0) {
            cout << "Down: 1" << endl;
        }
    }
}
void findCarPosition(int &carCol, int &carRow, int parking[3][5]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 5; col++) {
            if (parking[row][col] == 2) {
                carCol = col;
                carRow = row;
            }
        }
    }
}
void findStairPosition(int &stairCol2, int &stairCol1, int parking[3][5]) {
    for (int i = 0; i < 5; i++) {
        if (parking[0][i] == 1) {
            stairCol2 = i;
        }
        if (parking[1][i] == 1) {
            stairCol1 = i;
        }
    }
}
void inputParkingConfiguration(int parking[3][5]) {
    cout << "Enter Ground Flood Plan " << endl << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Enter Object (2 for car, 1 for stairs, 0 for empty spaces): ";
        cin >> parking[2][i];
    }
    cout << endl;
    cout << "Enter First Flood Plan " << endl << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Enter Object (2 for car, 1 for stairs, 0 for empty spaces): ";
        cin >> parking[1][i];
    }
    cout << endl;
    cout << "Enter Second Flood Plan " << endl << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Enter Object (2 for car, 1 for stairs, 0 for empty spaces): ";
        cin >> parking[0][i];
    }
}
void printParkingLot(int parking[3][5]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 5; col++) {
            cout << parking[row][col] << "\t";
        }
        cout << endl;
    }
}