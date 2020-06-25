// fixed and set precision

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x = 8000.0/81.0;
	cout << "The fixed 4 decimal places " << setiosflags(ios::fixed) << setprecision(4) << x;
	return 0;
}
