#include <iostream>
using namespace std;

int main ()
{
   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

   cout << "Greeting message: ";
   cout << greeting << endl;
   
   char name[30] = "MY World";
   cout << name << endl;
   
   name[5] = '\0';
   cout << name << endl;
     
   system("PAUSE");
   return 0;
}
