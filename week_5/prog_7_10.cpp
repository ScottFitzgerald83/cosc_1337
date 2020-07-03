//
// Created by Scott Fitzgerald on 7/2/20.
// This program uses a constant reference parameter
// it also how to return an object from a function
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

    int getPartNum() const {
        return partNum;
    }

    string getDescription() const {
        return description;
    }

    int getOnHand() const {
        return onHand;
    }

    double getPrice() const {
        return price;
    }
};

// Implementation code for INventoryItem class func storeInfo
void InventoryItem::storeInfo(int p, string d, int oH, double cost) {
    partNum = p;
    description = d;
    onHand = oH;
    price = cost;
}

// Func prototype for client program
InventoryItem createItem();
void showValues (const InventoryItem&);

// Main function
int main() {

}





















