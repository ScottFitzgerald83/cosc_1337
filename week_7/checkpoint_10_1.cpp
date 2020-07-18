// Write a statement that displays the address of the variable count
// Created by Scott Fitzgerald on 7/16/20.
#include <iostream>
using namespace std;

int main() {
    int count, *pcount = &count;
    cout << "count variable is located at: " << *pcount << endl;
    return 0;
}