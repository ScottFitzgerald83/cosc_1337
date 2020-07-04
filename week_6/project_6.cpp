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

using namespace std;

// Global constants
const int NUM_EMPLOYEES = 4;

// Function prototypes
struct Payroll;
Payroll getEmployeeInfo(int);

void payrollReport();

struct Payroll {
    int empId{};
    string empName;
    double hourlyPayRate{};
    int empType{};
};

int main() {
    Payroll employees[NUM_EMPLOYEES];

    cout << "Armadillo Automotive Group payroll program." << endl;

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        employees[i] = getEmployeeInfo(i + 1);
    }
    return 0;
}

Payroll getEmployeeInfo(int count) {
    Payroll employee;

    cout << "Enter information for employee " << count << endl;
    cout << "Employee ID: ";
    cin >> employee.empId;
    cout << "Employee name: ";
    cin.get();
    getline(cin, employee.empName);
    cout << "Pay rate: ";
    cin >> employee.hourlyPayRate;
    cout << "Type: ";
    cin >> employee.empType;

    return employee;
}

void payrollReport() {
    cout << "\nResults";
    cout << "*******\n\n";
}