#include <iostream>
using namespace std;

void loopUntilNegative();

int main()
{
	loopUntilNegative();
	
	return 0;
}

void loopUntilNegative()
{
	int sentinel = 0;
	int counter = 0;
	int num = 0;

	while (sentinel >= 0)
	{
		cout << "Enter an integer number. Enter any negative "
			 << "integer to exit: ";
		cin >> num;

		if (counter == 0 && num < 0)
		{
			cout << "\nNo data entered.\n";
		}
		else
		{
			sentinel = num;	
		}
		
		counter += 1;
	}
}