#include <iostream>
using namespace std;

main(){
int h;
cout <<"Enter h: ";
cin >> h;
int x, y;
cout <<"Enter x coordinate: ";
cin >> x;
cout <<"Enter y coordinate: ";
cin >> y;
if ((x < 6 && x!=0) && (y < 8 && y!=0)){
 cout <<"Inside";
}
if ((x < 6 && y!=0) && (y > 8)){
 cout <<"Outside";
}
if ((x > 6) && (y < 8 && y!=0)){
 cout <<"Outside";
}
if ((x > 6) && (y > 8)){
 cout <<"Outside";
}
if(x==2 || x==4 || x==6){
 cout <<"Border";
}
if(x==2 && (y<8)){
 cout <<"Border";
}
if(x==4 && (y<8)){
 cout <<"Border";
}
if(x==6 && (y<8)){
 cout <<"Border";
}
if(x==0 && y==0){
 cout <<"Border";
}
}