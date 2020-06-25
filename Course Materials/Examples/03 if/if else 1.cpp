/*
Name    
Date    
Project 

*****************
Description
This program will show how if statement works
if number is positive then print positive number or print 
negative number

*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()						// start of main function
{
    //Variable decleration
    int number1;
    
    cout << "Please enter a number ";
    cin >> number1;

    //checking
    if (number1 % 2 == 0)
        cout << "The number " << number1 << " is a even number" << endl;
    else
        cout << "The number " << number1 << " is a odd number" << endl;
    
    system ("pause");           // Freeze the DOS screen
	return 0;		            // indicate that the program ended successfully

}                               // end of main function


