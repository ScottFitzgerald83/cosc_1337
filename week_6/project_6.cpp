// Scott Fitzgerald
// Project #6
// Status: Completed
// Date: 2020-07-04

// Payroll program for Armadillo Automotive Group. Uses structs to separately store
// employee information and payroll information. Accepts user input to get this information,
// then calculates and displays weekly payroll.
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Global constants
const int NUM_EMPLOYEES = 4;                                // Number of employees
const double INCOME_TAX_RATE = .15;                         // Flat tax rate

// Function prototypes
struct EmployeeInfo;                                        // Struct to hold master employee info
struct WeeklyPayroll;                                       // Struct to hold weekly per-employee payroll info
EmployeeInfo getEmployeeInfo(int);                          // Gets employee info, returns struct
int getIdNumber();                                          // Get employee id number
string getName();                                           // Get employee name
double getPayRate();                                        // Get employee hourly pay rate
int getEmpType();                                           // Get employee type
double getTimecardInfo(const string&);                      // Get number of hours worked per employee
WeeklyPayroll processWeeklyPayroll(double, double, int);    // Process gross pay/income tax/net pay calculations
void payrollReport(EmployeeInfo[], WeeklyPayroll[]);        // Print payroll report

struct EmployeeInfo {
    int empId;                 // Employee's id number
    string empName;            // Employee's name
    double hourlyPayRate;      // Employee's hourly pay rate
    int empType;               // Employee type (0 - union, 1 - management)
};

struct WeeklyPayroll {
    int empId;                 // Employee id number
    string empName;            // Employee name
    double grossPay;           // Weekly gross pay
    double incomeTax;          // Weekly income tax
    double netPay;             // Weekly net pay
};


int main() {
    // Main function -- coordinates program and calls other functions
    // to process employee identity info and calculate pay
    EmployeeInfo employees[NUM_EMPLOYEES];                  // Array of structs, holds master info
    double hoursWorked[4];                                  // Array to hold num hours worked
    WeeklyPayroll employeePay[NUM_EMPLOYEES];               // Array of structs, hold pay info

    cout << "Armadillo Automotive Group payroll program." << endl;

    // Loop over number of employees to get info and
    // add details to Struct array `employees`
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        employees[i] = getEmployeeInfo(i + 1);
    }

    // Loop through employees to get num hours worked
    cout << "\nEnter timecard information for each employee: " << endl;
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        hoursWorked[i] = getTimecardInfo(employees[i].empName);
    }

    // Process payroll info
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        employeePay[i] = processWeeklyPayroll(hoursWorked[i], employees[i].hourlyPayRate, employees[i].empType);
        employeePay[i].empId = employees[i].empId;
        employeePay[i].empName = employees[i].empName;
    }

    payrollReport(employees, employeePay);
    return 0;
}

EmployeeInfo getEmployeeInfo(int count) {
    // Gets master employee information and returns a struct
    // with id number, name, payrate, and employee type
    EmployeeInfo employee;

    cout << "\nEnter information for employee " << count << endl;
    employee.empId = getIdNumber();
    employee.empName = getName();
    employee.hourlyPayRate = getPayRate();
    employee.empType = getEmpType();

    return employee;
}

int getIdNumber() {
    // Input handler for getting employee's id number
    // Validates that id number is a positive number
    int employeeId = -1;

    cout << "Employee ID: ";
    while (!(cin >> employeeId) || employeeId < 0) {
        cout << "ERROR! employee ID must be greater than 0" << endl;
        cout << "Employee ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return employeeId;
}

string getName() {
    // Input handler for getting an employee's name
    string employeeName;

    cout << "Employee name: ";
    cin.get();
    getline(cin, employeeName);

    return employeeName;
}

double getPayRate() {
    // Input handler for getting an employee's pay rate
    // Validates that input is a positive number
    double payRate;

    cout << "Pay rate: ";
    while (!(cin >> payRate) || payRate < 0) {
        cout << "ERROR! Pay rate must be greater than 0" << endl;
        cout << "Pay rate: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return payRate;

}

int getEmpType() {
    // Input handler for getting an employee's type (0 for union, 1 for management)
    // Validates that employee is either 0 or 1.
    int employeeType = -1;

    cout << "Employee type (0 for union, 1 for management): ";
    while (!(cin >> employeeType) || (employeeType != 0 && employeeType != 1)) {
        cout << "ERROR! Employee type must be 0 or 1" << endl;
        cout << "Employee type: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return employeeType;

}

double getTimecardInfo(const string& empName) {
    // Input handler for getting number of hours worked
    // Validates number of hours worked is a positive number
    double hours;

    cout << "Enter hours worked for " << empName << ": ";
    while (!(cin >> hours) || hours < 0 ) {
        cout << "ERROR! Hours worked must be a positive number" << endl;
        cout << "Hours worked for " << empName << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return hours;
}

WeeklyPayroll processWeeklyPayroll(double numHours, double payRate, int empType) {
    // Calculates weekly gross pay, income tax rate, and net pay
    // Returns a WeeklyPayroll struct
    WeeklyPayroll employeePay;                              // Struct to hold pay
    double overtimePay = 0;                                 // Used to store overtime pay

    // Calculate gross pay -- overtime is worth 1.5x
    if (numHours > 40 && empType == 0) {
        overtimePay = (numHours - 40) * 1.5 * payRate;
        employeePay.grossPay = payRate * 40 + overtimePay;
    } else {
        employeePay.grossPay = numHours * payRate;
    }

    // Calculate tax by multiplying numHours worked by tax rate
    employeePay.incomeTax = employeePay.grossPay * INCOME_TAX_RATE;

    // Calculate net pay by subtracting tax from gross
    employeePay.netPay = employeePay.grossPay - employeePay.incomeTax;

    return employeePay;

}

void payrollReport(EmployeeInfo employees[], WeeklyPayroll employeePay[]) {
    // Prints the weekly payroll report to the console
    double totalGrossPay = 0;
    double totalNetPay = 0;

    // Set decimal precision to 2 and print header
    cout << fixed << setprecision(2);
    cout << "\nPayroll report\n" << endl;

    // Set up header row widths and alignment
    cout << left << setw(4)  << "ID"
                 << setw(20) << "Name" <<
           right << setw(11) << "Gross Pay"
                 << setw(11) << "Tax"
                 << setw(11) << "Net Pay" << endl;

    // For each employee, loop through Structs to get and print
    // identity and pay information
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << left << setw(4) << employees[i].empId
                     << setw(20) << employees[i].empName <<
               right << setw(11) << employeePay[i].grossPay
                     << setw(11) << employeePay[i].incomeTax
                     << setw(11) << employeePay[i].netPay << endl;
        totalGrossPay += employeePay[i].grossPay;
        totalNetPay += employeePay[i].netPay;
    }

    cout << "\nTotal Gross Pay: $" << totalGrossPay;
    cout << "\nTotal Gross Pay: $" << totalNetPay;

    cout << "\n\nPress any key to continue . . . " << endl;
}
