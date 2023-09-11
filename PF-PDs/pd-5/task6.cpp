#include <iostream>
using namespace std;

main()
{
 int day;
 cout <<"Enter day: ";
 cin >> day;
 int doctor = 7;
 for(int x = 1; x<= day; x++)
 {
  int patient;
  int treatedPatient = 0;
  int untreatedPatient = 0;
  cout <<"Enter number of patients: ";
  cin >> patient;

  if(doctor == patient)
  {
   treatedPatient = treatedPatient + doctor;
   untreatedPatient = untreatedPatient + 0;
  }
  int less = patient - doctor;
  if(doctor < patient)
  {
   treatedPatient = treatedPatient + doctor;
   untreatedPatient = untreatedPatient + less;
  }
  int more = doctor - patient;
  if(doctor > patient)
  {
   treatedPatient = treatedPatient + more;
   untreatedPatient = untreatedPatient + 0;
    cout << treatedPatient;
    cout << untreatedPatient ;
  }
  
 }


}