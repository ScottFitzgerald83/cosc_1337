/*
An exception is a problem that arises during the execution of a program. 
A C++ exception is a response to an exceptional circumstance that arises while a program is running, 
such as an attempt to divide by zero.

Exceptions provide a way to transfer control from one part of a program to another. 
C++ exception handling is built upon three keywords: try, catch, and throw.

    throw: A program throws an exception when a problem shows up. This is done using a throw keyword.

    catch: A program catches an exception with an exception handler at the place in a program where you want to handle the problem. The catch keyword indicates the catching of an exception.

    try: A try block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks.

Assuming a block will raise an exception, a method catches an exception using a combination of the try and catch keywords. 
A try/catch block is placed around the code that might generate an exception. 
*/

#include <iostream>
#include <cmath>  // used for math
using namespace std;

int main( )
{
  try
  {
    double value;
    cout << "Enter a number more than 0 (no negative number): ";
    cin >> value;    
    
    if (value < 0) throw "Negative square root is imaginery!";
    cout << "Square root of " << value <<  " is " << sqrt(value) << endl;
  }
  catch(char const *str)
  {
       cout << str  << endl;
  }
  
  return 0;  
}

