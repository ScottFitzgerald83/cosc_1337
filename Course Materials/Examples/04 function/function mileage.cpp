//******************************************************************
// Mileage program
// Programmer: 
// Completed : 3/02/2003
// Status    : Complete
//
// This program computes your mileage for a trip given number of
// gallons of gas used, and starting and ending mileage
//******************************************************************

#include <iostream>      // input/output declarations
#include <iomanip>       // i/o manupulator declarations
using namespace std;

// function prototypes
float mileage( float startMiles, float endMiles, float gallonsUsed );

int main()
{
    float startMiles;      // Starting mileage
    float endMiles;        // Ending mileage
    float gallonsUsed;     // Gallons of gas used
    float mpg;             // Computed miles per gallon

//	Set up floating point output format
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

//  Get starting and ending mileage, and gallons of gas used
    cout << "Enter starting mileage: ";
    cin  >> startMiles;
    cout << "Enter ending mileage: ";
    cin  >> endMiles;
    cout << "Enter number of gallons of gas used: ";
    cin  >> gallonsUsed;

//  Calculate mileage
    mpg = mileage( startMiles, endMiles, gallonsUsed );

//  Print starting and ending mileage, gallons of gas used,
//  and calculated mileage
    cout << "For a trip with:" << endl;
    cout << "    " << gallonsUsed << " gallons of gas used" << endl;
    cout << "    and a starting mileage of " << startMiles << endl;
    cout << "    and  an ending mileage of " << endMiles << endl;
    cout << "    the mileage per gallon is " << mpg << endl;

    return 0;
}

// Function mileage
//
// Purpose: calculates and returns the trip mileage

float mileage( float startMiles,     // In - starting mileage
			   float endMiles,       // In - ending mileage
			   float gallonsUsed )   // In - gallons of gas used
{
    float milesTraveled;   // Total miles traveled
    float mpg;             // Computed miles per gallon

//  Calculate mileage
    milesTraveled = endMiles - startMiles;
    mpg = milesTraveled / gallonsUsed;

	return mpg;
}

