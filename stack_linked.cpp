#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node()
        {
            next=NULL;
        }

};

class Stack
{
    public:
        Node* top;

        Stack()
        {
            top=NULL;
        }

        void push(int d)
        {
            Node* new_node=new Node();
            if (!new_node)
            {
                cout<<"Stack is Full";
            }
            else
            {
                new_node->data=d;
                new_node->next=top;
                top=new_node;
            }
        }

        bool isempty()
        {
            if (top==NULL)
            {
                cout<<"Stack is Empty";
                return true;
            }
            else
            {
                return false;
            }
        }

        int peek()
        {
            if (!isempty())
            {
                return top->data;
            }
            else
            {
                return 0;
            }
            
            
        }

        void display()
        {
            Node* temp=top;
            cout<<"Stack is: ";
            while (temp!=NULL)
            {
                cout<<temp->data<<"\n";
                temp=temp->next;
            }
            

        }
        void pop()
        {
            Node*temp;
            temp=top;
            top=top->next;
            delete temp;
        }
};

int main()
{
    Stack s;
    s.push(9);
    s.push(5);
    s.push(4);
    s.push(7);
    s.pop();    
    s.display();
}