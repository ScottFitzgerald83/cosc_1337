// class more

#include <iostream>
using namespace std;
/*
A member function of a class is a function that has 
its definition or its prototype within the 
class definition like any other variable. It operates 
on any object of the class of 
which it is a member, and has access to all the members 
of a class for that object.

Member functions can be defined within the class definition 
or separately using 
scope resolution operator, ::. Defining a member function 
within the class definition 
declares the function inline, even if you do not use the 
inline specifier

If you like you can define same function outside the class 
using scope resolution operator

only important point is that you would have to use class name 
just before Scope Resolution Operator :: operator. 
A member function will be called using a dot operator (.) on a 
object where 
it will manipulate data related to that object only


*/

class Box
{
   public:
      double length;         // Length of a box
      double width;        // width of a box
      double height;         // Height of a box

      // Member functions declaration
      double getVolume(void);
      void setLength( double len );
      void setwidth( double bre );
      void setHeight( double hei );
};

// Member functions definitions
double Box::getVolume(void)
{
    return length * width * height;
}

void Box::setLength( double len )
{
    length = len;
}

void Box::setwidth( double bre )
{
    width = bre;
}

void Box::setHeight( double hei )
{
    height = hei;
}

// Main function for the program
int main( )
{
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.setLength(6.0); 
   Box1.setwidth(7.0); 
   Box1.setHeight(5.0);

   // box 2 specification
   Box2.setLength(12.0); 
   Box2.setwidth(13.0); 
   Box2.setHeight(10.0);

   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;
   
   system("PAUSE");
   return 0;
}
