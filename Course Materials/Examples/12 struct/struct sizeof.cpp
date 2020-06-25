#include <iostream>
#include <cstring>
using namespace std;

struct Employee
{
    short id;
    int age;
    double wage;
};
 
int main()
{
    cout << "The size of Employee is " << sizeof(Employee) << "\n";
 
    system("PAUSE");
    return 0;
}
