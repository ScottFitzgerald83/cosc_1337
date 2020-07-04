// Scott Fitzgerald
// Project #6
// Status: In Progress
// Date: 2020-07-04

// Payroll program for Armadillo Automotive Group.
// In this assignment you must create and use a struct to hold
// the general employee information for one employee. Ideally,
// you should use an array of structs to hold the employee information
// for all employees.
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Global constants
const int NUM_EMPLOYEES = 4;

// Function prototypes
struct EmployeeInfo;
EmployeeInfo getEmployeeInfo(int);
int getIdNumber();
string getName();
double getPayRate();
int getEmpType();
double getTimecardInfo(const string&);

void payrollReport();

struct EmployeeInfo {
    int empId{};
    string empName;
    double hourlyPayRate{};
    int empType{};
};

int main() {
    EmployeeInfo employees[NUM_EMPLOYEES];
    double hoursWorked[4];

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

    cout << endl;

    return 0;
}

EmployeeInfo getEmployeeInfo(int count) {
    EmployeeInfo employee;

    cout << "\nEnter information for employee " << count << endl;
    employee.empId = getIdNumber();
    employee.empName = getName();
    employee.hourlyPayRate = getPayRate();
    employee.empType = getEmpType();

    return employee;
}

int getIdNumber() {
    int employeeId;

    cout << "Employee ID: ";
    cin >> employeeId;

    return employeeId;
}

string getName() {
    string employeeName;

    cout << "Employee name: ";
    cin.get();
    getline(cin, employeeName);

    return employeeName;
}

double getPayRate() {
    // TODO: Implement function
    double payRate;

    cout << "Pay rate: ";
    cin >> payRate;

    return payRate;

}

int getEmpType() {
    // TODO: Implement function
    int employeeType = 0;

    cout << "Type: ";
    cin >> employeeType;

    return employeeType;

}

double getTimecardInfo(const string& empName) {
    double hours;

    cout << "Enter hours worked for " << empName << ": ";
    cin >> hours;

    return hours;
}

void payrollReport() {
    // TODO: Implement function
    cout << "\nResults";
    cout << "*******\n\n";
}
