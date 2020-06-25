#include<iostream>
using namespace std;

struct Employee
{
       char name[50];
       int age;
       char quali[70];
       int teleno;
       char info[80];
};

void display(Employee *emp3);
 
int main()
{
    Employee emp1;
    
    cout << "Enter the name of the employee " ;
    cin >> emp1.name;
    cout << "Enter the age of the employee " ;
    cin >> emp1.age;
    cout << "Enter the qualification of the employee " ;
    cin >> emp1.quali;
    cout <<  "Enter the telephone no of the employee " ;
    cin >> emp1.teleno;
    cout << "Enter other information about the employee " ;
    cin >> emp1.info;

    cout << endl << "The modified age of the Employee : " << emp1.age << endl;
    cout << " The modified telephone no of the Employee : " << emp1.teleno << endl;
    
    display(&emp1);

    cout << endl << "The modified age of the Employee : " << emp1.age << endl;
    cout << " The modified telephone no of the Employee : " << emp1.teleno << endl;

    system("PAUSE");
    return(0);

}

void display(Employee *emp3)
{
            emp3->age = emp3-> age+10;
            emp3->teleno = 3299574;
}
