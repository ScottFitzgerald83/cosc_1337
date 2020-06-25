//C++ streams

#include <iostream>              //includes iostream header
#include <fstream>               //includes filestream header
using namespace std;


int main() {
    
    {                                
		string sentence;                   //local string variable
		
		cout << "Enter a sentence ";
        cin >> sentence;                   //read string from - standard input
 
        cout << "The sentence is " << sentence << endl;                  //write string to standard output
        
        cout << "Reading and writing to a file " << endl;
 
        ifstream input("in.txt");   //creating input stream named input stream filename=in.txt
        ofstream output("out.txt"); //creating output stream named output stream filename=out.txt
 
        input >> sentence;                      //reads a string from input stream
        output << "The sentence is " << sentence;  //writes string to output stream
        
        input.close();
        output.close();
    }
    return 0;
}
