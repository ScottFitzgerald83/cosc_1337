// arrays and pointers
#include <iostream>
using namespace std;

/*Pointers and arrays are strongly related. 
pointers and arrays are interchangeable in many cases. 
For example, a pointer that points to the beginning of an array can access that array by 
using either pointer arithmetic or array-style indexing.
*/

const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // let us have array address in pointer.
   ptr = var;
   for (int i = 0; i < MAX; i++)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;
 
      // point to the next location
      ptr++;
   }

    system("PAUSE");
    return 0;
}
