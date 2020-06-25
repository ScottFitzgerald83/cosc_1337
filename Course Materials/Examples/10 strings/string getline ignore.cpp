 #include <string>
 #include <iostream>
using namespace std;

int main()
{
double num;
    string mystr;

    cout << "Please enter a number: " << "\n";
    cin >> num;
    cout << "Your number is: " << num << "\n";
    cin.ignore(256, '\n'); // Why do I need this line?
    cout << "Please enter your name: \n";
    getline (cin, mystr);
    cout << "So your name is " << mystr << "?\n";
    cout << "Have a nice day. \n";
    
    system("PAUSE");
    return 0;
}
