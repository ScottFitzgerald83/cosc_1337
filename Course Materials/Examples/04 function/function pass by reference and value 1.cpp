// pass by reference and pass by value

#include <iostream>				// for cin, cout, endl
using namespace std;


// prototype of functions below main()
void findOdd(int );
int getValue(int & );

int main()						// start of main function
{
    //Variable decleration
    int number1;
    int value;
    
    value = getValue(number1);

    findOdd(value);

    system ("pause");           // Freeze the DOS screen
	return 0;		            // indicate that the program ended successfully

}                               // end of main function

void findOdd(int num1)
{
  if (num1%2 == 1)
        cout << "The number " << num1 << " is an odd number" << endl;
}  // end of findODdd


int getValue(int &  num1)
{
    cout << "Please enter a number : ";
    cin >> num1;
    return 101;
}
