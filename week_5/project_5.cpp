// Scott Fitzgerald
// Project #5
// Status: Completed
// Date: 2020-07-02

// Program for calculating and display shipping costs based on destination
// and parcel dimensions. Uses a Parcel class and members to confirm packages
// meet size/weight requirements.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Global constants
const int MAX_WEIGHT = 50;                        // Maximum allowed weight
const int MIN_SIDE_LENGTH_INCHES = 0;             // Used to validate side lengths
const int MAX_SIDE_LENGTH_INCHES = 72;            // Max allowed side length
const int MAX_GIRTH_INCHES = 120;                 // Max allowed girth
const int OUT_OF_STATE_CHARGE = 35;               // Out of state service charge
const int OUT_OF_COUNTRY_CHARGE = 40;             // Out of country service charge

// Function prototypes
void initialMenu();
char transactionMenu();
bool isValidSelection(char);
void processTransaction(int&, int&, int&, char, double&);
double calcCost(int);
string getDestFromChar(char);
string getStatusFromBool(bool);
void confirmTransaction(int&, int&, int&, char, bool, int, double);
void displaySummary(int&, int, int, double&);

class Parcel {
    // Parcel class used to instantiate objects
    // Contains private/public members for setting and getting parcel
    // attributes and checking inputs for validity
private:
    int weight = 0;                 // The weight of the Parcel
    int dimensions[3] = {0, 0, 0};  // Array containing side lengths
    int girth = 0;                  // The girth of the Parcel
    int serviceCharge = 0;          // Out of state/country service charges
public:
    // Setters
    void setWeight();               // Set the object's weight
    void setDimensions();           // Populate the dimensions array
    void setGirth();                // Set the girth
    void setSvcCharge(char);        // Set relevant service charges

    // Getters
    int getWeight() const;          // Get the parcel's weight
    int getSvcCharge() const;       // Get any service charge

    // Other functions
    bool validateWeightAndSize();   // Check weight and size inputs

    // Class variables
    bool isValid;                 // Whether the dimensions/sides/weight are valid
    bool accepted;                // Whether the parcel was accepted

};

void Parcel::setWeight() {
    // Setter for assigning a weight to the object
    // Checks that the input weight is a positive number

    cout << "Enter the parcel's weight (in pounds): ";
    cin >> weight;
    if (weight < 0) {
        cout << "Weight must be a positive number. Skipping transaction.\n";
        isValid = false;
    }
}

int Parcel::getWeight() const {
    // Getter for fetching the object's weight
    return weight;
}

void Parcel::setDimensions() {
    // Setter for assigning length/width/height to the object
    // Uses the dimensions[] array rather than three separate members
    // Checks that all sides are positive numbers

    for (int i = 0; i < 3; i++) {
        cout << "Enter the length of side " << i + 1 << " (in inches): ";
        cin >> dimensions[i];
    }

    if (*min_element(dimensions, dimensions + 3) < 0) {
        cout << "All sides must be positive numbers. Skipping transaction\n";
        isValid = false;
    }
}

bool Parcel::validateWeightAndSize() {
    // Used to check that the weight and sides are positive. If package
    // meets requirements, set isValid and isAccepted bools to true

    // Largest size is the max array element from box dimensions
    int shortestSide = *min_element(dimensions, dimensions + 3);
    int largestSide = *max_element(dimensions, dimensions + 3);

    // Check if box meets weight, size, and girth requirements
    isValid = (weight <= MAX_WEIGHT &&
               shortestSide > MIN_SIDE_LENGTH_INCHES &&
               largestSide <= MAX_SIDE_LENGTH_INCHES &&
               girth <= MAX_GIRTH_INCHES);

    // If valid dimensions, set isValid and accepted bools to true
    if (isValid) {
        accepted = true;
    } else {
        isValid = false;
        accepted = false;
    }
    return isValid;
}

void Parcel::setGirth() {
    // Assign the package's girth. Validates that girth
    // does not exceed 10 feet. If it does, prints an error

    int longestSide = *max_element(dimensions, dimensions + 3);
    girth = 2 * (dimensions[0] + dimensions[1] + dimensions[2] - longestSide);
    if (girth > MAX_GIRTH_INCHES) {
        cout << "ERROR! Girth must not exceed 10 feet; package will be rejected." << endl;
        cout << "Girth is calculated by adding the two shortest sides and "
                "multiplying by 2." << endl;
    }
}

void Parcel::setSvcCharge(char location) {
    // Sets a service charge based on location
    // See globals for the values of these charges

    // Set out of state or out of country charge as needed
    if (location == 'O') {
        serviceCharge = OUT_OF_STATE_CHARGE;
    }
    if (location == 'F') {
        serviceCharge = OUT_OF_COUNTRY_CHARGE;
    }
}

int Parcel::getSvcCharge() const {
    // Getter to return the service charge
    return serviceCharge;
}

int main() {
    // Main function; prints the welcome menu and iterates over a loop
    // of transactions until 'X' is received for shipping location

    char shippingLocation;                         // Char representing destination
    bool validDest;                                // Whether the input for destination is valid
    int transNumber = 1;                           // Counter for transaction display
    int numAccepted = 0;                           // Counter for num accepted parcels
    int numRejected = 0;                           // Counter for num rejected parcels
    double totalCost = 0;                          // Total cost for all transactions

    initialMenu();                                 // Display the initial menu
    while (true) {
        shippingLocation = transactionMenu();      // Display the transaction menu
        if (shippingLocation == 'X') {             // If 'X' is received, break loop
            break;
        }
        validDest = isValidSelection(shippingLocation);  // Validate menu selection

        if (validDest) {
            processTransaction(numAccepted, numRejected, transNumber, shippingLocation, totalCost);
        } else {
            cout << "Invalid destination, skipping." << endl;
        }
    }

    displaySummary(transNumber, numAccepted, numRejected, totalCost);

    return 0;
}

void initialMenu() {
    // Prints the initial menu for the user
    cout << "WELCOME TO ALLYBABA SHIPPING SERVICE" << endl;
    cout << "This program calculates a parcel's shipping cost" << endl;
}

char transactionMenu() {
    // Prints the transaction menu with instructions
    // returns an uppercase char representing the location
    char location;

    cout << "************************************************************\n";
    cout << "***************             Menu             ***************\n";
    cout << "************************************************************\n";
    cout << "Enter Location - (T)exas; (O)ut of state, (F)oreign, e(X)it\n";
    cout << "Enter package weight and 3 dimensions.\n";
    cout << "Enter X to exit.\n\n";
    cout << "Enter Location - (T)exas; (O)ut of state, (F)oreign, e(X)it: ";
    cin >> location;

    return toupper(location);
}

bool isValidSelection(char shippingLocation) {
    // Determine if the shipping location menu selection is valid
    // return statement evaluates to true if valid selection

    return (shippingLocation == 'T' ||
            shippingLocation == 'O' ||
            shippingLocation == 'F' ||
            shippingLocation == 'X');
}

void processTransaction(int &numAccepted, int &numRejected, int &transNumber,
                        char shippingLocation, double &totalCost) {
    // Takes a valid shipping location, creates an instance of the
    // Parcel class, sets its attributes, and confirms the transaction
    Parcel box;
    double shippingCost = 0;
    int shippingCharge = 0;
    double transCost = 0;

    box.setSvcCharge(shippingLocation);              // Add location-base service charges
    box.setWeight();                                 // Set the box's weight
    box.setDimensions();                             // Set the box's dimensions
    box.setGirth();                                  // Set the box's girth
    box.validateWeightAndSize();                     // Determine if dimensions/girth are valid
    shippingCost = calcCost(box.getWeight());        // Calculate shipping cost based on weight
    shippingCharge = box.getSvcCharge();             // Calculate shipping charges
    transCost = shippingCost + shippingCharge;       // Add charges to cost
    confirmTransaction(numAccepted, numRejected, transNumber, shippingLocation,
                        box.accepted, box.getWeight(), transCost);

    // Only increment totalCost if parcel is accepted
    if (box.accepted) {
        totalCost += transCost;
    }
}

double calcCost(int parcelWeight) {
    // Calculates a shipping cost for a given weight
    // Does so by searching through an array for a weight,
    // then finding the element in the charge array with the same index

    int weight[] = {1, 2, 3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50};
    double charge[] = {1.50, 2.10, 4.00, 6.75, 9.90, 14.95, 19.40, 24.20, 27.30,
                       31.90, 38.50, 43.50, 44.80, 47.40, 55.20};
    int count = 0;

    while (parcelWeight >= weight[count]) {
        if (parcelWeight == weight[count]) {
            break;
        }
        count += 1;
    }

    return charge[count];
}

string getDestFromChar(char location) {
    // Takes a char and returns a string representing the parcel's destination

    if (location == 'T') {
        return "Texas";
    } else if (location == 'O') {
        return "Out of state";
    } else if (location == 'F') {
        return "Out of country";
    } else {
        return "Unknown";
    }
}

string getStatusFromBool(bool accepted) {
    // Takes a bool and returns a string representing whether or not the parcel was accepted

    if (accepted) {
        return "Accepted";
    }
    return "Rejected";
}

void confirmTransaction(int &numAccepted, int &numRejected, int &transNumber,
                        char location, bool accepted, int weight, double cost) {
    // Takes a valid transaction and prints the details of that transaction to the screen

    // Declarations
    string destination;                                   // String representing destination
    string acceptanceStatus;                              // String representing acceptance/rejection
    string displayCost = to_string(cost);                 // String representing cost

    destination = getDestFromChar(location);              // Get string repr of location char
    acceptanceStatus = getStatusFromBool(accepted);       // Get string rep of status bool

    // Display results for each transaction
    // Set cost to N/A for rejected parcels
    cout << "\nTransaction # " << transNumber << endl;
    cout << "Destination:    " << destination << endl;
    cout << "Accepted:       " << acceptanceStatus << endl;
    cout << "Weight:         " << weight << endl;
    if (accepted) {
        cout << fixed << setprecision(2);
        cout << "Shipping cost:  $"  << cost << endl;
    } else {
        cout << "Shipping cost:  N/A" << endl;
    }

    // Increment number of accepted or rejected packages
    if (accepted) {
        numAccepted += 1;
    } else {
        numRejected += 1;
    }
    // Increment transaction number
    transNumber += 1;
}

void displaySummary(int &transNumber, int numAccepted, int numRejected, double &totalCost) {
    // Display stats on number of accepted/rejected package, along
    // with cost, to the user

    cout << "\nNumber of accepted packages: " << numAccepted;
    cout << "\nNumber of rejected packages: " << numRejected;
    cout << "\nTotal Cost:                  $" << totalCost << endl;
}
