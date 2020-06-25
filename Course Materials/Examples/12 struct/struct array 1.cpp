// array of structures
#include <iostream>
#include <string>
using namespace std;

struct Movies {
  string title;
  int year;
} ;

void printMovie (Movies );

int main ()
{
  Movies films [3];
  int count;

  for (count = 0; count < 3; count++)
  {
    cout << "Enter title: ";
    getline (cin, films[count].title);
    
    cout << "Enter year: ";
    cin >> films[count].year;
    
    cin.ignore();
  }

  cout << "\nYou have entered these movies:\n";
   for (count = 0; count < 3; count++)
   {	
    printMovie (films[count]);  
   }
  
    return 0;
}

void printMovie (Movies movie)
{
 string spacer(10, ' ');
  cout << spacer << movie.title;
  cout << " (" << movie.year << ")\n";
}
