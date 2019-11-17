#include<iostream>
using namespace std;
int power(int b,int r)
{
    if (r==0)
    {
        return 1;
    }else
    {
        b*=power(b,r-1);
        return b;
    }
}
int main()
{
    int a,n,p;
    cout<<"Enter the Number: ";
    cin>>n;
    cout<<"\n\nEnter the power: ";
    cin>>p;
    a=power(n,p);
    cout<<"\n\nNumber is: "<<a;
}