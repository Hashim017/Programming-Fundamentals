#include <iostream>
using namespace std;

main(){
string name;
cout <<"Enter name: ";
cin >> name;
int subject1, subject2, subject3, subject4, subject5;
cout <<"Enter first subject marks: ";
cin >> subject1;
cout <<"Enter second subject marks: ";
cin >> subject2;
cout <<"Enter third subject marks: ";
cin >> subject3;
cout <<"Enter fourth subject marks: ";
cin >> subject4;
cout <<"Enter fifth subject marks: ";
cin >> subject5;
int marks;
marks = subject1 + subject2 + subject3 + subject4 + subject5;
float percentage = (marks*100)/500;

if(percentage >=90 && percentage <= 100){
 cout << name << endl;
 cout <<"Total marks: " << marks << endl;
 cout <<"Percentage is: " << percentage << endl;
 cout <<"Grade is: A+";
}
if(percentage >=80 && percentage <= 90){
 cout << name << endl;
 cout <<"Total marks: " << marks << endl;
 cout <<"Percentage is: " << percentage << endl;
 cout <<"Grade is: A";
}
if(percentage >=70 && percentage <= 80){
 cout << name << endl;
 cout <<"Total marks: " << marks << endl;
 cout <<"Percentage is: " << percentage << endl;
 cout <<"Grade is: B+";
}
if(percentage >=60 && percentage <= 70){
 cout << name << endl;
 cout <<"Total marks: " << marks << endl;
 cout <<"Percentage is: " << percentage << endl;
 cout <<"Grade is: B";
}
if(percentage >=50 && percentage <= 60){
 cout << name << endl;
 cout <<"Total marks: " << marks << endl;
 cout <<"Percentage is: " << percentage << endl;
 cout <<"Grade is: C";
}
}