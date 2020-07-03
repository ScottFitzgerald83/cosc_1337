//
// Created by Scott Fitzgerald on 7/1/20.
// Demostrates when a constructor executes.
#include <iostream>

using namespace std;

class Demo {
public:
    Demo() {
        cout << "Now the constructor is running.\n";
    }
};

int main() {
    cout << "This is displayed before the object is created.\n";

    // Define a demo object
    Demo demoObj;

    cout << "This is displayed after the object is created.\n";
    return 0;
}

