// class basic

#include <iostream>
using namespace std;

/*
A class definition starts with the keyword class followed 
by the class name; 
and the class body, enclosed by a pair of curly braces. 
A class definition must be followed either by a semicolon 
or a list of declarations;

The keyword public determines the access attributes 
of the members of the class that follow it. 
A public member can be accessed from outside the class 
anywhere within the scope of the class object.
*/

class Box
{
   public:
      double length;   // Length of a box
      double width;  // width of a box
      double height;   // Height of a box
};

int main( )
{
   Box Box1;        // Declare Box1 of type Box
   Box Box2;        // Declare Box2 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.height = 15.0; 
   Box1.length = 16.0; 
   Box1.width = 17.0;

   // box 2 specification
   Box2.height = 1.0;
   Box2.length = 2.0;
   Box2.width = 3.0;
   
   // volume of box 1
   volume = Box1.height * Box1.length * Box1.width;
   cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.height * Box2.length * Box2.width;
   cout << "Volume of Box2 : " << volume <<endl;
   
   //system("PAUSE");
   return 0;
}
