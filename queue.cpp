#include<iostream>
using namespace std;

class Queue
{
    public:
        int MAX;
        int front;
        int rear;
        int *S;


        Queue(int n)
        {
            front=-1;
            rear=-1;
            MAX=n;
            S=new int[MAX];
        }

        bool isempty()
        {
            if (front==0 || rear==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isfull()
        {
            if (rear==MAX-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool enqueue(int d)
        {
            if (!isfull())
            {
                front=0;
                rear++;
                S[rear]=d;
                return true;

            }
            else
            {
                cout<<"Queue is Full";
                return false;
            }
        }

        void dequeue()
        {
            cout<<"Element is going to dequeue: "<<S[front]<<"\n";
           front++;
        }

        int front_r()
        {
           return S[rear];
        }

};

int main()
{

    int n=6;
    int p;
    Queue q(n);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);
    cout<<"Before Dequeue: ";
    for (int i = q.front; i <= q.rear; i++)
    {
        cout<<q.S[i]<<" ";
    }
    q.dequeue();

    cout<<"\nAfter Dequeue: ";
    for (int i = q.front; i <= q.rear; i++)
    {
        cout<<q.S[i]<<" ";
    }

    q.dequeue();

    cout<<"\nAfter Dequeue: ";
    for (int i = q.front; i <= q.rear; i++)
    {
        cout<<q.S[i]<<" ";
    }


    

    p=q.front_r();
    cout<<"\n"<<p;
}