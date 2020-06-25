#include <iostream>
using namespace std;

void calc(int seconds);

int main()
{
	int seconds;

	cout << "Enter an integer number of seconds: ";
	cin >> seconds;

	calc(seconds);
	
	return 0;
}

void calc(int seconds)
{
	int convertedMinutes;
	int convertedSeconds;

	convertedMinutes = seconds / 60;
	convertedSeconds = seconds % 60;

	cout << seconds << " seconds converts to " << convertedMinutes
		 << " minutes and " << convertedSeconds << " seconds.\n";
}