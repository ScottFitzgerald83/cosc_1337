/// example about struct
#include <iostream>
#include <string>
#include <sstream>          //string stream class
using namespace std;

struct Fraction{
	int numerator;
	int denomenator;
};

int main ()
{
  Fraction f1;
  Fraction f2;
  Fraction f3;
  int wholeNumber = 0;
  
  f1.numerator = 10;
  f1.denomenator = 100;
  
  f2.numerator = 25;
  f2.denomenator = 100;
  
  f3.numerator = f1.numerator * f2.numerator;
  f3.denomenator = f1.denomenator * f2.denomenator;
  
  if (f3.numerator > f3.denomenator)
  {
  	wholeNumber = f3.numerator / f3.denomenator;
  	f3.numerator = f3.numerator % f3.denomenator;
  }
  else if (f3.numerator == f3.denomenator)
  {
  	wholeNumber = 1;
  	f3.numerator = 0;
  	f3.denomenator = 0;
  }
  else
  {
  	
  }
  
  cout << wholeNumber;

  system("PAUSE");
  return 0;
}

