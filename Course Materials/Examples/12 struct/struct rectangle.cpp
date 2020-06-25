/// example about structures
#include <iostream>
using namespace std;

struct Rectangle {
	int length;
	int width;
	int area;
};
void input(Rectangle []);
void calc(Rectangle []);
void findArea(Rectangle []);
void print(Rectangle);

int main ()
{
  Rectangle myRectangle[2];

  
  input(myRectangle);
  calc(myRectangle);
  findArea(myRectangle);
  

  system("PAUSE");
  return 0;
}

void input(Rectangle myRectangle[])
{
	for(int i=0; i < 2; i++)
  {
  	cout << "Enter Length ";
  	cin >> myRectangle[i].length;
  	
  	cout << "Enter Width ";
  	cin >> myRectangle[i].width;
  }
}

void calc(Rectangle myRectangle[])
{
	for(int i=0; i < 2; i++)
  	{
  		myRectangle[i].area = myRectangle[i].length * myRectangle[i].width;
  	}
}

void findArea(Rectangle myRectangle[])
{
	int max;
  	int location = 0;
	max = myRectangle[0].area;
  
    for(int i=0; i < 2; i++)
  	{
  		if (myRectangle[i].area > max)
  	  	{
  	  		location = i;
  	  		max = myRectangle[i].area;
		}
  		
  	}		
  	print(myRectangle[location]);
  	
  	
}
void print(Rectangle anotherRectangle)
{
	cout << "The max length is " << anotherRectangle.length << endl;
  	cout << "The max width is " << anotherRectangle.width << endl; 
}
