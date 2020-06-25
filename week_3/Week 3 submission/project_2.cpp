// Scott Fitzgerald
// Project #2
// Status: Completed
// Date: 2020-06-17

// This program helps balance a checkbook at the end of the month. The user enters 
// the initial balance followed by a series of transactions. Calculates end of month balance 
// at the end of the program
#include <iostream>
#include <string>		// Needed to use string data type
#include <iomanip>      // Needed to set float display width
using namespace std;

// Function prototypes
double getBeginningBalance();
void getTransactions(double& runningAccountBalance, double serviceCharge, double& accumulatedServiceCharges);
void confirmTransaction(char transactionType, double transactionAmount);
double processTransaction(char transactionType, double transactionAmount, double serviceCharge, double& accumulatedServiceCharges);
void displayTransactionConfirmation(double& runningAccountBalance, double& accumulatedServiceCharges, char transactionType);
void processEndOfMonth(double runningAccountBalance, double accumulatedServiceCharges);

int main()
{
	// Declarations
	double beginningBalance = 0;							// user-input beginning balance
	double runningAccountBalance = 0;   					// used to store transaction totals
	double totalExpenses = 0;								// accumulator for expenses
	double totalIncomes = 0;								// accumulator for incomes
	double serviceCharge = .25;       						// don't charge until EOM
	double accumulatedServiceCharges = 0;					// don't charge until EOM

	// Get initial balance from user
	beginningBalance = getBeginningBalance();
	runningAccountBalance = beginningBalance;

	// Get transactions, updating the running balance and accumulated service charge variables
	getTransactions(runningAccountBalance, serviceCharge, accumulatedServiceCharges);

	return 0;
}

double getBeginningBalance()
{
	// Gets the beginning balance from the user
	double balance = 0;

	cout << "\nAlly Baba Checkbook Balancing Program" << endl; 
	cout << "\nEnter the beginning balance: $";
	cin >> balance;

	return balance;
}

void getTransactions(double &runningAccountBalance, double serviceCharge, double &accumulatedServiceCharges)
{
	// Gets the type and amount of the transaction from the user

	// Declarations
	char transactionType;				// Used to get transaction type from user
	double transactionAmount = 0;		// Used to get transaction amount from user
	double transactionValue = 0;		// Amount by which to increment/decrement running balance

	// Loop over transaction menu and input until 'E' is received
	while (transactionType != 'E')
	{
		cout << "\n---------------------------------------------------" << endl;
		cout << "Select Transaction Type: " << endl;
		cout << "C - Process a check" << endl;
		cout << "D - Process a deposit" << endl;
		cout << "E – Exit" << endl;
		cout << "\nEnter transaction type: ";
		cin >> transactionType;

		// Confirm the transaction type is valid
		if (transactionType != 'C' && transactionType != 'D' && transactionType != 'E')
		{
			cout << transactionType << " is not a valid selection, skipping." << endl;
			continue;
		}
		// If transaction type is a check or deposit, confirm and process the transaction
		if (transactionType == 'C' || transactionType == 'D')
		{
			cout << "Enter transaction amount: $";
			cin >> transactionAmount;
			
			// First, confirm the transaction amount is valid
			if (transactionAmount < 0)
			{
				cout << "$ " << transactionAmount << " is not a valid amount. Transaction must be";
				cout << "\nlarger than zero. Skipping this transaction, try again." << endl;
				continue;
			}
			// If valid, then confirm and process the transaction
			else
			{
				// process the transaction, update running balance, and display transaction results
				confirmTransaction(transactionType, transactionAmount);
				transactionValue = processTransaction(transactionType, transactionAmount, serviceCharge, accumulatedServiceCharges);
				runningAccountBalance += transactionValue;
				displayTransactionConfirmation(runningAccountBalance, accumulatedServiceCharges, transactionType);
			}
		}

		// Otherwise if 'E' is received for transactionType, perform end of month processing
		else if (transactionType == 'E')
		{
			processEndOfMonth(runningAccountBalance, accumulatedServiceCharges);
		}
	}
}

void confirmTransaction(char transactionType, double transactionAmount)
{
	// Confirm the type and amount of transaction, print results
	string enumeratedTransactionType;
	
	if (transactionType == 'C')
	{
		 enumeratedTransactionType = "check";
	}
	else if (transactionType == 'D')
	{
		 enumeratedTransactionType = "deposit";
	}

	cout << "Processing " << enumeratedTransactionType << " for $" << transactionAmount << endl;
}

double processTransaction(char transactionType, double transactionAmount, double serviceCharge, double &accumulatedServiceCharges)
{
	// Takes a transaction type and amount and returns the amount
	// The amount is used by the caller to increment/decrement the running balance
	double amount = 0;

	// If transaction is a check, return a negative amount increment accumulatedServiceCharges
	if (transactionType == 'C')
	{
		amount -= transactionAmount;
		accumulatedServiceCharges += serviceCharge;
	}
	// If a deposit, just return a positive amount
	else if (transactionType == 'D')
	{
		amount += transactionAmount;
	}
	
	return amount;
}

void displayTransactionConfirmation(double &runningAccountBalance, double &accumulatedServiceCharges, char transactionType)
{
	// Displays the results of a single transaction
	cout << fixed << setprecision (2);

	cout << "\nProcessed..." << endl;
	cout << "Balance: $" << runningAccountBalance << endl;
	if (transactionType == 'C')
	{
		cout << "Service charge: $0.25 for a check." << endl;
	}
	cout << "Total service charges: $" << accumulatedServiceCharges << endl;
}

void processEndOfMonth(double runningAccountBalance, double accumulatedServiceCharges)
{
	// Displays the end of month results by subtracting service charges from running balance
	cout << "\nProcessing end of month" << endl;
	cout << "Final balance: $" << runningAccountBalance - accumulatedServiceCharges << endl;
}



