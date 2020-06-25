#include <iostream>
using namespace std;

double division(int num, int den)
{
   if( den == 0 )
   {
      throw "Division by zero condition!";
   }
   return (num/den);
}

int main ()
{
   int dividend = 50;
   int divisor = 0;
   double quotient = 0;
 
   try 
   {
     quotient = division(dividend, divisor);
     cout << "The anwer to division is " << quotient << endl;
   }
   catch (const char* msg) //raising an exception of type const char*, so while catching this exception, we have to use const char* in catch block.
   {
     cerr << msg << endl;
   }
   
   system("PAUSE");
   return 0;
}
