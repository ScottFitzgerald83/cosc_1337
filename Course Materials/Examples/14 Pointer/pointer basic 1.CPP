// my first pointer
#include <iostream>
using namespace std;


/*
First, myPtr is assigned the address of firstVal using the address-of operator (&). 
Then, the value pointed to by myPtr is assigned a value of 10. Because, at this moment, 
myPtr is pointing to the memory location of firstVal, this in fact modifies the value of firstVal.
*/

int main ()
{
  int firstVal, secondVal;
  int * myPtr;

  myPtr = &firstVal;
  *myPtr = 110;
  
  myPtr = &secondVal;
  *myPtr = 210;
  
  cout << "The First value is " << firstVal << '\n';
  cout << "The Second value is " << secondVal << '\n';
  
  system("PAUSE");
  return 0;
}

