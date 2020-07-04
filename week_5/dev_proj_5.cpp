// Scott Fitzgerald
// Project #5
// Status: In Progress
// Date: 2020-07-02

// Program for caclulating shipping costs based on destination
// and parcel dimensions. Uses a Parcel class and members to confirm
// valid input and calculate costs.

#include <iostream>
#include <string>

using namespace std;

// Global constants
int OUT_OF_STATE_CHARGE = 35;               // Out of state service charge
int OUT_OF_COUNTRY_CHARGE = 40;            // Out of country service charge

// Function prototypes
void initialMenu();
char transactionMenu();
string getDestFromChar(char location);
string getStatusFromBool(bool);
void confirmTransaction(int& numAccepted, int& numRejected, int& transNumber, char location, bool accepted, int weight, int cost);
bool isValidSelection(char shippingLocation);
void processTransaction(int& numAccepted, int& numRejected, int& transNumber, char shippingLocation);
void displaySummary(int& transNumber, int numAccepted, int numRejected);

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
    int getWeight();                // Get the parcel's weight
    int getSvcCharge();             // Get any service charge

    // Other functions
    bool validateWeightAndSize();   // Check weight and size inputs

    // Class variables
    bool isValid;                   // Whether the dimensions/sides/weight are valid
    bool accepted;                  // Whether the parcel was accepted

};

void Parcel::setWeight() {
    // Setter for assigning a weight to the object
    // Checks that the input weight is a positive number

    cout << "Enter the parcel's weight: ";
    cin >> weight;
    if (weight < 0) {
        cout << "Weight must be a positive number. Skipping transaction.\n";
        isValid = false;
    }
}

int Parcel::getWeight() {
    // Getter for fetching the object's weight
    return weight;
}

void Parcel::setDimensions() {
    // Setter for assigning length/width/height to the object
    // Uses the dimensions[] array rather than three separate members
    // Checks that all sides are positive numbers

    cout << "Enter the length of side 1: ";
    cin >> dimensions[0];
    cout << "Enter the length of side 2: ";
    cin >> dimensions[1];
    cout << "Enter the length of side 3: ";
    cin >> dimensions[2];
    if (*min_element(dimensions, dimensions + 3) < 0) {
        cout << "All sides must be positive numbers. Skipping transaction\n";
        isValid = false;
    }
}

bool Parcel::validateWeightAndSize() {
    // Used to check that the weight and sides are positive
    // If package meets requirements, set isValid and isAccepted
    // bools to true

    // Largest size is the max array element from box dimensions
    int shortestSide = *min_element(dimensions, dimensions + 3);
    int largestSide = *max_element(dimensions, dimensions + 3);
    // Check if box meets weight, size, and girth requirements
    isValid = weight <= 50 && shortestSide > 0 && largestSide <= 6 && girth <= 10;
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
    if (girth > 10) {
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

int Parcel::getSvcCharge() {
    // Getter to return the service charge
    return serviceCharge;
}

int main() {
    // Main function; prints the welcome menu and iterates over a loop
    // of transactions until 'X' is received for shipping location
    char shippingLocation;
    bool validDest;
    int transNumber = 1;
    int numAccepted = 0;
    int numRejected = 0;

    initialMenu();                                       // Display the initial menu
    while (true) {
        shippingLocation = transactionMenu();            // Display the transaction menu
        if (shippingLocation == 'X') {                   // If 'X' is received, break loop
            break;
        }
        validDest = isValidSelection(shippingLocation);  // Validate menu selection

        if (validDest) {
            processTransaction(numAccepted, numRejected, transNumber, shippingLocation);
        } else {
            cout << "Invalid destination, skipping." << endl;
        }
    }

    displaySummary(transNumber, numAccepted, numRejected);

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

void processTransaction(int &numAccepted, int &numRejected, int &transNumber, char shippingLocation) {
    // Takes a valid shipping location, creates an instance of the
    // Parcel class, sets its attributes, and confirms the transaction
    Parcel box;
    int cost;

    box.setSvcCharge(shippingLocation);              // Add location-base service charges
    box.setWeight();                                 // Set the box's weight
    box.setDimensions();                             // Set the box's dimensions
    box.setGirth();                                  // Set the box's girth
    box.validateWeightAndSize();                     // Determine if dimensions/girth are valid
    cost = box.getSvcCharge();                       // TODO: Point to getCost() after implementing function
    confirmTransaction(numAccepted, numRejected, transNumber, shippingLocation, box.accepted, box.getWeight(), cost);
}

string getDestFromChar(char location) {
    // Takes a char and returns a string representing
    // the parcel's destination

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
    // Takes a bool and returns a string representing
    // whether or not the parcel was accepted

    if (accepted) {
        return "Accepted";
    }
    return "Rejected";
}

void confirmTransaction(int &numAccepted, int &numRejected, int &transNumber, char location, bool accepted, int weight, int cost) {
    // Takes a valid transaction and prints the details
    // of that transaction to the screen

    string destination;
    string acceptanceStatus;

    destination = getDestFromChar(location);
    acceptanceStatus = getStatusFromBool(accepted);

    cout << "\nTransaction # " << transNumber << endl;
    cout << "Destination:    " << destination << endl;
    cout << "Accepted:       " << acceptanceStatus << endl;
    cout << "Weight:         " << weight << endl;
    cout << "Shipping cost: $" << cost << endl;                     // TODO: Print N/A if rejected

    if (accepted) {
        numAccepted += 1;
    } else {
        numRejected += 1;
    }

    transNumber += 1;
}

void displaySummary(int &transNumber, int numAccepted, int numRejected) {
    cout << "Number of accepted packages:" << numAccepted;
    cout << "Number of rejected packages" << numRejected;
    cout << "Total Cost $XXX.XX" << endl;
}
