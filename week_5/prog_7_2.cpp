//
// Created by Scott Fitzgerald on 7/1/20.
// Demonstrates a simple class
#include <iostream>
#include <cmath>

using namespace std;

// Circle class declaration
class Circle {
private:
    double radius;

public:
    void setRadius(double);
    double calcArea();
};

void Circle::setRadius(double r) {
    radius = r;
}

double Circle::calcArea() {
    return 3.14 * pow(radius, 2);
}

int main() {
    // Define 2 Circle objects
    Circle circle1;
    Circle circle2;

    // Call the setRadius function for each circle
    circle1.setRadius(1);
    circle2.setRadius(2.5);

    // Call the calcArea function for each circle and
    // display the returned result
    cout << "The area for circle 1 is " << circle1.calcArea() << endl;
    cout << "The area for circle 2 is " << circle2.calcArea() << endl;
}
