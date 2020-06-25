
//Passing by reference means that you don't pass the value of an object, 
// you are passing the object itself. There are no copies made, 
//only the original object is what is worked with.

#include <iostream>
using namespace std;
 
int test(int &val1)
{
    val1 = val1 + val1;
     
    return(val1);
}
 
int main()
{
    int val = 5;
 
    cout << test(val); 
    cout << "\n" << val; // Should equal 10
 
    system("PAUSE");
    return(0);
}
