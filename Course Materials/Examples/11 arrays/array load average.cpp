#include <iostream>		
using namespace std;

void getValues(int &,int[]);
void calc(int &, int[], int);
void display(int , int, int[]);

int main()						
{ 
	int arrayValue[100];
	int count = 0;
	int sum = 0;
	
	
	getValues(count,arrayValue);
	calc(sum, arrayValue, count);
	display(sum, count,arrayValue);
	
    return 0;
}       

void display(int sum, int count, int arrayValue[])
{
	int average = 0;
	average = sum/count;
	cout << "The average of grades is " << average << endl;

}


void getValues(int &count,int arrayValue[])
{
	int value; 

	
	cout << "Please enter your grade; less than 0 will terminate ";
	cin >> value;
	
	while (value >= 0 && count <= 100)
	{
		arrayValue[count] = value;
		count+=1;
		cout << "Please enter your grade; less than 0 will terminate ";
		cin >> value; 		
	}

}

void calc(int &sum, int arrayValue[], int count)
{
	for(int i=0;i<count;i++)
	{
		sum = sum+arrayValue[i];
		//cout << arrayValue[i] << endl;
		
	}	
}
