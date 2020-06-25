// array and pointers
#include <iostream>
using namespace std;

//display address of elements of an array using both array and pointers
int main() 
{
    float a[5];
    float *ptr;
    
    cout << "Displaying address using arrays: "<<endl;
    for (int i = 0; i < 5; ++i) {
        cout << "&a[" << i << "] = " << &a[i] <<endl;
    }

   
    

    system("PAUSE");
    return 0;
}
