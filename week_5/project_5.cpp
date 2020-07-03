// Scott Fitzgerald
// Project #5
// Status: In Progress
// Date: 2020-07-02

// Displays the highest and lowest integers entered by a user. Program
// exits when user enters a 0.//
// Created by Scott Fitzgerald on 7/2/20.
#include <iostream>

using namespace std;

// Function prototypes
void displayMenu();

void displayResults(int numAccepted, int numRejected, double totalCost);

// Class declaration
class Package {
private:
    int side1 = 0;
    int side2 = 0;
    int side3 = 0;
    int weight = 0;
    int girth = 0;
public:
    // Setters
    void setWeight(int);
    static void setPackageDetails();
    bool determineValidity(Package);
    void setSides(Package, int s1, int s2, int s3);
    int setGirth(int s1, int s2, int s3);
    double setPrice();

    // Getters
    int getWeight();
    int getGirth();
    int getPrice();

    static bool validateSideLengths(int s1, int s2, int s3);
};

void Package::setWeight(int w) {
    weight = w;
}

int Package::setGirth(int s1, int s2, int s3) {
    int largest = s1;

    if (s2 > largest) {
        largest = s2;
    }
    if (s3 > largest) {
        largest = s3;
    }

    // Set girth to twice the two shortest sides
    girth = 2 * (s1 + s2 + s3 - largest);

    return 0;
}

int Package::getGirth() {
    return girth;
}

void Package::setPackageDetails() {
    // Declarations for box object and sides
    Package box;
    int weight;
    int s1;
    int s2;
    int s3;

    // Get weight and dimensions from user
    cout << "Enter package weight: ";
    cin >> weight;
    box.setWeight(weight);
    cout << "Box weight is " << box.weight << endl;
    cout << "Enter side 1: ";
    cin >> s1;
    cout << "Enter side 2: ";
    cin >> s2;
    cout << "Enter side 3: ";
    cin >> s3;

    // Set side lengths
    box.setSides(box, s1, s2, s3);
}

bool Package::determineValidity(Package box) {
    bool validSize;
    bool validWeight;

    validSize = validateSideLengths(box.side1, box.side2, box.side3);
    validWeight = box.weight <= 50;

    cout << "box side1 is " << box.side1 << endl;
    cout << "box side2 is " << box.side2 << endl;
    cout << "box side3 is " << box.side3 << endl;

    cout << "box size meets reqs : " << validSize << endl;
    cout << "box weight is " << box.getWeight() << endl;
    cout << "box weight meets reqs : " << validWeight << endl;

    return validSize && validWeight;
}

void Package::setSides(Package box, int s1, int s2, int s3) {
    side1 = s1;
    side2 = s2;
    side3 = s3;
}


double Package::setPrice() {
    return 0;
}

int Package::getWeight() {
    return weight;
}

int Package::getPrice() {
    return 0;
}

bool Package::validateSideLengths(int s1, int s2, int s3) {
    // Evaluates to true if no side lengths exceed 6 ft
    return s1 <= 6 && s2 <= 6 && s3 <= 6;
}

int main() {
    int transactionCounter = 0;
    int numAccepted = 0;
    int numRejected = 0;
    double totalCost = 0.0;

    // Display menu
    cout << "WELCOME TO ALLYBABA SHIPPING SERVICE\n\n";
    displayMenu();
    displayResults(numAccepted, numRejected, totalCost);

    return 0;
}

void displayMenu() {
    char location = 'A';
    bool meetsShippingRequirements;

    while (location != 'X') {
        cout << "************************************************************\n";
        cout << "***************             Menu             ***************\n";
        cout << "************************************************************\n";
        cout << "Enter Location - (T)exas; (O)ut of state, (F)oreign, e(X)it\n";
        cout << "Enter package weight and 3 dimensions.\n";
        cout << "Enter X to exit.\n\n";
        cout << "Enter Location - (T)exas; (O)ut of state, (F)oreign, e(X)it: ";

        cin >> location;
        location = toupper(location);

        if (location == 'X') {
            break;
        } else {
            Package box;
            box.setPackageDetails();
            meetsShippingRequirements = box.determineValidity(box);
            cout << "meetsShippingRequirements: " << meetsShippingRequirements << endl;
        }
    }
}

void displayResults(int numAccepted, int numRejected, double totalCost) {
    cout << "Number of accepted packages:   " << numAccepted << endl;
    cout << "Number of rejected packages:   " << numRejected << endl;
    cout << "Total cost of all packages:   $" << totalCost << endl;
}