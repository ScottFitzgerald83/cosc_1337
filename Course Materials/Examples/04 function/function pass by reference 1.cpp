// pass by reference

#include <iostream>				// for cin, cout, endl
using namespace std;

void calc(int &);

int main()
{
    int number = 5;
 
    cout << "The value of number before calling the function " << number << endl; 
      
    calc(number);            //calling the function
    
    cout << "The value of number after returning from the function " << number << endl; 

    
    system("PAUSE");
    return 0;
}// end of main


void calc(int &num)
{
    num = 30;
}    //end of cal
