// class and constructor

#include <iostream>
using namespace std;

class Simple
{
private:
    int m_nID;
 
public:
    Simple()
	{
        cout << "Constructing Simple " << endl;
    }
 
};
 
int main()
{
    // Allocate a Simple on the stack
   Simple cSimple;
    
   system("PAUSE");
   return 0;
}
// cSimple goes out of scope here
