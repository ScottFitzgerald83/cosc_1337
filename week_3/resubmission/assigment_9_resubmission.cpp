// Scott Fitzgerald
// Assignment #9
// Status: Resubmission
// Date: 2020-06-17

// Displays the highest and lowest integers entered by a user. Program
// exits when user enters a 0.

#include <iostream>
using namespace std;

void getData(int& number, int& highest, int& lowest);
void displayMessage();
void displayResults(int highest, int lowest);

int main()
{
	// Main function calls other functions to display instructions,
	// get user input, and display results
	int number;
	int highest = 0;
	int	lowest;

	displayMessage();
	getData(number, highest, lowest);
	displayResults(highest, lowest);
	
	return 0;
}

void displayMessage()
{
	// Display program details/instructions to console
	cout << "\nThis program determines the highest and lowest numbers provided by you\n\n";
	cout << "Enter one integer at a time, followed by the Enter Key.\n";
	cout << "When you are done, type 0 and press Enter.\n\n";
}

void getData(int &number, int &highest, int &lowest)
{
	// Take a series of numbers as user input, keeping track of the highest/lowest
	cout << "Enter an integer: ";
	cin >> number;

	// Validate first integer input is nonzero
	while (number == 0)
	{
		cout << "No data entered. Enter an integer: ";
		cin >> number;
	}

	// Accepts a series of numbers from the user until user inputs 0
	while (number != 0)
	{
		// Update lowest if new lowest provided
		if (number < lowest)
		{
			lowest = number;
		}
		// Update highest if new higests provided
		if (number > highest)
		{
			highest = number;
		}


		cout << "Enter another integer: ";
		cin >> number;
	}
}

void displayResults(int highest, int lowest)
{
	// Display results to the console
	cout << "\n\nResults \n__________\n";
	cout << "The highest number is " << highest << endl;
	cout << "The lowest number is " << lowest << endl;	

}

