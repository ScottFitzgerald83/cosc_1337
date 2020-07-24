// Scott Fitzgerald
// Project #8
// Status: Completed
// Date: 2020-07-22
// Defines a Date class with a default date of 1/1/2020. Contains public member functions
// for creating date objects and setting valid day, month, and year. Also contains public
// methods for printing dates in various formats.
#include <iostream>
#include <string>
#include <vector>                   // Used to store month names

using namespace std;

string getMonthName(int);           // Get month string from int

class Date {
private:
    int day;                        // Day in numeric format
    int month;                      // Month in numeric format
    int year;                       // Year in numeric format
public:
    Date();                         // Date class
    void setDate(int, int, int);    // Date setter
    void printMDYnumeric();         // Print date in MM/DD/YYYY format
    void printMDYalpha();           // Print date in Month DD, YYYY format
    void printDMYalpha();           // Print date in DD Month YYYY format
    void printEachFormat();         // Prints each of the above formats
};

Date::Date() {
    month = 1;                      // Default date values
    day = 1;                        // Default date values
    year = 2020;                    // Default date values
};

void Date::setDate(int m, int d, int y) {
    // Date setter implementation. Confirms the date is valid; if invalid
    // date is not updated but remains the default from above, 1/1/2020

    // Set boolean values for whether each data component is valid
    bool isValidMonth = (m >= 1 && m <= 12);
    bool isValidDay = (d >= 1 && d <= 31);
    bool isValidYear = (y >= 1950 && y <= 2020);
    bool isValidDate = isValidMonth && isValidDay && isValidYear;

    // Only update Date object if all date parts are valid
    if (isValidDate) {
        month = m;
        day = d;
        year = y;
    }
}

void Date::printMDYnumeric() {
    // prints the date in MM/DD/YYYY format, i.e., 3/15/2010
    cout << month << "/" << day << "/" << year << endl;
}

void Date::printMDYalpha() {
    // Prints the date in Month DD, YYYY format, i.e., March 15, 2010
    cout << getMonthName(month) << " " << day << ", " << year << endl;
}

void Date::printDMYalpha() {
    // Prints the date in DD Month YYYY format, i.e., 15 March 2010
    cout << day << " " << getMonthName(month) << " " << year << endl;
}

void Date::printEachFormat() {
    // Prints the date in each of the formats defined in the print date functions
    cout << endl;
    printMDYnumeric();
    printMDYalpha();
    printDMYalpha();
}

int main() {
    // Defines several valid and invalid date object
    // Sets the dates for those objects then displays each date
    // in the various formats defined above

    // Declare valid and invalid date objects for testing
    Date validDateObj;
    Date invalidDateObj;

    // display valid dates in each format
    cout << "**********************" << endl;
    cout << "    Valid dates" << endl;
    cout << "**********************" << endl;
    validDateObj.setDate(2, 9, 1983);
    validDateObj.printEachFormat();
    validDateObj.setDate(3, 10, 2016);
    validDateObj.printEachFormat();
    validDateObj.setDate(4, 30, 1970);
    validDateObj.printEachFormat();
    validDateObj.setDate(7, 31, 2010);
    validDateObj.printEachFormat();
    validDateObj.setDate(12, 25, 1999);
    validDateObj.printEachFormat();

    // display invalid dates in each format
    cout << "**********************" << endl;
    cout << "    Invalid dates" << endl;
    cout << "**********************" << endl;
    invalidDateObj.setDate(0, 9, 1983);
    invalidDateObj.printEachFormat();
    invalidDateObj.setDate(13, 31, 2016);
    invalidDateObj.printEachFormat();
    invalidDateObj.setDate(4, 0, 1940);
    invalidDateObj.printEachFormat();
    invalidDateObj.setDate(7, 32, 2010);
    invalidDateObj.printEachFormat();
    invalidDateObj.setDate(12, 25, 1949);
    invalidDateObj.printEachFormat();
    invalidDateObj.setDate(12, 25, 2021);

    return 0;
}

string getMonthName(int monthNumber) {
    // Takes an int value and returns the corresponding month
    vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                             "October", "November", "December"};
    return months[monthNumber - 1];
}

