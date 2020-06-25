

#include <iostream>  	// for cin, cout, endl
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//class Date
class Date
{
	//priavte variables
	private:
		int day;
		int month;
		int year;
		
	//public variables and functions
	public:
		string getMonthName(); // prototype

		Date() // consturctor
		{
			day = 1;
			month = 1;
			year = 2020;
			
		}
		
		void setDate(int d, int m, int y)
		{
			if(m <= 12 || m >= 1)
				month = m;
			if(d <= 31 || d >= 1)
				day = d;
			if(y <= 2020 || y >= 1950)
				year = y;
		}
		int getMonth()
		{
			return month;
		}
		int getDay()
		{
			return day;
		}
		int getYear()
		{
			return year;
		}
};

// function thats part of the Date class
string Date :: getMonthName()
{
	if(month == 1)
		return "January";
	else if(month == 2)
		return "February";
	else if(month == 3)
		return "March";
	else if(month == 4)
		return "April";
	else if(month == 5)
		return "May";
	else if(month == 6)
		return "June";
	else if(month == 7)
		return "July";
	else if(month == 8)
		return "August";
	else if(month == 9)
		return "September";
	else if(month == 10)
		return "October";
	else if(month == 11)
		return "November";
	else if(month == 12)
		return "December";
} // end of getMonthName

//main function
int main()						
{
	Date date; // calling class
	date.setDate(4,12,2010);
	cout << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << endl;
	cout << date.getMonthName() << " " << date.getDay() << ", " << date.getYear() << endl;
	cout << date.getDay()<<" "<< date.getMonthName()<<" "<< date.getYear() << endl;
    return 0;
	           
}  // end of main function

