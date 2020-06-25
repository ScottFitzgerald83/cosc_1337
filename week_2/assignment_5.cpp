// Scott Fitzgerald
// Assignment #5
// Status: Completed
// Date: 2020-06-10

// Brief description of what the program does

// AllyBaba Furniture store wants to calculate the price of desks sold
// This program accepts user input on the number of desks and length/width of each
// The desk cost is determined by area, which is calculated and displayed to the user

#include <iostream>
#include <cstdlib>  // Needed to use exit function
using namespace std;

// Function prototypes
void getData();
void processData(double length, double width, int deskNumber, int& totalCost);
void printData(int cost);

int main()
{
	// Main function
	getData();
	return 0;
}

void getData()
{
	// Gets number of desks and length/width of each from user
	int numberDesks = 0;      // Number of desks, provided by user
	double length = 0;        // Length provided by user
	double width = 0;         // Width provided by user
	int totalCost = 0;        // Used to store/increment the running cost  
	int deskCounter = 1;  // Counter variable for loop

	// Get number of desks from the user
	cout << "\nThis program calculates the cost of a series of desks";
	cout << "\nbased on their lengths and widths";
	cout << "\n\nEnter the number of desks: ";
	cin >> numberDesks;

	// For each desk, get and pass the length/width to processData() to calculate cost
	for (deskCounter = 0; deskCounter < numberDesks; deskCounter++)
	{
		cout << "\nEnter the length of desk #" << deskCounter + 1 << " (in feet): ";
		cin >> length;
		
		cout << "Enter the width of desk #" << deskCounter + 1 << " (in feet): ";
		cin >> width;
		
		processData(length, width, deskCounter + 1, totalCost);
	}

	printData(totalCost);
}

void processData(double length, double width, int deskNumber, int &totalCost)
{
	// Calculates the cost of a desk based on length and width
	double deskArea = length * width;
	int costOfIndividualDesk = 0;
	double costOfAllDesks = 0;
	
	// If the area of the desk is less than 1000 sq. ft, the cost is $100 per desk
	if (deskArea > 0 && deskArea < 1000)
	{
		costOfIndividualDesk = 100;
		totalCost += costOfIndividualDesk;
	}
	// If more than 1000 sq. ft, the price is $125 per desk.
	else if (deskArea >= 1000)
	{
		costOfIndividualDesk = 125;
		totalCost += costOfIndividualDesk;
	}
	else
	{
		cout << "ERROR: Invalid length and/or width were provided.\n";
		cout << "Length and width must be positive numbers.\n";
		cout << "Length provided: " << length << endl;
		cout << "Width provided: " << width << endl;
		exit(-1);
	}

	// Print the cost of the desk
	cout << "The cost of desk #" << deskNumber << " is $" << costOfIndividualDesk << endl;

}

void printData(int cost)
{
	// Print the total cost
	cout << "\n\nTotal cost: $" << cost << "\n\n";
}