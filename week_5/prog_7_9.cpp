//
// Created by Scott Fitzgerald on 7/2/20.
// Demostrates passing an object to a function. Passes to one function
// by reference and to another by value
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class InventoryItem {
private:
    int partNum;
    string description;
    int onHand;
    double price;

public:
    void storeInfo(int p, string d, int oH, double cost);

    int getPartNum() {
        return partNum;
    }

    string getDescription() {
        return description;
    }

    int getOnHand() {
        return onHand;
    }

    double getPrice() {
        return price;
    }
};

// Implementation code for Inventory Item class func storeInfo
void InventoryItem::storeInfo(int p, string d, int oH, double cost) {
    partNum = p;
    description = d;
    onHand = oH;
    price = cost;
}

// Function protos for client program
void storeValues(InventoryItem&);               // Receives an object by reference
void showValues(InventoryItem);                 // Receives an object by value

// **** main ****
int main() {
    InventoryItem part;

    storeValues(part);
    showValues(part);
    return 0;
}
/************************************************************************
 *                              storeValues
 *  This function stores user input data in the members of an
 *  InventoryItem object passed to it by reference
 ************************************************************************/
void storeValues(InventoryItem &item) {
    int partNum;
    string description;
    int qty;
    double price;

    // Get data from the user
    cout << "Enter data for the new part number \n";
    cout << "Part number: ";
    cin >> partNum;
    cout << "Description: ";
    cin.get();

    getline(cin, description);
    cout << "Quantity on hand: ";
    cin >> qty;
    cout << "Unit price: ";
    cin >> price;

    // Store the data in the InventoryItem object
    item.storeInfo(partNum, description, qty, price);
}

/********************************************************************
 *                          showValues
 * This function displays the member data stored in the
 * InventoryItem object passed to it by value
 *********************************************************************/
void showValues(InventoryItem item) {
    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "Part Number:   " << item.getPartNum() << endl;
    cout << "Description:   " << item.getDescription() << endl;
    cout << "Units on Hand: " << item.getOnHand() << endl;
    cout << "Price:        $" << item.getPrice() << endl;
}