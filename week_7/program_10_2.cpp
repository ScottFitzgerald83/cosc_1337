// This program stores the address of a variable in a pointer
// Created by Scott Fitzgerald on 7/17/20.
//
#include <iostream>

using namespace std;

int main() {

    int x = 25;       // int variable
    int *ptr;         // Pointer variable can point to int

    ptr = &x;         // Store the address of x in ptr
    cout << "The value of x is "  << x << endl;
    cout << "The address of x is "  << ptr << endl;

    return 0;
}