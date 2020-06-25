/*
Name    
Date    
Project 

*****************
Description
This program will show how if statement works
if number is positive, adds 100 to the number and print the sum.
if number is negative, subtracts 100 from the number and print the difference

*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()						// start of main function
{
    //Variable decleration
    double number1 = -20;
    double answer = 0;

    //checking
    if (number1 >= 20)
       {
           answer = number1 + 100;
           cout << "The number " << number1 << " adding 100 is " << answer << endl;
       }
    else
       {
           answer = number1 - 100;
           cout << "The number " << number1 << " subtracting 100 is " << answer << endl;
       }
    
    system ("pause");           // Freeze the DOS screen
	return 0;		            // indicate that the program ended successfully

}                               // end of main function


