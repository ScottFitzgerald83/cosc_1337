// Write a statement defining a variable dPtr. The variable
// should be a pointer to a double.
// Created by Scott Fitzgerald on 7/16/20.
#include <iostream>

using namespace std;

int main() {
    double foo, *dPtr = &foo;
    cout << "foo variable is located at: " << *dPtr << endl;
    return 0;
}
