/// example about structures
#include <iostream>
#include <string>
using namespace std;

struct Movies 
{
  string title;
  int year;
};

void printMovie (Movies );

int main ()
{
  Movies myMovies;

  myMovies.title = "2001 A AllyBaba Odyssey";
  myMovies.year = 1968;
  
  printMovie(myMovies);

  system("PAUSE");
  return 0;
}

void printMovie (Movies movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}
