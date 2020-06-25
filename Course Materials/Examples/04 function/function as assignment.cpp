/*
Name    
Date    
Project 

*****************
Description
Examples for assignment of a function

*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int calc(int );

int main()
{
    int number = 5;
 
    cout << "The value of number before calling the function " << number << endl; 
         
    cout << "The value of number after assignment of the function " << calc(number) << endl; 

    system("PAUSE");
    return 0;
}// end of main


int calc(int num)
{
    num = 30;
    return num;
}    //end of cal
