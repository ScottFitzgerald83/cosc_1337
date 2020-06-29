// Scott Fitzgerald
// Project #4
// Status: Complete
// Date: 2020-06-27

// Tracks how many pounds of food each of its three monkeys eats each day during a typical week.
// Gets food eaten in pounds per monkey per day as user input, then calculates and displays a table
// of food per day per monkey. Also calculates and displays average, min, and max food eaten for all monkeys.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Global constants for number of monkeys and days
const int NUM_MONKEYS = 3;
const int NUM_DAYS = 7;

// Function declarations
void inputFoodAmounts(double foodEaten[][NUM_DAYS], string dayName[NUM_DAYS]);
double getLeastFoodEaten(double foodEaten[][NUM_DAYS]);
double getMostFoodEaten(double foodEaten[][NUM_DAYS]);
double getAverageFoodEaten(double foodEaten[][NUM_DAYS]);
void printTable(double foodEaten[][NUM_DAYS], string dayName[NUM_DAYS]);

int main() {
    // Calls the input food and print table functions

    // Variable Declarations
    string dayName[NUM_DAYS] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};  // Days of the week
    double foodEaten[NUM_MONKEYS][NUM_DAYS];                                       // 2D array to hold food amounts

    inputFoodAmounts(foodEaten, dayName);
    printTable(foodEaten, dayName);

    return 0;
}
void inputFoodAmounts(double foodEaten[][NUM_DAYS], string dayName[NUM_DAYS])
{
    // Gets the amount of food per monkey per day from user

    // Nested loop to populate 2D array
    for (int monkey = 0; monkey < NUM_MONKEYS; monkey++) {
        for (int day = 0; day < NUM_DAYS; day++) {
            cout << "Enter pounds of food eaten by monkey " << (monkey + 1)
                 << " on " << dayName[day] << ": ";
            cin >> foodEaten[monkey][day];
        }
        cout << endl;
    }
}

double getLeastFoodEaten(double foodEaten[][NUM_DAYS]) {
    // Returns the minimum amount of food eaten by any monkey on any day
    // Set the minimum to the first value in the first array

    // Declarations
    double leastFoodEaten = foodEaten[0][0];   // Set the minimum to the first array value

    // If any subsequent value is lower, set leastFoodEaten to that
    for (int monkey = 0; monkey < NUM_MONKEYS; monkey++) {
        for (int day = 0; day < NUM_DAYS; day++) {
            if (foodEaten[monkey][day] <= leastFoodEaten) {
                leastFoodEaten = foodEaten[monkey][day];
            }
        }
    }
    return leastFoodEaten;
}

double getMostFoodEaten(double foodEaten[][NUM_DAYS]) {
    // Returns the maximum amount of food eaten by any monkey on any day
    // Set the maximum to the first value in the first array

    // Declarations
    double mostFoodEaten = foodEaten[0][0];     // Set the maximum to the first array value

    // If any subsequent value is higher, set mostFoodEaten to that
    for (int monkey = 0; monkey < NUM_MONKEYS; monkey++) {
        for (int day = 0; day < NUM_DAYS; day++) {
            if (foodEaten[monkey][day] >= mostFoodEaten) {
                mostFoodEaten = foodEaten[monkey][day];
            }
        }
    }
    return mostFoodEaten;
}

double getAverageFoodEaten(double foodEaten[][NUM_DAYS])
{
    // Gets the average amount of food eaten per day by all monkeys

    // Declarations
    double totalFoodEaten = 0;  // Set an accumulator variable

    // Add each food amount to the accumulator
    for (int monkey = 0; monkey < NUM_MONKEYS; monkey++) {
        for (int day = 0; day < NUM_DAYS; day++) {
                totalFoodEaten += foodEaten[monkey][day];
            }
        }
    // Divide the total by the number of days
    return totalFoodEaten / NUM_DAYS;
}

void printTable(double foodEaten[][NUM_DAYS], string dayName[NUM_DAYS])
{
    // Prints table of food per monkey per day

    // Print results
    cout << "Pounds of Food Eaten by Monkey and Day of Week\n\n";
    cout << "Monkey\t";
    for (int day = 0; day < NUM_DAYS; day++) {
        cout << dayName[day] << "\t";
    }
    cout << endl;

    for (int monkey = 0; monkey < NUM_MONKEYS; monkey++) {
        cout << monkey + 1 << "\t";
        for (int day = 0; day < NUM_DAYS; day++) {
            cout << foodEaten[monkey][day] << "\t";
        }
        cout << endl;
    }

    // Set decimal precision to 2 places
    cout << fixed << setprecision(2);
    cout << "\nThe average food eaten per day by all monkeys:       "
         << getAverageFoodEaten(foodEaten) << " pounds" << endl;
    cout << "The least amount of food eaten by any monkey:        "
         << getLeastFoodEaten(foodEaten) << " pounds" << endl;
    cout << "The largest amount of food eaten per by any monkey:  "
         << getMostFoodEaten(foodEaten) << " pounds" << endl;
}