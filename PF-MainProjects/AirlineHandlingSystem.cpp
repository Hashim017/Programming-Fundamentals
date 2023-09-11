#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

// Global Arrays And Variables

string names[100] = {"Hashim"};
string passwords[100] = {"123"};
string roles[100] = {"manager"};

string flightNames[100];
int flightPricesB[100];
int flightPricesE[100];
string flightTimes[100];
string flightRoutes[100];
int ticketsQuantity[100];
string routess[100];
string namess[100];
int pricesB[100];
int pricesE[100];
int quantityT[100];

int count = 1;
int Flightscount = 0;
int displayTickets = 0;
int pass = 0;

int mainMenuIndex = 0;
int clientInterfaceIndex = 0;
int managerMenuIndex = 0;
int clientMenuIndex = 0;
int ticketClassIndex = 0;

// Function Prototypes

void gotoxy(int x, int y);
void color1(int color);
string getField(string record, int field);
bool checkvalidint(string testQuantity);
void interFace();
void header();
int checkArray(string name, string password);
void signUp();
void addCredentials(string username, string password, string role);
void storeCredentials(string username, string password, string role);
void loadCredentials();
string signIn();
int clientInterface();
int mainMenu();
void managerMenu();
int managerMenuOptions();
void clientSignIn();
void getFlightData();
void addFlights(string name, int priceB, int priceE, string time, string route, int quantity);
void storeFlights();
void loadFlights();
int checkArrays(string name, string route);
void updatePrice(string name);
void viewFlights();
void updateTime(string name);
void removeFlight();
void clearScreen();
void updateRoutes(string name);
void updateTickets(string name);
void flightCheck(string name);
void clientMenu();
int clientMenuOptions();
void findFlight(string route);
bool loadFlights(string route, bool check);
void displayFlights(string route);
void checkFlight(string fName, string route);
void selectClass(int pass);
void businessTicket(int pass);
void economyTicket(int pass);
void confirmTickets(int pass);
int ticketClass();
void addAdmin();
void viewTickets();
void refundTickets();
void confirmRefunding();
void getHelp();

main()
{
    int op;

    loadFlights();
    loadCredentials();
    interFace();
    while (op != 2)
    {
        // color1(11);
        op = mainMenu();
        if (op == 0)
        {
            string userRole = signIn();
            if (userRole == "manager")
            {
                cout << endl;
                cout << "Your are Entering In Manager Menu" << endl;
                clearScreen();
                managerMenu();
            }
            else if (userRole == "client")
            {
                cout << endl;
                cout << "Your are Entering In client menu" << endl;
                clearScreen();
                clientMenu();
            }
            else
            {
                cout << endl;
                cout << "Credentials Do Not Exist." << endl;
                clearScreen();
            }
        }
        else if (op == 1)
        {
            clientSignIn();
        }
    }
    storeFlights();
    system("cls");
    header();
    cout << endl;
    cout << "Thanks for using Airline Management System :)" << endl;
    clearScreen();
}

// Funtion Definitions

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void color1(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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

bool checkvalidint(string testQuantity)
{
    string x = testQuantity;
    for (int z = 0; z < x.length(); z++)
    {
        if (testQuantity[z] != '0' && testQuantity[z] != '1' && testQuantity[z] != '2' && testQuantity[z] != '3' && testQuantity[z] != '4' && testQuantity[z] != '5' && testQuantity[z] != '6' && testQuantity[z] != '7' && testQuantity[z] != '8' && testQuantity[z] != '9' && testQuantity[z] != '.')
        {
            return false;
        }
    }
    return true;
}

void interFace()
{
    color1(4);
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                          " << endl;
    cout << "//  .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------. //                          " << endl;
    color1(6);
    cout << "//  |      __      | | |     _____    | | |  _______     | | |   _____      | | |     _____    | | | ____  _____  | | |  _________   | //                          " << endl;
    cout << "//  |     /  \\     | | |    |_   _|   | | | |_   __ \\    | | |  |_   _|     | | |    |_   _|   | | ||_   \\|_   _| | | | |_   ___  |  | //                       " << endl;
    cout << "//  |    / /\\ \\    | | |      | |     | | |   | |__) |   | | |    | |       | | |      | |     | | |  |   \\ | |   | | |   | |_  \\_|  | //                      " << endl;
    cout << "//  |   / ____ \\   | | |      | |     | | |   |  __ /    | | |    | |   _   | | |      | |     | | |  | |\\ \\| |   | | |   |  _|  _   | //                       " << endl;
    cout << "//  | _/ /    \\ \\_ | | |     _| |_    | | |  _| |  \\ \\_  | | |   _| |__/ |  | | |     _| |_    | | | _| |_\\   |_  | | |  _| |___/ |  | //                     " << endl;
    cout << "//  ||____|  |____|| | |    |_____|   | | | |____| |___| | | |  |________|  | | |    |_____|   | | ||_____|\\____| | | | |_________|  | //                         " << endl;
    color1(4);
    cout << "//  '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' //////////////////////      " << endl;
    color1(6);
    cout << "//  |  ____  ____  | | |      __      | | | ____  _____  | | |  ________    | | |   _____      | | |     _____    | | | ____  _____  | | |    ______    |  //      " << endl;
    cout << "//  | |_   ||   _| | | |     /  \\     | | ||_   \\|_   _| | | | |_   ___ `.  | | |  |_   _|     | | |    |_   _|   | | ||_   \\|_   _| | | |  .' ___  |   |  //   " << endl;
    cout << "//  |   | |__| |   | | |    / /\\ \\    | | |  |   \\ | |   | | |   | |   `. \\ | | |    | |       | | |      | |     | | |  |   \\ | |   | | | / .'   \\_|   |  //" << endl;
    cout << "//  |   |  __  |   | | |   / ____ \\   | | |  | |\\ \\| |   | | |   | |    | | | | |    | |   _   | | |      | |     | | |  | |\\ \\| |   | | | | |    ____  |  // " << endl;
    cout << "//  |  _| |  | |_  | | | _/ /    \\ \\_ | | | _| |_\\   |_  | | |  _| |___.' / | | |   _| |__/ |  | | |     _| |_    | | | _| |_\\   |_  | | | \\ `.___]  _| |  // " << endl;
    cout << "//  | |____||____| | | ||____|  |____|| | ||_____|\\____| | | | |________.'  | | |  |________|  | | |    |_____|   | | ||_____|\\____| | | |  `._____.'   |  //    " << endl;
    color1(4);
    cout << "//  .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------.   .--------------.   .--------------.  //     " << endl;
    color1(6);
    cout << "//  |    _______   | | |  ____  ____  | | |    _______   | | |  _________   | | |  _________   | | | ____    ____ | /////////////////////////////////////////       " << endl;
    cout << "//  |   /  ___  |  | | | |_  _||_  _| | | |   /  ___  |  | | | |  _   _  |  | | | |_   ___  |  | | ||_   \\  /   _|| //                                            " << endl;
    cout << "//  |  |  (__ \\_|  | | |   \\ \\  / /   | | |  |  (__ \\_|  | | | |_/ | | \\_|  | | |   | |_  \\_|  | | |  |   \\/   |  | //                                      " << endl;
    cout << "//  |   '.___`-.   | | |    \\ \\/ /    | | |   '.___`-.   | | |     | |      | | |   |  _|  _   | | |  | |\\  /| |  | //                                          " << endl;
    cout << "//  |  |`\\____) |  | | |    _|  |_    | | |  |`\\____) |  | | |    _| |_     | | |  _| |___/ |  | | | _| |_\\/_| |_ | //                                          " << endl;
    cout << "//  |  |_______.'  | | |   |______|   | | |  |_______.'  | | |   |_____|    | | | |_________|  | | ||_____||_____|| //                                           " << endl;
    color1(4);
    cout << "//  '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' ///////////////////////////////////////////// " << endl;
    color1(6);
    cout << "//                                                                                                                           _,'` \\_______/,====/              //" << endl;
    cout << "//                                                                                                                   _____,-' _.-'`      ,`    /               //" << endl;
    cout << "//                                                     _.---....__/______________________________________________.-'`    |         ,`        /                 //" << endl;
    cout << "//                                                   .'.      | /                |        |                |``''-----....|_________\\_______/_                  //" << endl;
    cout << "//                                              __.'   \\   __|/_______          |  ____  |____________,...|---------........___| |_________,=`                 //" << endl;
    cout << "//                             ________,,...---' ||  '--          |    _::::====== < ____ > ----------------|            ==:::::===|   |  |                    //" << endl;
    cout << "//                            :'''``     ``''----+---------------'''``        _____________________________|__           |      | |   |  |/                    //" << endl;
    cout << "//                      _,.-'||        _         |       | _--========:''''```                       .'   `.  |_________=====================                  //" << endl;
    cout << "//                     `-.._ || -:::: |_|        |       ||_| |_       ``'''----------------.-------.---------'          |      | | __|__|\\_                   //" << endl;
    cout << "//                          '||                  |     __|=== |_]........        :       /|__\\______|___,---.    ____,...|,.----'''` _;                        //" << endl;
    cout << "//                            `'----.....________|____[____]__|__________________:_____<::|_____________::::|-''`        ___,..---''`                          //" << endl;
    cout << "//                                                       `----------'\\|             `---''-._,.---''`                                                          //" << endl;
    color1(4);
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    getch();
}

void header()
{
    system("cls");
    color1(6);
    cout << "            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    color1(2);
    cout << "            ////          $$$$$$\\  $$\\           $$\\ $$\\                            $$$$$$\\                        $$\\                                             ////" << endl;
    cout << "            ////         $$  __$$\\ \\__|          $$ |\\__|                          $$  __$$\\                       $$ |                                            ////" << endl;
    cout << "            ////         $$ /  $$ |$$\\  $$$$$$\\  $$ |$$\\ $$$$$$$\\   $$$$$$\\        $$ /  \\__|$$\\   $$\\  $$$$$$$\\ $$$$$$\\    $$$$$$\\  $$$$$$\\$$$$\\                  ////" << endl;
    cout << "            ////         $$$$$$$$ |$$ |$$  __$$\\ $$ |$$ |$$  __$$\\ $$  __$$\\       \\$$$$$$\\  $$ |  $$ |$$  _____|\\_$$  _|  $$  __$$\\ $$  _$$  _$$\\                 ////" << endl;
    cout << "            ////         $$  __$$ |$$ |$$ |  \\__|$$ |$$ |$$ |  $$ |$$$$$$$$ |       \\____$$\\ $$ |  $$ |\\$$$$$$\\    $$ |    $$$$$$$$ |$$ / $$ / $$ |                ////" << endl;
    cout << "            ////         $$ |  $$ |$$ |$$ |      $$ |$$ |$$ |  $$ |$$   ____|      $$\\   $$ |$$ |  $$ | \\____$$\\   $$ |$$\\ $$   ____|$$ | $$ | $$ |                ////" << endl;
    cout << "            ////         $$ |  $$ |$$ |$$ |      $$ |$$ |$$ |  $$ |\\$$$$$$$\\       \\$$$$$$  |\\$$$$$$$ |$$$$$$$  |  \\$$$$  |\\$$$$$$$\\ $$ | $$ | $$ |                ////" << endl;
    cout << "            ////         \\__|  \\__|\\__|\\__|      \\__|\\__|\\__|  \\__| \\_______|       \\______/  \\____$$ |\\_______/    \\____/  \\_______|\\__| \\__| \\__|                ////" << endl;
    cout << "            ////                                                                             \\$$$$$$ |                                                             ////" << endl;
    cout << "            ////                                                                              \\______/                                                             ////" << endl;
    color1(6);
    cout << "            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl
         << endl;
    color1(3);
}

int mainMenu()
{
    while (true)
    {
        header();
        // Display the menu options
        cout << "Select One Of The Following Options:\n";
        cout << endl;
        cout << (mainMenuIndex == 0 ? "> For Admin Sign In.\n" : "  For Admin Sign In.\n");
        // if (mainMenuIndex == 0)
        // {
        //     cout << "> For Admin Sign In.\n";
        // }
        // else
        // {
        //     cout << "  For Admin Sign In.\n";
        // }
        cout << (mainMenuIndex == 1 ? "> For Customer.\n" : "  For Customer.\n");
        cout << (mainMenuIndex == 2 ? "> Exit.\n" : "  Exit.\n");

        char input = getch();

        if (input == 72)
        {
            mainMenuIndex = (mainMenuIndex + 2) % 3;
        }
        else if (input == 80)
        {
            mainMenuIndex = (mainMenuIndex + 1) % 3;
        }
        else if (input == 13)
        {
            return mainMenuIndex;
            break;
        }
        else
        {
            continue;
        }
    }
}

// Login Functions.

void clientSignIn()
{
    int x = -1;
    while (x != 2)
    {
        x = clientInterface();
        if (x == 0)
        {
            string userRole = signIn();
            if (userRole == "client")
            {
                cout << endl;
                cout << "Your are Entering In client menu" << endl;
                clearScreen();
                clientMenu();
            }
            else
            {
                cout << endl;
                cout << "User Not Found Kindly Sign Up First." << endl;
                clearScreen();
            }
        }
        if (x == 1)
        {
            signUp();
        }
    }
}

int clientInterface()
{
    while (true)
    {
        header();
        // Display the menu options
        cout << "Select One Of The Following Options:\n";
        cout << endl;
        cout << (clientInterfaceIndex == 0 ? "> For Sign In.\n" : "  For Sign In.\n");
        cout << (clientInterfaceIndex == 1 ? "> For Sign Up.\n" : "  For Sign Up.\n");
        cout << (clientInterfaceIndex == 2 ? "> To Return To Main Menu.\n" : "  To Return To Main Menu.\n");

        char input = getch();

        if (input == 72)
        {
            clientInterfaceIndex = (clientInterfaceIndex + 2) % 3;
        }
        else if (input == 80)
        {
            clientInterfaceIndex = (clientInterfaceIndex + 1) % 3;
        }
        else if (input == 13)
        {
            return clientInterfaceIndex;
            break;
        }
        else
        {
            continue;
        }
    }
}

int checkArray(string name, string password)
{
    bool tf = false;
    for (int x = 0; x < count; x++)
    {
        if (name == names[x])
        {
            tf = true;
            break;
        }
    }
    if (tf)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void signUp()
{
    string username;
    string password;
    string role;

    system("cls");
    header();

    cout << "Enter your name: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    int check = 0;
    check = checkArray(username, password);
    if (check == 0)
    {
        role = "client";
        addCredentials(username, password, role);
        storeCredentials(username, password, role);
    }
    if (check == 1)
    {
        cout << endl
             << "Credentials Already Exists Try Different Username." << endl;
        clearScreen();
    }
}

void addCredentials(string username, string password, string role)
{
    names[count] = username;
    passwords[count] = password;
    roles[count] = role;
    count++;
    cout << endl
         << "Congratulations, User Added Successfully." << endl;
    clearScreen();
}

void storeCredentials(string username, string password, string role)
{
    fstream newfile;
    newfile.open("Credentials.txt", ios::app);
    newfile << username << "," << password << "," << role << endl;
    newfile.close();
}

void loadCredentials()
{
    string record;
    fstream data;
    data.open("Credentials.txt", ios::in);
    while (getline(data, record))
    {
        names[count] = getField(record, 1);
        passwords[count] = getField(record, 2);
        roles[count] = getField(record, 3);
        count++;
    }
    data.close();
}

string signIn()
{
    system("cls");
    header();
    cout << endl;

    string name, password;

    cout << "Enter Username: ";
    cin >> name;
    cout << "Enter Password: ";
    cin >> password;

    bool tf = false;
    int x;
    for (x = 0; x < count; x++)
    {
        if (name == names[x] && password == passwords[x])
        {
            tf = true;
            break;
        }
    }
    if (tf)
    {
        return roles[x];
    }
    else
    {
        return "undefined";
    }
}

// Manager functions.

void managerMenu()
{
    string name;
    int x = -1;
    while (x != 9)
    {
        x = managerMenuOptions();

        if (x == 0)
        {
            getFlightData();
        }
        if (x == 1)
        {
            header();
            cout << "Enter Name of Flight: ";
            cin >> name;
            updatePrice(name);
        }
        if (x == 2)
        {
            viewFlights();
        }
        if (x == 3)
        {
            header();
            cout << "Enter Name of Flight: ";
            cin >> name;
            updateTime(name);
        }
        if (x == 4)
        {
            header();
            removeFlight();
        }
        if (x == 5)
        {
            header();
            cout << "Enter Name of Flight: ";
            cin >> name;
            updateRoutes(name);
        }
        if (x == 6)
        {
            header();
            cout << "Enter Name of Flight: ";
            cin >> name;
            updateTickets(name);
        }
        if (x == 7)
        {
            addAdmin();
        }
        if (x == 8)
        {
            header();
            cout << "Enter Name of Flight: ";
            cin >> name;
            flightCheck(name);
        }
    }
}

int managerMenuOptions()
{
    while (true)
    {
        header();
        // Display the menu options
        cout << "Select One Of The Following Options:\n";
        cout << endl;
        cout << (managerMenuIndex == 0 ? "> To add flight.\n" : "  To add flight.\n");
        cout << (managerMenuIndex == 1 ? "> To update the prices.\n" : "  To update the prices.\n");
        cout << (managerMenuIndex == 2 ? "> To view the flights.\n" : "  To view the flights.\n");
        cout << (managerMenuIndex == 3 ? "> To update timings of flights.\n" : "  To update timings of flights.\n");
        cout << (managerMenuIndex == 4 ? "> To remove or cancel the flights.\n" : "  To remove or cancel the flights.\n");
        cout << (managerMenuIndex == 5 ? "> To update flights routes.\n" : "  To update flights routes.\n");
        cout << (managerMenuIndex == 6 ? "> To update the tickets Quantity.\n" : "  To update the tickets Quantity.\n");
        cout << (managerMenuIndex == 7 ? "> To add another admin.\n" : "  To add another admin.\n");
        cout << (managerMenuIndex == 8 ? "> To view either flight is full or not after sale of tickets.\n" : "  To view either flight is full or not after sale of tickets.\n");
        cout << (managerMenuIndex == 9 ? "> To Exit.\n" : "  To Exit.\n");

        char input = getch();

        if (input == 72)
        {
            managerMenuIndex = (managerMenuIndex + 9) % 10;
        }
        else if (input == 80)
        {
            managerMenuIndex = (managerMenuIndex + 1) % 10;
        }
        else if (input == 13)
        {
            return managerMenuIndex;
            break;
        }
        else
        {
            continue;
        }
    }
}

void getFlightData()
{
    string name, time, route, testQuantity, testPriceB, testPriceE;
    int priceB, priceE, quantity;

    header();
    cout << "Enter Flight Name: ";
    cin >> name;
    while ((checkvalidint(name)))
    {
        cout << endl
             << "Invalid Name, Kindly Re Enter: ";
        cin >> name;
    }
    cout << "Enter Business Seat Price (In Dollars) : ";
    cin >> testPriceB;
    while ((!checkvalidint(testPriceB)))
    {
        cout << endl
             << "Invalid Price, Kindly Re Enter: ";
        cin >> testPriceB;
    }
    priceB = stoi(testPriceB);
    cout << "Enter Economy Seat Price (In Dollars) : ";
    cin >> testPriceE;
    while ((!checkvalidint(testPriceE)))
    {
        cout << endl
             << "Invalid Price, Kindly Re Enter: ";
        cin >> testPriceE;
    }
    priceE = stoi(testPriceE);
    cout << "Enter Flight Time: ";
    cin.ignore();
    getline(cin, time);
    cout << "Enter Flight Route: ";
    getline(cin, route);
    cout << "Enter Number Of Tickets: ";
    cin >> testQuantity;
    while ((!checkvalidint(testQuantity)))
    {
        cout << endl
             << "Invalid Quantity, Kindly Re Enter: ";
        cin >> testQuantity;
    }
    quantity = stoi(testQuantity);

    int check = checkArrays(name, route);

    if (check == 1)
    {
        cout << endl;
        cout << "Flight Name or Route Already Exists." << endl;
        clearScreen();
    }

    else if (check == 0)
    {
        addFlights(name, priceB, priceE, time, route, quantity);
        storeFlights();
    }
}

void addFlights(string name, int priceB, int priceE, string time, string route, int quantity)
{
    flightNames[Flightscount] = name;
    flightPricesB[Flightscount] = priceB;
    flightPricesE[Flightscount] = priceE;
    flightTimes[Flightscount] = time;
    flightRoutes[Flightscount] = route;
    ticketsQuantity[Flightscount] = quantity;
    Flightscount++;
    cout << endl
         << "Flight Added Successfully." << endl;
    clearScreen();
}

void storeFlights()
{
    fstream data;
    data.open("FlightsRecord.txt", ios::out);
    for (int x = 0; x < Flightscount; x++)
    {
        data << flightNames[x] << "," << flightPricesB[x] << "," << flightPricesE[x] << "," << flightTimes[x] << "," << flightRoutes[x] << "," << ticketsQuantity[x] << endl;
    }
    data.close();
}

void loadFlights()
{
    string record;
    fstream data;
    data.open("FlightsRecord.txt", ios::in);
    while (getline(data, record))
    {
        flightNames[Flightscount] = getField(record, 1);
        flightPricesB[Flightscount] = stof(getField(record, 2));
        flightPricesE[Flightscount] = stof(getField(record, 3));
        flightTimes[Flightscount] = getField(record, 4);
        flightRoutes[Flightscount] = getField(record, 5);
        ticketsQuantity[Flightscount] = stoi(getField(record, 6));
        Flightscount++;
    }
    data.close();
}

int checkArrays(string name, string route)
{
    bool tf = false;
    for (int x = 0; x <= Flightscount; x++)
    {
        if (flightNames[x] == name && route == flightRoutes[x])
        {
            tf = true;
            break;
        }
    }
    if (tf)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void updatePrice(string name)
{
    string priceB, priceE;
    int count = 0;
    int x;
    for (x = 0; x < Flightscount; x++)
    {
        if (name == flightNames[x])
        {
            count++;
            break;
        }
    }
    if (count != 0)
    {
        cout << "Business Seat Price Is: " << flightPricesB[x] << " $" << endl;
        cout << "Enter New Price (In Dollars): ";
        cin >> priceB;
        while ((!checkvalidint(priceB)))
        {
            cout << endl
                 << "Invalid Price, Kindly Re Enter: ";
            cin >> priceB;
        }
        flightPricesB[x] = stoi(priceB);
        cout << "Economy Seat Price Is: " << flightPricesE[x] << " $" << endl;
        cout << "Enter New Price (In Dollars): ";
        cin >> priceE;
        while ((!checkvalidint(priceE)))
        {
            cout << endl
                 << "Invalid Price, Kindly Re Enter: ";
            cin >> priceE;
        }
        flightPricesE[x] = stoi(priceE);
        cout << endl
             << "Price Updated Successfully." << endl;
        storeFlights();
        clearScreen();
    }
    if (count == 0)
    {
        cout << endl
             << "Flight Not Found." << endl;
        clearScreen();
    }
}

void viewFlights()
{
    header();
    int num = 1;
    int a;
    int b = 17;

    for (int x = 0; x < Flightscount; x++)
    {
        a = 3;
        if (flightNames[x] != "!")
        {
            cout << num << "- "
                 << "Flight Name: "
                 << "\t"
                 << "\t"
                 << "Business Seat Price: "
                 << "\t"
                 << "\t"
                 << "Economy Seat Price: "
                 << "\t"
                 << "\t"
                 << "Flight Time: "
                 << "\t"
                 << "\t"
                 << "Flight Route: "
                 << "\t"
                 << "\t"
                 << "Quantity Of Tickets: "
                 << endl;
            gotoxy(a, b);
            cout << flightNames[x];
            a = 32;
            gotoxy(a, b);
            cout << flightPricesB[x];
            gotoxy(a = a + 32, b);
            cout << flightPricesE[x];
            gotoxy(a = a + 32, b);
            cout << flightTimes[x];
            gotoxy(a = a + 24, b);
            cout << flightRoutes[x];
            gotoxy(a = a + 24, b);
            cout << ticketsQuantity[x];
            cout << endl
                 << endl;
        }
        b = b + 3;
        num++;
    }
    clearScreen();
}

void updateTime(string name)
{
    string time;
    int count = 0;

    for (int x = 0; x < Flightscount; x++)
    {
        if (name == flightNames[x])
        {
            cout << "Flight Time Is: " << flightTimes[x] << endl;
            cout << "Enter New Time: ";
            cin.ignore();
            getline(cin, time);
            flightTimes[x] = time;
            cout << endl
                 << "Time Updated Successfully." << endl;
            storeFlights();
            clearScreen();
            count++;
        }
    }
    if (count == 0)
    {
        cout << endl
             << "Flight Not Found." << endl;
        clearScreen();
    }
}

void removeFlight()
{
    string name;
    int num = 1;
    int a;
    int b = 17;

    for (int x = 0; x < Flightscount; x++)
    {
        a = 3;
        if (flightNames[x] != "!")
        {
            cout << num << "- "
                 << "Flight Name: "
                 << "\t"
                 << "\t"
                 << "Business Seat Price: "
                 << "\t"
                 << "\t"
                 << "Economy Seat Price: "
                 << "\t"
                 << "\t"
                 << "Flight Time: "
                 << "\t"
                 << "\t"
                 << "Flight Route: "
                 << "\t"
                 << "\t"
                 << "Quantity Of Tickets: "
                 << endl;
            gotoxy(a, b);
            cout << flightNames[x];
            a = 32;
            gotoxy(a, b);
            cout << flightPricesB[x] << " $";
            gotoxy(a = a + 32, b);
            cout << flightPricesE[x] << " $";
            gotoxy(a = a + 32, b);
            cout << flightTimes[x];
            gotoxy(a = a + 24, b);
            cout << flightRoutes[x];
            gotoxy(a = a + 24, b);
            cout << ticketsQuantity[x];
            cout << endl
                 << endl;
        }
        b = b + 3;
        num++;
    }
    cout << "Enter Name of Flight: ";
    cin >> name;
    bool tf = false;
    int x;
    for (x = 0; x < Flightscount; x++)
    {
        if (name == flightNames[x])
        {
            tf = true;
            break;
        }
    }
    if (tf)
    {
        flightNames[x] = "!";
        flightRoutes[x] = "!";
        cout << endl
             << "Flight Removed Successfully." << endl;
        storeFlights();
        clearScreen();
    }
    else
    {
        cout << endl
             << "Invalid Flight Name." << endl;
        clearScreen();
    }
}

void clearScreen()
{
    color1(13);
    cout << endl;
    cout << "                                                                       Press Any Key To Continue.";
    getch();
    system("cls");
    color1(7);
}

void updateRoutes(string name)
{
    string route;
    int count = 0;
    for (int x = 0; x < Flightscount; x++)
    {
        if (name == flightNames[x])
        {
            cout << "Flight Route Is: " << flightRoutes[x] << endl;
            cout << "Enter New Route: ";
            cin.ignore();
            getline(cin, route);
            flightRoutes[x] = route;
            cout << endl
                 << "Route Updated Successfully." << endl;
            storeFlights();
            clearScreen();
            count++;
        }
    }
    if (count == 0)
    {
        cout << endl
             << "Flight Not Found." << endl;
        clearScreen();
    }
}

void updateTickets(string name)
{
    string testQuantity;
    int quantity;
    int count = 0;

    for (int x = 0; x < Flightscount; x++)
    {
        if (name == flightNames[x])
        {
            cout << "Quantity of Tickets Is: " << ticketsQuantity[x] << endl;
            cout << "Enter Number of Tickets You Want To Add: ";
            cin >> testQuantity;
            while ((!checkvalidint(testQuantity)))
            {
                cout << endl
                     << "Invalid Quantity, Kindly Re Enter: ";
                cin >> testQuantity;
            }
            quantity = stoi(testQuantity);
            ticketsQuantity[x] = quantity + ticketsQuantity[x];
            cout << endl
                 << "Tickets Quantity Updated Successfully." << endl;
            storeFlights();
            clearScreen();
            count++;
        }
    }
    if (count == 0)
    {
        cout << endl
             << "Flight Not Found." << endl;
        clearScreen();
    }
}

void addAdmin()
{
    string username;
    string password;
    string role;

    system("cls");
    header();

    cout << "Enter name: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    int check = 0;
    check = checkArray(username, password);
    if (check == 0)
    {
        role = "manager";
        addCredentials(username, password, role);
        storeCredentials(username, password, role);
    }
    if (check == 1)
    {
        cout << endl
             << "Credentials Already Exists Try Different Username or Password." << endl;
        clearScreen();
    }
}

void flightCheck(string name)
{
    int x;

    bool tf = false;
    for (x = 0; x < Flightscount; x++)
    {
        if (name == flightNames[x])
        {
            tf = true;
            break;
        }
    }
    if (tf == true && ticketsQuantity[x] == 0)
    {
        cout << endl
             << "Flight Is Full." << endl;
    }
    else if (tf == true && ticketsQuantity[x] != 0)
    {
        cout << endl
             << "Flight Is Not Full." << endl;
        cout << "Remaining Tickets Are: " << ticketsQuantity[x] << endl;
        clearScreen();
    }
    else
    {
        cout << endl
             << "Flight Not Found." << endl;
        clearScreen();
    }
}

// Client functions.

void clientMenu()
{
    header();
    int x = -1;
    string route;

    while (x != 4)
    {
        header();
        x = clientMenuOptions();

        if (x == 0)
        {
            header();
            cout << "Enter Route of Flight: ";
            cin.ignore();
            getline(cin, route);
            findFlight(route);
        }
        else if (x == 1)
        {
            viewTickets();
        }
        else if (x == 2)
        {
            refundTickets();
        }
        else if (x == 3)
        {
            getHelp();
        }
    }
}

int clientMenuOptions()
{
    while (true)
    {
        header();
        // Display the menu options
        cout << "Select One Of The Following Options:\n";
        cout << endl;
        cout << (clientMenuIndex == 0 ? "> To Find A Flight.\n" : "  To Find A Flight.\n");
        cout << (clientMenuIndex == 1 ? "> To View Tickets.\n" : "  To View Tickets.\n");
        cout << (clientMenuIndex == 2 ? "> To Refund Tickets.\n" : "  To Refund Tickets.\n");
        cout << (clientMenuIndex == 3 ? "> To Get Help.\n" : "  To Get Help.\n");
        cout << (clientMenuIndex == 4 ? "> To Exit.\n" : "  To Exit.\n");

        char input = getch();

        if (input == 72)
        {
            clientMenuIndex = (clientMenuIndex + 4) % 5;
        }
        else if (input == 80)
        {
            clientMenuIndex = (clientMenuIndex + 1) % 5;
        }
        else if (input == 13)
        {
            return clientMenuIndex;
            break;
        }
        else
        {
            continue;
        }
    }
}

void findFlight(string route)
{
    bool check = false;

    bool checkCount = loadFlights(route, check);
    if (checkCount == true)
    {
        displayFlights(route);
    }
    else if (checkCount == false)
    {
        cout << endl;
        cout << "Unfortunately, No Flights Are Available." << endl;
        clearScreen();
    }
}

bool loadFlights(string route, bool check)
{
    for (int x = 0; x < Flightscount; x++)
    {
        if (route == flightRoutes[x])
        {
            namess[x] = flightNames[x];
            routess[x] = flightRoutes[x];
            pricesB[x] = flightPricesB[x];
            pricesE[x] = flightPricesE[x];
            check = true;
        }
    }
    return check;
}

void displayFlights(string route)
{
    int num = 1;
    int a;
    int b = 19;
    string fName;

    for (int y = 0; y < Flightscount; y++)
    {
        a = 3;
        if (route == routess[y])
        {
            cout << endl;
            cout << num << "- ";
            cout << "Flight Name: "
                 << "\t"
                 << "\t"
                 << "Flight Route: "
                 << "\t"
                 << "\t"
                 << "Flight Time: "
                 << endl;
            gotoxy(a, b);
            cout << namess[y];
            a = 32;
            gotoxy(a, b);
            cout << routess[y];
            gotoxy(a + 24, b);
            cout << flightTimes[y];
            cout << endl;
        }
        num++;
        b = b + 3;
    }
    cout << endl
         << endl
         << "Select Name of Flight: ";
    cin >> fName;
    checkFlight(fName, route);
}

void checkFlight(string fName, string route)
{
    bool tf = false;
    for (int x = 0; x < Flightscount; x++)
    {
        if (fName == flightNames[x])
        {
            tf = true;
            pass = x;
            break;
        }
    }
    if (tf)
    {
        selectClass(pass);
    }
    else
    {
        cout << endl
             << endl
             << "Invalid Flight Name." << endl;
        clearScreen();
    }
}

void selectClass(int pass)
{
    int option;
    header();
    while (option != 2)
    {
        option = ticketClass();
        if (option == 0)
        {
            businessTicket(pass);
        }
        if (option == 1)
        {
            economyTicket(pass);
        }
    }
}

int ticketClass()
{
    while (true)
    {
        header();
        cout << "Select Class of Ticket: \n";
        cout << endl;
        cout << (ticketClassIndex == 0 ? "> Business.\n" : "  Business.\n");
        cout << (ticketClassIndex == 1 ? "> Economy.\n" : "  Economy.\n");
        cout << (ticketClassIndex == 2 ? "> To Exit.\n" : "  To Exit.\n");

        char input = getch();

        if (input == 72)
        {
            ticketClassIndex = (ticketClassIndex + 2) % 3;
        }
        else if (input == 80)
        {
            ticketClassIndex = (ticketClassIndex + 1) % 3;
        }
        else if (input == 13)
        {
            return ticketClassIndex;
            break;
        }
        else
        {
            continue;
        }
    }
}

void businessTicket(int pass)
{
    string testQuantity;
    header();
    cout << "Price of One Business Class Seat Is: " << pricesB[pass] << " $" << endl
         << endl;
    cout << "Enter The Quantity of Tickets You Want To Buy: ";
    cin >> testQuantity;
    while ((!checkvalidint(testQuantity)))
    {
        cout << endl
             << "Invalid Quantity, Kindly Re Enter: ";
        cin >> testQuantity;
    }
    quantityT[pass] = stoi(testQuantity);
    if (quantityT[pass] > ticketsQuantity[pass])
    {
        cout << endl
             << "Sorry, Available Tickets Are: " << ticketsQuantity[pass] << endl;
        clearScreen();
    }
    if (quantityT[pass] <= ticketsQuantity[pass])
    {
        header();
        cout << "Your Payable Amount Is: " << quantityT[pass] * pricesB[pass] << " $"
             << endl;
        confirmTickets(pass);
    }
}

void economyTicket(int pass)
{
    string testQuantity;
    header();
    cout << "Price of One Economy Class Seat Is: " << pricesE[pass] << " $" << endl
         << endl;
    cout << "Enter The Quantity of Tickets You Want To Buy: ";
    cin >> testQuantity;
    while ((!checkvalidint(testQuantity)))
    {
        cout << endl
             << "Invalid Quantity, Kindly Re Enter: ";
        cin >> testQuantity;
    }
    quantityT[pass] = stoi(testQuantity);
    if (quantityT[pass] > ticketsQuantity[pass])
    {
        cout << endl
             << "Sorry, Available Tickets Are: " << ticketsQuantity[pass] << endl;
        clearScreen();
    }
    if (quantityT[pass] <= ticketsQuantity[pass])
    {
        header();
        cout << "Your Payable Amount Is: " << quantityT[pass] * pricesE[pass] << " $"
             << endl;
        confirmTickets(pass);
    }
}

void confirmTickets(int pass)
{
    int y;

    cout << endl
         << endl
         << "Press 1 To Confirm Tickets." << endl;
    cout << "Press Any Key To Exit." << endl;
    cout << "Your Option: ";
    cin >> y;
    if (y == 1)
    {
        system("cls");
        header();
        cout << endl
             << endl
             << "Thanks For Using Our Airline Management System. Have A Safe Journey :)"
             << endl;
        displayTickets = displayTickets + quantityT[pass];
        ticketsQuantity[pass] = ticketsQuantity[pass] - quantityT[pass];
        clearScreen();
    }
}

void viewTickets()
{
    string name;
    int x;
    int a;
    int b = 17;

    header();

    cout << "Enter Name of Flight: ";
    cin >> name;
    bool tf = false;
    for (x = 0; x < Flightscount; x++)
    {
        if (name == namess[x])
        {
            tf = true;
            pass = x;
            break;
        }
    }
    if (tf)
    {
        a = 0;
        header();

        cout << "Flight Name:"
             << "\t"
             << "\t"
             << "Flight Route:"
             << "\t"
             << "\t"
             << "Tickets Bought:"
             << endl;
        gotoxy(a, b);
        cout << name;
        a = 24;
        gotoxy(a, b);
        cout << flightRoutes[x];
        gotoxy(a + 24, b);
        cout << displayTickets << endl;
        clearScreen();
    }
    else
    {
        cout << endl
             << "Flight Not Found." << endl;
        clearScreen();
    }
}

void refundTickets()
{
    string name, ticketClass, testQuantity;
    int x, refundT;

    system("cls");
    header();

    cout << "Enter Name of Flight: ";
    cin >> name;
    bool tf = false;
    for (x = 0; x < Flightscount; x++)
    {
        if (name == namess[x])
        {
            tf = true;
            pass = x;
            break;
        }
    }
    if (tf)
    {
        system("cls");
        header();

        cout << "Flight Name:"
             << "\t"
             << "Flight Route:"
             << "\t"
             << "\t"
             << "Tickets Bought:"
             << endl
             << name
             << "\t"
             << "\t"
             << flightRoutes[x]
             << "\t"
             << "\t"
             << "\t"
             << displayTickets << endl
             << endl;
        cout << "Enter Your Ticket Class: ";
        cin >> ticketClass;
        if (ticketClass == "business")
        {
            cout << "Enter Quantity of Tickets You Want To Refund: ";
            cin >> testQuantity;
            while ((!checkvalidint(testQuantity)))
            {
                cout << endl
                     << "Invalid Quantity, Kindly Re Enter: ";
                cin >> testQuantity;
            }
            refundT = stoi(testQuantity);
            displayTickets = displayTickets - refundT;
            ticketsQuantity[pass] = ticketsQuantity[pass] + refundT;
            cout << endl
                 << "Your Refundable Amount Is: " << pricesB[pass] * refundT << " $";
            confirmRefunding();
        }
        else if (ticketClass == "economy")
        {
            cout << "Enter Quantity of Tickets You Want To Refund: ";
            cin >> testQuantity;
            while ((!checkvalidint(testQuantity)))
            {
                cout << endl
                     << "Invalid Quantity, Kindly Re Enter: ";
                cin >> testQuantity;
            }
            refundT = stoi(testQuantity);
            displayTickets = displayTickets - refundT;
            ticketsQuantity[pass] = ticketsQuantity[pass] + refundT;
            cout << endl
                 << "Your Refundable Amount Is: " << pricesE[pass] * refundT << " $";
            confirmRefunding();
        }
        else
        {
            cout << "Invalid Ticket Class." << endl;
            clearScreen();
        }
    }
    else
    {
        cout << endl
             << "Flight Not Found." << endl;
        clearScreen();
    }
}

void confirmRefunding()
{
    int y;

    cout << endl
         << endl
         << "Press 1 To Confirm Refunding." << endl;
    cout << "Press Any Key To Exit." << endl;
    cout << "Your Option: ";
    cin >> y;
    if (y == 1)
    {
        system("cls");
        header();
        cout << endl
             << endl
             << "Thanks For Using Our Airline Management System. :)"
             << endl;
        clearScreen();
    }
}

void getHelp()
{
    header();
    cout << "Follow the following instructions." << endl
         << endl;
    cout << "Use the arrow keys to move the cursor to required option." << endl
         << endl;
    cout << "Press enter key to select option." << endl
         << endl;
    cout << "For more instructions follow us on instagram: 'chhashim17'" << endl
         << endl;
    cout << "Contact: 'chhashimi34@gmail.com'";
    clearScreen();
}