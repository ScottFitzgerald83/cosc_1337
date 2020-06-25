// pass by reference and value
#include <iostream>				// for cin, cout, endl
using namespace std;

int getValues(int & );
float getAverage(int , int );
void outAverage(float );

int main()						// start of main function
{ 
    int numbers;
    int count = 0;
    int sum = 0;
    float average = 0.0;
    
    getValues(numbers);
    
    while (numbers != -999)
    {     
          count++;
          sum = sum + numbers;
          getValues(numbers);
    }
    
    if (count > 0)
    {
       average = getAverage(sum, count);
       outAverage(average);
    }
    else
       cout << "No data entered " << endl;
  
    system ("pause");           // Freeze the DOS screen
	return 0;		            // indicate that the program ended successfully

}                               // end of main function

int getValues(int & nums)
{
    cout << "Enter values! -999 will terminate. ";
    cin >> nums;
}

float getAverage(int sums, int counts)
{
      return float(sums)/float(counts);
}

void outAverage(float avg)
{
     cout << "The average is : " << avg << endl;
 }
 
