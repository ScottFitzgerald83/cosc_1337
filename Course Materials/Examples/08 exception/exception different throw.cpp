/*

different thow code
*/

#include <iostream>
using namespace std;

int checkNumbers(int );

int main()
{
    int number;

    cout << "Enter number: ";
    cin >> number;

    try
    {
        cout << "The number is 0 will throw 100; 1 will throw 200 " << checkNumbers(number)  << endl;
    }
    
    catch(int& code)
    {
        if (code == 100)
           cout << "ERROR CODE for number 0 message : " << code  << endl; 
        else if (code == 200)
           cout << "ERROR CODE for number 1 message : " << code  << endl;
    }
    
    /*
    A default catch can be made by giving an ellipsis as a parameter - 
    this should be at the bottom of the chain if there are multiple catchs as it will handle any and all exceptions.
    */
    catch(...)
    {
        cout << "An unknown error has occurred."  << endl;
    }
    
    
    cout << "I can add the rest of my codes below " << endl;

   system("PAUSE");
   return 0;
}

//
int checkNumbers(int num)
{
    if(num == 0)
       throw 100;
       
    else if(num == 1)
       throw 200;     
	     
    return num;
}
