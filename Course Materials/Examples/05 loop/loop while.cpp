// while

#include <iostream>	
#include <string>		
using namespace std;

void getHeading();

int main()						
{ 
	char choice = ' ';
	
	getHeading();
	cout << "Please enter your choice ";
	cin >> choice;
	
	while (toupper(choice)  != 'E')
	{

		getHeading();
		cout << "Please enter your choice ";
		cin >> choice;
	}  // end of while (toupper(choice)  != 'E')
	
    return 0;
}   // end of main    

// Function will display heading on the screen
void getHeading()
{
	cout << "*************** Ally Baba Bank ***************" << endl;
	cout << " C -       Check"  << endl;
	cout << " D -       Deposit" << endl;
	cout << " E -       End of month Summary" << endl;
	cout << "*********************************************" << endl;
	cout << endl;
}                       

