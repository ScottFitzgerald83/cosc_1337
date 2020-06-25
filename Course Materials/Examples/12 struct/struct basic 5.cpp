#include <iostream>
#include <cstring>
using namespace std;
 
// First we need to define our Advertising struct
struct Advertising
{
    int adsShown;
    double clickThroughRatePercentage;
    double averageEarningsPerClick;
};
 
void printAdvertising(Advertising );

int main()
{
    // Declare an Advertising struct variable
    Advertising ad;
 
    cout << "How many ads were shown today? ";
    cin >> ad.adsShown;
    cout << "What percentage of users clicked on the ads? ";
    cin >> ad.clickThroughRatePercentage;
    cout << "What was the average earnings per click? ";
    cin >> ad.averageEarningsPerClick;
 
    printAdvertising(ad);
    
    return 0;
}


void printAdvertising(Advertising ad)
{
    cout << "Number of ads shown: " << ad.adsShown << endl;
    cout << "Click through rate: " << ad.clickThroughRatePercentage << endl;
    cout << "Average earnings per click: $" << ad.averageEarningsPerClick << endl;
 
    // The following line is split up to reduce the length
    // We need to divide ad.clickThroughRatePercentage by 100 because it's a percent of 100, not a multiplier
    cout << "Total Earnings: $" <<
        (ad.adsShown * ad.clickThroughRatePercentage / 100 * ad.averageEarningsPerClick) << endl;
}
 
