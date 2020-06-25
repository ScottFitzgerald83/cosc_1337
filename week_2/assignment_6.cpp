// Scott Fitzgerald
// Assignment #6
// Status: Completed
// Date: 2020-06-04

// Calculates and displays the sum of odd numbers between 1 and 100

#include <iostream>
using namespace std;

void displayMessage();
void sumOddsThrough100();

int main()
{
	// Calls the displayMessage() and sumOdds() functions
	displayMessage();
	sumOddsThrough100();	

	return 0;
}

void displayMessage()
{
	// Displays a message to the console explaining program
	cout << "\n\nThis program sums all the odd numbers between 1 and 100." << endl;
}

void sumOddsThrough100()
{
	// loops over each number between 1 and 100 checking for even/oddness
	// odd numbers are printed to the terminal
	int count = 0;
	int sum = 0;

	while (count < 100) 
	{
		if (count % 2 != 0)
		{
			sum += count;
		}
		count += 1;
	}
	cout << "\nThe sum of all odd numbers between 1 and 100 is " << sum << "\n\n";
}