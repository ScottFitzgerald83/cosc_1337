/*
To read a line.
*/



#include <iostream>				// for cin, cout, endl
#include <string>				// string class
using namespace std;


int main()						// start of main function
{
    
   string line;
   int p;   
   
   getline(cin, line);  
   cout << line << endl;    

    
	return 0;		     // indicate that the program ended successfully

}   // end of main function

