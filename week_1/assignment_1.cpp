// Scott Fitzgerald
// Assignment #1
// Status: Completed
// Date: 2020-06-02

// Accepts two integers as input from the user. Calculates and displays the
// sum, difference, product, quotient, and modulus of those two integers.

#include <iostream>
using namespace std;

int main() 
{
	// Takes two integers as input and outputs sum, difference, product, quotient, and modulus

	// Declarations
	int integerOne;  // First integer from user           
	int integerTwo;  // Second integer from user           
	int sum;         // Sum of the two integers
	int difference;  // Difference of the two integers
	int product;     // Product of the two integers
	int quotient;    // Quotient of the two integers
	int modulus;     // Modulus of the two integers

	// Get integer input from user
	cout << "Enter an integer value: ";
	cin >> integerOne;
	cout << "Enter another integer value: ";
	cin >> integerTwo;
	
	// Calculate sum, difference, product, quotient, and modulus; store as variables
	sum = integerOne + integerTwo;
	difference = integerOne - integerTwo;
	product = integerOne * integerTwo;
	quotient = integerOne / integerTwo;
	modulus = integerOne % integerTwo;
	
	// Display the results
	cout << "The sum of " << integerOne << " and " << integerTwo << " is " << sum  << endl;
	cout << "The difference of " << integerOne << " and " << integerTwo << " is " << difference << endl;
	cout << "The product of " << integerOne << " and " << integerTwo << " is " << product << endl;
	cout << "The quotient of " << integerOne << " and " << integerTwo << " is " << quotient << endl;
	cout << "The modulus of " << integerOne << " and " << integerTwo << " is " << modulus  << endl;

	return 0;
}
