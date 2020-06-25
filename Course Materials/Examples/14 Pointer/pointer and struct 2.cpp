// pointers to structures
/*
introduce a new operator: the arrow operator (->):
How you can access member variable of structure by using pointer. 
You know that you can access the member variables with normal variable by using “.” Dot operator.

std.age;
std.ID;

but if you want to access the member variables by using pointers then you will use “->” arrow operator.

pstd->age;
pstd->ID;

*/
          
#include <iostream>
#include <cstdio>
using namespace std;

struct Student 
{
int ID;
int age;
long phone;
};
 
int main ()
{

Student stud;
Student *pStud;
pStud = &stud;

stud.age = 20;
stud.ID = 123;
stud.phone = 220011;

printf(" Student information by using structure pointer \n \n");
printf(" Student ID %d\n",pStud->ID);
printf(" Student age %d\n",pStud->age);
printf(" Student phone %d\n\n",pStud->phone);

pStud->age = 30;
pStud->ID = 130;
pStud->phone = 113344;

printf(" Student information has changed by using structure pointer \n \n");
printf(" Student ID %d\n",pStud->ID);
printf(" Student age %d\n",pStud->age);
printf(" Student phone %d\n\n",pStud->phone);

    system("PAUSE");
    return 0;
}
