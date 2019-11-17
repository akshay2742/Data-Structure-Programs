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

class Queue
{
    public:
        Node* front;
        Node* rear;

        Queue()
        {
            front=NULL;
            rear=NULL;
        }

        void enqueue(int d)
        {
            Node* new_node=new Node();
            new_node->data=d;

            if (!new_node)
            {
                cout<<"Stack is Full";
            }
            else if (front==NULL)
            {
                front=new_node;
                rear=new_node;
                return;
            }
            else
            {
                rear->next=new_node;
                rear=rear->next;
            }
        }

        void dequeue()
        {
            
            front=front->next;
        }

        void display()
        {
            Node* temp=front;
            cout<<"Queue is: ";
            while (temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            
        }

};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(9);
    q.dequeue();
    q.display();
    
    
}

