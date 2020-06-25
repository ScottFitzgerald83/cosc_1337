
/*
C++ allows you to pass a pointer to a function. 
To do so, simply declare the function parameter as a pointer type.

 we pass an integer pointer to a function 
and change the value inside the function which reflects back in the calling function
*/

#include <iostream>
#include <ctime>
using namespace std;


void getSeconds(int *);

int main ()
{
   int sec;

   getSeconds( &sec );

   // print the actual value
   cout << "Number of seconds :" << sec << endl;

   system("PAUSE");
   return 0;
}

void getSeconds(int *par)
{
   // get the current number of seconds
   *par = time( NULL );

}
