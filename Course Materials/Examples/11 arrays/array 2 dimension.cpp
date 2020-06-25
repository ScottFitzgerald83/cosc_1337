
//***************************************************************
//  Programmer: 
//
//  Purpose:
//  A class takes 4 tests during a semester. This program
//  calculates and prints each student's test average, and
//  the class average for each test. The test grades are in a
//  data file - each line has the 4 test grades for 1 student
//  (maximum of 25 students).
//
//***************************************************************

#include <iostream>	
#include <fstream>  // define directive for file manipulation	
#include <iomanip>
using namespace std;


const int MAX_STUDENTS = 25;    // The maximum class size
const int NUM_TESTS = 4;        // Number of tests in a semester

// Prototypes
void GetGrades( ifstream&, int[][4], int&);
void PrintTests( const int grade[][4],
		     float studentAvg[], 
		       int numStudents, 
		     float classAvg[]);

int main()
{
   ifstream gradeFile;                  // Input file of grades

   int grade[MAX_STUDENTS][NUM_TESTS]; // Semester test grades
   float studentAvg[MAX_STUDENTS];     // Students test average
   float classAvg[NUM_TESTS];          // Class avg for each test
   int numStudents;                    // Number of students
   int studNo;                         //index for a student

// Open the grades file
   gradeFile.open( "grades.txt");
   if (!gradeFile)
   {
      cout << "Could not open \"grades.txt\"";
      return 1;
   }

// Get the semester test grades from the file
   GetGrades( gradeFile, grade, numStudents);

// Print test report
   PrintTests( grade, studentAvg, numStudents, classAvg);

   return 0;
}

//***************************************************************
//  Function: GetGrades
//
//  Purpose: Read test grades from a data file
//***************************************************************

void GetGrades( ifstream& gradeFile,  // in/out - input grade file
		int  grade[][4],       // out    - table of grades
		int& numStudents)        // out    - number of students
{                    
   int test1,        // Student's grade for test 1
       test2,        // Student's grade for test 2
       test3,        // Student's grade for test 3
       test4;        // Student's grade for test 4

   numStudents = 0;
   gradeFile >> test1 >> test2 >> test3 >> test4;
   while (gradeFile && numStudents < MAX_STUDENTS)
   {
      grade[numStudents][0] = test1;
      grade[numStudents][1] = test2;
      grade[numStudents][2] = test3;
      grade[numStudents][3] = test4;
      numStudents++;
      gradeFile >> test1 >> test2 >> test3 >> test4;
   }
}

                                           
//***************************************************************
//  Function: PrintTests
//
//  Purpose: Print Test Report that includes all student test
//           grades, each student's test average, and the
//           class average for each test. 
//***************************************************************
                                                      
void PrintTests( const int grade[][4], // in - table of grades
		     float studentAvg[], // in - students test averages
		       int numStudents,  // in - number of students
		     float classAvg[])   // in - class avg for each test
{
   const int LINE_LENGTH = 60;

   int studNo;     // Student index
   int testNo;     // Test index
   int linePos;    // Position on a line

// Set up floating point formatting
   cout.setf( ios::fixed, ios::floatfield);
   cout.setf( ios::showpoint);
   cout << setprecision(1);

// Print report header
   cout << setw(10) << "Student No"
	<< setw(10) << "Test 1"
	<< setw(10) << "Test 2"
	<< setw(10) << "Test 3"
	<< setw(10) << "Test 4"
	<< setw(10) << "Test Avg"
	<< endl;
   for (linePos = 0; linePos < LINE_LENGTH; linePos++)
      cout << '=';
   cout << endl;

// Print grades for each student
   for (studNo = 0; studNo < numStudents; studNo++)
   {
      cout << setw(10) << studNo;
      for (testNo = 0; testNo < NUM_TESTS; testNo++)
	 cout << setw(10) << grade[studNo][testNo];
      cout << setw(10) << studentAvg[studNo]
           << endl;
   }


}


