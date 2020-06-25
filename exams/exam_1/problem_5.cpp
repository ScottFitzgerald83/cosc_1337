#include <iostream>
using namespace std;

void calc(float num, float& result);

int main()
{
	float num;
	float result;
	
	cout << "Enter a floating point number: ";
	cin >> num;
	
	calc(num, result);

}

void calc(float num, float &result)
{
	result = 25.0 * num + 37.0; 
	cout << result << endl;
}