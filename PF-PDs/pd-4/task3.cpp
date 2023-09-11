#include <iostream>
using namespace std;

main(){
string month;
cout <<"Enter month: ";
cin >> month;
int date;
cout <<"Enter date: ";
cin >> date;

if(month == "march" && date>=21 || date<=31){
 cout <<"Aries";
}
else if(month == "april" && date>=1 || date<=19){
 cout <<"Aries";
}
else if(month == "april" && date>=20 || date<=30){
 cout <<"Taurus";
}
else if(month == "may" && date>=1 || date<=20){
 cout <<"Taurus";
}
else if(month == "may" && date>=21 || date<=31) && (date>=1 || date<=20)){
 cout <<"Gemini";
}
else if((month == "june" || month == "july") && (date>=21 || date<=30) && (date>=1 || date<=22)){
 cout <<"Cancer";
}
else if((month == "july" || month == "august") && (date>=23 || date<=31) && (date>=1 || date<=22)){
 cout <<"Leo";
}
else if((month == "august" || month == "september") && (date>=23 || date<=30) && (date>=1 || date<=22)){
 cout <<"Virgo";
}
else if((month == "september" || month == "october") && (date>=23 || date<=31) && (date>=1 || date<=22)){
 cout <<"Libra";
}
else if((month == "october" || month == "november") && (date>=23 || date<=31) && (date>=1 || date<=21)){
 cout <<"Scorpio";
}
else if((month == "november" || month == "december") && (date>=22 || date<=31) && (date>=1 || date<=21)){
 cout <<"Sagittarius";
}
else if((month == "december" || month == "january") && (date>=22 || date<=31) && (date>=1 || date<=19)){
 cout <<"Capricon";
}
else if((month == "january" || month == "february") && (date>=20 || date<=31) && (date>=1 || date<=18)){
 cout <<"Aquaris";
}
else if((month == "february" || month == "march") && (date>=19 || date<=31) && (date>=1 || date<=20)){
 cout <<"Pisces";
}
} 