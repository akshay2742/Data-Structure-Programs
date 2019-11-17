#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
        Node()
        {
            next=NULL;
        }
};
class clinked_list
{
    public:
        Node* head;
        Node* tail;

        clinked_list()
        {
            head=NULL;
            tail=NULL;
        }

        void add_to_start(int d)
        {
            Node* new_node=new Node();
            new_node->data=d;
            if (head==NULL)
            {
                head=new_node;
                tail=new_node;
                new_node->next=tail;
                new_node->prev=tail; 
                
            }
            else
            {
               new_node->next=head;
               head->prev=new_node;
               new_node->prev=tail;
               head=new_node;
                tail->next=head;
            }
        }
        void add_to_tail(int d)
        {
            Node* new_node=new Node();
            new_node->data=d;
            if (head==NULL)
            {
                head=new_node;
                tail=new_node;
                new_node->next=head;
                new_node->prev=tail;
            }
            else
            {
                tail->next=new_node;
                
                new_node->next=head;
                new_node->prev=tail;
                head->prev=new_node;
                tail=new_node;
               
            }
            
        }

        void traverse()
        {
            Node* temp=head;
            do
            {
                cout<<temp->data<<"\n";
                temp=temp->next;
            } while (temp!=head);
            
        }

        void reverse_traverse()
        {
            Node* temp=tail;
            do
            {
                cout<<temp->data<<"\n";
                temp=temp->prev;
            } while (temp!=tail);
            
        }

};

int main()
{
    clinked_list list;

    list.add_to_start(9);
    list.add_to_start(4);
    list.add_to_start(2);
    list.add_to_start(1);
    list.add_to_tail(15);
    cout<<"Traversal of list:\n";
    list.traverse();
    cout<<"Reverse Traversal of list:\n";
    list.reverse_traverse();
}