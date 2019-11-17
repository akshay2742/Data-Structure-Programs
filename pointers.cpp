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