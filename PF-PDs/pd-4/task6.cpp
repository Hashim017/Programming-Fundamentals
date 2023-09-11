#include <iostream>
using namespace std;

main(){
string month;
cout <<"Enter month: ";
cin >> month;
int stay;
cout <<"Enter stay days: ";
cin >> stay;

float result;
float resultt;
if((month == "may" || month == "october") && stay <=7){
 result = 65*stay;
 cout <<"Appartment: " << result << " $" << endl;
 resultt = 50*stay;
 cout <<"Studio: " << resultt << " $";
}
else if((month == "may" || month == "october") && (stay > 7) && (stay <14)){
 float dis;
 result = 65*stay;
 cout <<"Appartment: " << result << " $" << endl;
 resultt = 50*stay;
 dis = resultt - (resultt*5)/100;
 cout <<"Studio: " << dis << " $";
}
else if((month == "may" || month == "october") && stay > 14){
 float dis;
 float diss;
 result = 65*stay;
 diss = result - (result*10)/100;
 cout <<"Appartment: " << diss << " $" << endl;
 resultt = 50*stay;
 dis = resultt - (resultt*30)/100;
 cout <<"Studio: " << dis << " $";
}
else if((month == "june" || month == "september") && stay <=14){
 result = 68.70*stay;
 cout <<"Appartment: " << result << " $" << endl;
 resultt = 75.20*stay;
 cout <<"Studio: " << resultt << " $";
}
else if((month == "june" || month == "september") && stay > 14){
 float dis;
 float diss;
 result = 65*stay;
 diss = result - (result*10)/100;
 cout <<"Appartment: " << result << " $" << endl;
 resultt = 50*stay;
 dis = resultt - (resultt*20)/100;
 cout <<"Studio: " << dis << " $";
}
else if((month == "july" || month == "august") && stay <=14){
 result = 68.70*stay;
 cout <<"Appartment: " << result << " $" << endl;
 resultt = 75.20*stay;
 cout <<"Studio: " << resultt << " $";
}
else if((month == "june" || month == "september") && stay > 14){
 float diss;
 result = 65*stay;
 diss = result - (result*10)/100;
 cout <<"Appartment: " << result << " $" << endl;
 resultt = 50*stay;
 cout <<"Studio: " << resultt << " $";
}
}