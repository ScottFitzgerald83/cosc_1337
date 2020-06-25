#include <iostream>
using namespace std;

int main ()
{
   int vals[] = {4, 7, 11};

   //An array name is the starting address of the array
   //cout << "The memory address is " << &vals << endl;	   // displays the memory address
   //cout << "The value of 1st location is " << vals[0] << endl;    // displays 4

   //An array name can be used as a pointer constant
	//cout << "The value of 1st location is " << *vals << endl;    // displays 4
	
	//A pointer can be used as an array name
 	int *valptr = vals;
 	cout << "The value of 1st location  is " << *valptr << endl;  
 	cout << "The address of 1st location  is " << valptr << endl; 
	  
	cout << "The value of 2nd location is " << valptr[1] << endl;   
      
      cout << "The address of 2nd location  is " << valptr + 1 << endl; 
      
      	cout << "The value of 3rd location is " << valptr[2] << endl;   
      
      cout << "The address of 23rdnd location  is " << valptr + 2 << endl; 
    
    //It means (address in valptr) + (1 * size of an int)
    cout <<  "The value of 2nd location is " << valptr+1 << endl; 
    cout <<  "The value of 3rd location is " << *(valptr+2) << endl; // displays 11
    
    //Array access method
    //array name and [ ]
     vals[2] = 17;
     cout <<  "The value of 3rd location is " << vals[2] << endl; // displays 17

     //pointer to array and [ ]
     valptr[2] = 171;
     cout <<  "The value of 3rd location is " << valptr[2] << endl; // displays 171

     //array name and subscript arithmetic
     //*(vals+2) = 172;
     cout <<  "The value of 3rd location is " << *(vals+2) << endl; // displays 172
     
     //pointer to array and subscript arithmetic
     //*(valptr+2) = 179;
     cout <<  "The value of 3rd location is " << *(valptr+2) << endl; // displays 179
       

    system("PAUSE");
    return 0;
}
