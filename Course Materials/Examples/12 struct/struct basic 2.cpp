/// example about structures
#include <iostream>
#include <string>
using namespace std;

struct Movies {
  string title;
  int year;
};

void printMovie (Movies );

int main ()
{
  Movies myMovies;

  cout << "Enter title: ";
  getline (cin, myMovies.title);
  
  cout << "Enter year: ";
  cin >> myMovies.year;


  cout << "My favorite movie is: ";
  printMovie (myMovies);
  
  system("PAUSE");
  return 0;
}

void printMovie (Movies movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}
