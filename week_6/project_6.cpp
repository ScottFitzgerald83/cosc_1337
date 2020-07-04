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
Payroll getEmployeeInfo();

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
        employees[i] = getEmployeeInfo();
    }
    return 0;
}

Payroll getEmployeeInfo() {
    Payroll employee;

    cout << "Enter the employee number: ";
    employee.empId = 1;
    employee.empName = "Bjarne Stroustrup";
    employee.hourlyPayRate = 1000000;
    employee.empType = 0;

    return employee;
}

void payrollReport() {
    cout << "\nResults";
    cout << "*******\n\n";
}