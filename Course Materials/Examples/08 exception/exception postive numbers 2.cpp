/*
throw for negatives
*/

#include <iostream>
using namespace std;

int main()
{
	int StudentAge;

	try 
    {
		cout << "Student Age: ";
		cin >> StudentAge;

		if(StudentAge < 0)
			throw "Positive Number Required";

		cout << "\nStudent Age: " << StudentAge << "\n\n";
	}
	catch(const char* Message)
	{
		cout << "Error: " << Message;
	}

	cout << "\n";

   system("PAUSE");
   return 0;
}
