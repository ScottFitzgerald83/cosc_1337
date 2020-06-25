#include<iostream>
using namespace std;

int main()
    {
       int i=10;
       int *j;
       int **k;

       j=&i;
       k=&j;

       cout<<"\n ------------ values  -------------\n"<<endl;
       cout<<"value of i ="<<i<<endl;
       cout<<"value of j = "<<j<<endl;
       cout<<"value of k = "<<k<<endl;

       cout<<"\n ---------- addresses ------------- \n"<<endl;
       cout<<"address of i = "<<&i<<endl;
       cout<<"address of j = "<<&j<<endl;
       cout<<"address of k = "<<&k<<endl;

       cout<<"\n -------- values of pointers ------\n"<<endl;
       cout<<"value of *&i = "<<*&i<<endl;
       cout<<"value of *j = "<<*j<<endl;
       cout<<"value of *k = "<<*k<<endl;
       cout<<"value of **k = "<<**k<<endl;

       system("PAUSE");
       return 0;
    }
