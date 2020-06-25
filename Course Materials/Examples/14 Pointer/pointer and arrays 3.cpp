// pointers and ararys
#include <iostream>
using namespace std;

/*
pointers and arrays are not completely interchangeable.
*/


int main ()
{
  int numbers[5];
  int * p;
  
  p = numbers;  
  *p = 110;
  p++;  
  
  *p = 120;
  p = &numbers[2]; 
   
  *p = 130;
  p = numbers + 3;  
  
  *p = 140;
  
  p = numbers;  
  *(p+4) = 150;
  
  for (int n=0; n<5; n++)
    cout << "The value is at " << n << " location is " << numbers[n] << endl;

    system("PAUSE");
    return 0;
}
