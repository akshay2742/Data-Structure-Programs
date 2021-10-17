#include<iostream>
using namespace std;
int main()
{
    int r;
    int a=5;
    int *p= &a;
    int **q=&p;
    cout<<&a;
    cout<<"\n"<<p;
    cout<<"\n"<<*p;
    cout<<"\n"<<a;
    cout<<"\n"<<**q;
    cout<<"\n"<<a;
    cout<<"\n"<<*q;

    r=a%10;
    cout<<r;
    

}

//Getting the address of pointer
#include <iostream>

using namespace std;
int main () {
   int  var1;
   char var2[10];

   cout << "Address of var1 variable: ";
   cout << &var1 << endl;

   cout << "Address of var2 variable: ";
   cout << &var2 << endl;

   return 0;
}
