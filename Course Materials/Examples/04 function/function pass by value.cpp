
/*
Passing by value means that 
you are taking a copy of what has been passed to the function, 
work with it in the function, but do not modify the original value.
*/

#include <iostream>
using namespace std;
 
int test(int val1)
{
    val1 = val1 + val1;
     
    return(val1);
}
 
int main()
{
    int val = 5;
 
    cout << test(val) << endl; 
    cout << val << endl;      // Should equal 5
 
    system("PAUSE");
    return(0);
}
