 #include <string>
 #include <iostream>
using namespace std;

int main()
{
   string firstname, lastname, fullname;

   cout << "First name: ";
   getline (cin, firstname);
   cout << "Last name: ";
   getline (cin, lastname);

   fullname = lastname + ", " + firstname;
   cout << "Fullname: " << fullname << endl;
    
    system("PAUSE");
    return 0;
}
