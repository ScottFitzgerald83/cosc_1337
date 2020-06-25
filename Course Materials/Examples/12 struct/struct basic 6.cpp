// create a struct with 4 members
// employee id, hrsworked, regular pay, grosspay
// calls the object and inout data for the values
// use a printData function to print the values.
// use a MAX = 5 employees

#include <iostream>
#include <string>
using namespace std;

struct Employee {
  int Id;
  float hrsWorked;
  float regPay;
  float grossPay;
} ;

void printEmployee (Employee [] );

int main ()
{
  Employee myEmployee[5];
  
  for (int i = 0; i < 5; i++)
  {
	  cout << "Enter employee id ";
	  cin >> myEmployee[i].Id;
	  
	  cout << "Enter hrs worked ";
	  cin >> myEmployee[i].hrsWorked;
	  
	  myEmployee[i].regPay = 0.0;
	  myEmployee[i].grossPay = 0.0;
}

   printEmployee(myEmployee);

  return 0;
}

void printEmployee (Employee emp[])
{
  for (int i = 0; i < 5; i++)
  {
	  cout << emp[i].Id << endl;
	  cout << emp[i].hrsWorked << endl;
	  cout << emp[i].regPay << endl;
	  cout << emp[i].grossPay << endl;
}
}
