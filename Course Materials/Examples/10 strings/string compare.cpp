/*
A string demonstration: assignment, concatenate, compare
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str1("Alpha");
  string str2("Beta");
  string str3("Omega");
  string str4;

  str4 = str1; 
  cout << str1 << endl << str2 << endl << str3 << endl;

  
  str4 = str1 + str2;            // concatenate two strings
  cout << "Concatenate two strings: " << str4 << endl;

  str4 = str1 + " to " + str3;
  cout << "Concatenate two strings: " << str4 << endl;

  
  if(str3 > str1)                // compare strings
     cout << "Compare two strings " << "str3 > str1\n";
  if(str3 == str1 + str2)
    cout << "Compare two strings " << "str3 == str1+str2\n";

  // create a string object using another string object
  string str5(str1);
  cout << "A string object using another string object: " << str5 << endl;

    system("PAUSE");
    return 0;

  return 0;
}

