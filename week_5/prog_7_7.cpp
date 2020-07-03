//
// Created by Scott Fitzgerald on 7/2/20.
// Demonstrates a destructor
#include <iostream>

using namespace std;

class Demo {
public:
    Demo();                         // Constructor prototype
    ~Demo();                        // Destructor prototype
};

Demo::Demo()                        // Constructor function def
{
    cout << "An object has just been defined, so the constructor "
         << "is running.\n";
}

Demo::~Demo()                       // Destructor function def
{
    cout << "Now the destructor is running";
}

int main() {
    Demo demoObj;                   // Declare a Demo obj

    cout << "The object now exists, but is about to be destroyed.\n";
    return 0;
}



