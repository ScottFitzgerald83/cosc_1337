// Scott Fitzgerald
// Assignment #8
// Status: Completed
// Date: 2020-06-17

// Finds and displays the factorial of a user-provided number 

#include <iostream>
using namespace std;

void getData(int& number);
double factorial(int n);
void displayResults(int number, double result);

int main()
{
	// Calculates and displays the factorial of a provided number
	int number = 0;
	double result = 0;

	cout << "\nThis program calculates the factorial of a positive integer.\n";
	getData(number);

	result = factorial(number);
	displayResults(number, result);

	return 0;
}

void getData(int &number)
{
	// Gets (and validates) positive integer as user input 
	cout << "Enter a positive integer: ";
	cin >> number;

	// Validate input to ensure integer is positive
	while (number < 0)
	{
		cout << "\nERROR: Factorial of less than 0 cannot be computed.\n";
		cout << "Enter a positive integer: ";
		cin >>number; 
	}
}

double factorial(int num)
{
	// Recursively finds and returns factorial of a given positive integer
	if (num == 1 || num == 0)
	{
		return 1;
	}
	else
	{
		return num * factorial(num - 1);
	}
}

void displayResults(int number, double result)
{
	// Displays the results to the console
	cout << "The factorial of " << number << " is " << result << endl;
}
