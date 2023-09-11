c

void equal();
void unequal();

main(){
  cout <<"Enter 1st integer: ";
  int num1;
  cin >> num1;
  cout <<"Enter 2nd integer: ";
  int num2;
  cin >> num2;
  if(num1 == num2){
   equal();
   }
  if(num1 != num2){
   unequal();
   }
}

void equal(){
  cout <<"True";
} 

void unequal(){
  cout <<"False";
}