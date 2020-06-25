// Scott Fitzgerald
// Assignment #4
// Status: Complete
// Date: 2020-06-02

// Accepts a numeric grade as input from the professor. Converts the numeric grade to
// a letter grade and displays the results, along with a custom message
#include <iostream>
#include <string>
using namespace std;

// Function prototypes
double getData();
void processData(double numericGrade);

int main()
{
	// Get and store grade from user, then pass to processing function
	double numericGrade = getData();

	processData(numericGrade);

	return 0;
}

double getData()
{
	// Gets the numeric grade from the user and returns to caller
	double numberGrade = 0;
	
	cout << "\n\nThis program converts a numeric grade into a letter grade ";
	cout << "and prints a custom message based on the grades.";
	cout << "\n\nEnter a numeric grade between 0 and 100: ";
	cin >> numberGrade;

	return numberGrade;
}

void processData(double numericGrade)
{
	// Determines letter grade for a valid numeric grade and prints 
	// grade and a custom message based on grade

	// Declarations
	const int SCORE_LOWER_BOUND = 0;    // Lowest possible score
	const int SCORE_UPPER_BOUND = 100;  // Highest possible score
	const int A_THRESHOLD = 90;         // Letter grade thresholde
	const int B_THRESHOLD = 80;         // Letter grade thresholde
	const int C_THRESHOLD = 70;         // Letter grade thresholde
	const int D_THRESHOLD = 60;         // Letter grade thresholde	
	string message;						// Used to store custom message

	// Checks for valid input (0 <= score <= 100)
	if (numericGrade >= SCORE_LOWER_BOUND and numericGrade <= SCORE_UPPER_BOUND)
	{	
		if (numericGrade >= A_THRESHOLD) {
			message = "Letter Grade A – I am Genius!";
		}
		else if (numericGrade >= B_THRESHOLD)
		{
			message = "Letter Grade B – I am Good worker";
		}
		else if (numericGrade >= C_THRESHOLD)
		{
			message = "Letter Grade C – I am Barely Average";
		}
		else if (numericGrade >= D_THRESHOLD)
		{
			message = "Letter Grade D – I am not doing my work";
		}
		else
		{
			message = "Letter Grade Grade F – I will try Next Time";
		}

		cout << message << endl;
	}
	else
	{
		// Invalid score entered
		cout << "An invalid score was entered. Run again and enter a score between ";
		cout << SCORE_LOWER_BOUND << " and " << SCORE_UPPER_BOUND << "\n";
	}
}




