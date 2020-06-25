// recursion

#include <iostream>
using namespace std;

int factorial(int);

int main() {
    int number;
    cout<<"Enter a number to find factorial: ";
    cin>>number;
    cout<<"Factorial of " << number <<" = "<< factorial(number);
    return 0;
}

int factorial(int num) {
    if (num  > 1) {
        return num * factorial(num - 1);
    }
    else {
        return 1;
    }
}
