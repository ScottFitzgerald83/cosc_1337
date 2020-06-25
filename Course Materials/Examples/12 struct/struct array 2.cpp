// array of structures
#include <iostream>
#include <string>
using namespace std;

struct Movies {
  string title;
  int year;
} ;

void printMovie (Movies movie);
void getData(Movies []);

int main ()
{
  Movies films [3];
  
  getData(films);

  cout << "\nYou have entered these movies:\n";
  for (int n = 0; n < 3; n++)
    printMovie (films[n]);
    
    return 0;
}

void getData(Movies films[])
{
	for (int n = 0; n < 3; n++)
  	{
    	cout << "Enter title: ";
    	getline (cin, films[n].title);
    
    	cout << "Enter year: ";
    	cin >> films[n].year;
    
    	cin.ignore();
  }
  
}

void printMovie (Movies movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}
