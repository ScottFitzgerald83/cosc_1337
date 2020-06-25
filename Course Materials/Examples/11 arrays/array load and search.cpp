#include <iostream>
#include <string>
	
using namespace std;

void inputData(int[], float[], float[], int &,string[]);
void search(int[], float[], float[], int,string[]);

const int MAX_EMPLOYEE = 3;
int main()						
{ 	
	int employeeId[MAX_EMPLOYEE];
	float hourlyPay[MAX_EMPLOYEE];
	float hoursWorked[MAX_EMPLOYEE];
	int count = 0;
	string employeeName[MAX_EMPLOYEE];
	
	
	inputData(employeeId, hourlyPay, hoursWorked, count,employeeName);
	search(employeeId, hourlyPay, hoursWorked, count,employeeName);  		
	
    return 0;
}       

void inputData(int empId[], float hPay[], float hWorked[], int & count,string empName[])
{
	int ID = 0;
	cout << "Please enter employee ID: ";
	cin >> ID;
	
	while (ID != 0 && count < MAX_EMPLOYEE)
	{
		empId[count] = ID;
		cout << "Please enter employee name: ";
		cin >> empName[count];
		cout << "Please enter employee hourly pay: ";
		cin >> hPay[count];
		cout << "Please enter employee hours worked: ";
		cin >> hWorked[count];
		count++;
		
		if (count < MAX_EMPLOYEE)
		{	
		cout << "Please enter employee ID: ";
		cin >> ID;
		}
	}
	
}

void search(int empId[], float hPay[], float hWorked[], int count,string empName[])
{
	int ID = 0;
	int counter = 0;
	bool found = false;
	float salary = 0.0;
	
	cout << "Enter your employee ID to search: ";
	cin >> ID;
	
	while (counter < count && not found)
	{
		if (empId[counter] == ID)
		{
			found = true;
			salary = hPay[counter] * hWorked[counter];
			
		} 
		counter = counter +1;
	}
	
	if (not found)
	{
		cout << "We didn't find your thing";
	}
	else
	{
		cout << empName[counter-1]<< " made : $" << salary;
	}
}
