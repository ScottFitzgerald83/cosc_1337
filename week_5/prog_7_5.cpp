//
// Created by Scott Fitzgerald on 7/1/20.
// Uses a constructor to initialize a member variable
#include <iostream>
#include <cmath>

using namespace std;

// Circle class declaration
class Circle {
private:
    double radius;

public:
    Circle();

    void setRadius(double);

    double calcArea();
};

// Circle member function implementation
// Initialize radius class member
Circle::Circle() {
    radius = 1.0;
};

void Circle::setRadius(double r) {
    if (r >= 0.0)
        radius = r;
    // else leave it set to its previous value
}
double Circle::calcArea() {
    return 3.14 * pow(radius, 2);
}

int main() {
    // Define a circle object. Since setRadius function never
    // called, it will keep the value set by the constructor
    Circle circle1;

    // Define a second Circle object and set its radius to 2.5
    Circle circle2;
    circle2.setRadius(2.5);

    // Get and display area of each circle
    cout << "The area of circle 1 is " << circle1.calcArea() << endl;
    cout << "The area of circle 2 is " << circle2.calcArea() << endl;

    return 0;
}