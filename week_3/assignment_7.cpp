// Scott Fitzgerald
// Assignment #4
// Status: Completed
// Date: 2020-06-17

// Calculates the average of odd numbers between 1 and 100

#include <iostream>
using namespace std;

void processData(double& average);
void displayResults(double average);

int main()
{
	// main function; sets average variable and calls the processData()
	// and displayResults() functions
	double average = 0;

	cout << "\nThis program calculates and displays the average of odd ";
	cout << "numbers between 1 and 100." << endl;
	processData(average);
	displayResults(average);
	
	return 0;
}

void processData(double &average)
{
	// Calculates the average of all odd numbers between 1 and 100

	int counter = 0;
	int sumOddNumbers = 0;
	int countOddNumbers = 0;

	// Loops through numbers from 1 to 100, checking if they are odd
	// adds odd numbers to accumulator
	for (counter = 1; counter < 100; counter++) 
	{
		if (counter % 2 != 0) 
		{
			sumOddNumbers += counter;
			countOddNumbers += 1;
		}
	}
	average = sumOddNumbers / countOddNumbers;
}

void displayResults(double average)
{
	// Takes the average as input and displays it to the console
	cout << "The average of all odd numbers between 1 and 100 is " << average << endl;
}