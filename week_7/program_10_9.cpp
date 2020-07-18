// This program ues a pointer to display the contents of an array
// Created by Scott Fitzgerald on 7/18/20.
//
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 8;
    int set [ ] = {5, 10, 15, 20, 25, 30, 35, 40};
    int *numPtr;

    // Make numPtr point to the set array
    numPtr = set;

    // Use the pointer to display the array elements
    cout << "The numbers in set are:\n";
    for (int index = 0; index < SIZE; index++)
    {
        cout << *numPtr << " ";
        numPtr++;
    }

    // Display the array elements in reverse order
    cout << "\nThe numbers in set backwards are:\n";
    for (int index = 0; index < SIZE; index++) {
        numPtr --;
        cout << *numPtr << " ";
    }
    return 0;
}