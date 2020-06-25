// fixed and set precision

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
float x = 12.34;
cout << fixed;
cout << "SetPrecision(2) for double 12.34 || " << setprecision(2) << x << endl;
cout << "SetPrecision(4) for double 12.34 || " << setprecision(4) << x << endl;
x = 123.45;
cout << "SetPrecision(4) for double 123.45 || " << setprecision(4) << x << endl;
cout << "SetPrecision(5) for double 123.45 || " << setprecision(5) << x << endl;
x = 12.3;
cout << "SetPrecision(5) for double 12.3 || " << setprecision(5) << x << endl;
cout << "SetPrecision(4) for double 12.3 || " << setprecision(4) << x << endl;

system("PAUSE");
return 0;
}
