// pass by reverence and value

#include <iostream>				// for cin, cout, endl
using namespace std;

int getValue(int & , int & , char & );
int getAns(int , int , char , int & );
void getOut(int , int , char , int );

int main()						// start of main function
{ 
    int n1 = 0;
    int n2 = 0;
    int ans = 0;
    char op = ' ';
    
    getValue(n1, n2, op);
    getAns(n1, n2, op, ans);
    
    system ("pause");           // Freeze the DOS screen
	return 0;		            // indicate that the program ended successfully

}                               // end of main function

int getValue(int & num1, int & num2, char & ops)
{
    cout << "Please enter Number 1 ";
    cin >> num1;
    cout << "Please enter Number 2 ";
    cin >> num2;
    cout << "Please enter Operator ";
    cin >> ops;
    return 0;
}

int getAns(int num1, int num2, char ops, int & answer)
{
    if  (ops == '+')
        answer = num1 + num2;
    else if (ops == '-')
        answer = num1 - num2;
    else if (ops == '*')
        answer = num1 * num2;
    else if (ops == '/')
       if (num2 == 0)
        {
        cout << "Cannot divide by zero " << endl;
        return 0;
        }
       else
        answer = num1 / num2;
    else if (ops == '%')
        answer = num1 % num2;
    else 
    {
    	cout << "Wrong Operator " << endl;
    	return 0;
	}
        
    getOut(num1, num2, ops, answer);
    return 0;
}

void getOut(int num1, int num2, char ops, int answer)
{
    cout << "The numbers are " << num1 << " and " << num2 << endl;
    cout << "The Operation is " << ops << endl;
    cout << "The answer is " << answer << endl;
}


