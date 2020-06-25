// This will convert integer division to a float

#include <iostream>
using namespace std;

int main()
{
    int value1;
    int value2;
    float result;
    
    cout << "Enter Dividend (Integer) ";
    cin >> value1;
    cout << "Enter Divisor (Integer) ";
    cin >> value2;
    
    result = (float)value1 / (float)value2;
    
    cout << "The quotient in float " << result << endl;
    
    system("PAUSE");
    return 0;
}
