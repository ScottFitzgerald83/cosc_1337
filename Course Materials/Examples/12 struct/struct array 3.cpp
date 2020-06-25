/// example array of  struct
 
#include <iostream>
#include <string>
#include <sstream>          //string stream class
using namespace std;

struct Student{
	string name;
};

struct Grade{
	int test1;
	int test2;
	int test3;
	int test4;
	int average;
	char letterGrade;
	Student sData;
};

void getData( Grade [] );
void getAverage ( Grade [] );

int main ()
{
  Grade myGrade[2];
  
  getData( myGrade );
  getAverage ( myGrade );
  

  system("PAUSE");
  return 0;
}

void getData( Grade myGrade[] )
{
	for ( int i = 0; i < 2; i ++ )
  {
  
	  cout << "Gimme your name: ";
	  cin >> myGrade[i].sData.name;
	  
	  cout << "Test 1: ";
	  cin >> myGrade[i].test1;
	  
	  cout << "Test 2: ";
	  cin >> myGrade[i].test2;
	  
	  cout << "Test 3: ";
	  cin >> myGrade[i].test3;
	  
	  cout << "Test 4: ";
	  cin >> myGrade[i].test4;
	  
	}
}

void getAverage ( Grade myGrade[] )
{

int total = 0;

for ( int h = 0; h < 2; h ++ )
	{
		total = myGrade[h].test1 + myGrade[h].test2 + myGrade[h].test3 + myGrade[h].test4;
		myGrade[h].average = total / 4;
		
		if ( myGrade[h].average >= 90 )
		{
			myGrade[h].letterGrade = 'A';
		 } 
		else if ( myGrade[h].average >= 80 )
		{
			myGrade[h].letterGrade = 'B';
		}
		else if ( myGrade[h].average >= 70 )
		{
			myGrade[h].letterGrade = 'C';
		
		 }
		else
		{
			myGrade[h].letterGrade = 'F';	
		}  
		cout << "Student -> " << myGrade[h].sData.name << " has grade -> " << myGrade[h].letterGrade << endl;
	} 
	 
}
