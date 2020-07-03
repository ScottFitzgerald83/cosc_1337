//
// Created by Scott Fitzgerald on 7/2/20.
// Demonstrates the use of overloaded constructors
#include <iostream>
#include <iomanip>
using namespace std;

// Sale class declaration
class Sale{
private:
    double taxRate;
public:
    Sale(double rate)
    {
        taxRate = rate;
    }

    Sale()
    {
        taxRate = 0.0;
    }

    double calcSaleTotal(double cost)
    {
        double total = cost + cost * taxRate;
        return total;
    }
};

int main()
{
    double salePrice = 24.95;
    Sale cashier1(.06);         // Define a Sale obj w/ 6% sales tax
    Sale cashier2;                 // Define a tax-exempt Sale obj

    // Format the output
    cout << fixed << showpoint << setprecision(2);

    // Get and display total sale price for two $24.95 sales
    cout << "With a 0.06 sales tax rate, the total\n";
    cout << "of the $" << salePrice << " sale is $";
    cout << cashier1.calcSaleTotal(salePrice) << endl;

    cout << "\nOn a tax-exempt purchase, the total\n";
    cout << "of the $" << salePrice << " sale, of course, $";
    cout << cashier2.calcSaleTotal(salePrice) << endl;

    return 0;
}