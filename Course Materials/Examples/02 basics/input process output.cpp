// Basic input, process, output

#include <iostream>				// for cin, cout, endl
using namespace std;


int main()
{
	// decleration
    double hours;
    double rate;
    double pay;
 
    // getting data
    cout << "Enter the hours worked " ;
    cin >> hours;
    
    cout << "Enter the rate ";
    cin >> rate;
    
    // calculation
    pay = hours * rate;
    
    // printing
    cout << "The total pay is " << pay << endl;
      
    system("PAUSE");
    return 0;
    
}// end of main


