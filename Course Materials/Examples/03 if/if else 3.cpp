/*
Name    
Date    
Project 

*****************
Description
This program will show how if statement works
nested checks for letter grade

*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()						// start of main function
{
    //Variable decleration
    double grade = 35;
    char letter = ' ';

    //checking
    if (grade >= 90)
         letter = 'A';
    else if (grade >= 80)
         letter = 'B';
    else if (grade >= 70)
         letter = 'C'; 
    else if (grade >= 60)
         letter = 'D';
    else
         letter = 'F';
         
    cout << "My letter grade is : " << letter << endl; 
          
    system ("pause");           // Freeze the DOS screen
	return 0;		            // indicate that the program ended successfully

}                               // end of main function


