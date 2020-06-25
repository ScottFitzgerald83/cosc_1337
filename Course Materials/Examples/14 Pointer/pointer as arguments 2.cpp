// pointers as arguments:

#include <iostream>
using namespace std;
/*
If a pointer type is used as a function parameter type, then an actual address is being sent into the function instead

    In this case, you are not sending the function a data value -- instead, 
    you are telling the function where to find a specific piece of data
    Such a parameter would contain a copy of the address sent in by the caller, but not a copy of the target data
    When addresses (pointers) are passed into functions, the function could affect actual variables existing in the scope of the caller

*/


 void SquareByAddress(int * ptr)
 // Note that this function doesn't return anything.  void function. 
 {  
    *ptr = (*ptr) * (*ptr);  		// modifying the target, *ptr
 } 

 int main() 
 { 
   int num = 4; 
   cout << "num = " << num << '\n';	// num = 4
   
   SquareByAddress(&num); 		// address of num passed in
   
   cout << "num = " << num << '\n';	// num = 16
   
     system("PAUSE");
  return 0;
 } 
