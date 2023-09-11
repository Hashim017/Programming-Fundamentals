#include <iostream>
using namespace std;

main(){

string name;
cout <<"Enter Movie Name: ";
cin>> name;
float adultTicket;
cout <<"Enter Adult Ticket Price: ";
cin>> adultTicket;
float childTicket;
cout <<"Enter Child Ticket Price: ";
cin>> childTicket;
int adultTicketsSold;
cout <<"Enter Number Of Adult Tickets Sold: ";
cin >> adultTicketsSold;
int childTicketsSold;
cout <<"Enter Number Of Child Tickets Sold: ";
cin >> childTicketsSold;
float percentage;
cout <<"Enter Percentage Of Amount Donated To Charity: ";
cin >> percentage;
float totalAmount;
totalAmount = (adultTicket * adultTicketsSold) + (childTicket * childTicketsSold);
cout <<"Total Amount Generated Is: " << totalAmount <<endl;
float amountAfterD;
amountAfterD = totalAmount * 10 / 100;
float amountAfterDonation;
amountAfterDonation = totalAmount - amountAfterD;
cout <<"Amount After Donation Is: " << amountAfterDonation;

}