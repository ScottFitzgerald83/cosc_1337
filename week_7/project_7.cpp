// Scott Fitzgerald
// Project #7
// Status: In Progress
// Date: 2020-07-05
#include <iostream>
using namespace std;

// Globals
const int MAX_NAME_LENGTH = 30;

// Prototypes
struct Grades;
Grades getStudentData();

struct Grades {
    char studentName[MAX_NAME_LENGTH + 1];
    int test1;
    int test2;
    int test3;
};
/*
 * Your program should work for any number of students.
 * When the program starts, it should ask the user for the
 * number of students to be processed. Then it should
 * dynamically allocate an array of that size
 * (array of student/score structures) using the new operator.
 */

int main() {
    int num_students;

    cout << "Test score program" << endl;
    cout << "Enter the number of students: ";
    cin >> num_students;

    Grades *studentGrades = new Grades;

    for (int i = 0; i < num_students; i++) {
        studentGrades[i] = getStudentData();
        cout << "\nName: " << studentGrades[i].studentName;
        cout << "\ntest1: " << studentGrades[i].test1;
        cout << "\ntest2: " << studentGrades[i].test2;
        cout << "\ntest3: " << studentGrades[i].test3;
    }

}

Grades getStudentData() {
    Grades studentGrades;

    cout << "\nEnter the student's name: ";
    cin.get();
    cin.getline(studentGrades.studentName, MAX_NAME_LENGTH);
    cout << "Enter the grade for test 1: ";
    cin >> studentGrades.test1;
    cout << "Enter the grade for test 2: ";
    cin >> studentGrades.test2;
    cout << "Enter the grade for test 3: ";
    cin >> studentGrades.test3;

    return studentGrades;

}