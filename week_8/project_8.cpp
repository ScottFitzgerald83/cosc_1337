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

int main() {
    // Defines several valid and invalid date object
    // Sets the dates for those objects then displays each date
    // in the various formats defined above

    // Declare date object
    Date validDate1, validDate2, validDate3, validDate4, validDate5;
    Date invalidDate1, invalidDate2, invalidDate3, invalidDate4, invalidDate5, invalidDate6;

    // valid date objects
    validDate1.setDate(2, 9, 1983);
    validDate2.setDate(3, 10, 2016);
    validDate3.setDate(4, 30, 1970);
    validDate4.setDate(7, 31, 2010);
    validDate5.setDate(12, 25, 1999);

    // invalid date objects
    invalidDate1.setDate(0, 9, 1983);
    invalidDate2.setDate(13, 31, 2016);
    invalidDate3.setDate(4, 0, 1940);
    invalidDate4.setDate(7, 32, 2010);
    invalidDate5.setDate(12, 25, 1949);
    invalidDate6.setDate(12, 25, 2021);

    // display each date in each format
    cout << "\n**********************" << endl;
    cout << "    Valid dates" << endl;
    cout << "**********************" << endl;

    cout << "\nDate 1: " << endl;
    validDate1.printMDYnumeric(); validDate1.printMDYalpha(); validDate1.printDMYalpha();
    cout << "\nDate 2: " << endl;
    validDate2.printMDYnumeric(); validDate2.printMDYalpha(); validDate2.printDMYalpha();
    cout << "\nDate 3: " << endl;
    validDate3.printMDYnumeric(); validDate3.printMDYalpha(); validDate3.printDMYalpha();
    cout << "\nDate 4: " << endl;
    validDate4.printMDYnumeric(); validDate4.printMDYalpha(); validDate4.printDMYalpha();
    cout << "\nDate 5: " << endl;
    validDate5.printMDYnumeric(); validDate5.printMDYalpha(); validDate5.printDMYalpha();

    cout << "\n**********************" << endl;
    cout << "     Invalid dates" << endl;
    cout << "**********************" << endl;

    cout << "\nDate 1: " << endl;
    invalidDate1.printMDYnumeric(); invalidDate1.printMDYalpha(); invalidDate1.printDMYalpha();
    cout << "\nDate 2: " << endl;
    invalidDate2.printMDYnumeric(); invalidDate2.printMDYalpha(); invalidDate2.printDMYalpha();
    cout << "\nDate 3: " << endl;
    invalidDate3.printMDYnumeric(); invalidDate3.printMDYalpha(); invalidDate3.printDMYalpha();
    cout << "\nDate 4: " << endl;
    invalidDate4.printMDYnumeric(); invalidDate4.printMDYalpha(); invalidDate4.printDMYalpha();
    cout << "\nDate 5: " << endl;
    invalidDate5.printMDYnumeric(); invalidDate5.printMDYalpha(); invalidDate5.printDMYalpha();
    cout << "\nDate 6: " << endl;
    invalidDate6.printMDYnumeric(); invalidDate6.printMDYalpha(); invalidDate6.printDMYalpha();

    return 0;
}

string getMonthName(int monthNumber) {
    vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                             "October", "November", "December"};
    return months[monthNumber - 1];
}