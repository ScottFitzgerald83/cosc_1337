// Scott Fitzgerald
// Project #1
// Status: Completed
// Date: 2020-06-02

// Reads 2 integer values from the keyboard, then calculates and displays
// their sum, product, average, quotient, remainder

#include <iostream>
using namespace std;

// Function prototypes
// Getting and processing input
void getData(int& integerOne, int& integerTwo);
void processData(int integerOne, int integerTwo);

// Mathematical operations
int sum(int num1, int num2);
int product(int num1, int num2);
double average(int num1, int num2);
double quotient(int num1, int num2);
int remainder(int num1, int num2);

int main()
{
	// Gets integer values from getData() and passes them to proccessData()
	int integerOne = 0;
	int integerTwo = 0;

	getData(integerOne, integerTwo);
	processData(integerOne, integerTwo);

	return 0;
}

void getData(int &integerOne, int &integerTwo)
{
	// Gets integers from user and stores them in main()'s integer variables
	cout << "\nThis program performs a series of calculations for two numbers provided." << endl;
	cout << "Enter an integer value: ";
	cin >> integerOne;
	cout << "Enter another integer value: ";
	cin >> integerTwo;

}

void processData(int integerOne, int integerTwo)
{
	// Processes operations and displays the results
	cout << "The sum of " << integerOne << " and " << integerTwo << " is " << sum(integerOne, integerTwo) << endl;
	cout << "The product of " << integerOne << " and " << integerTwo << " is " << product(integerOne, integerTwo) << endl;
	cout << "The average of " << integerOne << " and " << integerTwo << " is " << average(integerOne, integerTwo) << endl;
	
	// Check for invalid division operations
	if (integerTwo == 0)
	{
		cout << "Division by zero is undefined, unable to find quotient." << endl;
		cout << "Division by zero is undefined, unable to find remainder." << endl;
	}
	else
	{
		cout << "The quotient after dividing " << integerOne << " and " << integerTwo << " is " << quotient(integerOne, integerTwo) << endl;
		cout << "The remainder after dividing " << integerOne << " and " << integerTwo << " is " << remainder(integerOne, integerTwo) << endl;	
	}
}

int sum(int num1, int num2)
{
	// Finds the sum of two integers
	return num1 + num2;
}

int product(int num1, int num2)
{
	// Finds the product of two integers
	return num1 * num2;
}

double average(int num1, int num2)
{
	// Finds the average of two integers
	return (num1 + num2) / 2.0;  // Implicitly casts type from int
}

double quotient(int num1, int num2)
{
	// Finds the quotient of two integers
	return (num1 * 1.0) / num2;  // Implicitly casts type from int
}

int remainder(int num1, int num2)
{
	// Finds the remainder (modulus) of two integers
	return num1 % num2;
}



