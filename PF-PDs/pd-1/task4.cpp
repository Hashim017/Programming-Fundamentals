#include <iostream>
using namespace std;

main(){

cout <<"Enter Your Name: ";
string name;
cin >> name;
cout <<"Enter Subject 1 Marks: ";
float subject1;
cin >> subject1;
cout <<"Enter Subject 2 Marks: ";
float subject2;
cin >> subject2;
cout <<"Enter Subject 3 Marks: ";
float subject3;
cin >> subject3;
cout <<"Enter Subject 4 Marks: ";
float subject4;
cin >> subject4;
cout <<"Enter Subject 5 Marks: ";
float subject5;
cin >> subject5;
float total;
total = (subject1 + subject2 + subject3 + subject4 + subject5) * 100 / 500;
cout <<"Percentage Is: " << total;

}  