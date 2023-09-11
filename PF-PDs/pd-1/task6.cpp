#include <iostream>
using namespace std;

main(){

cout <<"Enter Size Of Fertilizer Bag In Pounds: ";
float sizeInPounds;
cin>> sizeInPounds;
cout <<"Enter The Cost Of Bag: ";
float costOfBag;
cin>> costOfBag;
cout <<"Enter Area In Square Feet That Bag Covered: ";
float area;
cin >> area;
float costOfFertilizer;
costOfFertilizer = costOfBag / sizeInPounds;
cout <<"Cost Of Fertilizer Per Pound: " << costOfFertilizer << endl;
float areaPerSquare;
areaPerSquare = costOfBag / area;
cout <<"Cost Of Fertilizing Area Per Square Feet: " << areaPerSquare;


}