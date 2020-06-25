/*
Demonstrate insert(), erase(), and replace().
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
  int i;
  string s1 = "Quick of Mind, Strong of Body, Pure of Heart";
  string s2;

  i = s1.find("Quick");
  if(i != string::npos) {
    cout << "Match found at " << i << endl;
    cout << "Remaining string is: ";
    s2.assign(s1, i, s1.size());
    cout << s2;
  }
  cout << endl << endl;

  i = s1.find("Strong");
  if(i != string::npos) {
    cout << "Match found at " << i << endl;
    cout << "Remaining string is: ";
    s2.assign(s1, i, s1.size());
    cout << s2;
  }
  cout << endl << endl;

  i = s1.find("Pure");
  if(i!=string::npos) {
    cout << "Match found at " << i << endl;
    cout << "Remaining string is: ";
    s2.assign(s1, i, s1.size());
    cout << s2;
  }
  cout << endl << endl;

  // find list "of"
  i = s1.rfind("of");
  if(i!=string::npos) {
    cout << "Match found at " << i << endl;
    cout << "Remaining string is: ";
    s2.assign(s1, i, s1.size());
    cout << s2;
  }



    system("PAUSE");
    return 0;

  return 0;
}

