// class and object basic

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
 
class Programming {
public:
  void output();  //function declaration
};
 
// function definition outside the class scope resolution operator (::)
 
void Programming::output() {
  cout << "Function defined outside the class.\n";
}
 
int main() {
  Programming myObject;
  myObject.output();
 
  system("PAUSE");
  return 0;
}
