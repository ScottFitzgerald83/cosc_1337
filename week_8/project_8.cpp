// Scott Fitzgerald
// Project #8
// Status: In Progress
// Date: 2020-07-22
#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date();

    void setDate(int, int, int);

    void printMDYnumeric();

    void printMDYalpha();

    void printDMYalpha();
};

Date::Date() {
    month = 1;
    day = 1;
    year = 2020;
};

void Date::setDate(int m, int d, int y) {
    bool isValidMonth = (m >= 1 && m <= 12);
    bool isValidDay = (d >= 1 && d <= 31);
    bool isValidYear = (y >= 1950 && y <= 2020);
    bool isValidDate = isValidMonth && isValidDay && isValidYear;

    if (isValidDate) {
        month = m;
        day = d;
        year = y;
    }
}

void Date::printMDYnumeric() {
    // 3/15/2010
    cout << month << "/" << day << "/" << year << endl;
}

void Date::printMDYalpha() {
    // March 15, 2010
    // TODO: Get string month names
    cout << month << " " << day << ", " << year << endl;
}

void Date::printDMYalpha() {
    // TODO: Get string month names
    // 15 March 2010
    cout << day << " " << month << " " << year << endl;
}

int main() {
    // Define a couple Date object
    Date date1;
    Date date2;

    // set the dates in the objects and set it to 3/4/2020
    date1.setDate(3, 14, 2020);
    date2.setDate(7, 20, 1999);

    // display each date in each format
    cout << "Date 1:" << endl;
    date1.printMDYnumeric();
    date1.printDMYalpha();
    date1.printMDYalpha();

    cout << "Date 2:" << endl;
    date2.printMDYnumeric();
    date2.printDMYalpha();
    date2.printMDYalpha();

    return 0;
}