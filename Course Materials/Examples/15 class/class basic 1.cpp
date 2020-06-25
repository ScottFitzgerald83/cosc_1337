// class basic

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
 
class Programming 
{
public:
  void output() 
  {
  cout << "Function defined outside the class.\n";
  }
};
 

int main() {
  Programming myObject;
  myObject.output();
 
  system("PAUSE");
  return 0;
}
