#include <iostream>
using namespace std;

float payFromHours(float hoursWorked, float payRate);

int main()
{
	float payRate, hoursWorked, payAmount;
	
	cout << "Enter the number of hours worked: ";
	cin >> hoursWorked;
	
	cout << "Enter the pay rate: $";
	cin >> payRate;

	payAmount = payFromHours(hoursWorked, payRate);
	cout << "\nYour pay is: $" << payAmount << endl;

	
	return 0;
}

float payFromHours(float hoursWorked, float payRate)
{
	float overtimePay = 0;

	if (hoursWorked <= 40)
	{
		return hoursWorked * payRate;
	}
	else
	{
		overtimePay = (hoursWorked - 40) * payRate * 1.5;
		return (40.0 * payRate + overtimePay);
	}
}