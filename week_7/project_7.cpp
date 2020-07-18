// Scott Fitzgerald
// Project #7
// Status: In Progress
// Date: 2020-07-18
// This program gets names and grades of students from user input. From there, it calculates
// The average grade per student and displays the results.
#include <iostream>
#include <iomanip>

using namespace std;

// Globals
const int MAX_NAME_LENGTH = 30;                                 // Longest name allowed
const int GRADE_LOWER_BOUND = 0;                                // Lowest grade allowed
const int GRADE_UPPER_BOUND = 110;                              // Highest grade allowed
const int A_THRESHOLD = 90;                                     // Letter grade thresholds
const int B_THRESHOLD = 80;                                     // Letter grade thresholds
const int C_THRESHOLD = 70;                                     // Letter grade thresholds
const int NUM_TESTS = 3;                                        // Number of tests

// Prototypes
struct Grades;                                                  // Struct to hold student name/grade pairs
void showIntro();                                               // Message to introduce the progam
void getStudentData(Grades *studentGrades, int numStudents);    // Gets user input on num students and grades
int getValidGrade(int testNumber);                              // Get and validate each grade
void sortGradesAscending(int *ptestScores, int size);           // Sort the grades in ascending order
double calcAverage(const int testScores[]);                     // Calculate each student's average
char calcLetterGrade(double average);                           // Calculate each student's letter grade
double calcClassAverage(Grades *studentGrades, int numStudents);// Calculate avg grade for the class
void displayResults(Grades *studentGrades, int numStudents, double average);    // Display resuts

struct Grades {
    char studentName[MAX_NAME_LENGTH + 1];                      // Name of the student
    int testScores[3], *ptrTestScores = testScores;             // Array to hold grades, along with pointer
    double average;                                             // Average of all grades
    char letterGrade;                                           // Student's letter grade
};

int main() {
    // Main function, prints program description and instructions
    // Calls the other functions to get student names and grades,
    // Sort grades, calculate and display averages
    int num_students;
    double classAverage;

    showIntro();
    cin >> num_students;

    Grades *studentGrades = new Grades[num_students];
    getStudentData(studentGrades, num_students);

    for (int i = 0; i < num_students; i++) {
        studentGrades[i].average = calcAverage(studentGrades[i].testScores);
        sortGradesAscending(studentGrades[i].ptrTestScores, NUM_TESTS);
        studentGrades[i].letterGrade = calcLetterGrade(studentGrades[i].average);
    }

    classAverage = calcClassAverage(studentGrades, num_students);
    displayResults(studentGrades, num_students, classAverage);
}

void showIntro() {
    // Displays basic program information and instructions
    cout << "*************************************************************************" << endl;
    cout << "This program takes student names and scores and calculates grade averages" << endl;
    cout << "*************************************************************************" << endl;
    cout << "\nEnter the number of students: ";
}

void getStudentData(Grades *studentGrades, int numStudents) {
    // Get students' grades from user input. Takes an array pointer, loops over input operation `numStudents` times

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter the student's name: ";
        cin.get();
        cin.getline(studentGrades[i].studentName, MAX_NAME_LENGTH);
        for (int j = 0; j < NUM_TESTS; j++) {
            studentGrades[i].testScores[j] = getValidGrade(j + 1);
        }
    }
}

int getValidGrade(int testNumber) {
    // Get and return a valid grade between `GRADE_LOWER_BOUND` and `GRADE_UPPER_BOUND` inclusive
    int validGrade = -1;

    cout << "Enter the grade for test #" << testNumber << ": ";
    while (!(cin >> validGrade) || (validGrade < GRADE_LOWER_BOUND || validGrade > GRADE_UPPER_BOUND)) {
        cout << "ERROR! Grade must be an integer between " << GRADE_LOWER_BOUND
             << " and " << GRADE_UPPER_BOUND << " inclusive." << endl;
        cout << "Enter the grade for test #" << testNumber << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return validGrade;
}

void sortGradesAscending(int *ptestScores, int size) {
    // Takes a pointer to an array and sorts the array in ascending order. Used to sort student grades.
    int i, j, temp;

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (*(ptestScores + j) < *(ptestScores + i)) {
                temp = *(ptestScores + i);
                *(ptestScores + i) = *(ptestScores + j);
                *(ptestScores + j) = temp;
            }
        }
    }
}

double calcAverage(const int testScores[]) {
    // Take array of testScores and return the average score
    return (testScores[0] + testScores[1] + testScores[2]) * 1.0 / NUM_TESTS;
}

char calcLetterGrade(double average) {
    // Takes a grade average and returns the corresponding letter grade
    char letterGrade;

    if (average <= C_THRESHOLD) {
        letterGrade = 'F';
    } else if (average <= B_THRESHOLD) {
        letterGrade = 'C';
    } else if (average <= A_THRESHOLD) {
        letterGrade = 'B';
    } else {
        letterGrade = 'A';
    }

    return letterGrade;
}

double calcClassAverage(Grades *studentGrades, int numStudents) {
    // Takes a struct array and calculates the average of all students' test scores
    double totalPoints = 0;
    int numberOfTests = numStudents * NUM_TESTS;

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < NUM_TESTS; j++) {
            totalPoints += studentGrades[i].testScores[j];
        }
    }
    return totalPoints / numberOfTests;
}

void displayResults(Grades *studentGrades, int numStudents, double average) {
    // Display the results
    cout << fixed << setprecision(2);

    cout << left << setw(30) << "Name"
         << left << setw(20) << "Scores"
         << right << setw(15) << "Letter Grade" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(30) << studentGrades[i].studentName;
        cout << left << setw(3) << studentGrades[i].testScores[0];
        cout << left << setw(3) << studentGrades[i].testScores[1];
        cout << left << setw(3) << studentGrades[i].testScores[2];
        cout << right << setw(15) << studentGrades[i].letterGrade << endl;
    }
    cout << "___________________________________" << endl;
    cout << left << setw(30) << "Average: " << average
         << left << setw(20);
}