// Scott Fitzgerald
// Project #2
// Status: Completed
// Date: 2020-06-28

// This program helps balance a checkbook at the end of the month. The user enters
// the initial balance followed by a series of transactions. Calculates end of month balance
// at the end of the program
#include <iostream>
#include <string>        // Needed to use string data type
#include <iomanip>      // Needed to set float display width

using namespace std;

// Global constants
const double CHECKSERVICECHARGE = .35;
const double LOWBALANCECHARGE = 15.0;
const double MINACCOUNTBALANCE = 500.0;

// Function prototypes
double getBeginningBalance();
void getTransactions(double& currentBal, double& totalSvcCharges, bool& lowBalFeeAssessed);
void printTransactionMenu();
int getTransactionTypeAndAmount(char& tranType, double& tranAmt);
double processCheck(double tranAmt, double &totalSvcCharges);
double processDeposit(double tranAmt);
void confirmTransaction(double& currentBal, double& totalSvcCharges, char tranType, bool& lowBalFeeAssessed);
void printConfirmation(char transactionType, double transactionAmount);
void processEndOfMonth(double currentBal, double totalSvcCharges);

int main() {
    // Declarations
    double beginningBalance = 0;             // user-input beginning balance
    double currentBal = 0;                   // used to store transaction totals
    double totalSvcCharges = 0;              // don't charge until EOM
    bool lowBalFeeAssessed = false;          // whether or not low balance fee has been assessed

    // Get initial balance from user
    beginningBalance = getBeginningBalance();
    currentBal = beginningBalance;

    // Get transactions, updating the running balance and accumulated service charge variables
    getTransactions(currentBal, totalSvcCharges, lowBalFeeAssessed);

    return 0;
}

double getBeginningBalance() {
    // Gets the beginning balance from the user
    double balance = 0;

    cout << "\nAlly Baba Checkbook Balancing Program" << endl;
    cout << "\nEnter the beginning balance: $";

    // loop over input until valid amount received
    while (!(cin >> balance)) {
        cout << "ERROR! Balance must be a number value. Enter the beginning balance: $";
        cin.clear();
    }

    return balance;
}

void getTransactions(double &currentBal, double &totalSvcCharges, bool &lowBalFeeAssessed) {
    // Gets the type and amount of the transaction from the user

    // Declarations
    char tranType = '\0';                // Used to get transaction type from user
    double tranAmt = 0;        // Used to get transaction amount from user
    double transactionValue = 0;        // Amount by which to increment/decrement running balance

    // Loop over transaction menu and input until 'E' is received
    while (tranType != 'E') {
        printTransactionMenu();
        getTransactionTypeAndAmount(tranType, tranAmt);

        // process either a check or deposit
        if (tranType == 'C') {
            transactionValue = processCheck(tranAmt, totalSvcCharges);
        }
        else if (tranType == 'D')
        {
            transactionValue = processDeposit(tranAmt);
        }
        // process transaction, increment/decrement balance, then confirm transaction
        printConfirmation(tranType, tranAmt);
        currentBal += transactionValue;
        confirmTransaction(currentBal, totalSvcCharges, tranType, lowBalFeeAssessed);

        // getTransactionTypeAndAmount() may set tranType to E; in that case,
        // process end of month report
        if (tranType == 'E')  {
            processEndOfMonth(currentBal, totalSvcCharges);
        }
    }
}

void printTransactionMenu() {
    // Prints the transaction menu and instructions
    cout << "\n---------------------------------------------------" << endl;
    cout << "Select Transaction Type: " << endl;
    cout << "C - Process a check" << endl;
    cout << "D - Process a deposit" << endl;
    cout << "E – Exit" << endl;
    cout << "\nEnter transaction type and amount separated by a space (ex.: C 42.42): ";
}

int getTransactionTypeAndAmount(char &tranType, double &tranAmt) {
    // Get and validate transaction type and amount
    string retryMessage = "Enter transaction type and amount separated by a space (ex.: C 42.42): ";

    cin >> tranType;
    tranType = toupper(tranType);

    // Don't process transaction if menu selection is end of month
    if (tranType == 'E') {
        tranAmt = 0;
        return 0;
    }
    cin >> tranAmt;

    // Loop until valid transaction type entered
    while (tranType != 'C' && tranType != 'D' && tranType != 'E') {
        cout << "Received transaction type: " << tranType << endl;
        cout << "ERROR! Transaction type must be one of: C, D, E" << endl;
        cout << retryMessage;
        cin >> tranType >> tranAmt;
        tranType = toupper(tranType);
    }

    // Loop until positive transaction amount entered
    while (tranAmt < 0) {
        cout << "ERROR! Transaction amount must be a positive number" << endl;
        cout << retryMessage;
        cin >> tranType >> tranAmt;
        tranType = toupper(tranType);
    }
    return 0;
}


double processCheck(double tranAmt, double &totalSvcCharges)
{
    // Assesses a service charge for checks and returns debit amount (negative double)
    double amount = 0;

    amount -= tranAmt;
    totalSvcCharges += CHECKSERVICECHARGE;

    return amount;
}

double processDeposit(double tranAmt)
{
    // Process a deposit by returning credit amount (positive double)
    double amount = 0;

    amount += tranAmt;

    return amount;
}

void printConfirmation(char transactionType, double transactionAmount)
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


void confirmTransaction(double &currentBal, double &totalSvcCharges, char tranType, bool &lowBalFeeAssessed)
{
    // Displays the results of a single transaction
    cout << fixed << setprecision (2);

    cout << "\nProcessed..." << endl;
    cout << "Balance: $" << currentBal << endl;

    // Assess a service charge for checks
    if (tranType == 'C')
    {
        cout << "Service charge: $" << CHECKSERVICECHARGE << " for a check." << endl;
    }
    // Assess a one-time low balance fee if balance under $500
    if (currentBal < 500 && !(lowBalFeeAssessed))
    {
        cout << "Service charge: " << LOWBALANCECHARGE << " balance below $" << MINACCOUNTBALANCE << endl;
        totalSvcCharges += LOWBALANCECHARGE;
        lowBalFeeAssessed = true;
    }
    cout << "Total service charges: $" << totalSvcCharges << endl;
}

void processEndOfMonth(double currentBal, double totalSvcCharges) {
    // Displays the end of month results
    cout << "\nProcessing end of month" << endl;
    cout << "Final balance: $" << currentBal - totalSvcCharges << endl;
}
