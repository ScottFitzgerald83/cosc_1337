// Scott Fitzgerald
// Exam #1 Lab
// Status: Completed
// Date: 2020-06-19

// Manages income flow for AllyBaba Apartment complex. The manager enters the 
// day of the month each of 10 units paid their rent. Calculates and displays
// payment, fee, collections, and eviction statistics

#include <iostream>
using namespace std;

// Function prototypes
void displayInstructions();
int getDayOfMonth();
int calculateFeesIfLate(int dayOfMonth,  int LATE_FEE, int EVICTION_CHARGE, int &tenantsEvicted);
void collectPaymentDetails(int unitNumber,  int MONTHLY_RENT, int LATE_FEE, int EVICTION_CHARGE, int& unitsPaid, 
	int& lateFeesCollected, int& moniesCollected, int& tenantsEvicted, int& moneyInCollections);
void displayResults(int unitsPaid,  int lateFeesCollected,  int moniesCollected,  int tenantsEvicted, int moneyInCollections);

int main()
{
	// Sets constants and variables, coordinates program execution

	// Constants for parameters provided in program statement
	const int NUM_UNITS = 10;         // The number of units Ally owns
	const int MONTHLY_RENT = 2000;    // Rent per unit
	const int LATE_FEE = 5;           // Daily late fee for late rents
	const int EVICTION_CHARGE = 500;  // Eviction charge if rent not paid
	
	// Variables to keep track of payment stats
	int unitsPaid = 0;                // Number of units that paid their rent
	int lateFeesCollected = 0;        // Total late fees collected
	int moniesCollected = 0;          // Total monies collected
	int tenantsEvicted = 0;           // Total tenants evicted
	int moneyInCollections = 0;		  // Money in collections

	// Explain the program and provide instructions
	// Then, loop through each unit to collect payment details
	// Finally, display the results to the user 
	displayInstructions();
	for (int unitNumber = 1; unitNumber <= NUM_UNITS; unitNumber++)
	{
		collectPaymentDetails(unitNumber, MONTHLY_RENT, LATE_FEE, EVICTION_CHARGE, 
			unitsPaid, lateFeesCollected, moniesCollected, tenantsEvicted, moneyInCollections);
	}

	displayResults(unitsPaid, lateFeesCollected, moniesCollected, tenantsEvicted, moneyInCollections);

	return 0;
}

void displayInstructions()
{
	// Displays program info and instructions to the user
	cout << "\nAllyBaba Apartment complex income flow";
	cout << "\n-------------------------------------";
	cout << "\n\nThis program calculates income flow for Ally's apartment units.";
	cout << "\nIt will ask for the day on which each tenant paid their rent.";
	cout << "\nIf any tenant has not paid their rent, enter 0 for the day.\n\n";
}

int getDayOfMonth(int unitNumber)
{
	// Get and validate day of month that rent was paid
	// If 0 is entered, this indicates rent was not paid
	int dayOfMonth;

	cout << "Enter the payment day for unit " << unitNumber << ": ";
	cin >> dayOfMonth;

	// Validation for day number
	while (dayOfMonth < 0 || dayOfMonth > 30)
	{
		cout << "\nERROR: Day of month must be between 0 and 30, try again: ";
		cin >> dayOfMonth;
	}

	return dayOfMonth;
}

int calculateFeesIfLate(int dayOfMonth, int LATE_FEE, int EVICTION_CHARGE, int &tenantsEvicted)
{
	// Calculate fees and eviction charge if payment is late
	// If rent not paid, charge both daily late fee and eviction charge
	int lateFees = 0;

	if (dayOfMonth == 0)
	{
		lateFees += LATE_FEE * 27 + EVICTION_CHARGE;
		tenantsEvicted += 1;
	}
	else if (dayOfMonth > 3)
	{
		lateFees += LATE_FEE * (dayOfMonth - 3);	
	}

	return lateFees;
}

void collectPaymentDetails(int unitNumber,  int MONTHLY_RENT,  int LATE_FEE,  int EVICTION_CHARGE,  int &unitsPaid,
	int &lateFeesCollected, int &moniesCollected, int &tenantsEvicted, int &moneyInCollections)
{
	// Collect payment details for a single apartment unit
	// Get the day rent was paid, determine if that payment was late
	// Calculate late fees, eviction charges, and monies collected, updating variables in main()
	int dayNumber;
	int rentDue = MONTHLY_RENT;
	int totalLateFees = 0;

	// Get day number per unit from user; calculate any late fees and eviction charges
	dayNumber = getDayOfMonth(unitNumber);
	totalLateFees = calculateFeesIfLate(dayNumber, LATE_FEE, EVICTION_CHARGE, tenantsEvicted);

	// Increment the rent (per tenant), plus total rent/monies collected
	rentDue += totalLateFees;
	
	// If rent wasn't paid, increase the amount in collections by their rent + late fees + eviction charge
	if (dayNumber == 0)
	{
		moneyInCollections += rentDue;
	}
	// Otherwise, increase the money and late fees collected
	else
	{
		moniesCollected += rentDue;
		lateFeesCollected += totalLateFees;
		unitsPaid += 1;
	}
	
}

void displayResults(int unitsPaid, int lateFeesCollected, int moniesCollected, int tenantsEvicted, int moneyInCollections)
{
	// Display the number of units that paid, total late fees collected, total money collected,
	// number of tenants evicted, and totaly money in collections

	cout << "\nResults" << endl;
	cout << "---------" << endl;
	cout << "Number of units that paid their rent: " << unitsPaid << endl;
	cout << "Total late fees collected: $" << 	lateFeesCollected << endl;
	cout << "Total monies collected: $" << 	moniesCollected << endl;
	cout << "Number of tenants evicted: " << 	tenantsEvicted << endl;
	cout << "Money that will be in collections: $" << moneyInCollections << endl;
}