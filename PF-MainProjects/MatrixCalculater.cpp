// simple matrix calculator
#include <iostream>
#include <cstdlib>
#include <limits>
#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

int menu();
int operationMenu();
void initializeMatrix(int matrix[][3]);
void addMatrices(int matrixA[][3], int matrixB[][3], int matrixC[][3]);
void subtractMatrices(int matrixA[][3], int matrixB[][3], int matrixC[][3]);
void scalerProduct(int matrix[][3], int number);
void productMatrices(int matrixA[][3], int matrixB[][3], int matrixC[][3]);
int multiply(int matrixA[3], int matrixB[][3], int col);
void showResult(int matrix[3][3]);
bool isDiagonal(int matrix[3][3]);
void transpose(int matrix[3][3]);
bool isSymmetric(int matrix[3][3]);
void color(int color1)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
}

int main()
{
    system("cls");
    color(2);
    cout << "##::::'##::::'###::::'########:'########::'####:'##::::'##:" << endl;
    cout << "###::'###:::'## ##:::... ##..:: ##.... ##:. ##::. ##::'##::" << endl;
    cout << "####'####::'##:. ##::::: ##:::: ##:::: ##:: ##:::. ##'##:::" << endl;
    cout << "## ### ##:'##:::. ##:::: ##:::: ########::: ##::::. ###::::" << endl;
    cout << "##. #: ##: #########:::: ##:::: ##.. ##:::: ##:::: ## ##:::" << endl;
    cout << "##:.:: ##: ##.... ##:::: ##:::: ##::. ##::: ##::: ##:. ##::" << endl;
    cout << "##:::: ##: ##:::: ##:::: ##:::: ##:::. ##:'####: ##:::. ##:" << endl;
    cout << "..:::::..::..:::::..:::::..:::::..:::::..::....::..:::::..::" << endl << endl;
    int choice, subChoice;
    int matrixA[3][3], matrixB[3][3], matrixC[3][3];
    while (true)
    {
        choice = menu();
        if (choice == 1)
        {
            initializeMatrix(matrixA);
        }
        else if (choice == 2)
        {
            initializeMatrix(matrixB);
        }
        else if (choice == 4)
        {
            char mat;
            color(3);
            cout << "Which matrix do you want to print (A, B, C) : ";
            cin >> mat;
            if (mat == 'A')
            {
                showResult(matrixA);
            }
            else if (mat == 'B')
            {
                showResult(matrixB);
            }
            else if (mat == 'C')
            {
                showResult(matrixC);
            }
        }
        else if (choice == 3)
        {
            subChoice = operationMenu();
            if (subChoice == 1)
            {
                addMatrices(matrixA, matrixB, matrixC);
            }
            else if (subChoice == 2)
            {
                subtractMatrices(matrixA, matrixB, matrixC);
            }
            else if (subChoice == 3)
            {
                char mat;
                int number;
                cout << "Which matrix do you want to use (A, B) : ";
                cin >> mat;
                if (mat == 'A')
                {
                    cout << "Enter the number : ";
                    cin >> number;
                    scalerProduct(matrixA, number);
                }
                else if (mat == 'B')
                {
                    cout << "Enter the number : ";
                    cin >> number;
                    scalerProduct(matrixB, number);
                }
            }
            else if (subChoice == 4)
            {
                productMatrices(matrixA, matrixB, matrixC);
            }
            else if (subChoice == 5)
            {
                char mat;
                bool result;
                cout << "Which matrix do you want to use (A, B, C) : ";
                cin >> mat;
                if (mat == 'A')
                {
                    result = isDiagonal(matrixA);
                }
                else if (mat == 'B')
                {
                    result = isDiagonal(matrixB);
                }
                else if (mat == 'C')
                {
                    result = isDiagonal(matrixC);
                }
                if (result == 0)
                {
                    cout << "Matrix is not diagonal" << endl;
                }
                else if (result == 1)
                {
                    cout << "Matrix is diagonal" << endl;
                }
                getch();
            }
            else if (subChoice == 6)
            {
                char mat;
                bool result;
                cout << "Which matrix do you want to use (A, B, C) : ";
                cin >> mat;
                if (mat == 'A')
                {
                    transpose(matrixA);
                }
                else if (mat == 'B')
                {
                    transpose(matrixB);
                }
                else if (mat == 'C')
                {
                    transpose(matrixC);
                }
            }
            else if (subChoice == 7)
            {
                char mat;
                bool result;
                cout << "Which matrix do you want to use (A, B, C) : ";
                cin >> mat;
                if (mat == 'A')
                {
                    result = isSymmetric(matrixA);
                }
                else if (mat == 'B')
                {
                    result = isSymmetric(matrixB);
                }
                else if (mat == 'C')
                {
                    result = isSymmetric(matrixC);
                }
                if (result == 0)
                {
                    cout << "Matrix is not symmetrical" << endl;
                }
                else if (result == 1)
                {
                    cout << "Matrix is symmetrical" << endl;
                }
                getch();
            }
        }
    }
}

void initializeMatrix(int matrix[][3])
{

    color(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter the element : ";
            cin >> matrix[i][j];
        }
    }
}

int menu()
{
    int choice;
    color(5);
    cout << "1. Enter the elements of first matrix" << endl;
    cout << "2. Enter the elements of the second matrix" << endl;
    cout << "3. Operations" << endl;
    cout << "4. Print Matrix" << endl;
    cin >> choice;
    return choice;
}

int operationMenu()
{
    int choice;
    color(4);
    cout << "1. Add the matrices" << endl;
    cout << "2. Subtract the matrices" << endl;
    cout << "3. Scalar Product" << endl;
    cout << "4. Multiply the matrices" << endl;
    cout << "5. Check Diagonal Matrix" << endl;
    cout << "6. Transpose of Matrix" << endl;
    cout << "7. Check Symmetrical Matrix" << endl;
    cin >> choice;
    return choice;
}

void addMatrices(int matrixA[][3], int matrixB[][3], int matrixC[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    showResult(matrixC);
}

void subtractMatrices(int matrixA[][3], int matrixB[][3], int matrixC[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    showResult(matrixC);
}

void scalerProduct(int matrix[][3], int number)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = number * matrix[i][j];
        }
    }
    showResult(matrix);
}

void showResult(int matrix[3][3])
{
    color(6);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    getch();
}

void productMatrices(int matrixA[][3], int matrixB[][3], int matrixC[][3])
{
    int result;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result = multiply(matrixA[i], matrixB, j);
            matrixC[i][j] = result;
        }
    }
    showResult(matrixC);
}

int multiply(int matrixA[3], int matrixB[][3], int col)
{
    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        result = result + matrixA[i] * matrixB[i][col];
    }
    return result;
}

bool isDiagonal(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

void transpose(int matrix[3][3])
{
    int tempMatrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tempMatrix[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[j][i] = tempMatrix[i][j];
        }
    }
}

bool isSymmetric(int matrix[3][3])
{
    int tempMatrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tempMatrix[i][j] = matrix[i][j];
        }
    }
    transpose(matrix);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(tempMatrix[i][j] != matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
