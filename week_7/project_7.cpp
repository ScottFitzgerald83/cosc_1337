// Scott Fitzgerald
// Project #7
// Status: In Progress
// Date: 2020-07-05
#include <iostream>

using namespace std;

// Globals
const int MAX_NAME_LENGTH = 30;
const int GRADE_LOWER_BOUND = 0;
const int GRADE_UPPER_BOUND = 110;
const int NUM_TESTS = 3;

// Prototypes
struct Grades;

void getStudentData(Grades *studentGrades, int numStudents);

int getValidGrade(int testNumber);

void sortGradesAscending(int *ptestScores, int size);

double calcAverage(const int testScores[]);

struct Grades {
    char studentName[MAX_NAME_LENGTH + 1];
    int testScores[3], *ptrTestScores = testScores;
    double average;
};

int main() {
    int num_students;

    cout << "Test score program" << endl;
    cout << "Enter the number of students: ";
    cin >> num_students;

    Grades *studentGrades = new Grades[num_students];
    getStudentData(studentGrades, num_students);

    for (int i = 0; i < num_students; i++) {
        studentGrades[i].average = calcAverage(studentGrades[i].testScores);
        sortGradesAscending(studentGrades[i].ptrTestScores, NUM_TESTS);
        cout << "\nname: " << studentGrades[i].studentName;
        cout << "\ntest1: " << studentGrades[i].testScores[0];
        cout << "\ntest2: " << studentGrades[i].testScores[1];
        cout << "\ntest3: " << studentGrades[i].testScores[2];
        cout << "\naverage: " << studentGrades[i].average;
    }
}

void getStudentData(Grades *studentGrades, int numStudents) {
    // Get students' grades from user input. Takes a pointer to a
    // struct array, loops over input operation `numStudents` times

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
    // Get and return a valid grade between `GRADE_LOWER_BOUND`
    // and `GRADE_UPPER_BOUND` inclusive
    int validGrade = -1;

    cout << "Enter the grade for test #" << testNumber << ": ";
    while (!(cin >> validGrade) || (validGrade < GRADE_LOWER_BOUND || validGrade > GRADE_UPPER_BOUND)) {
        cout << "ERROR! Grade must be between " << GRADE_LOWER_BOUND
             << " and " << GRADE_UPPER_BOUND << " inclusive." << endl;
        cout << "Enter the grade for test #" << testNumber << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return validGrade;
}

void sortGradesAscending(int *ptestScores, int size) {
    int i, j, t;

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (*(ptestScores + j) < *(ptestScores + i)) {
                t = *(ptestScores + i);
                *(ptestScores + i) = *(ptestScores + j);
                *(ptestScores + j) = t;
            }
        }
    }
}

double calcAverage(const int testScores[]) {
    // Take array of testScores and return average
    double average = 0.0;

    average = (testScores[0] + testScores[1] + testScores[2]) * 1.0 / NUM_TESTS;

    return average;
}