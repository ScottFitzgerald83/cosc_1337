#include <iostream>
#include <string>
using namespace std;

// Global constants
int OUT_OF_STATE_CHARGE = 35;
int OUT_OF_COUNTRY_CHARGE =  40;

// Function prototypes
void initialMenu();
char transactionMenu();
string getDestFromChar(char location);
string getStatusFromBool(bool);
void confirmTransaction(char location, bool accepted, int weight, int cost);
bool isValidSelection(char shippingLocation);
void processTransaction(char shippingLocation);

class Parcel {
    // TODO: Add docstring
	private:
		int weight = 0;
		int dimensions[3] = {0, 0, 0};
		int girth = 0;
		int serviceCharge = 0;
	public:
        // Setters
		void setWeight();
		void setDimensions();
		void setGirth();
		void setSvcCharge(char);
        // Getters
		int getWeight();
		int getSvcCharge();

		// Other functions
		bool validateWeightAndSize();
		// Class variables
		bool isValid;
		bool accepted;

};

void Parcel::setWeight() {
    // TODO: Add docstring
    cout << "Enter the parcel's weight: ";
    cin >> weight;
    if (weight < 0) {
        cout << "Weight must be a positive number. Skipping transaction.\n";
        isValid = false;
    }
}

int Parcel::getWeight() {
    // TODO: Add docstring
	return weight;
}

void Parcel::setDimensions() {
    // TODO: Add docstring
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
    // TODO: Add docstring
    // Largest size is the max array element from box dimensions
    int shortestSide = *min_element(dimensions, dimensions + 3);
    int largestSide = *max_element(dimensions, dimensions + 3);
    // Check if box meets weight, size, and girth requirements
    isValid = weight <= 50 && shortestSide > 0 && largestSide <= 6 && girth <= 10;
    if (isValid) {
        accepted = true;
    }
    return isValid;
}

void Parcel::setGirth() {
    // TODO: Add docstring
    int longestSide = *max_element(dimensions , dimensions + 3);
    girth = 2 * (dimensions[0] + dimensions[1] + dimensions[2] - longestSide);
    if (girth > 10) {
        cout << "Girth must not exceed 10 feet; package will be rejected." << endl;
        cout << "Girth is calculated by adding the two shortest sides and "
                "multiplying by 2." << endl;
    }
}

void Parcel::setSvcCharge(char location) {
    // TODO: Add docstring
    if      (location == 'O') {serviceCharge = OUT_OF_STATE_CHARGE;
    }
    if (location == 'F') {
        serviceCharge = OUT_OF_COUNTRY_CHARGE;
    }
}

int Parcel::getSvcCharge() {
    // TODO: Add docstring
    return serviceCharge;
}

int main() {
    // TODO: Add docstring
	char shippingLocation;
	bool validDest;

	initialMenu();                                   // Display the initial menu
	shippingLocation = transactionMenu();            // Display the transaction menu
    validDest = isValidSelection(shippingLocation);  // Validate menu selection
    if (validDest) {
        processTransaction(shippingLocation);
    }
    else {
        cout << "Invalid destination, skipping." << endl;
    }

	return 0;
}

void initialMenu() {
    // TODO: Add docstring
    cout << "WELCOME TO ALLYBABA SHIPPING SERVICE" << endl;
    cout << "This program calculates a parcel's shipping cost" << endl;
}

char transactionMenu() {
    // TODO: Add docstring
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
    // TODO: Add docstring
    return (shippingLocation == 'T' ||
            shippingLocation == 'O' ||
            shippingLocation == 'F' ||
            shippingLocation == 'X');
}
void processTransaction(char shippingLocation) {
    Parcel box;
    int cost;

    box.setSvcCharge(shippingLocation);              // Add location-base service charges
    box.setWeight();                                 // Set the box's weight
    box.setDimensions();                             // Set the box's dimensions
    box.setGirth();                                  // Set the box's girth
    box.validateWeightAndSize();                     // Determine if dimensions/girth are valid
    // TODO: Point to getCost() after implementing function
    cost = box.getSvcCharge();
    confirmTransaction(shippingLocation, box.accepted, box.getWeight(), cost);
}

string getDestFromChar(char location) {
    // TODO: Add docstring

    if (location == 'T') {
        return "Texas";
    }
    else if (location == 'O') {
        return "Out of state";
    }
    else if (location == 'F') {
        return "Out of country";
    }
    else {
        return "Unknown";
    }
}

string getStatusFromBool(bool accepted) {
    // TODO: Add docstring
    if (accepted) {
        return "Accepted";
    }
    return "Rejected";
}

void confirmTransaction(char location, bool accepted, int weight, int cost) {
    // TODO: Add docstring
    string destination;
    int transactionNumber = 1;
    string acceptanceStatus;

    destination = getDestFromChar(location);
    acceptanceStatus = getStatusFromBool(accepted);

    cout << "\nTransaction #" << transactionNumber << endl;
    cout << "Destination:    " << destination << endl;
    cout << "Accepted:       " << acceptanceStatus << endl;
    cout << "Weight:         " << weight << endl;
    cout << "Shipping cost: $" << cost << endl;

    transactionNumber += 1;
}

