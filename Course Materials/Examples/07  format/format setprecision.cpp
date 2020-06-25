// set precision
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double value = 8000.0/81.0;
	cout << "the answer with 2 precision " << setprecision(2) << value << endl;
	cout << "the answer with 4 precision " << setprecision(4) << value << endl;
	
	return 0;
}
  
