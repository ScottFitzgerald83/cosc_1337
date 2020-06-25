// more on class

#include <iostream>
using namespace std;
 
/*
A protected member variable or function is very similar to a private member 
but it provided one additional benefit that they can be accessed in child classes 
which are called derived classes.

You will learn derived classes and inheritance in next chapter. 
For now you can check following example where I have derived one child class SmallBox from a parent class Box.

Following example is similar to above example and 
here width member will be accessible by any member function of its derived class SmallBox.
*/

class Box
{
   protected:
      double width;
};
 
class SmallBox:Box // SmallBox is the derived class.
{
   public:
      void setSmallWidth( double wid );
      double getSmallWidth( void );
};
 
// Member functions of child class
double SmallBox::getSmallWidth(void)
{
    return width ;
}
 
void SmallBox::setSmallWidth( double wid )
{
    width = wid;
}
 
// Main function for the program
int main( )
{
   SmallBox box;
 
   // set box width using member function
   box.setSmallWidth(5.0);
   cout << "Width of box : "<< box.getSmallWidth() << endl;
 
   system("PAUSE");
   return 0;
}
