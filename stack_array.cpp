#include<iostream>
using namespace std;
int stack[100], n=100, top=-1;
int i;

void push(int d)
{
    if (top>=n-1)
    {
        cout<<"Stack is Overflow";
    }
    else
    {
        top++;
        stack[top]=d;
    }
    
}
void pop()
{
    if (top<=-1)
    {
        cout<<"Stack is Underflow";
    }
    else
    {
        top--;
    }
}

void display()
{
    if (top<=-1)
    {
        cout<<"Stack is Undeerflow";
    }
    else
    {
        cout<<"Stack is: \n";
        for ( i = top; i >= 0; i--)
        {
            cout<<stack[i]<<"\n";
        }
        
    }
}

int topel()
{
    
    return stack[top];
}

int main()
{
    int n;
    push(9);
    push(7);
    push(5);
    push(2);
    push(3);
    pop();
    display();

    n=topel();
    cout<<"\nTop Element is: "<<n;

}