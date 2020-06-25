#include <iostream>
using namespace std;

int calc(int num1, int num2);

int main()
{
	int num1 = 0;
	int num2 = 0;
	int sumDivisibleNumbers = 0;

	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	sumDivisibleNumbers = calc(num1, num2);
	cout << "The sum of all numbers between " << num1
		 << " and " << num2 << " that are divisible by "
		 << "17 is: " << sumDivisibleNumbers << endl;
	return 0;
}

int calc(int num1, int num2)
{
	int sum = 0;

	for (int i = num1; i <= num2; i++)
	{
		if (i % 17 == 0)
		{
			sum += i;
		}
	}

	return sum;
}