
/*
A pointer to a C++ class is done exactly the same way as a pointer to a structure 
and to access members of a pointer to a class you use the member access operator -> operator, 
just as you do with pointers to structures. Also as with all pointers, you must initialize the pointer before using it.
*/

#include <iostream>
using namespace std;

class Box
{
   public:
      // Constructor definition
      Box(double l, double b, double h)
      {
         cout <<"Constructor called." << endl;
         length = l;
         width = b;
         height = h;
      }
      double Volume()
      {
         return length * width * height;
      }
   private:
      double length;     // Length of a box
      double width;    // Breadth of a box
      double height;     // Height of a box
};

int main(void)
{
   Box Box1(3.0, 1.0, 2.0);    // Declare box1
   Box Box2(8.0, 6.0, 2.0);    // Declare box2
   Box *ptrBox;                // Declare pointer to a class.

   // Save the address of first object
   ptrBox = &Box1;

   // Now try to access a member using member access operator
   cout << "Volume of Box1: " << ptrBox->Volume() << endl;

   // Save the address of first object
   ptrBox = &Box2;

   // Now try to access a member using member access operator
   cout << "Volume of Box2: " << ptrBox->Volume() << endl;
  
   system("PAUSE");
   return 0;
}
