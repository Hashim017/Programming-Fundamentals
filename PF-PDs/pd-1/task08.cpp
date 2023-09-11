#include <iostream>
using namespace std;

main(){

float vegetablePrice;
cout <<"Enter Vegetable Price Per Kilogram: ";
cin >> vegetablePrice;
float fruitPrice;
cout <<"Enter Fruit Price: ";
cin >> fruitPrice;
int totalVegetablePrice;
cout <<"Enter Total Kilograms Of Vegetable: ";
cin >> totalVegetablePrice;
int totalFruitPrice;
cout <<"Enter Total Kilograms Of Fruit: ";
cin >> totalFruitPrice;
float vegetableCost;
vegetableCost = vegetablePrice * totalVegetablePrice;
float fruitCost;
fruitCost = fruitPrice * totalFruitPrice;
float t;
t = vegetableCost + fruitCost;
cout << t;
float total;
total = (vegetableCost + fruitCost) * 1.94;
cout <<"Result Is: " << total;

}