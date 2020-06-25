// Scott Fitzgerald
// Assignment #10
// Status: Completed
// Date: 2020-06-17

// Reads a text file with student numeric grades. Calculates the average of the grades. 
// Also finds how many grades are more than the average. Writes to output file.
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void displayMessage();
int getGrades(string fileName, float& average);
int outputResults(string outputFileName, float average, int numGradesAboveAverage);

int main()
{
	// Declarations
	string inputFileName = "input.txt";  // input filename
	string outputFileName = "output.txt";  // input filename
	int numGradesAboveAverage;
	float average = 0;

	// Display message, read in grades, output results
	displayMessage();
	numGradesAboveAverage = getGrades(inputFileName, average);
	outputResults(outputFileName, average, numGradesAboveAverage);
	
	return 0;

}

void displayMessage()
{
	// Display information about the program
	cout << "\nThis program reads and averages the grades in a data file named input.txt." << endl;	
	cout << "It writes out the average and how many were above average in output.txt" << endl;
}

int getGrades(string fileName, float &average)
{
	// Read in and average the grades from input.txt
	// Then determine how many grades are above average

	// Declarations
	ifstream inputFile;             // ifsream object for input file 
	int countGrades = 0;            // counter for the number of grades 
	double value = 0.0;             // container for each grade
	double total = 0.0;             // sum of grades, used to calculate average
	int higherThanAverage = 0;      // counter for above average grades

	// Open the input file, make sure it opened
	inputFile.open(fileName);
	if (inputFile.fail())
		{
			cout << "Error opening file.\n";
			return 1;
		}
	else
		{
			// Read each line, incrementing grade count and value
			while (inputFile >> value)
			{
				countGrades++;
				total += value;
			}

			// Calculate average
			average = total / countGrades;

			// Start back at the top of the file
			inputFile.clear();
			inputFile.seekg(0, inputFile.beg);

			// Count and return number of grades higher than the average
			while (inputFile >> value)
			{
				if (value > average)
				{
					higherThanAverage += 1;
				}
			}
			return higherThanAverage;
		}

	// Close the file
	inputFile.close();

}

int outputResults(string fileName, float average, int numGradesAboveAverage)
{
	// Create output filestream
	ofstream outputFile;
	
	// Open the output file, make sure it opened
	outputFile.open(fileName);
	if (outputFile.fail())
		{
			cout << "Error opening output file.\n";
			return 1;
		}
	// Write the results to output file
	else
		{
			outputFile << "The average of the grades is " << average << "\n";
			outputFile << numGradesAboveAverage << " of the grades were higher than the average.\n";
		}

	// Close the file
	outputFile.close();

	return 0;
}
