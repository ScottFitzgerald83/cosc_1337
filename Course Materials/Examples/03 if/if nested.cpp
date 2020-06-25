/*
Name    
Date    
Project 

*****************
Description
This program will show Nested If works


*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()						// start of main function
{
    //Variable decleration
    char gender = 'm';
    double age  = 64;

    //checking
    if (gender == 'm')
       {
           if (age >= 65)
              cout << "I am male and over 65 " << endl;
           else
              cout << "I am male but under 65 " << endl;          
       }
    
    system ("pause");           // Freeze the DOS screen
	return 0;		            // indicate that the program ended successfully

}                               // end of main function


