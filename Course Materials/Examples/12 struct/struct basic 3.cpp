#include <iostream>
#include <cstring>
using namespace std;

struct Employee
{
    short id;
    int age;
    double wage;
};
 
void printInformation(Employee );

 
int main()
{
    Employee joe = { 14, 32, 24.15 };
    Employee frank = { 15, 28, 18.27 };
 
    // Print Joe's information
    printInformation(joe);
 
    cout << "\n";
 
    // Print Frank's information
    printInformation(frank);
 
    system("PAUSE");
    return 0;
}

void printInformation(Employee employee)
{
    cout << "ID:   " << employee.id << "\n";
    cout << "Age:  " << employee.age << "\n";
    cout << "Wage: " << employee.wage << "\n";
}
