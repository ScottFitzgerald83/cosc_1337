// more pointers

#include <iostream>
using namespace std;


int main ()
{
  int firstVal = 5, secondVal = 15;
  int * ptr1, * ptr2;

  ptr1 = &firstVal;           // ptr1 = address of firstvalue
  ptr2 = &secondVal;          // ptr2 = address of secondvalue
  *ptr1 = 120;                 // value pointed to by ptr1 = 120
  *ptr2 = *ptr1;              // value pointed to by ptr2 = value pointed to by ptr1
  ptr1 = ptr2;                // ptr1 = ptr2 (value of pointer is copied)
  *ptr1 = 420;                 // value pointed to by ptr1 = 420
  
  cout << "The First value is " << firstVal << '\n';
  cout << "The Secondvalue is " << secondVal << '\n';
  
  //system("PAUSE");
  return 0;
}

