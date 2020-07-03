//
// Created by Scott Fitzgerald on 7/2/20.
//
#include <iostream>
using namespace std;

class Tank {
private:
    int gallons;
public:
    Tank() {
        gallons = 50;
    }

    Tank(int gal) {
        gallons = gal;
    }

    int getGallons() {
        return gallons;
    }
};

int main() {
    Tank storage1, storage2, storage3(20);

    cout << storage1.getGallons() << endl;
    cout << storage2.getGallons() << endl;
    cout << storage3.getGallons() << endl;
    return 0;
}