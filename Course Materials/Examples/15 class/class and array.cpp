// array of objects

#include <iostream>
using namespace std;

/*
Arrays of variables of type "class" is known as "Array of objects". 
The "identifier" used to refer the array of objects is an user defined data type.
*/

const int MAX =100;

class Details
{
      private:
              int salary;
              float roll;
      public:
             void getname( )
                {
                cout << "Enter the Salary ";
                cin >> salary;
                cout << "Enter the roll ";
                cin >> roll;
                }
            void putname( )
                {
                cout << "Employees " << salary << endl <<
                "and roll is " << roll << '\n';
                }
};

int main()
{
    Details det[MAX];
    
    int n = 0;
    char ans;
    
    do
    {
        cout << "Employee Number " << n+1  << endl;
        det[n++].getname();
        cout << "Enter another (y/n)? " ;
        cin >> ans;
    } 
    
    while ( ans != 'n' );
        for (int j=0; j<n; j++)
        {
            cout << "Employee Number is " << j+1  << endl;
            det[j].putname( );
        }
    
    system("PAUSE");
    return 0;
} 
