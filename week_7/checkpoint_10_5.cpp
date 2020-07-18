// Rewrite the following loop so it uses pointer notation
// (with the indirection operator) instead of subscript notation.
//      for (int x = O; x < 100; x++)
//          cout << array[x ] << endl;
// Created by Scott Fitzgerald on 7/16/20.
#include <iostream>
using namespace std;

int main() {
    int array[100], *parray = array;
    for (int x = 0; x < 100; x++)
    {
        array[x] = x;
    }

    for (int x = 0; x < 100; x ++) {
        cout << *(array + x) << endl;
    }
    return 0;
}